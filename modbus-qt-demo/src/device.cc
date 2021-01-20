#include "inc/device.hpp"
#include "inc/mainwindow.h"
#include "ui_deviceform.h"

QJsonObject MainWindow::m_database = QJsonObject();

Device::Device(const int id, QWidget *parent)
    : QWidget(parent), ui(new Ui::DeviceForm), m_id(id), m_putterStatus(0), m_timer(new QTimer)
{
    ui->setupUi(this);
    ui->labelSlaveAddress->setText(QString::number(id));

    m_qrCodeImage = QImage(c_qrCodeImgWidth, c_qrCodeImgWidth, QImage::Format::Format_BGR888);

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
    connect(ui->pushButtonDistance, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Ultrasound);
    });
    connect(ui->pushButtonFullStatus, &QPushButton::clicked, [this]() {
        emit requestSensoreData(m_id, SensorType::Infrared);
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
    ui->pushButtonFullStatus->setDisabled(checked);
    ui->pushButtonDistance->setDisabled(checked);
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
    emit requestSensoreData(m_id, SensorType::Scaner);
    emit requestSensoreData(m_id, SensorType::Ultrasound);
    emit requestSensoreData(m_id, SensorType::Infrared);
}
int Device::convertRawDataToNumber(const QVector<qint16> &rawData)
{
    int result = 0;
    for (auto &&unit : rawData)
    {
        result <<= 16;
        result += unit;
    }
    return result;
}
void Device::getSensorData(const int id, const SensorType sensor, const QVector<qint16> &data)
{
    if (id != this->m_id)
        return;
    static const QMap<SensorType, QLabel *> labelMap =
        {{SensorType::Tempreature, ui->labelTempreature},
         {SensorType::Humidity, ui->labelHumidity},
         {SensorType::Gas, ui->labelGas},
         {SensorType::Weight, ui->labelWeight},
         {SensorType::Putter, ui->labelPutterStatus},
         {SensorType::Scaner, ui->labelUserInfo},
         {SensorType::Ultrasound, ui->labelDistance},
         {SensorType::Infrared, ui->labelFullStatus}};
    static const QMap<SensorType, std::function<QString(const QVector<qint16> &)>> functionMap =
        {
            {SensorType::Tempreature, [this](const QVector<qint16> &val) -> QString {
                 return QString::number(convertRawDataToNumber(val) / 100.0) + " ^oC";
             }},
            {SensorType::Humidity, [this](const QVector<qint16> &val) -> QString {
                 return QString::number(convertRawDataToNumber(val) / 100.0) + " %";
             }},
            {SensorType::Gas, [this](const QVector<qint16> &val) -> QString {
                 return QString::number(convertRawDataToNumber(val) * 3.3 / 4096.0) + " v/3.3v";
             }},
            {SensorType::Weight, [this](const QVector<qint16> &val) -> QString {
                 return QString::number(convertRawDataToNumber(val) / 100.0) + " kg";
             }},
            {SensorType::Putter, [this](const QVector<qint16> &val) -> QString {
                 this->m_putterStatus = convertRawDataToNumber(val) > 0;
                 return (m_putterStatus ? tr("打开") : tr("关闭"));
             }},
            {SensorType::Ultrasound, [this](const QVector<qint16> &val) -> QString {
                 return QString::number(convertRawDataToNumber(val)) + tr("mm");
             }},
            {SensorType::Infrared, [this](const QVector<qint16> &val) -> QString {
                 return QString(convertRawDataToNumber(val) > 0 ? tr("已满")
                                                                : tr("未满"));
             }},
            {SensorType::Scaner, [this](const QVector<qint16> &val) -> QString {
                 if (val.first() == 0)
                 {
                     return ui->labelUserInfo->text();
                 }
                 QString id;
                 for (int index = 1; index < val.length(); ++index)
                 {
                     qDebug() << (char)(val[index]);
                     id += (char)(val[index]);
                 }
                 const QString info = MainWindow::querryUserInfoFromDataBase(id);
                 qDebug() << info;
                 qrEncode(id);
                 this->ui->labelQRCode->setPixmap(QPixmap::fromImage(this->m_qrCodeImage));
                 if (info.isEmpty())
                 {
                     return tr("查无此人");
                 }
                 emit requestSensoreData(m_id, SensorType::Putter, 1, 0x05);
                 return info;
             }}};
    QLabel *const label = labelMap[sensor];
    QString msg = functionMap[sensor](data);

    label->setText(msg);
}

void Device::qrEncode(const QString &msg)
{
    if (msg.isEmpty())
        return;
    m_qrCodeImage.fill(QColor(255, 255, 255));
    const int qrAreaWidth = c_qrCodeImgWidth - 2 * c_qrCodeBorder;
    QRcode *code = QRcode_encodeString(msg.toStdString().c_str(), 0, QR_ECLEVEL_M, QR_MODE_8, 1);
    if (code == nullptr)
        return;
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
