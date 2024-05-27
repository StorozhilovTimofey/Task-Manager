#pragma once

#include "IControllerData.h"
#include "IModelData.h"
#include "IViewData.h"


class ControllerData : public IControllerData
{
public:
    ControllerData(IViewData::Ptr view, IModelData::Ptr model);
    void PrintRAM() override;
    void PrintCPU() override;
private:
    IViewData::Ptr view;
    IModelData::Ptr model;
};