#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPortInfo>
#include "modbus.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void pushButtonConnectClicked();
    void refreshAvaliablePorts();
    void pushButtonDisconnectClicked();
    void querryData();
    void getDataFromSensor(const unsigned int tempreature, const unsigned int humidity);
private:
    Ui::MainWindow *ui;
    Sensor* m_sensor;
    QTimer* m_timer;
};
#endif // MAINWINDOW_H
