#pragma once

#include "IVram.h"


class ViewRAM : public IViewRAM, public QWidget
{
public:
    ViewRAM(QWidget *parent = nullptr);

public slots:
    void ShowRAMParams(const std::vector<std::string>& RAMParams,
                       const std::vector<std::string>& params) override;
    ~ViewRAM() = default;

private:
    QLabel *label;
};
