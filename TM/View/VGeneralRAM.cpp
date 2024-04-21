#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QString>
#include <string>
#include <vector>

#include "VGeneralRAM.h"

void ViewGRAM::ShowGeneralParams(const std::vector<std::string>& params)
{
    int fargc = 1;
    char* fargv[] = { "TaskManager" };
    QApplication app(fargc, fargv);
    QWidget window;
    window.setWindowTitle("Параметры");
    QVBoxLayout* layout = new QVBoxLayout;

    for (const std::string& elem : params)
    {
        QLabel* label = new QLabel(QString::fromStdString(elem));
        layout->addWidget(label);
    }

    window.setLayout(layout);
    window.show();

    app.exec();
}
