#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Views/dashboard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), activeMenuWidget(nullptr)
{
    ChangeRootWidget(new DashBoard(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ChangeRootWidget(QWidget *widget)
{
    if (activeMenuWidget)
    {
        delete activeMenuWidget;
    }
    activeMenuWidget = widget;
    setCentralWidget(widget);
}

