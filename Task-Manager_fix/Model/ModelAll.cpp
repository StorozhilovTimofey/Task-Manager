#include "ModelAll.h"
#include "IModelAll.h"


std::shared_ptr<IModelCPU> ModelAll1::getCpu()
{
    return createModelCPU();
}

std::shared_ptr<IModelRAM> ModelAll1::getRam()
{
    return createModelRAM();
}