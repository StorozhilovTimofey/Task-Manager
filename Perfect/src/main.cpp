#include "ControllerRAM.h"
#include "GeneralRAMParams.h"
#include "IGeneralRAMParams.h"

int main(void)
{
    auto model = std::make_shared<ModelGRAM>(); // Указатель на модель
    auto view = std::make_shared<ViewGRAM>(); // Указатель на вид
    auto controller = create(view, model); // Указатель на контроллер, с принятием других указателей

    controller->Launch(); // Запуск проекта

    return 0;
}