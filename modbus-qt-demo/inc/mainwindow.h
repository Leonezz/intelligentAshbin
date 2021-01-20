#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include <QAction>
#include <QLabel>
#include "inc/modbus.hpp"
#include "inc/serialinfo.hpp"
#include "inc/serialsettingdialog.hpp"
#include "inc/device.hpp"
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

struct RequestInfo
{
    int slaveID;
    int opreationCode;
    SensorType sensor;
    int data;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    static const QString querryUserInfoFromDataBase(const QString &id);

private:
    void initToolBarActions();
    void initSerialDialog();
    void initStatusBar();
    void initModbusClient();
    void initTabWidget();
    void initDataBase();
private slots:
    void addDevice();
    void serialSettingDialogExec();
    void actionConnectSerialTriggered();
    void getSerialSettings(const SerialInfo &info);
    void statusInfo(const QString &msg);
    void statusWarn(const QString &msg);
    void statusError(const QString &msg);
    void removeDevice();
    void addRequestToQueue(const int slaveID, const SensorType sensor, int data, const int op);
    void requestModbus();
    void getModbusReply(const QVector<qint16> &data, int slaveID, SensorType sensor);
signals:
    void sendSensorDataToDevice(int id, const SensorType sensor, const QVector<qint16> &data);

private:
    Ui::MainWindow *ui;
    int m_slaveCount;
    static QJsonObject m_database;
    QAction *m_actionNewDevice;
    QAction *m_actionSerialSetting;
    QAction *m_actionConnectSerial;
    QLabel *m_statusLabel;
    SerialSettingDialog *m_dialogSerialSetting;
    Modbus *m_modbusClient;
    SerialInfo m_serialInfo;
    bool m_serialConnected;
    QList<Device *> m_deviceList;
    // in the pair, the first is slaveID, the second is regAddr
    QQueue<RequestInfo> m_requestQueue;
    QTimer *m_requestTimer;
    quint64 request_cnt = 0;
    quint64 reply_cnt = 0;
};

#endif // MAINWINDOW_H
