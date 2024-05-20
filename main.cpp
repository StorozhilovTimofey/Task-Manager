#include "Model.h"
#include "View.h"
#include "Controller.h"

int main(int argc, char** argv)
{
    std::shared_ptr<IModelData> model = createModel(); // Указатель на модь
    std::shared_ptr<IViewData> view = createView(); // Указатель на вид
    std::shared_ptr<IControllerData> controller = createController(view, model); // Указатель на контроллер, с принятием других указателей

    controller->Launch1(); // Запуск общих параметров оперативной памяти
    controller->Launch2();

    return 0;
}