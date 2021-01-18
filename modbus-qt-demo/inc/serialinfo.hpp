#pragma once
#include <QSerialPort>

struct SerialInfo
{
    QString portName;
    QSerialPort::Parity parity;
    QSerialPort::BaudRate baudRate;
    QSerialPort::StopBits stopBits;
    QSerialPort::DataBits dataBits;
};

enum SensorType
{
    Tempreature = 0,
    Humidity = 1,
    Gas = 2,
    Weight = 3,
    Putter = 4,
    Scaner = 5,
    Ultrasound = 6,
    Infrared = 7
};