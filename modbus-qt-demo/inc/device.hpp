#pragma once
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QPainter>

#include "qrencode/qrencode.h"
#include "inc/serialinfo.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class DeviceForm;
}
QT_END_NAMESPACE
class Device : public QWidget
{
    Q_OBJECT
public:
    Device(const int id, QWidget *parent = nullptr);
    ~Device();
public slots:
    void getSensorData(const int id, const SensorType sensor, const QVector<qint16> &data);
signals:
    void removeDevice();
    void requestSensoreData(const int id, const SensorType sensor, const int data = 0, const int op = 0x04);
private slots:
    void autoReflash();
    void checkBoxAutoReflashClicked(bool checked);

private:
    void qrEncode(const QString &msg);
    int convertRawDataToNumber(const QVector<qint16> &rawData);
private:
    Ui::DeviceForm *ui;
    QImage m_qrCodeImage;
    const int c_qrCodeImgWidth = 400;
    const int c_qrCodeBorder = 50;
    const int m_id;
    bool m_putterStatus;
    QTimer *m_timer;
};
