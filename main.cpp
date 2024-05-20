#include "Model.h"
#include "View.h"
#include "Controller.h"

int main(int argc, char** argv)
{
    std::shared_ptr<IModelRAM> modelRAM = createModelRAM(); // Указатель на модь
    std::shared_ptr<IViewRAM> viewRAM = createViewRAM(); // Указатель на вид
    std::shared_ptr<IControllerRAM> controllerRAM = createControllerRAM(viewRAM, modelRAM); // Указатель на контроллер, с принятием других указателей

    controllerRAM->Launch1(); // Запуск общих параметров оперативной памяти
    controllerRAM->Launch2();

    return 0;
}