#pragma once
#include <QtSerialBus>
#include <QSerialPort>
#include <QObject>
#include "serialinfo.hpp"

class Modbus : public QObject
{
    Q_OBJECT
public:
    Modbus(QObject *parent = nullptr);
    ~Modbus();
    bool connctSerial(const SerialInfo &info);
    void disconnectSerial();
    void readSensorData(const SensorType sensor, int slaveAddr);
    void writeSensorData(const SensorType sensor, int slaveAddr, int data);
signals:
    void info(const QString &msg);
    void warn(const QString &msg);
    void error(const QString &msg);
    // report data to mainwindow through singnal
    void reportData(const QVector<qint16> &rawData, const int slaveAddr, const SensorType sensor);
private slots:
    // this is called when recived a reply after request
    void readyRead();

private:
    QModbusClient *m_client = nullptr;
    const int c_sensorRegStartAddr[8] = {0, 1, 2, 3, 0, 5, 19, 20};
    const int c_dataLength[8] = {1, 1, 1, 2, 1, 14, 1, 1};
    const QMap<int, SensorType> c_startAddrToSensor = {
        {0, SensorType::Tempreature},
        {1, SensorType::Humidity},
        {2, SensorType::Gas},
        {3, SensorType::Weight},
        {4, SensorType::Putter},
        {5, SensorType::Scaner},
        {19, SensorType::Ultrasound},
        {20, SensorType::Infrared}};
};