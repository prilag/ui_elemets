#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMap<QString, int> elements;
    elements.insert("E30", 1);
    elements.insert("E36", 2);
    elements.insert("E46", 3);
    p1_settings = new SpinBox(this,0,9," min");
    p1_settings->resize(QSize(50,80));
    p1_settings->move(20,20);

    p2_settings = new SpinBox(this, elements);
    p2_settings->resize(QSize(50,80));
    p2_settings->move(100,20);
}

MainWindow::~MainWindow()
{
    delete ui;
}
