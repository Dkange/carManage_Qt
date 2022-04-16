#ifndef CMYCHART_H
#define CMYCHART_H

#include <QObject>
#include <QtCharts>

QT_CHARTS_USE_NAMESPACE

struct BarDateInfo
{
    QString qsKey;
    QVector<qreal> vecVal;
};

class CMyChart : public QObject
{
    Q_OBJECT

public:
    enum EType
    {
        eInvalid,       //无效
        eBarChart,      //柱状图
        ePieChart,      //饼状图
        eLineChart,     //折线图
        eSplineChart    //曲线图
    };

    enum EColor
    {
        eBlue,          //蓝色
        eGreen,         //绿色
        eYellow,        //黄色
        ePurple,        //紫色
        eRed,           //红色
        eLightBlue,     //淡蓝色
        eLightGreen,    //淡绿色
        eLightYellow,   //淡黄色
        eLightPurple,   //淡紫色
    };

public:
    CMyChart(const CMyChart::EType& type, QChartView* pView, QObject *parent = nullptr);
    virtual ~CMyChart();

public:
    //根据选择的图形，返回CMyChart
    static CMyChart* GetChartWithType(const EType& eType, QChartView* pView);

    //根据传入颜色转换成QColor
    QColor toQColor(const EColor& eColor);

public:
    //清空界面上显示的图形
    virtual void ClearGraphical() = 0;
    //设置提示信息是否显示
    void SetLegend(bool bLegend = true);
    //设置标题栏
    void SetTitle(const QString& qsTitle);
    //设置X轴坐标、刻度尺，柱状图、饼状图调此接口无用
    virtual void SetAxisXRange(const qreal& qMin = 0, const qreal& qMax = 10, const int& nTickCount = 5){};
    //设置Y轴坐标、刻度尺，柱状图、饼状图调此接口无用
    virtual void SetAxisYRange(const qreal& qMin = 0, const qreal& qMax = 10, const int& nTickCount = 5){};
    //设置时间坐标轴，柱状图、饼状图调此接口无用
    virtual void SetDateTimeAxisX(const QDateTime& dtStart,
                                 const QDateTime& dtEnd,
                                 const QString& qsFormat = "yyyy-MM-dd",
                                  const int& nTickCount = 5){};
    //设置X轴标题，饼状图调此接口无用
    virtual void SetAxisXTitle(const QString& qsAxisXTitle){};
    //设置Y轴标题，柱状图调此接口无用
    virtual void SetAxisYTitle(const QString& qsAxisYTitle){};

    //柱状图添加一组数据
    virtual void AppendSeries(const QString& qsAxisXName,
                              QMap<QString, qreal>& mapData,
                              const QVector<EColor>& vecColors = m_vecDefCol){};

    //饼状图添加数据
    virtual void AppendSeries(QMap<QString, qreal>& mapData, const QVector<EColor>& vecColors = m_vecDefCol){};

    //折线图、曲线图添加一条线
    virtual void AppendSeries(const QString& name, QMap<qreal, qreal> mapVal){};
    //折线图、曲线图添加坐标轴为时间的一条线
    virtual void AppendSeries(const QString& name, QMap<QDateTime, qreal> mapVal){};

public:
    EType                   m_eType;
    QChart*                 m_pChart;
    QChartView*             m_pChartView;
    static QVector<EColor>  m_vecDefCol;    //默认颜色顺序
};

#endif // CMYCHART_H
