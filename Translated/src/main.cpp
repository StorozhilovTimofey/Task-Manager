#include "IControllerGeneralRAM.h"
#include "IModelGeneralRAM.h"
#include "IViewGeneralRAM.h"
#include "ControllerGeneralRAM.h"
#include "ModelGeneralRAM.h"
#include "ViewGeneralRAM.h"

int main(void)
{
    IModelGeneralRAM* model = new ModelGeneralRAM();
    IViewGeneralRAM* view = new ViewGeneralRAM();
    IControllerGeneralRAM* controller = new ControllerGeneralRAM(model, view);

    controller->Launch();

    delete model; delete view; delete controller;

    return 0;
}