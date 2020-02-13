#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QFontDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFontDatabase::addApplicationFont(":/fonts/OpenSans-Regular.ttf");
    MainWindow w;

    QSplashScreen splash(QPixmap(":/images/app_icon.png"));
    splash.show();
    splash.finish(&w);

    w.showMaximized();
    w.showloginDialog();

    return a.exec();
}
