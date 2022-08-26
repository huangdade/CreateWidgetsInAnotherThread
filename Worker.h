#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QWidget>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    void createWidgets();

signals:
    void resultReady(QWidget* widget);
};

#endif // WORKER_H
