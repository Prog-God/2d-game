#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>

#include <QDebug>

#include <execution>

#include "field.h"

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

    Field baseField;

    void drawField(Field&);


    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);

    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};
#endif // MAINWINDOW_H
