#include "mainwindow.h"
#include <vector>
#include <iostream>

MainWindow::MainWindow(ControllerAll controllerAll, QWidget *parent) : QWidget(parent)
{
    controllerAll = controllerAll;

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

    resize(700, 400);

    ramButton->move(550, 50); // Переместить кнопку RAM в позицию (550, 50)
    cpuButton->move(250, 150); // Переместить кнопку CPU в позицию (250, 150)

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
