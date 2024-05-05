#pragma once

#include <QString>
#include <QtWidgets>

#include "IVram.h"

class ViewRAM : public IViewRAM, public QWidget
{
public:
    ViewRAM(QWidget *parent = 0);
public slots:
    void ShowRAMParams(const std::vector<std::string>& RAMParams,
                       const std::vector<std::string>& params) override;
    ~ViewRAM();
private:
    QLabel *label;
};
