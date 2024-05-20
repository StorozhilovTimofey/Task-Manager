#include "Model.h"

IModelRAM::IMptr createModelRAM()
{
    return std::make_shared<ModelRAM>();
}