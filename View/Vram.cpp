#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <string>
#include <vector>

#include "Vram.h"

ViewRAM::ViewRAM()
{
    ramWindow = new QWidget;
    ramWindow->setWindowTitle("Random Access Memory");
    ramWindow->show();
}

void ViewRAM::ShowRAMParams(const std::vector<std::string> &RAMParams,
                            const std::vector<std::string>& params)
{
    QVBoxLayout* layout = new QVBoxLayout();
    QString vector_1, vector_2;

    for (const std::string& elem : RAMParams)
    {
        vector_1 += QString::fromStdString(elem) + '\n';
    }
    QLabel* label_1 = new QLabel(vector_1);
    layout->addWidget(label_1);

    for (const std::string& elem : params)
    {
        vector_2 += QString::fromStdString(elem) + '\n';
    }
    QLabel* label_2 = new QLabel(vector_2);
    layout->addWidget(label_2);

    ramWindow->setLayout(layout);
}

ViewRAM::~ViewRAM()
{
    delete ramWindow;
}
