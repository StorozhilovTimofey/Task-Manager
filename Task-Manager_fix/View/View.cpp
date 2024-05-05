#include "View.h"
#include "Vram.h"
#include "CPUView.h"

IViewRAM::IVptr createViewRAM()
{
    return std::make_shared<ViewRAM>();
}

IViewCPU::IVptr createViewCPU()
{
    return std::make_shared<ViewCPU>();
}
