/*
* @File_name:  main.cpp
* @Description: gui_fatigue_detect
* @Date:   2021-11-21 14:40:32
* @Author: ESI_SYD@Tongji
*/


#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.setFixedHeight(600);
    w.setFixedWidth(700);
    w.show();
    return a.exec();
}
