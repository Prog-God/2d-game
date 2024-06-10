#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tmr = new QTimer(this);
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start(1000);

    this->setMouseTracking(true);


}

// FIX: как-то исправить эту глобальную...
Player mainPlayer;

MainWindow::~MainWindow()
{
    delete ui;
    delete tmr;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 1));

    //painter.drawLine(QPointF(10,10), QPointF(90,90));

    //QPolygon pol;
    //for(QPoint p : points)
    //    pol << p;
    //painter.drawPolygon(pol);

    for (int i = 1; i < points.size(); ++i)
    {
        painter.drawLine(points[i-1], points[i]);
    }

    QPolygon pol(mainPlayer.getPoints()); // FIX: засунуть полностью в класс Player - будет проще различать границы

    painter.drawPolygon(pol);

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint curP = event->pos();
    //qDebug() << curP;
    points.push_back(curP);

    repaint();
}

void MainWindow::updateTime()
{
    //qDebug() << QTime::currentTime().toString();
    //qDebug() << hasMouseTracking();
    repaint();

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int stepSize = 20;

    int key = event->key();
    switch (key)
    {
        case Qt::Key_W:
        {
            mainPlayer.movePlayer(QPoint(0, -stepSize));
            repaint();
        }break;

        case Qt::Key_S:
        {
            mainPlayer.movePlayer(QPoint(0, stepSize));
            repaint();
        }break;

        case Qt::Key_A:
        {
            mainPlayer.movePlayer(QPoint(-stepSize, 0));
            repaint();
        }break;

        case Qt::Key_D:
        {
            mainPlayer.movePlayer(QPoint(stepSize, 0));
            repaint();
        }break;

        default:
        {

        }
    }
}


