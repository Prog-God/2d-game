#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // TODO: ЗДЕСЬ оно не сработает - надо в другое место куда-то!!!!!!!!!
    baseField.setFieldSize(ui->centralwidget->width(), ui->centralwidget->height());

    qDebug() << "width " << baseField.getField_width();
    qDebug() << "height " << baseField.getField_height();


    startTimer(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int counter = 0;

void MainWindow::drawField(Field &)
{
    std::list<Bullet>& bul_fd = baseField.bullets_on_field;

    std::for_each(std::execution::par,
                  bul_fd.begin(),
                  bul_fd.end(),
                  [](auto& blt) { blt.moveBullet(); } );


    // TODO:
    // проверка перекрытия объектов Bullet и Player
    // при перекрытии:                          отнимать хитпоинты
    // проверка потери хп после перекрытия:     удалять объект с поля, если враг; конец игры, если игрок





    //float window_width = ui->centralwidget->width();
    //float window_height = ui->centralwidget->height();



    //TODO: ошибка вызова функции (удалена) оператора присваивания Bullet!!!!

    //bul_fd.erase(std::remove_if(bul_fd.begin(),
    //                            bul_fd.end(),
    //                            [window_width, window_height] (auto& blt){ return (blt.getPosition().x() > window_width); }),
    //            bul_fd.end());



    const float collider_enemy_size = 50;

    // ХЗ, куда и главное как это засунуть в классе куда-нибудь....
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribX(0, ui->centralwidget->width() - collider_enemy_size);
    std::uniform_int_distribution<> distribY(0, ui->centralwidget->height() - collider_enemy_size);


    float startX = distribX(gen);
    startX = startX - (static_cast<int>(startX) % static_cast<int>(collider_enemy_size));
    float startY = distribY(gen);
    startY = startY - (static_cast<int>(startY) % static_cast<int>(collider_enemy_size));


    // TODO: Надо по таймеру как-то.
    //КОСТЫЛЬ на костыле:
    if (counter == 250)
    {
        auto en = baseField.generateEnemy(QVector2D(startX, startY));
        baseField.enemies_on_field.push_back(std::move(en));
        counter = 0;
    }
    ++counter;

    repaint();
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    drawField(baseField);
}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    painter.setPen(QPen(Qt::cyan, 2));
    const float col_bullet_size = baseField.bullets_on_field.front().getCollider_size();
    for(auto it(baseField.bullets_on_field.cbegin()); it != baseField.bullets_on_field.cend(); ++it)
    {
        painter.drawEllipse(QRectF(it->getPosition().x(), it->getPosition().y(),
                                   col_bullet_size, col_bullet_size));
    }

    painter.setPen(QPen(Qt::red, 1));
    const float col_enemy_size = baseField.enemies_on_field.front().getСollider_size();
    for(auto it(baseField.enemies_on_field.cbegin()); it != baseField.enemies_on_field.cend(); ++it)
    {
        painter.drawRect(it->getCurrent_position().x(), it->getCurrent_position().y(),
                        col_enemy_size, col_enemy_size);
    }

    painter.setPen(QPen(Qt::green, 1));
    const float col_player_size = baseField.player.getСollider_size();
    painter.drawRect(baseField.player.getCurrent_position().x(),
                     baseField.player.getCurrent_position().y(),
                     col_player_size, col_player_size);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    Player& pl = baseField.player;

    int key = event->key();
    switch (key)
    {
    case Qt::Key_Up:
    {
        // Проверяю на выход за границы окна...
        // Потом это явно как-то по-другому надо делать: у меня ж всякие границы уровня будут и пр. предметы


        if (pl.getCurrent_position().y() - pl.getMovement_speed() >= 0)
            pl.movePlayer(Direction::Up);
        //else
        //      не могу напрямую что-то сделать с положением игрока... ХЗ
        //      теперь даже просто к границе насильно его не прибить вплотную
    }break;

    case Qt::Key_Down:
    {
        if (pl.getCurrent_position().y() + pl.getСollider_size() + pl.getMovement_speed() <= this->height())
            pl.movePlayer(Direction::Down);
    }break;

    case Qt::Key_Left:
    {
        if (pl.getCurrent_position().x() - pl.getMovement_speed() >= 0)
            pl.movePlayer(Direction::Left);
    }break;

    case Qt::Key_Right:
    {
        if (pl.getCurrent_position().x() + pl.getСollider_size() + pl.getMovement_speed() <= this->width())
            pl.movePlayer(Direction::Right);
    }break;

    case Qt::Key_Space:
    {
        auto bullet = baseField.player.takeShot();
        baseField.bullets_on_field.push_back(std::move(bullet));
    }break;

    default: {}
    }
}


