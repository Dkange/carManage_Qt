#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCharts>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectDB();//连接数据库
    void initData();//初始化数据

private slots:
    void on_actionCar_triggered();

    void on_actionCalc_triggered();

    void on_comboBoxFactory_currentIndexChanged(const QString &selectFactory);

    void on_comboBoxBrand_currentIndexChanged(const QString &selectBrand);

    void on_spinBoxCount_valueChanged(int num);

    void on_ButtonCancel_clicked();

    void on_ButtonSure_clicked();

    void on_comboBoxFactory_1_currentIndexChanged(const QString &arg1);

    void on_comboBoxBrand_1_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
