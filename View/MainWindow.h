#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
public:
   MainWindow(QWidget *parent = nullptr) : QMainWindow(parent)
   {
       setWindowTitle("System Information");

       // Create the stacked widget to hold the pages
       stackedWidget = new QStackedWidget(this);

       // Create the RAM page
       ramLabel = new QLabel("RAM Page");
       ramLabel->setAlignment(Qt::AlignCenter);
       QVBoxLayout *ramLayout = new QVBoxLayout;
       ramLayout->addWidget(ramLabel);
       ramPage = new QWidget;
       ramPage->setLayout(ramLayout);
       stackedWidget->addWidget(ramPage);

       // Create the CPU page
       cpuLabel = new QLabel("CPU Page");
       cpuLabel->setAlignment(Qt::AlignCenter);
       QVBoxLayout *cpuLayout = new QVBoxLayout;
       cpuLayout->addWidget(cpuLabel);
       cpuPage = new QWidget;
       cpuPage->setLayout(cpuLayout);
       stackedWidget->addWidget(cpuPage);

       // Create the button to switch between pages
       switchButton = new QPushButton("Switch Page");
       connect(switchButton, &QPushButton::clicked, this, &MainWindow::changePage);

       // Set the main layout for the window
       QVBoxLayout *mainLayout = new QVBoxLayout;
       mainLayout->addWidget(stackedWidget);
       mainLayout->addWidget(switchButton);

       // Set the central widget for the main window
       centralWidget = new QWidget;
       centralWidget->setLayout(mainLayout);
       setCentralWidget(centralWidget);
   }

public slots:
   void changePage()
   {
       int nextPage = (stackedWidget->currentIndex() + 1) % stackedWidget->count();
       stackedWidget->setCurrentIndex(nextPage);
   }

private:
   QStackedWidget *stackedWidget;
   QLabel *ramLabel;
   QLabel *cpuLabel;
   QPushButton *switchButton;
   QWidget *ramPage;
   QWidget *cpuPage;
   QWidget *centralWidget;
};
