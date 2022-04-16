#include "cmychart.h"
#include "cmybarchart.h"
#include "cmypiechart.h"
#include "cmylinechart.h"
#include "cmysplinechart.h"

QVector<CMyChart::EColor> CMyChart::m_vecDefCol = {eBlue, eGreen, eYellow, ePurple, eRed, eLightBlue, eLightGreen, eLightYellow, eLightPurple};

CMyChart::CMyChart(const CMyChart::EType& type, QChartView* pView, QObject *parent)
    : QObject (parent), m_eType(type), m_pChartView(pView)
{
    m_pChart = new QChart;
    m_pChart->setAnimationOptions(QChart::SeriesAnimations);
    m_pChart->legend()->setVisible(true);       //设置提示打开（默认打开）
    m_pChart->legend()->show();     //显示提示
    m_pChart->layout()->setContentsMargins(0, 0, 0, 0);    //设置布局边距
    m_pChart->setMargins(QMargins(0, 0, 0, 0)); //设置控件边距
    m_pChart->setBackgroundRoundness(0);    //保存图表背景角上的圆角的直径。

    m_pChartView->setChart(m_pChart);
    m_pChartView->setRenderHint(QPainter::Antialiasing);    //防图形走样
}

CMyChart::~CMyChart()
{

}

CMyChart* CMyChart::GetChartWithType(const EType &eType, QChartView *pView)
{
    if(pView == NULL)
        return NULL;

    switch (eType)
    {
    case eInvalid:
        return NULL;
    case eBarChart:
        return new CMyBarChart(eType, pView);
    case ePieChart:
        return new CMyPieChart(eType, pView);
    case eLineChart:
        return new CMyLineChart(eType, pView);
    case eSplineChart:
        return new CMySplineChart(eType, pView);
    default:
        return NULL;
    }
}

QColor CMyChart::toQColor(const EColor &eColor)
{
    switch (eColor)
    {
    case eBlue:
        return QColor(0, 122, 255);
    case eGreen:
        return QColor(27, 201, 133);
    case eYellow:
        return QColor(255,168, 0);
    case ePurple:
        return QColor(37, 217, 255);
    case eRed:
        return QColor(252, 79, 76);
    case eLightBlue:
        return QColor(104, 153, 255);
    case eLightGreen:
        return QColor(37, 217, 255);
    case eLightYellow:
        return QColor(255, 211, 35);
    case eLightPurple:
        return QColor(212, 139, 250);
    default:
        return QColor(0, 122, 255);
    }
}

void CMyChart::SetLegend(bool bLegend)
{
    if(bLegend)
        m_pChart->legend()->show();
    else
        m_pChart->legend()->hide();
}

void CMyChart::SetTitle(const QString &qsTitle)
{
    m_pChart->setTitle(qsTitle);
}

