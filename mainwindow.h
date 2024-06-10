#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QPainter>
#include <QMouseEvent>

#include <QTime>
#include <QDebug>

#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QTimer *tmr; //Адресная переменная таймера
    std::vector<QPoint> points;

private slots:
    void updateTime(); //Слот для обновления времени на экране

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
