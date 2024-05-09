#include "ControllerAll.h"
#include "IViewAll.h"
#include "IModelAll.h"

std::shared_ptr<IControllerCPU> ControllerAll1::getCpu(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model)
{
    return createControllerCPU(view->getCpu(), model->getCpu());
}

std::shared_ptr<IControllerRAM> ControllerAll1::getRam(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model)
{
    return createControllerRAM(view->getRam(), model->getRam());
}