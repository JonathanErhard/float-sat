#pragma once

#include <QDialog>
#include <QPicture>
#include <QPainter>
#include <QVector>
#include "../loader.h"
#include "../qcustomplot.h"

namespace Ui {
class RsWidget;
}

class RsWidget : public QDialog, public CustomWidgetInterface
{
    Q_OBJECT

  public:
    explicit RsWidget(std::string i, QWidget *parent = nullptr);
    ~RsWidget();

    void updateIndividual(std::string txt);
    void show();
    QWidget* getQWidget();

    
  private:
    QElapsedTimer timer;
    QCustomPlot customPlot;
    QVector<double> y0 = QVector<double>(0);
    QVector<double> x = QVector<double>(0);
    Ui::RsWidget *ui;
    QPicture* pic;
    QPainter* painter;
    QPixmap* pix;

};

CustomWidgetInterface* createRsWidget(QWidget* parent, std::string i);
