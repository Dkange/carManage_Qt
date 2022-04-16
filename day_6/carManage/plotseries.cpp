#include "plotseries.h"

plotSeries::plotSeries()
{

}

QChart *plotSeries::plotBar(QBarSeries *seriesB,QStringList &categories)//用于绘制柱状图
{

    //    set->append(1);

    QChart *chartB = new QChart();
    chartB->addSeries(seriesB);
    chartB->setTitle("各品牌库存量");
    chartB->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    qDebug()<<categories<<endl;
    chartB->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chartB->setAxisX(axis, seriesB);//设置坐标轴

    chartB->legend()->setVisible(true); //设置图例为显示状态
    chartB->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部

    return chartB;
}

QChart *plotSeries::plotPie(QPieSeries *seriesP)//用于绘制饼状图
{

    if(seriesP->slices().size() > 0)
    {
        seriesP->slices().clear();
        seriesP->setHoleSize(0.35);
        seriesP->setLabelsVisible();

        //        qDebug() << seriesP->slices().size();
        QPieSlice *slice_red =seriesP->slices().at(0);

        QPieSlice *slice_green =seriesP->slices().at(1);

        slice_red->setColor(QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%51+50));

        slice_green->setColor(QColor(qrand()%255,qrand()%255,qrand()%255,qrand()%51+50));
    }

    QChart *chartP = new QChart();

    chartP->addSeries(seriesP);

    chartP->setTitle("销量与库存");

    chartP->legend()->hide();

    chartP->setAnimationOptions(QChart::SeriesAnimations);

    return chartP;
}
