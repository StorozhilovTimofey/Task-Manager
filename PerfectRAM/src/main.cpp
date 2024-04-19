#include "ControllerRAM.h"
#include "GeneralRAMParams.h"
#include "IGeneralRAMParams.h"
#include "ParticularRAMParams.h"
#include "IParticularRAMParams.h"

int main(void)
{
    auto modelGeneralRAM = std::make_shared<ModelGRAM>(); // Указатель на модель
    auto viewGeneralRAM = std::make_shared<ViewGRAM>(); // Указатель на вид
    auto controllerGeneralRAM = create(viewGeneralRAM, modelGeneralRAM); // Указатель на контроллер, с принятием других указателей

    controllerGeneralRAM->Launch(); // Запуск общих параметров оперативной памяти

    auto modelParticularRAM = std::make_shared<ModelPRAM>();
    auto viewParticularRAM = std::make_shared<ViewPRAM>();
    auto controllerParticularRAM = create(viewParticularRAM, modelParticularRAM);

    controllerParticularRAM->Launch();

    return 0;
}