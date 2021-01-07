#include "inc/device.hpp"
#include "ui_deviceform.h"
Device::Device(const int id, QWidget *parent)
    : QWidget(parent), ui(new Ui::DeviceForm), m_id(id), m_putterStatus(0), m_timer(new QTimer)
{
    ui->setupUi(this);
    ui->labelSlaveAddress->setText(QString::number(id));

    m_qrCodeImage = QImage(c_qrCodeImgWidth,c_qrCodeImgWidth,QImage::Format::Format_BGR888);

    connect(ui->pushButtonDeleteDevice, &QPushButton::clicked, [this]() {
        emit removeDevice();
    });
    connect(ui->pushButtonTemreature, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Tempreature);
    });
    connect(ui->pushButtonHumidity, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Humidity);
    });
    connect(ui->pushButtonGas, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Gas);
    });
    connect(ui->pushButtonWeight, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Weight);
    });
    connect(ui->pushButtonTogglePutterStatus, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Putter, (int)(!m_putterStatus), 0x05);
    });
    connect(ui->pushButtonReflashPutterStatus, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Putter);
    });
    connect(ui->checkBoxAutoReflash, &QCheckBox::clicked, this, &Device::checkBoxAutoReflashClicked);
    connect(m_timer, &QTimer::timeout, this, &Device::autoReflash);
}

void Device::checkBoxAutoReflashClicked(bool checked)
{
    ui->pushButtonGas->setDisabled(checked);
    ui->pushButtonHumidity->setDisabled(checked);
    ui->pushButtonTemreature->setDisabled(checked);
    ui->pushButtonWeight->setDisabled(checked);
    ui->pushButtonReflashPutterStatus->setDisabled(checked);
    if (checked)
    {
        m_timer->start(1200);
    }
    else
    {
        m_timer->stop();
    }
}
void Device::autoReflash()
{
    emit requestSensoreData(m_id, SensorType::Tempreature);
    emit requestSensoreData(m_id, SensorType::Humidity);
    emit requestSensoreData(m_id, SensorType::Gas);
    emit requestSensoreData(m_id, SensorType::Weight);
    emit requestSensoreData(m_id, SensorType::Putter);
}

void Device::getSensorData(const int id, const SensorType sensor, const int data)
{
    if (id != this->m_id)
        return;
    static const QMap<SensorType, QLabel *> labelMap =
        {{SensorType::Tempreature, ui->labelTempreature},
         {SensorType::Humidity, ui->labelHumidity},
         {SensorType::Gas, ui->labelGas},
         {SensorType::Weight, ui->labelWeight},
         {SensorType::Putter, ui->labelPutterStatus}};
    static const QMap<SensorType, std::function<QString(int)>> functionMap =
        {
            {SensorType::Tempreature, [](int val) -> QString { return QString::number(val / 100.0) + " ^oC"; }},
            {SensorType::Humidity, [](int val) -> QString { return QString::number(val / 100.0) + " %"; }},
            {SensorType::Gas, [](int val) -> QString { return QString::number(val * 3.3 / 4096.0) + " v/3.3v"; }},
            {SensorType::Weight, [](int val) -> QString { return QString::number(val / 100.0) + " kg"; }},
            {SensorType::Putter, [](int val) -> QString { return ((val > 0) ? tr("打开") : tr("关闭")); }}};
    QLabel *const label = labelMap[sensor];
    m_putterStatus = (data > 0);
    QString msg = functionMap[sensor](data);

    label->setText(msg);
}

void Device::qrEncode(const QString& msg)
{
    m_qrCodeImage.fill(QColor(255, 255, 255));
    const int qrAreaWidth = c_qrCodeImgWidth - 2 * c_qrCodeBorder;
    QRcode *code = QRcode_encodeString(msg.toStdString().c_str(), 0, QR_ECLEVEL_M, QR_MODE_8, 1);
    const int qrNodeCnt = code->width;
    const int qrNodeWidth = qrAreaWidth / qrNodeCnt;

    QPainter painter(&this->m_qrCodeImage);
    painter.setPen(QColor(0, 0, 0));
    painter.setBrush(QColor(0, 0, 0));
    for (int i = 0; i < qrNodeCnt; ++i)
    {
        for (int j = 0; j < qrNodeCnt; ++j)
        {
            if (code->data[i * qrNodeCnt + j] & 0x01)
            {
                painter.drawRect(i * qrNodeWidth + c_qrCodeBorder, j * qrNodeWidth + c_qrCodeBorder, qrNodeWidth, qrNodeWidth);
            }
        }
    }
}

Device::~Device()
{
    delete ui;
}
