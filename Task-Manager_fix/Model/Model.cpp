#include "Model.h"

IModelRAM::IMptr createModelRAM()
{
    return std::make_shared<ModelRAM>();
}

IModelCPU::IMptr createModelCPU()
{
    return std::make_shared<ModelCPU>();
}
