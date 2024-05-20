#include "ControllerData.h"

ControllerData::ControllerData(IViewData::Ptr view, IModelData::Ptr model) :
    view(view), model(model)
{
}

void ControllerData::Launch1()
{
    model->CreateFile();
    std::vector<std::string> result_1 = model->GRAMparams(path, needs);
    std::vector<std::string> result_2 = model->AllData();
    view->ShowRAMParams(result_1, result_2);
    model->DeleteFile();
}

void ControllerData::Launch2()
{
    std::vector<double> c = this->model->getParametres();

    this->view->ShowCpuParametres(c);
}