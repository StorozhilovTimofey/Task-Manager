#include "ControllerAll.h"
#include "IModelAll.h"
#include "IViewAll.h"


std::shared_ptr<IControllerCPU> ControllerAll::getCpu(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model)
{
    return createControllerCPU(view->getCpu(), model->getCpu());
}


std::shared_ptr<IControllerRAM> ControllerAll::getRam(std::shared_ptr<IViewAll> view, std::shared_ptr<IModelAll> model)
{
    return createControllerRAM(view->getRam(), model->getRam());
}