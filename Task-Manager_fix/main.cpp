#include "mainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);


    std::shared_ptr<IViewAll> a = createVAll();
    std::shared_ptr<IViewCPU> b = a->getCpu();
    std::shared_ptr<IViewRAM> c = a->getRam();

    std::shared_ptr<IModelAll> d = createMAll();
    std::shared_ptr<IModelCPU> e = d->getCpu();
    std::shared_ptr<IModelRAM> f = d->getRam();

    std::shared_ptr<IControllerAll> g = createCAll();
    std::shared_ptr<IControllerCPU> h = g->getCpu(a, d);
    std::shared_ptr<IControllerRAM> l = g->getRam(a, d);

    MainWindow window;
    window.show();
    

    return app.exec();
}
