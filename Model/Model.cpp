#include "Model.h"

IModelRAM::IMptr createModel()
{
    return std::make_shared<ModelRAM>();
}
