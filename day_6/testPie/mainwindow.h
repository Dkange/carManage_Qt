#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCharts>
#include <QMainWindow>
//#include <QtWidgets/QApplication>

//#include <QtWidgets/QMainWindow>

//#include <QtCharts/QChartView>

//#include <QtCharts/QPieSeries>

//#include <QtCharts/QPieSlice>
using namespace QtCharts;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
