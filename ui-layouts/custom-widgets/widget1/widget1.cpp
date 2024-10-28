#include "widget1.h"
#include "ui_widget1.h"
#include <iostream>
#include <math.h>
#include <QPen>


Widget1::Widget1(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Widget1)
{
    ui->setupUi(this);
    pix = new QPixmap(ui->picLabel->size());
    pic = new QPicture();
    painter = new QPainter();

timer.start();
    //this->setFixedSize(QSize(260, 260));
    ui->plotLayout->addWidget(&customPlot);
    /*customPlot.addGraph();
    customPlot.graph(0)->setPen(QPen(QColor(40,110,255)));

    customPlot.graph(0)->setData(x0, y0);*/
  customPlot.addGraph();
  customPlot.graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
  customPlot.graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
  customPlot.addGraph();
  
  // generate some points of data (y0 for first, y1 for second graph):

  // configure right and top axis to show ticks but no labels:
  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
  customPlot.xAxis2->setVisible(true);
  customPlot.xAxis2->setTickLabels(false);
  customPlot.yAxis2->setVisible(true);
  customPlot.yAxis2->setTickLabels(false);
  // make left and bottom axes always transfer their ranges to right and top axes:
  connect(customPlot.xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot.xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot.yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot.yAxis2, SLOT(setRange(QCPRange)));
  // pass data points to graphs:
  customPlot.graph(0)->setData(x, y0);
  
  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
  customPlot.yAxis->setRange(-180, 180);
  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
 
  // Note: we could have also just called customPlot.rescaleAxes(); instead
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
 // customPlot.setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

Widget1::~Widget1()
{
    delete ui;
}


void Widget1::update(const corfu::ground::Telemetry &receivedTelemetry){
    if(receivedTelemetry.serviceID != 11 || receivedTelemetry.subserviceID != 1) return;

    auto val = std::stod(receivedTelemetry.payload.at("AdcsStandardTelemetry").at("Yaw").getValue());
    painter->begin(pic);
    float s = 469.0f;
    painter->drawEllipse(0,0,s,s);
    painter->drawLine(s/2,s/2,s/2*sin(val*M_PI/180)+s/2, s/2*cos(val*M_PI/180)+s/2);
    painter->end();


    y0.append(val);
    float t = timer.elapsed()/1000.0f;
    x.append(t);
    
    painter->begin(pix);
    pix->fill(Qt::white);
    pic->play(painter);
    painter->end();
    ui->picLabel->setPixmap(*pix);
    customPlot.xAxis->setRange(t-60, t);

  customPlot.graph(0)->setData(x, y0);

    customPlot.replot();
}

void Widget1::show(){
    this->setAttribute(Qt::WA_DeleteOnClose);
    QWidget::show();
}

QWidget* Widget1::getQWidget(){
    return static_cast<QWidget*>(this);
}

//Creation Function that returns a casted widget
CustomWidgetInterface* createWidget1(QWidget* parent, std::string i){
    return  static_cast<CustomWidgetInterface*>(new Widget1(parent));
}
