#ifndef CMYBARCHART_H
#define CMYBARCHART_H

#include <QObject>
#include "CMyChart.h"

class CMyBarChart : public CMyChart
{
    Q_OBJECT
public:
    explicit CMyBarChart(const CMyChart::EType& type, QChartView* pView, QObject *parent = nullptr);
    virtual ~CMyBarChart();

public:
    virtual void ClearGraphical();
    virtual void SetAxisXTitle(const QString& qsAxisXTitle);
    virtual void SetAxisYTitle(const QString& qsAxisYTitle);
    virtual void SetAxisYRange(const qreal& qMin = 0, const qreal& qMax = 10, const int& nTickCount = 5);
    virtual void AppendSeries(const QString& qsAxisXName,
                              QMap<QString, qreal>& mapData,
                              const QVector<EColor>& vecColors = m_vecDefCol);

private:
    QValueAxis*             m_pBarAxisY;
    QBarSeries*             m_pBarSeries;
    QVector<QBarSet*>       m_vecBarSet;
    QBarCategoryAxis*       m_pBarAxisX;
};

#endif // CMYBARCHART_H

