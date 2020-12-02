#include <QtSerialBus>
#include <QSerialPort>
#include <QObject>
class Sensor : public QObject
{
    Q_OBJECT

public:
    Sensor(QObject *parent = nullptr);
    void initSerialModbus(const QString &portName,
                          const int baudRate,
                          const QSerialPort::DataBits dataBits,
                          const QSerialPort::Parity parity,
                          const QSerialPort::StopBits stopBits);
    void connectDevice();
    void disconnectDevice();
    void readTemptempreatureAndHumidity(const int slaveID);
    // to be removed
    //int readSlaveID();
    //int readSlaveBaudRate();
    //int readLRCCode();
    //void setSlaveID(const int ID);
    //void setSlaveBaudRate(const int baudRate);
    //void setLRCCode(const int LRC);
signals:
    void tempreatureAndHumidityRecived(const unsigned int tempreature, const unsigned int humidity);

private:
    QModbusClient *m_master;
};