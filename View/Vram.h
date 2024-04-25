#pragma once

#include <QString>
#include <QWidget>

#include "IVram.h"

class ViewRAM : public IViewRAM
{
public:
    ViewRAM();
    void ShowRAMParams(const std::vector<std::string>& RAMParams,
                       const std::vector<std::string>& params) override;
    ~ViewRAM();
private:
    QString VectorToQString(const std::vector<std::string> vector);
    QWidget *ramWindow;
};
