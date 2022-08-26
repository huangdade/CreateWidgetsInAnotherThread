#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "Worker.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    Worker* worker = new Worker();

    // 调用 moveToThread 将该任务交给 workThread
    worker->moveToThread(&workerThread);

    connect(worker, SIGNAL(resultReady(QWidget*)), this, SLOT(handleResults(QWidget*)));

    workerThread.start();

    qDebug() << "worker";
    worker->createWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
    workerThread.quit();
    workerThread.wait();
}

void MainWindow::handleResults(QWidget *widget)
{
    qDebug() << "ready";
//    widget->moveToThread(QThread::currentThread());
    widget->setParent(ui->centralwidget);
    widget->move(100, 100);
    widget->resize(450, 30);
}

