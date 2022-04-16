#include "cmybarchart.h"

CMyBarChart::CMyBarChart(const CMyChart::EType& type, QChartView* pView, QObject *parent)
    : CMyChart(type, pView, parent)
{
    m_pBarSeries = new QBarSeries;          //创建分组系列
    m_pBarSeries->setLabelsVisible(true);   //设置显示柱形图值
    m_pBarSeries->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);   //设置值位置
    m_pChart->addSeries(m_pBarSeries);      //将分组放入chart容器
    m_pChart->createDefaultAxes();          //创建默认坐标轴
    m_pChart->legend()->setAlignment(Qt::AlignBottom);  //设置提示说明位置
    m_vecBarSet.fill(NULL, 10);     //默认最多只能有10个柱子
}

CMyBarChart::~CMyBarChart()
{
    delete m_pBarSeries;
    delete m_pBarAxisX;
    delete m_pBarAxisY;
}

void CMyBarChart::ClearGraphical()
{
    for(QVector<QBarSet*>::iterator it = m_vecBarSet.begin(); it != m_vecBarSet.end(); it++)
    {
        if(*it != NULL)
            delete *it;
    }

    m_vecBarSet.fill(NULL, 10); //默认最多只有10种类型的柱子
    m_pBarAxisX->clear();
    m_pBarSeries->clear();
}

void CMyBarChart::SetAxisXTitle(const QString &qsAxisXTitle)
{
    m_pBarAxisX->setTitleText(qsAxisXTitle);
}

void CMyBarChart::SetAxisYTitle(const QString &qsAxisYTitle)
{
    m_pBarAxisY->setTitleText(qsAxisYTitle);
}

void CMyBarChart::SetAxisYRange(const qreal& qMin, const qreal& qMax, const int& nTickCount)
{
    m_pBarAxisX = new QBarCategoryAxis;     //创建X轴
    m_pBarAxisY = new QValueAxis;           //创建Y轴
    m_pBarAxisX->setLabelsAngle(-45);       //设置X轴坐标倾斜
    m_pBarAxisY->setGridLineVisible(false); //设置网格不可见
    m_pBarAxisY->setRange(qMin, qMax);
    m_pBarAxisY->setTickCount(nTickCount);
    m_pChart->setAxisX(m_pBarAxisX, m_pBarSeries);  //将X坐标轴和分组进行统一
    m_pChart->setAxisY(m_pBarAxisY, m_pBarSeries);  //将Y坐标轴和分组进行统一
}

/*
 * 一个QBarSet代表的是同一颜色的柱形，里面存放多个柱子的值
 * 此接口先将一组数据作为柱子类型数的最大大小，然后根据先后顺序给柱子添加数据
 */
void CMyBarChart::AppendSeries(const QString &qsAxisXName, QMap<QString, qreal>& mapData, const QVector<EColor> &vecColors)
{
    QMap<QString, qreal>::iterator it = mapData.begin();
    for(int i = 0; i < mapData.size(); i++)
    {
        if(m_vecBarSet[i] == NULL)
        {
            m_vecBarSet[i] = new QBarSet(it.key());
            m_vecBarSet[i]->setColor(toQColor(vecColors[i]));
        }

        m_vecBarSet[i]->append(it.value());
        m_pBarSeries->append(m_vecBarSet[i]);
        it++;
    }
    m_pBarAxisX->append(qsAxisXName);
}

