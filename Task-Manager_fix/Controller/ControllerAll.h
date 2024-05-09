#pragma once

#include <memory>
#include <vector>

#include "Controller.h"
#include "Cram.h"
#include "CPUController.h"
#include "ModelAll.h"
#include "ViewAll.h"
#include "IControllerAll.h"
#include "IModelAll.h"
#include "IViewAll.h"


class ControllerAll : public IControllerAll
{
public:
    std::shared_ptr<IControllerCPU> getCpu(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model) override;
    std::shared_ptr<IControllerRAM> getRam(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model) override;

    ~ControllerAll() = default;
};