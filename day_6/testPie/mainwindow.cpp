#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPieSeries *series = new QPieSeries();

    series->setHoleSize(0.35);

    series->append("Protein 4.2%", 4.2);

    series->append("Carbs 56.4%", 56.4);

    series->append("Other 23.8%", 23.8);

    series->setLabelsVisible();

    QPieSlice *slice_red =series->slices().at(0);

    QPieSlice *slice_green =series->slices().at(1);

    QPieSlice *slice_blue =series->slices().at(2);

    slice_red->setColor(QColor(255,0,0,255));

    slice_green->setColor(QColor(0,255,0,255));

    slice_blue->setColor(QColor(0,0,255,255));

    QChart *chart = new QChart();

    chart->addSeries(series);

    chart->setTitle("PieChart Example");

    chart->legend()->hide();

//    QChartView *chartview = new QChartView(chart);

//    chartview->setRenderHint(QPainter::Antialiasing);

    chart->setAnimationOptions(QChart::SeriesAnimations);

    ui->widget->setChart(chart);


//    QGridLayout *baseLayout = new QGridLayout(); //便于显示，创建网格布局

//    baseLayout->addWidget(chartview, 1, 0);
//    ui->widget_1->setLayout(baseLayout); //显示到QWidget控件
//    ui->widget_2->setLayout(baseLayout);

    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");
    QBarSet *set3 = new QBarSet("Mary");
    QBarSet *set4 = new QBarSet("Samantha");

    *set0 << 1;// Jane 6个月份的值
    *set0 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 19<< 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    QBarSeries *seriesB = new QBarSeries();
    seriesB->append(set0);
    seriesB->append(set1);
    seriesB->append(set2);
    seriesB->append(set3);
    seriesB->append(set4);



    QChart *chartB = new QChart();
    chartB->addSeries(seriesB);
    chartB->setTitle("Simple barchart example");
    chartB->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chartB->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chartB->setAxisX(axis, seriesB);//设置坐标轴

    chartB->legend()->setVisible(true); //设置图例为显示状态
    chartB->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部

    ui->widget_2->setChart(chartB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

