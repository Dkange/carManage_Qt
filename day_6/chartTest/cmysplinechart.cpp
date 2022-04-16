#include "cmysplinechart.h"

CMySplineChart::CMySplineChart(const CMyChart::EType& type, QChartView* pView, QObject *parent)
    : CMyChart(type, pView, parent)
{
    m_bIsDateTime = false;
}

CMySplineChart::~CMySplineChart()
{
    for(QVector<QSplineSeries*>::iterator it = m_vecSplineSeries.begin(); it != m_vecSplineSeries.end(); it++)
        delete *it;
}

void CMySplineChart::ClearGraphical()
{
    for(QVector<QSplineSeries*>::iterator it = m_vecSplineSeries.begin(); it != m_vecSplineSeries.end(); it++)
        delete *it;

    m_vecSplineSeries.clear();
}

void CMySplineChart::SetAxisXRange(const qreal &qMin, const qreal &qMax, const int &nTickCount)
{
    m_pLineAxisX = new QValueAxis;
    m_pLineAxisX->setRange(qMin, qMax);
    m_pLineAxisX->setTickCount(nTickCount);
    m_pChart->addAxis(m_pLineAxisX, Qt::AlignBottom);
}

void CMySplineChart::SetAxisYRange(const qreal &qMin, const qreal &qMax, const int &nTickCount)
{
    m_pLineAxisY = new QValueAxis;
    m_pLineAxisY->setRange(qMin, qMax);
    m_pLineAxisY->setTickCount(nTickCount);
    m_pLineAxisY->setGridLineVisible(false);
    m_pChart->addAxis(m_pLineAxisY, Qt::AlignLeft);
}

void CMySplineChart::SetDateTimeAxisX(const QDateTime &dtStart, const QDateTime &dtEnd, const QString &qsFormat, const int &nTickCount)
{
    m_bIsDateTime = true;
    m_pAxisDateTime = new QDateTimeAxis;
    m_pAxisDateTime->setFormat(qsFormat);
    m_pAxisDateTime->setRange(dtStart, dtEnd);
    m_pAxisDateTime->setTickCount(nTickCount);
    m_pChart->addAxis(m_pAxisDateTime, Qt::AlignBottom);
}

void CMySplineChart::SetAxisXTitle(const QString &qsAxisXTitle)
{
    if(m_bIsDateTime)
        m_pAxisDateTime->setTitleText(qsAxisXTitle);
    else
        m_pLineAxisX->setTitleText(qsAxisXTitle);
}

void CMySplineChart::SetAxisYTitle(const QString &qsAxisYTitle)
{
    m_pLineAxisY->setTitleText(qsAxisYTitle);
}

void CMySplineChart::AppendSeries(const QString &name , QMap<qreal, qreal> mapVal)
{
    QSplineSeries* pSplineSeries = new QSplineSeries;
    pSplineSeries->setName(name);
    pSplineSeries->setPointsVisible(true);
    pSplineSeries->setPointLabelsVisible(true);   //设置显示点位
    m_pChart->addSeries(pSplineSeries);

    for(QMap<qreal, qreal>::iterator it = mapVal.begin(); it != mapVal.end(); it++)
        pSplineSeries->append(it.key(), it.value());

    m_vecSplineSeries.push_back(pSplineSeries);

    pSplineSeries->attachAxis(m_pLineAxisX);
    pSplineSeries->attachAxis(m_pLineAxisY);
}

void CMySplineChart::AppendSeries(const QString &name, QMap<QDateTime, qreal> mapVal)
{
    QSplineSeries* pSplineSeries = new QSplineSeries;
    pSplineSeries->setName(name);
    pSplineSeries->setPointsVisible(true);
    pSplineSeries->setPointLabelsVisible(false);   //设置显示点位
    m_pChart->addSeries(pSplineSeries);


    for(QMap<QDateTime, qreal>::iterator it = mapVal.begin(); it != mapVal.end(); it++)
        pSplineSeries->append(it.key().toMSecsSinceEpoch(), it.value());

    m_vecSplineSeries.push_back(pSplineSeries);
    pSplineSeries->attachAxis(m_pAxisDateTime);
    pSplineSeries->attachAxis(m_pLineAxisY);
}

