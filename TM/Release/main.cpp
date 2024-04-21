#include <QApplication>

#include "ControllerRAM.h"
#include "View/VGeneralRAM.h"
#include "Model/MGeneralRAM.h"

int main(int argc, char *argv[])
{
    auto modelGeneralRAM = std::make_shared<ModelGRAM>(); // Указатель на модель
    auto viewGeneralRAM = std::make_shared<ViewGRAM>(); // Указатель на вид
    auto controllerGeneralRAM = create(viewGeneralRAM, modelGeneralRAM); // Указатель на контроллер, с принятием других указателей

    controllerGeneralRAM->Launch(); // Запуск общих параметров оперативной памяти

    return 0;
}
