#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //p_settings = new SpinBox(this);
    p_settings = new SpinBox(this,0,9," min");
    p_settings->resize(QSize(50,80));
    p_settings->move(20,20);
}

MainWindow::~MainWindow()
{
    delete ui;
}
