#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <string>
#include <vector>

#include "Vram.h"

ViewRAM::ViewRAM(QWidget *parent) : QWidget(parent)
{
    label = new QLabel("RAM Params: ", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);

    setLayout(layout);
}

void ViewRAM::ShowRAMParams(const std::vector<std::string> &RAMParams,
                            const std::vector<std::string>& params)
{
    QString text;
    for (const auto &param : RAMParams)
    {
        text.append(QString::fromStdString(param) + "\n");
    }
    for (const auto &param : params)
    {
        text.append(QString::fromStdString(param) + "\n");
    }
    label->setText(text);
}

ViewRAM::~ViewRAM()
{
}
