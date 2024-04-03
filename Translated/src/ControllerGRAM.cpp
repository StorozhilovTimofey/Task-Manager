#include <string>
#include <vector>

#include "ControllerGRAM.h"

ControllerGRAM::ControllerGRAM(IViewGRAM::IVptr view, IModelGRAM::IMptr model) :
    view(view), model(model)
{
}

void ControllerGRAM::Launch()
{
    std::vector<std::string> result = model->GRAMparams(path, needs);
    view->ShowGeneralParams(result);
}