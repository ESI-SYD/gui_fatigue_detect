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
