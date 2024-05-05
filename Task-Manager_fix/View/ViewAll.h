#pragma once

#include <memory>
#include <vector>

#include "View.h"
#include "Vram.h"
#include "CPUView.h"


class ViewAll
{
public:
    std::shared_ptr<IViewCPU> Ptr_cpu;
    std::shared_ptr<IViewRAM> Ptr_ram;

    ViewAll()
    {
        Ptr_cpu = createViewCPU();
        Ptr_ram = createViewRAM();
    }
};