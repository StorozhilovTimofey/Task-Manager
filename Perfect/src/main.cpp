#include "ControllerRAM.h"
#include "GeneralRAMParams.h"
#include "IGeneralRAMParams.h"

int main(void)
{
    auto model = std::make_shared<ModelGRAM>();
    auto view = std::make_shared<ViewGRAM>();
    auto controller = create(view, model);

    controller->Launch();

    return 0;
}