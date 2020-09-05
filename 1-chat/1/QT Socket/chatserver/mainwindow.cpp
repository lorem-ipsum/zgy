#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initServer()
{
    this->listenSocket =new QTcpServer;
    this->listenSocket->listen(QHostAddress::Any,8888);
    QObject::connect(this->listenSocket,SIGNAL(newConnection()),this,SLOT(acceptConnection()));
}

void MainWindow::acceptConnection()
{
    this->readWriteSocket =this->listenSocket->nextPendingConnection();
    QObject::connect(this->readWriteSocket,SIGNAL(readyRead()),this,SLOT(recvMessage()));

}
void MainWindow::recvMessage()
{
    QString info;
    info += this->readWriteSocket->readAll();
    ui->infoEdit->append(info);
}

void MainWindow::on_sendButton_clicked()
{
    QByteArray *array =new QByteArray;
    array->clear();
    array->append(ui->inputEdit->toPlainText());
    this->readWriteSocket->write(array->data());
    ui->infoEdit->append(ui->inputEdit->toPlainText());
}
