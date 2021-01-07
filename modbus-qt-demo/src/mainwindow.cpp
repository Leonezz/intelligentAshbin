#include "inc/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_slaveCount(0)
    , m_modbusClient(new Modbus)
    , m_serialConnected(false)
    , m_requestTimer(new QTimer)
{
    ui->setupUi(this);
    initToolBarActions();
    initSerialDialog();
    initStatusBar();
    initTabWidget();
    initModbusClient();
    m_requestTimer->start(50);
    connect(m_requestTimer, &QTimer::timeout, this, &MainWindow::requestModbus);
    this->setWindowTitle(tr("Modbus Master demo"));
}

void MainWindow::requestModbus()
{
    if (m_requestQueue.empty())
        return;
    request_cnt++;
    RequestInfo info = m_requestQueue.dequeue();
    if (info.opreationCode == 0x04 || info.opreationCode == 0x01)
    {
        m_modbusClient->readSensorData(info.sensor, info.slaveID);
    }
    if (info.opreationCode == 0x05)
    {
        m_modbusClient->writeSensorData(info.sensor, info.slaveID, info.data);
    }
}

void MainWindow::initToolBarActions()
{
    m_actionNewDevice = new QAction(tr("new device"));
    connect(m_actionNewDevice, &QAction::triggered, this, &MainWindow::addDevice);

    m_actionSerialSetting = new QAction(tr("serial setting"));
    connect(m_actionSerialSetting, &QAction::triggered, this, &MainWindow::serialSettingDialogExec);

    m_actionConnectSerial = new QAction(tr("connect"));
    connect(m_actionConnectSerial, &QAction::triggered, this, &MainWindow::actionConnectSerialTriggered);

    this->menuBar()->addActions({m_actionNewDevice, m_actionSerialSetting, m_actionConnectSerial});
}

void MainWindow::initSerialDialog()
{
    m_dialogSerialSetting = new SerialSettingDialog(this);
    connect(m_dialogSerialSetting, &SerialSettingDialog::dialogClosed,
            this, &MainWindow::getSerialSettings);
}

void MainWindow::initModbusClient()
{
    connect(m_modbusClient, &Modbus::info, this, &MainWindow::statusInfo);
    connect(m_modbusClient, &Modbus::warn, this, &MainWindow::statusWarn);
    connect(m_modbusClient, &Modbus::error, this, &MainWindow::statusError);
    connect(m_modbusClient, &Modbus::reportData, this, &MainWindow::getModbusReply);
}

void MainWindow::getModbusReply(int data, int slaveID, SensorType sensor)
{
    emit sendSensorDataToDevice(slaveID, sensor, data);
    reply_cnt++;
    m_statusLabel->setText(QString("%1/%2").arg(reply_cnt).arg(request_cnt));
}

void MainWindow::initTabWidget()
{
    ui->tabWidget->clear();
}

void MainWindow::getSerialSettings(const SerialInfo &info)
{
    statusInfo(tr(
                   "Serial set to port %1 with baudrate: %2, parity: %3, stopbits: %4, databits: %5.")
                   .arg(info.portName)
                   .arg(info.baudRate)
                   .arg(info.parity)
                   .arg(info.stopBits)
                   .arg(info.dataBits));
    m_serialInfo = info;
}

void MainWindow::initStatusBar()
{
    m_statusLabel = new QLabel;
    this->statusBar()->addWidget(m_statusLabel);
}

void MainWindow::serialSettingDialogExec()
{
    m_dialogSerialSetting->exec();
}

void MainWindow::actionConnectSerialTriggered()
{
    if (!m_serialConnected)
    {
        if (m_modbusClient->connctSerial(m_serialInfo))
        {
            this->m_actionConnectSerial->setText(tr("disconnect"));
            m_serialConnected = true;
        }
    }
    else
    {
        m_modbusClient->disconnectSerial();
        this->m_actionConnectSerial->setText(tr("connect"));
        m_serialConnected = false;
    }
}

void MainWindow::addDevice()
{
    int id = m_deviceList.length() + 1;
    Device *device = new Device(id, this);
    m_deviceList.append(device);
    connect(device, &Device::removeDevice, this, &MainWindow::removeDevice);
    connect(device, &Device::requestSensoreData, this, &MainWindow::addRequestToQueue);
    connect(this, &MainWindow::sendSensorDataToDevice, device, &Device::getSensorData);
    ui->tabWidget->addTab(device, tr("device %1").arg(id));
}

void MainWindow::addRequestToQueue(const int slaveID, const SensorType sensor, int data, const int op)
{

    m_requestQueue.enqueue({slaveID, op, sensor, data});
}

void MainWindow::removeDevice()
{
    Device *const device = qobject_cast<Device *>(sender());
    ui->tabWidget->removeTab(ui->tabWidget->indexOf(device));
    m_deviceList.removeOne(device);
    delete device;
}

void MainWindow::statusInfo(const QString &msg)
{
    this->m_statusLabel->setText("info: " + msg);
}

void MainWindow::statusWarn(const QString &msg)
{
    this->m_statusLabel->setText("warn: " + msg);
}
void MainWindow::statusError(const QString &msg)
{
    this->m_statusLabel->setText("Error: " + msg);
}

MainWindow::~MainWindow()
{
    delete ui;
}
