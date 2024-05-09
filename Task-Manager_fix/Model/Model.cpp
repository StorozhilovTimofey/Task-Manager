#include "Model.h"
#include "ModelAll.h"

IModelRAM::IMptr createModelRAM()
{
    return std::make_shared<ModelRAM>();
}

IModelCPU::IMptr createModelCPU()
{
    return std::make_shared<ModelCPU>();
}

IModelAll::IMptr createMAll()
{
    return std::make_shared<ModelAll1>();
}
