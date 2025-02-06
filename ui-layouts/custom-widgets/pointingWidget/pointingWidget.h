#pragma once

#include <QDialog>
#include <QPicture>
#include <QPainter>
#include <QVector>
#include "../loader.h"
#include "../qcustomplot.h"

namespace Ui {
class PointingWidget;
}

class PointingWidget : public QDialog, public CustomWidgetInterface
{
    Q_OBJECT

  public:
    explicit PointingWidget(QWidget *parent = nullptr);
    ~PointingWidget();

    void update(const corfu::ground::Telemetry &receivedTelemetry);
    void show();
    QWidget* getQWidget();

  private:
    QElapsedTimer timer;
    QCustomPlot customPlot;
    QVector<double> y0 = QVector<double>(0);
    QVector<double> x = QVector<double>(0);
    Ui::PointingWidget *ui;
    QPicture* pic;
    QPainter* painter;
    QPixmap* pix;
};

CustomWidgetInterface* createPointingWidget(QWidget* parent, std::string i);
