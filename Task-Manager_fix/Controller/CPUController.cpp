#include "CPUController.h"


ControllerCPU::ControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model)
        : view(std::move(view)), model(std::move(model))
{
}


void ControllerCPU::Launch()
{
    std::vector<double> data = this->model->getParametres();

    this->view->ShowCpuParametres(data);
}
