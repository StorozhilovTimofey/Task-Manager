#include "ControllerData.h"

ControllerData::ControllerData(IViewData::Ptr view, IModelData::Ptr model) :
    view(view), model(model)
{
}

void ControllerData::PrintRAM()
{
    model->CreateFile();
    std::vector<std::string> ramG = model->getRamGeneral(path, needs);
    std::vector<std::string> ramS = model->getRamSpecific();
    view->ShowRamParametres(ramG, ramS);
    model->DeleteFile();
}

void ControllerData::PrintCPU()
{
    std::vector<double> c = this->model->getParametres();

    this->view->ShowCpuParametres(c);
}