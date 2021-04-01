#include "inc/modbus.hpp"

Modbus::Modbus(QObject *parent)
    : QObject(parent), m_client(new QModbusRtuSerialMaster(this))
{
}

Modbus::~Modbus()
{
    if (m_client != nullptr)
        m_client->disconnectDevice();
    delete m_client;
}

/**
 * @name    : connctSerial
 * @brief   : connect to slave devices through serial port
 * @param   : portName  serial port name to connect
 *            parity    serial connection parity(Even/Odd/None)
 *            baudRate  serial connection baudrate
 *            stopBits  serial connection stopbits
 *            dataBits  serial connection databits
 * */
bool Modbus::connctSerial(const SerialInfo &info)
{
    // client already connected
    if (m_client->state() == QModbusDevice::ConnectedState)
        m_client->disconnectDevice();
    m_client->setConnectionParameter(QModbusDevice::SerialPortNameParameter, info.portName);
    m_client->setConnectionParameter(QModbusDevice::SerialParityParameter, info.parity);
    m_client->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, info.baudRate);
    m_client->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, info.stopBits);
    m_client->setConnectionParameter(QModbusDevice::SerialDataBitsParameter, info.dataBits);
    m_client->setNumberOfRetries(1);
    m_client->setTimeout(1000);
    if (!m_client->connectDevice())
    {
        emit error(tr("Connect failed: ") + m_client->errorString());
        return false;
    }
    return true;
}

void Modbus::disconnectSerial()
{
    m_client->disconnectDevice();
}

void Modbus::readSensorData(const SensorType sensor, int slaveAddr)
{
    QModbusDataUnit::RegisterType reg = (sensor == SensorType::Putter)
                                            ? QModbusDataUnit::RegisterType::Coils
                                            : QModbusDataUnit::InputRegisters;
    const QModbusDataUnit writeUnit(reg, c_sensorRegStartAddr[sensor], c_dataLength[sensor]);
    if (auto *reply = m_client->sendReadRequest(writeUnit, slaveAddr))
    {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &Modbus::readyRead);
        else
            delete reply;
    }
    else
    {
        emit error(tr("Read error: ") + m_client->errorString());
    }
}

void Modbus::writeSensorData(const SensorType sensor, int slaveAddr, int data)
{
    QModbusDataUnit::RegisterType reg = (sensor == SensorType::Putter)
                                            ? QModbusDataUnit::RegisterType::Coils
                                            : QModbusDataUnit::InputRegisters;
    QModbusDataUnit writeUnit(reg, c_sensorRegStartAddr[sensor], c_dataLength[sensor]);
    writeUnit.setValue(0, data);
    if (auto *reply = m_client->sendWriteRequest(writeUnit, slaveAddr))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, &Modbus::readyRead);
        }
        else
            delete reply;
    }
    else
    {
        emit error(tr("Write error: ") + m_client->errorString());
    }
}

void Modbus::readyRead()
{
    auto *reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;
    qDebug() << reply->rawResult().data();
    if (reply->error() == QModbusDevice::NoError)
    {
        SensorType sensor = SensorType::Putter;
        const QModbusDataUnit unit = reply->result();
        if (unit.registerType() != QModbusDataUnit::RegisterType::Coils)
        {
            sensor = c_startAddrToSensor[unit.startAddress()];
        }
        const int dataLength = c_dataLength[sensor];
        QVector<quint16> result;
        for (int i = 0; i < dataLength; ++i)
        {
            result.append(unit.value(i));
        }
        emit reportData(result, reply->serverAddress(), sensor);
    }
    // Proctocal error
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        emit error(tr("Read response error: %1 (Modbus exception: 0x%2)")
                       .arg(reply->errorString())
                       .arg(reply->rawResult().exceptionCode(), -1, 16));
    }
    // unknown error
    else
    {
        emit error(tr("Read response error: %1 (error code: 0x%2)")
                       .arg(reply->errorString())
                       .arg(reply->rawResult().exceptionCode(), -1, 16));
    }
}