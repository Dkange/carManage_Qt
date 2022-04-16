#include <QtWidgets>

#include <QtCharts>



QT_CHARTS_USE_NAMESPACE



int main(intargc, char *argv[])

{

   QApplication a(argc, argv);



    QPieSeries *series = new QPieSeries();

   series->setHoleSize(0.35);

    series->append("Protein 4.2%", 4.2);

    series->append("Carbs 56.4%", 56.4);

    series->append("Other 23.8%", 23.8);



    QChartView *chartView = new QChartView();

   chartView->setRenderHint(QPainter::Antialiasing);

   chartView->chart()->setTitle("DonutChart Example");

   chartView->chart()->addSeries(series);

   chartView->chart()->legend()->setAlignment(Qt::AlignBottom);

    chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);

   chartView->chart()->legend()->setFont(QFont("Arial",7));



    QMainWindow window;

   window.setCentralWidget(chartView);

    window.resize(400, 300);

    window.show();



    returna.exec();

}
