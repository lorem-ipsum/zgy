#ifndef TQT_H_
#define TQT_H_

#include <QtGui>
#include <QtCore>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>


class Thread : public QThread
{
    Q_OBJECT
private:
    int number;
protected:
    void run();
public:
    Thread(QObject *parent=0);
    ~Thread();
signals:
    void UpdateSignal(int num);
public slots:
    void ResetSlot();
};

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel *label;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    Thread *myThread;
    int number;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
signals:
    void ResetSignal();
public slots:
    void ClearSlot();
    void StartSlot();
    void StopSlot();
    void UpdateSlot(int num);
};

#endif
