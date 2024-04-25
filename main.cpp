#include <QApplication>

#include "Controller/Controller.h"
#include "Model/Model.h"
#include "View/View.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    auto modelRAM = createModel(); // Указатель на модель
    auto viewRAM = createView(); // Указатель на вид
    auto controllerRAM = createController(viewRAM, modelRAM); // Указатель на контроллер, с принятием других указателей

    controllerRAM->Launch(); // Запуск общих параметров оперативной памяти

    return app.exec();
}
