#include "ViewAll.h"
#include "IViewAll.h"


std::shared_ptr<IViewCPU> ViewAll::getCpu()
{
    auto viewCPU = createViewCPU();
    return viewCPU;
}

std::shared_ptr<IViewRAM> ViewAll::getRam()
{
    auto viewRAM = createViewRAM();
    return viewRAM;
}
