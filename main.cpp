#include "Model.h"
#include "View.h"
#include "Controller.h"


int main(int argc, char** argv)
{
    std::shared_ptr<IModelData> model = Model::create();
    std::shared_ptr<IViewData> view = View::create();
    std::shared_ptr<IControllerData> controller = Controller::create(view, model);

    controller->PrintRAM();
    controller->PrintCPU();

    return 0;
}