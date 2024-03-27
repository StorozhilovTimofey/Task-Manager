#include <string>
#include <vector>

#include "ControllerGeneralRAM.h"

void ControllerGeneralRAM::Launch()
{
    std::vector<std::string> result = model->GeneralRAMParams(path, needs);
    view->ShowGeneralRAMParams(result);
}