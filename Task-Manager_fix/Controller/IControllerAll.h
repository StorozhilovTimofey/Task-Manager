#pragma once

#include "ICram.h"
#include "ICPUController.h"
#include "IViewAll.h"
#include "IModelAll.h"


class IControllerAll
{
public:
    virtual std::shared_ptr<IControllerCPU> getCpu(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model) = 0;
    virtual std::shared_ptr<IControllerRAM> getRam(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model) = 0;

    using ICptr = std::shared_ptr<IControllerAll>;
    ~IControllerAll() = default;
};
