#include "Model.h"
#include "View.h"
#include "Controller.h"

int main(int argc, char** argv)
{
    std::shared_ptr<IModelData> model = Model::create(); // Указатель на модь
    std::shared_ptr<IViewData> view = View::create(); // Указатель на вид
    std::shared_ptr<IControllerData> controller = Controller::create(view, model); // Указатель на контроллер, с принятием других указателей

    controller->PrintRAM(); // Запуск общих параметров оперативной памяти
    controller->PrintCPU();

    return 0;
}