#ifndef CMYLINECHART_H
#define CMYLINECHART_H

#include <QObject>
#include "CMyChart.h"

class CMyLineChart : public CMyChart
{
    Q_OBJECT
public:
    explicit CMyLineChart(const CMyChart::EType& type, QChartView* pView, QObject *parent = nullptr);
    ~CMyLineChart();

public:
    virtual void ClearGraphical();
    virtual void SetAxisXRange(const qreal& qMin = 0, const qreal& qMax = 10, const int& nTickCount = 5);
    virtual void SetAxisYRange(const qreal& qMin = 0, const qreal& qMax = 10, const int& nTickCount = 5);
    virtual void SetAxisXTitle(const QString& qsAxisXTitle);
    virtual void SetAxisYTitle(const QString& qsAxisYTitle);
    virtual void SetDateTimeAxisX(const QDateTime& dtStart,
                                 const QDateTime& dtEnd,
                                 const QString& qsFormat = "yyyy-MM-dd",
                                 const int& nTickCount = 5);

    virtual void AppendSeries(const QString& name, QMap<qreal, qreal> mapVal);
    virtual void AppendSeries(const QString& name, QMap<QDateTime, qreal> mapVal);

private:
    bool                    m_bIsDateTime;
    QValueAxis*             m_pLineAxisX;
    QValueAxis*             m_pLineAxisY;
    QDateTimeAxis*          m_pAxisDateTime;
    QVector<QLineSeries*>   m_vecLineSeries;
};

#endif // CMYLINECHART_H

