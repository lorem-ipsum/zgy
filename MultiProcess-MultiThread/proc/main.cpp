#include <QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QProcess *pro = new QProcess;


    qDebug() << "-------------running-----------";
    pro->start("C:\\Windows\\System32\\notepad.exe");
    //pro->execute("C:\\Windows\\System32\\notepad.exe");
    //pro->startDetached("C:\\Windows\\System32\\notepad.exe");

    if(pro->waitForStarted(12))
    {
        qDebug() << "dialer.exe starts";

        //等待外部程序结束，如果在给定的时间内关闭外部程序，返回为真，超时返回false
        if(pro->waitForFinished(10000))
            qDebug() << "closed";
        else
            qDebug() << "not closed";
    }
    qDebug() << "------------continue to run-----------";


    return a.exec();
}
