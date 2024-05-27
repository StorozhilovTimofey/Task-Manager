#include <QApplication>

#include "Controller.h"
#include "MainWindow.h"
#include "Model.h"
#include "View.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    std::shared_ptr<IModelData> model = Model::create();
    std::shared_ptr<IViewData> view = View::create();
    std::shared_ptr<IControllerData> controller = Controller::create(view, model);

    controller->PrintRAM();
    controller->PrintCPU();

    MainWindow window(model);
    window.display();
    window.show();

    return app.exec();
}
