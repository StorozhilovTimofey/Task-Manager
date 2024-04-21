#include "CGeneralRAM.h"

ControllerGRAM::ControllerGRAM(IViewGRAM::IGRAMVptr view, IModelGRAM::IGRAMMptr model) :
    view(view), model(model)
{
}

void ControllerGRAM::Launch()
{
    std::vector<std::string> result = model->GRAMparams(path, needs);
    view->ShowGeneralParams(result);
}
