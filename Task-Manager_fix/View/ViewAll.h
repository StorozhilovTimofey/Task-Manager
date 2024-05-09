#pragma once

#include <memory>
#include <vector>

#include "View.h"
#include "Vram.h"
#include "CPUView.h"
#include "IViewAll.h"


class ViewAll : public IViewAll
{
public:
    std::shared_ptr<IViewCPU> getCpu() override;
    std::shared_ptr<IViewRAM> getRam() override;

    ~ViewAll() = default;
};











