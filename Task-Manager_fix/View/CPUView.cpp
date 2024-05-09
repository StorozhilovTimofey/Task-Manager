#include <vector>
#include <iostream>

#include "CPUView.h"

ViewCPU::ViewCPU(QWidget *parent) : QWidget(parent)
{
    label = new QLabel("CPU Params:", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    setLayout(layout);
}

void ViewCPU::ShowCpuParametres(std::vector<double> input)
{
    QString text;
    for (const auto &param : input)
    {
        text.append(QString::fromStdString(std::to_string(param)) + "\n");
    }
    label->setText(text);
}