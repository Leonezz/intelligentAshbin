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
    void reportData(const int data, const int slaveAddr, const SensorType sensor);
private slots:
    // this is called when recived a reply after request
    void readyRead();

private:
    QModbusClient *m_client = nullptr;
    const int c_sensorRegStartAddr[5] = {0, 1, 2, 3, 0};
    const int c_dataLength[6] = {1, 1, 1, 2, 1};
};