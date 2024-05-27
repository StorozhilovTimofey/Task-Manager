#include "MainWindow.h"

MainWindow::MainWindow(IModelData::Ptr model) : model(model)
{

    stringsVector2 = model->getRamGeneral();
    stringsVector1 = model->getRamSpecific();

    numbersVector = model->getCpuParametres();
}


void MainWindow::display()
{
   QVBoxLayout *layout = new QVBoxLayout();

   QLabel *ramClaim = new QLabel("RAM: ");
   layout->addWidget(ramClaim);

   for (const auto &str : stringsVector1)
   {
       QLabel *strLabel = new QLabel(QString::fromStdString(str));
       layout->addWidget(strLabel);
   }

   for (const auto &str : stringsVector2)
   {
       QLabel *strLabel = new QLabel(QString::fromStdString(str));
       layout->addWidget(strLabel);
   }

   QLabel *numbersLabel = new QLabel("CPU: ");
   layout->addWidget(numbersLabel);


   QLabel *numLabel1 = new QLabel("Temperature: " + QString::number(numbersVector[0]) + "℃");
   layout->addWidget(numLabel1);

   QLabel *numLabel2 = new QLabel("Frequency: " + QString::number(numbersVector[1]) + "Hz");
   layout->addWidget(numLabel2);

   setLayout(layout);
   show();
}
