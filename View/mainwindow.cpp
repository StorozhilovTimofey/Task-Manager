#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    stackedWidget = new QStackedWidget(this);

    ramPage = new ViewRAM(this);
    cpuPage = new ViewCPU(this);

    stackedWidget->addWidget(ramPage);
    stackedWidget->addWidget(cpuPage);

    ramButton = new QPushButton("RAM Page", this);
    cpuButton = new QPushButton("CPU Page", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(ramButton);
    buttonLayout->addWidget(cpuButton);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(stackedWidget);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    connect(ramButton, &QPushButton::clicked, this, &MainWindow::SwitchToRAMPage);
    connect(cpuButton, &QPushButton::clicked, this, &MainWindow::SwitchToCPUPage);
}

void MainWindow::SwitchToRAMPage()
{
    stackedWidget->setCurrentWidget(ramPage);
}

void MainWindow::SwitchToCPUPage()
{
    stackedWidget->setCurrentWidget(cpuPage);
}
