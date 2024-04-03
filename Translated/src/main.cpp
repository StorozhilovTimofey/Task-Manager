#include "IControllerGRAM.h"
#include "IModelGRAM.h"
#include "IViewGRAM.h"
#include "ModelGRAM.h"
#include "ViewGRAM.h"
#include "Controller.h"

int main(void)
{
    auto model = std::make_shared<ModelGRAM>();
    auto view = std::make_shared<ViewGRAM>();
    auto controller = create(view, model);

    controller->Launch();

    return 0;
}