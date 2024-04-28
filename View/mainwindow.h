#pragma once

#include <QtWidgets>

#include "Vram.h"
#include "CPUView.h"

class MainWindow : public QWidget
{
public:
    MainWindow(QWidget *parent = 0);
public slots:
    void SwitchToRAMPage();
    void SwitchToCPUPage();
private:
    QStackedWidget *stackedWidget;
    QPushButton *ramButton;
    QPushButton *cpuButton;
    ViewRAM *ramPage;
    ViewCPU *cpuPage;
};
