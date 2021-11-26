#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Views/dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), activeMenuWidget(nullptr)
{
    changeRootWidget(new DashBoard(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeRootWidget(QWidget *widget)
{
    if (activeMenuWidget) activeMenuWidget->deleteLater();
    activeMenuWidget = widget;
    setCentralWidget(widget);
}

