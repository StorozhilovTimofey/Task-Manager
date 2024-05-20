#include "Model.h"

IModelData::Ptr createModel()
{
    return std::make_shared<ModelData>();
}