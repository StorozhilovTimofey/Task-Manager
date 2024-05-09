#include "ViewAll.h"


std::shared_ptr<IViewCPU> ViewAll::getCpu()
{
    return createViewCPU();
}


std::shared_ptr<IViewRAM> ViewAll::getRam()
{
    return createViewRAM();
}
