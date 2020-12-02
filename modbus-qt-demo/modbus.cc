#include "modbus.hpp"

Sensor::Sensor(QObject *parent) : QObject(parent)
{
}

void Sensor::initSerialModbus(const QString &portName,
                              const int baudRate,
                              const QSerialPort::DataBits dataBits,
                              const QSerialPort::Parity parity,
                              const QSerialPort::StopBits stopBits)
{
    m_master = new QModbusRtuSerialMaster(this);
    m_master->setConnectionParameter(QModbusDevice::SerialPortNameParameter, portName);
    m_master->setConnectionParameter(QModbusDevice::SerialBaudRateParameter, baudRate);
    m_master->setConnectionParameter(QModbusDevice::SerialParityParameter, parity);
    m_master->setConnectionParameter(QModbusDevice::SerialStopBitsParameter, stopBits);
}

void Sensor::connectDevice()
{
    m_master->connectDevice();
}

void Sensor::readTemptempreatureAndHumidity(const int slaveID)
{
    QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters, 0, 2);
    if (QModbusReply *reply = m_master->sendReadRequest(readUnit, slaveID))
    {
        if (reply->isFinished())
        {
            delete reply;
        }
        else
        {
            connect(
                reply, &QModbusReply::finished, [=]() {
                    if (reply->error() != QModbusDevice::NoError)
                    {
                    }
                    else
                    {
                        const QModbusDataUnit unit = reply->result();
                        if(unit.valueCount()==2)
                        {
                            emit tempreatureAndHumidityRecived(unit.value(0),unit.value(1));
                        }
                    }
                });
        }
    }
    else
    {
    }
}

void Sensor::disconnectDevice()
{
    m_master->disconnectDevice();
}