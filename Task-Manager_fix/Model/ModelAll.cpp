#include "ModelAll.h"
#include "IModelAll.h"


std::shared_ptr<IModelCPU> ModelAll::getCpu()
{
    return createModelCPU();
}

std::shared_ptr<IModelRAM> ModelAll::getRam()
{
    return createModelRAM();
}