#include "cam.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    cam w;

    // 使用QGraphicsView显示摄像头画面
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsProxyWidget* proxywidget = scene->addWidget(&w);
    proxywidget->setRotation(270);

    QGraphicsView* view = new QGraphicsView(scene);
    view->setWindowFlags(Qt::FramelessWindowHint);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();
//    view->show();
    //    view->rotate(90);

//    w.show();
    return a.exec();
}
