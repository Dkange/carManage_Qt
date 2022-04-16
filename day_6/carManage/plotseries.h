#ifndef PLOTSERIES_H
#define PLOTSERIES_H
#include <QtCharts>

class plotSeries
{
public:
    plotSeries();

    static QChart * plotBar(QBarSeries *seriesB,QStringList &categories);//用于绘制柱状图

    static QChart * plotPie(QPieSeries *seriesP);//用于绘制饼状图

};

#endif // PLOTSERIES_H
