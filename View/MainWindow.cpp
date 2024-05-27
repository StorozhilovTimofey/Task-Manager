#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("System Information");

    stackedWidget = new QStackedWidget(this);

    ramLabel = new QLabel("RAM Page");
    ramLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *ramLayout = new QVBoxLayout;
    ramLayout->addWidget(ramLabel);
    ramPage = new QWidget;
    ramPage->setLayout(ramLayout);
    stackedWidget->addWidget(ramPage);

    cpuLabel = new QLabel("CPU Page");
    cpuLabel->setAlignment(Qt::AlignCenter);
    QVBoxLayout *cpuLayout = new QVBoxLayout;
    cpuLayout->addWidget(cpuLabel);
    cpuPage = new QWidget;
    cpuPage->setLayout(cpuLayout);
    stackedWidget->addWidget(cpuPage);

    switchButton = new QPushButton("Switch Page");
    connect(switchButton, &QPushButton::clicked, this, &MainWindow::changePage);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(stackedWidget);
    mainLayout->addWidget(switchButton);

    centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
}

void MainWindow::changePage()
{
    int nextPage = (stackedWidget->currentIndex() + 1) % stackedWidget->count();
    stackedWidget->setCurrentIndex(nextPage);
}
