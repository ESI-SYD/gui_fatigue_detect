/*
* @File_name:  gui_fatigue_detect
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
    w.setWindowTitle("驾驶疲劳检测运行窗口");
    w.show();
    return a.exec();
}
