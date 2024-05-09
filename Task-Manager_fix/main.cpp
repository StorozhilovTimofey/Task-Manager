#include <QApplication>
#include <iostream>

#include "Controller.h"
#include "mainwindow.h"
#include "ControllerAll.h"
#include "ModelAll.h"
#include "ViewAll.h"
#include "IViewAll.h"
#include "IModelAll.h"
#include "IControllerAll.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);


    std::shared_ptr<IViewAll> a = createVAll();
    std::shared_ptr<IViewCPU> b = a->getCpu();
    auto c = a->getRam();

    std::shared_ptr<IModelAll> d = createMAll();
    std::shared_ptr<IModelCPU> e = d->getCpu();
    auto f = d->getRam();

    std::shared_ptr<IControllerAll> g = createCAll();
    std::shared_ptr<IControllerCPU> h = g->getCpu(a, d);
    auto l = g->getRam(a, d);

    ViewAll viewAll;
    ModelAll modelAll;
    ControllerAll controllerAll(viewAll, modelAll);

    MainWindow window(controllerAll);
    window.show();

    return app.exec();
}
