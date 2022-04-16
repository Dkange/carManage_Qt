#include "widget.h"
#include "ui_widget.h"
#include "cmychart.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi();

    QChartView *chartView = new QChartView(this);

    CMyChart* testChart = CMyChart::GetChartWithType(CMyChart::eBarChart,chartView);

    testChart->SetTitle("11111111111");

}

Widget::~Widget()
{
    delete ui;
}

