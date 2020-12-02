#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_sensor(new Sensor), m_timer(new QTimer)
{
    ui->setupUi(this);
    
    this->setWindowTitle("Modbus Master Demo");
    
    connect(ui->connectPushButton, &QPushButton::clicked,
            this, &MainWindow::pushButtonConnectClicked);
    connect(ui->disconnectPushButton, &QPushButton::clicked,
            this, &MainWindow::pushButtonDisconnectClicked);
    connect(ui->refreashPushButton, &QPushButton::clicked,
            this, &MainWindow::refreshAvaliablePorts);
    connect(m_sensor, &Sensor::tempreatureAndHumidityRecived,
            this, &MainWindow::getDataFromSensor);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::querryData);


    ui->correctBitCombobox->addItem("None");
    ui->baundRateComboBox->addItem("9600");
    ui->dataBitsComboBox->addItem("8");
    ui->stopBitComboBox->addItem("1");
}

void MainWindow::pushButtonConnectClicked()
{
    m_sensor->initSerialModbus(ui->serialportNameCombobox->itemText(ui->serialportNameCombobox->currentIndex()),
                               QSerialPort::BaudRate::Baud9600,
                               QSerialPort::DataBits::Data8,
                               QSerialPort::Parity::NoParity,
                               QSerialPort::StopBits::OneStop);
    m_sensor->connectDevice();
    m_timer->start(500);
}

void MainWindow::pushButtonDisconnectClicked()
{
    m_sensor->disconnectDevice();
    m_timer->stop();
}

void MainWindow::refreshAvaliablePorts()
{
    ui->serialportNameCombobox->clear();
    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    for (auto &&info : infoList)
    {
        ui->serialportNameCombobox->addItem(info.portName());
    }
}

void MainWindow::querryData()
{
    m_sensor->readTemptempreatureAndHumidity(1);
}

void MainWindow::getDataFromSensor(const unsigned int tempreature,
                                   const unsigned int humidity)
{
    this->ui->tempreatureLabal->setText(QString::number(tempreature/100.0));
    this->ui->humidityLabel->setText(QString::number(humidity/100.0));
}

MainWindow::~MainWindow()
{
    delete ui;
}
