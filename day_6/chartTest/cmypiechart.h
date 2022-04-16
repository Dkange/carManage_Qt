#ifndef CMYPIECHART_H
#define CMYPIECHART_H

#include <QObject>
#include "CMyChart.h"

class CMyPieChart : public CMyChart
{
    Q_OBJECT
public:
    explicit CMyPieChart(const CMyChart::EType& type, QChartView* pView, QObject *parent = nullptr);
    virtual ~CMyPieChart();

public:
    virtual void ClearGraphical();
    virtual void AppendSeries(QMap<QString, qreal>& mapData, const QVector<EColor>& vecColors = m_vecDefCol);

private slots:
    //点击扇形槽函数
    void ClickedSector(QPieSlice* pSlice);

private:
    QPieSeries* m_pPieSeries;
};

#endif // CMYPIECHART_H

