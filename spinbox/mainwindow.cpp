#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    p_settings = new SpinBox(this);
    p_settings->move(200,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
