#include "mainwindow.h"
#include <QApplication>
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;//主界面显示
    /*/a.connect(&w,SIGNAL(sammeterError()),&a,SLOT(quit()));
    //a.connect(&w,SIGNAL(sregulatorError()),&a,SLOT(quit()));
    /**********restart******************/
    //a.connect(&w,SIGNAL(sammeterError()),&a,SLOT(QProcess::start(program,arguments)));
    //a.connect(&w,SIGNAL(sregulatorError()),&a,SLOT(QProcess::start(program,arguments)));/*/
//    if(!w.isError())//初始化成功
//    {
       w.show();
       a.exec();
//    }
//    else
//    {
//       qApp->exit(0);
//       /*************restart this program************/
//       QProcess::startDetached(a.applicationFilePath());
//    }
    return 0;
}
