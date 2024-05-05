#include <QApplication>
#include <iostream>

#include "Controller.h"
#include "mainwindow.h"
#include "ControllerAll.h"
#include "ModelAll.h"
#include "ViewAll.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    ViewAll viewAll;
    ModelAll modelAll;
    ControllerAll controllerAll(viewAll, modelAll);

    MainWindow window(controllerAll);
    window.show();

    return app.exec();
}
