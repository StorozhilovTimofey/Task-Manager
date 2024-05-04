#include <QApplication>

#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    auto modelRAM = createModelRAM(); // Указатель на модель
    auto viewRAM = createViewRAM(); // Указатель на вид
    std::shared_ptr<IControllerRAM> controllerRAM = createControllerRAM(viewRAM, modelRAM); // Указатель на контроллер, с принятием других указателей

    controllerRAM->Launch(); // Запуск общих параметров оперативной памяти

    auto modelCPU = createModelCPU();
    auto viewCPU = createViewCPU();
    std::shared_ptr<IControllerCPU> controllerCPU = createControllerCPU(viewCPU, modelCPU);

    controllerCPU->Launch();

    MainWindow window;
    window.show();

    return app.exec();
}
