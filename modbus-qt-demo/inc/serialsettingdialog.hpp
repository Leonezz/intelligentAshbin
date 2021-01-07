#pragma once
#include <QObject>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QDialog>
#include "serialinfo.hpp"
QT_BEGIN_NAMESPACE
namespace Ui
{
    class SerialDialog;
}
QT_END_NAMESPACE
class SerialSettingDialog : public QDialog
{
    Q_OBJECT
public:
    SerialSettingDialog(QWidget *parent = nullptr);
    ~SerialSettingDialog();
signals:
    void dialogClosed(const SerialInfo& info);

private:
    void initComboboxes();
private slots:
    void okButtonClicked();

private:
    Ui::SerialDialog *ui;
};
