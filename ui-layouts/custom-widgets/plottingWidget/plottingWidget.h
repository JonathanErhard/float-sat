#pragma once

#include <QDialog>
#include <QPicture>
#include <QPainter>
#include <QVector>
#include "../loader.h"
#include "../qcustomplot.h"

namespace Ui {
class PlottingWidget;
}

class PlottingWidget : public QDialog, public CustomWidgetInterface
{
    Q_OBJECT

  public:
    explicit PlottingWidget(std::string i, QWidget *parent = nullptr);
    ~PlottingWidget();

    void updateIndividual(std::string txt);
    void show();
    QWidget* getQWidget();

    
  private:
    QElapsedTimer timer;
    QCustomPlot customPlot;
    QVector<double> y0 = QVector<double>(0);
    QVector<double> x = QVector<double>(0);
    Ui::PlottingWidget *ui;
    QPicture* pic;
    QPainter* painter;
    QPixmap* pix;

};

CustomWidgetInterface* createPlottingWidget(QWidget* parent, std::string i);
