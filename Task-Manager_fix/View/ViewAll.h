#pragma once

#include "CPUView.h"
#include "IViewAll.h"
#include "View.h"
#include "Vram.h"


class ViewAll : public IViewAll
{
public:
    std::shared_ptr<IViewCPU> getCpu() override;
    std::shared_ptr<IViewRAM> getRam() override;

    ~ViewAll() = default;
};
