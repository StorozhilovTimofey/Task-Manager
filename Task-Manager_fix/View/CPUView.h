#pragma once

#include <QtWidgets>
#include <vector>

#include "ICPUView.h"


class ViewCPU : public IViewCPU, public QWidget
{
public:
    ViewCPU(QWidget *parent = 0);
public slots:
    void ShowCpuParametres(std::vector<double> input) override; // Тут она должна вывести в консоль параметры
private:
    QLabel *label;
};
