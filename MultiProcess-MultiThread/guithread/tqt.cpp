//tqt.cpp
#include "tqt.h"
#include <assert.h>
#include <windows.h>

Thread::Thread(QObject *parent)
{
    number = 0;
}

Thread::~Thread()
{

}

void Thread::run()
{
    while(1)
    {
        emit UpdateSignal(number);
        number++;
        sleep(1);
    }
}

void Thread::ResetSlot()
{
    number = 0;
    emit UpdateSignal(number);
}

Widget::Widget(QWidget *parent)
{
    startButton = new QPushButton("start");
    stopButton = new QPushButton("stop");
    resetButton = new QPushButton("reset");
    label = new QLabel("empty");
    myThread = new Thread;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(startButton);
    layout->addWidget(stopButton);
    layout->addWidget(resetButton);
    setLayout(layout);

    connect(stopButton, SIGNAL(clicked()),
        this, SLOT(StopSlot()));
    connect(startButton, SIGNAL(clicked()),
        this, SLOT(StartSlot()));
    connect(resetButton, SIGNAL(clicked()),
        this, SLOT(ClearSlot()));
    connect(myThread, SIGNAL(UpdateSignal(int)),
        this, SLOT(UpdateSlot(int)));
    connect(this, SIGNAL(ResetSignal()),
        myThread, SLOT(ResetSlot()));


    setWindowTitle("Thread Test");
    resize(200, 200);
    myThread->start();

}

Widget::~Widget()
{

}

void Widget::StartSlot()
{
    myThread->start();
}

void Widget::StopSlot()
{
    myThread->terminate();
}

void Widget::UpdateSlot(int num)
{
    label->setText(QString::number(num));
}

void Widget::ClearSlot()
{
    emit ResetSignal();
}
