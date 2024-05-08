#include "View.h"
#include "Vram.h"
#include "CPUView.h"
#include "IViewAll.h"
#include "ViewAll.h"

IViewRAM::IVptr createViewRAM()
{
    return std::make_shared<ViewRAM>();
}

IViewCPU::IVptr createViewCPU()
{
    return std::make_shared<ViewCPU>();
}

IViewAll::IVptr createVAll()
{
    return std::make_shared<ViewAll1>();
}
