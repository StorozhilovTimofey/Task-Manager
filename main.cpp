#include <QApplication>

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    auto modelRAM = createModelRAM(); // Указатель на модель
    auto viewRAM = createViewRAM(); // Указатель на вид
    auto controllerRAM = createControllerRAM(viewRAM, modelRAM); // Указатель на контроллер, с принятием других указателей

    controllerRAM->Launch(); // Запуск общих параметров оперативной памяти

    auto modelCPU = createModelCPU();
    auto viewCPU = createViewCPU();
    auto controllerCPU = createControllerCPU(viewCPU, modelCPU);

    controllerCPU->Launch();

    return app.exec();
}
