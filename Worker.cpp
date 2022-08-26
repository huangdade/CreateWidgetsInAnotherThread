#include "Worker.h"

#include <QLabel>
#include <QDebug>
#include <QLineEdit>

Worker::Worker(QObject *parent)
    : QObject{parent}
{

}

void Worker::createWidgets()
{
    qDebug() << "label";
    QWidget* widget = new QWidget();

    QLabel* label = new QLabel(widget);
    label->setText("ABCD");
    QLineEdit* edit = new QLineEdit(widget);
    edit->move(100, 0);

    emit resultReady(widget);
}
