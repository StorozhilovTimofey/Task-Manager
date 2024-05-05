#pragma once

#include <QtWidgets>

#include "Vram.h"
#include "CPUView.h"
#include "ControllerAll.h"

class MainWindow : public QWidget
{
public:
    explicit MainWindow(ControllerAll controllerAll, QWidget *parent = 0);
public slots:
    void SwitchToRAMPage();
    void SwitchToCPUPage();
private:
    QStackedWidget *stackedWidget;
    QPushButton *ramButton;
    QPushButton *cpuButton;
    ViewRAM *ramPage;
    ViewCPU *cpuPage;
    ControllerAll *controllerAll;
};
