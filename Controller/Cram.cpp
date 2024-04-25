#include "Cram.h"

ControllerRAM::ControllerRAM(IViewRAM::IVptr view, IModelRAM::IMptr model) :
    view(view), model(model)
{
}

void ControllerRAM::Launch()
{
    model->CreateFile();
    std::vector<std::string> result_1 = model->GRAMparams(path, needs);
    std::vector<std::string> result_2 = model->AllData();
    view->ShowRAMParams(result_1, result_2);
    model->DeleteFile();
}
