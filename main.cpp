#include <QApplication>

#include "View/MainWindow.h"

#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    MainWindow window;

    std::shared_ptr<IModelData> model = Model::create();
    std::shared_ptr<IViewData> view = View::create();
    std::shared_ptr<IControllerData> controller = Controller::create(view, model);

    controller->PrintRAM();
    controller->PrintCPU();

    window.show();

    return app.exec();
}
