#include "Mram.h"
#include "Vram.h"
#include "Cram.h"
#include "Controller.h"
#include "CPUView.h"
#include "CPUModel.h"
#include "CPUController.h"

int main(int argc, char** argv)
{
    std::shared_ptr<IModelRAM> modelRAM = std::make_shared<ModelRAM>(); // Указатель на модель
    std::shared_ptr<IViewRAM> viewRAM = std::make_shared<ViewRAM>(); // Указатель на вид
    std::shared_ptr<IControllerRAM> controllerRAM = createControllerRAM(viewRAM, modelRAM); // Указатель на контроллер, с принятием других указателей

    controllerRAM->Launch(); // Запуск общих параметров оперативной памяти

    auto modelCPU = std::make_shared<ModelCPU>();
    auto viewCPU = std::make_shared<ViewCPU>();
    std::shared_ptr<IControllerCPU> controllerCPU = createControllerCPU(viewCPU, modelCPU);

    controllerCPU->Launch();

    return 0;
}