#include <string>
#include <vector>

#include "ControllerGeneralRAM.h"

ControllerGeneralRAM::ControllerGeneralRAM(IModelGeneralRAM::Ptr model,
                                           IViewGeneralRAM* view) :
    model(model), view(view)
{
}

void ControllerGeneralRAM::Launch()
{
    std::vector<std::string> result = model->GeneralRAMParams(path, needs);
    view->ShowGeneralRAMParams(result);
}