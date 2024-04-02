#include "IControllerGeneralRAM.h"
#include "IModelGeneralRAM.h"
#include "IViewGeneralRAM.h"
#include "ModelGeneralRAM.h"
#include "ViewGeneralRAM.h"
#include "Controller.h"

int main(void)
{
    auto model = std::make_shared<ModelGeneralRAM>();
    IViewGeneralRAM* view = new ViewGeneralRAM();
    auto controller = create(model, view);

    controller->Launch();

    delete view;

    return 0;
}