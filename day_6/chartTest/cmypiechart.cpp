#include "cmypiechart.h"

CMyPieChart::CMyPieChart(const CMyChart::EType& type, QChartView* pView, QObject *parent)
    : CMyChart(type, pView, parent)
{
    m_pPieSeries = new QPieSeries;
    m_pPieSeries->setHoleSize(0.5);     //设置空心占比
    m_pPieSeries->setPieSize(0.8);      //设置圆形占比
    m_pChart->addSeries(m_pPieSeries);  //将饼图放入容器
    m_pChart->legend()->setAlignment(Qt::AlignRight);  //设置提示说明位置
    connect(m_pPieSeries, SIGNAL(clicked(QPieSlice*)), this, SLOT(ClickedSector(QPieSlice*))); //点击扇形
}

CMyPieChart::~CMyPieChart()
{
    delete m_pPieSeries;
}

void CMyPieChart::ClearGraphical()
{
    m_pPieSeries->clear();
}

void CMyPieChart::ClickedSector(QPieSlice* pSlice)
{
    if(pSlice->isExploded())    //判断扇形有没有弹出
    {
        pSlice->setExploded(false);
        pSlice->setLabelVisible(false);
    }
    else {
        pSlice->setExploded(true);      //设置扇形弹出
        pSlice->setLabelVisible(true);  //设置扇形提示
    }
}

void CMyPieChart::AppendSeries(QMap<QString, qreal> &mapData, const QVector<EColor> &vecColors)
{
    m_pPieSeries->clear();
    QMap<QString, qreal>::iterator it = mapData.begin();
    for(int i = 0; i < mapData.size(); i++)
    {
        QPieSlice* pSlice = new QPieSlice(it.key(), it.value());
        pSlice->setLabel(it.key());
        pSlice->setColor(toQColor(vecColors[i]));
        m_pPieSeries->append(pSlice);
        it++;
    }

}

