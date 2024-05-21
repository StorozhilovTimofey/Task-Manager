#include "Model.h"


IModelData::Ptr Model::create()
{
    return std::make_shared<ModelData>();
}