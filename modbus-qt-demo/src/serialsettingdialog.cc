#include "inc/serialsettingdialog.hpp"
#include "ui_serialdialog.h"
SerialSettingDialog::SerialSettingDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::SerialDialog)
{
    ui->setupUi(this);
    initComboboxes();
    connect(ui->pushButtonOK, &QPushButton::clicked, this, &SerialSettingDialog::okButtonClicked);
    connect(ui->pushButtonCancel, &QPushButton::clicked, this, &SerialSettingDialog::close);
}

void SerialSettingDialog::initComboboxes()
{
    ui->correctBitCombobox->addItems({"odd", "even", "none", "mark", "space", "unknown"});
    ui->correctBitCombobox->setCurrentIndex(2);
    ui->correctBitCombobox->setEditable(false);

    ui->baundRateComboBox->addItems({"1200", "2400", "4800", "9600", "19200", "38400", "57600", "115200"});
    ui->baundRateComboBox->setCurrentIndex(7);
    ui->baundRateComboBox->setEditable(false);

    ui->dataBitsComboBox->addItems({"5", "6", "7", "8", "known"});
    ui->dataBitsComboBox->setCurrentIndex(3);
    ui->dataBitsComboBox->setEditable(false);

    ui->stopBitComboBox->addItems({"1", "1.5", "2", "unknown"});
    ui->stopBitComboBox->setCurrentIndex(0);
    ui->stopBitComboBox->setEditable(false);

    QList<QSerialPortInfo> infoList = QSerialPortInfo::availablePorts();
    for (auto &&info : infoList)
    {
        const QString &portName = info.portName();
        ui->serialportNameCombobox->addItem(portName);
    }
}

void SerialSettingDialog::okButtonClicked()
{
    const QString &portName = ui->serialportNameCombobox->currentText();
    static const QSerialPort::Parity parities[] =
        {QSerialPort::Parity::OddParity,
         QSerialPort::Parity::EvenParity,
         QSerialPort::Parity::NoParity,
         QSerialPort::Parity::MarkParity,
         QSerialPort::Parity::SpaceParity,
         QSerialPort::Parity::UnknownParity};
    const QSerialPort::Parity parity =
        parities[ui->correctBitCombobox->currentIndex()];
    static const QSerialPort::BaudRate baudRates[] =
        {QSerialPort::BaudRate::Baud1200,
         QSerialPort::BaudRate::Baud2400,
         QSerialPort::BaudRate::Baud4800,
         QSerialPort::BaudRate::Baud9600,
         QSerialPort::BaudRate::Baud19200,
         QSerialPort::BaudRate::Baud38400,
         QSerialPort::BaudRate::Baud57600,
         QSerialPort::BaudRate::Baud115200};
    const QSerialPort::BaudRate baudRate =
        baudRates[ui->baundRateComboBox->currentIndex()];
    static const QSerialPort::StopBits stopbits[] =
        {QSerialPort::StopBits::OneStop,
         QSerialPort::StopBits::OneAndHalfStop,
         QSerialPort::StopBits::TwoStop,
         QSerialPort::StopBits::UnknownStopBits};
    const QSerialPort::StopBits stopBit =
        stopbits[ui->stopBitComboBox->currentIndex()];
    static const QSerialPort::DataBits dataBits[] =
        {QSerialPort::DataBits::Data5,
         QSerialPort::DataBits::Data6,
         QSerialPort::DataBits::Data7,
         QSerialPort::DataBits::Data8,
         QSerialPort::DataBits::UnknownDataBits};
    const QSerialPort::DataBits dataBit =
        dataBits[ui->dataBitsComboBox->currentIndex()];
    emit dialogClosed(SerialInfo{portName, parity, baudRate, stopBit, dataBit});
    this->close();
}

SerialSettingDialog::~SerialSettingDialog()
{
    delete ui;
}