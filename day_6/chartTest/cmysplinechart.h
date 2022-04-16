#ifndef CMYSPLINECHART_H
#define CMYSPLINECHART_H

#include <QObject>
#include "CMyChart.h"

class CMySplineChart : public CMyChart
{
    Q_OBJECT
public:
    explicit CMySplineChart(const CMyChart::EType& type, QChartView* pView, QObject *parent = nullptr);
    ~CMySplineChart();

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

signals:

public slots:

private:
    bool                        m_bIsDateTime;
    QValueAxis*                 m_pLineAxisX;
    QValueAxis*                 m_pLineAxisY;
    QDateTimeAxis*              m_pAxisDateTime;
    QVector<QSplineSeries*>     m_vecSplineSeries;
};

#endif // CMYSPLINECHART_H

