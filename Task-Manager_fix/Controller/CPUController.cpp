#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include "CPUController.h"
#include "ICPUController.h"


ControllerCPU::ControllerCPU(IViewCPU::IVptr view, IModelCPU::IMptr model)
        : view(std::move(view)), model(std::move(model))
{
}


void ControllerCPU::Launch()
{
    std::vector<double> data = this->model->getParametres();

    this->view->ShowCpuParametres(data);
}
