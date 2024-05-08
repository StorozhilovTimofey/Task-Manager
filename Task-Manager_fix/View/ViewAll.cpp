#include "ViewAll.h"
#include "IViewAll.h"


std::shared_ptr<IViewCPU> ViewAll1::getCpu()
{
    auto viewCPU = createViewCPU();
    return viewCPU;
}

std::shared_ptr<IViewRAM> ViewAll1::getRam()
{
    auto viewRAM = createViewRAM();
    return viewRAM;
}
