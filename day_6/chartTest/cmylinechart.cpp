#include "cmylinechart.h"

CMyLineChart::CMyLineChart(const CMyChart::EType& type, QChartView* pView, QObject *parent)
    : CMyChart(type, pView, parent)
{
    m_bIsDateTime = false;
}

CMyLineChart::~CMyLineChart()
{
    for(QVector<QLineSeries*>::iterator it = m_vecLineSeries.begin(); it != m_vecLineSeries.end(); it++)
        delete *it;
}

void CMyLineChart::ClearGraphical()
{
    for(QVector<QLineSeries*>::iterator it = m_vecLineSeries.begin(); it != m_vecLineSeries.end(); it++)
        delete *it;

    m_vecLineSeries.clear();
}

void CMyLineChart::SetAxisXRange(const qreal &qMin, const qreal &qMax, const int &nTickCount)
{
    m_pLineAxisX = new QValueAxis;
    m_pLineAxisX->setRange(qMin, qMax);
    m_pLineAxisX->setTickCount(nTickCount);
    m_pChart->addAxis(m_pLineAxisX, Qt::AlignBottom);
}

void CMyLineChart::SetAxisYRange(const qreal &qMin, const qreal &qMax, const int &nTickCount)
{
    m_pLineAxisY = new QValueAxis;
    m_pLineAxisY->setRange(qMin, qMax);
    m_pLineAxisY->setTickCount(nTickCount);
    m_pLineAxisY->setGridLineVisible(false);
    m_pChart->addAxis(m_pLineAxisY, Qt::AlignLeft);
}

void CMyLineChart::SetDateTimeAxisX(const QDateTime &dtStart, const QDateTime &dtEnd, const QString &qsFormat, const int &nTickCount)
{
    m_bIsDateTime = true;
    m_pAxisDateTime = new QDateTimeAxis;
    m_pAxisDateTime->setFormat(qsFormat);
    m_pAxisDateTime->setRange(dtStart, dtEnd);
    m_pAxisDateTime->setTickCount(nTickCount);
    m_pChart->addAxis(m_pAxisDateTime, Qt::AlignBottom);
}

void CMyLineChart::SetAxisXTitle(const QString &qsAxisXTitle)
{
    if(m_bIsDateTime)
        m_pAxisDateTime->setTitleText(qsAxisXTitle);
    else
        m_pLineAxisX->setTitleText(qsAxisXTitle);
}

void CMyLineChart::SetAxisYTitle(const QString &qsAxisYTitle)
{
    m_pLineAxisY->setTitleText(qsAxisYTitle);
}

void CMyLineChart::AppendSeries(const QString &name , QMap<qreal, qreal> mapVal)
{
    QLineSeries* pLineSeries = new QLineSeries;
    pLineSeries->setName(name);
    pLineSeries->setPointsVisible(true);
    pLineSeries->setPointLabelsVisible(true);   //设置显示点位
    m_pChart->addSeries(pLineSeries);

    for(QMap<qreal, qreal>::iterator it = mapVal.begin(); it != mapVal.end(); it++)
        pLineSeries->append(it.key(), it.value());

    m_vecLineSeries.push_back(pLineSeries);

    pLineSeries->attachAxis(m_pLineAxisX);
    pLineSeries->attachAxis(m_pLineAxisY);
}

void CMyLineChart::AppendSeries(const QString &name, QMap<QDateTime, qreal> mapVal)
{
    QLineSeries* pLineSeries = new QLineSeries;
    pLineSeries->setName(name);
    pLineSeries->setPointsVisible(true);
    pLineSeries->setPointLabelsVisible(false);   //设置显示点位
    m_pChart->addSeries(pLineSeries);


    for(QMap<QDateTime, qreal>::iterator it = mapVal.begin(); it != mapVal.end(); it++)
        pLineSeries->append(it.key().toMSecsSinceEpoch(), it.value());

    m_vecLineSeries.push_back(pLineSeries);
    pLineSeries->attachAxis(m_pAxisDateTime);

    pLineSeries->attachAxis(m_pLineAxisY);
}

