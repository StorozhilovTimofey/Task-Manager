#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
public:
   MainWindow(QWidget *parent = nullptr);
public slots:
   void changePage();
private:
   QStackedWidget *stackedWidget;
   QLabel *ramLabel;
   QLabel *cpuLabel;
   QPushButton *switchButton;
   QWidget *ramPage;
   QWidget *cpuPage;
   QWidget *centralWidget;
};
