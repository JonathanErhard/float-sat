#ifndef WIDGET1_H
#define WIDGET1_H

#include <QDialog>
#include <QPicture>
#include <QPainter>
#include <QVector>
#include "../loader.h"
#include "../qcustomplot.h"

namespace Ui {
class Widget1;
}

class Widget1 : public QDialog, public CustomWidgetInterface
{
    Q_OBJECT

  public:
    explicit Widget1(QWidget *parent = nullptr);
    ~Widget1();

    void update(const corfu::ground::Telemetry &receivedTelemetry);
    void show();
    QWidget* getQWidget();

  private:
    QElapsedTimer timer;
    QCustomPlot customPlot;
    QVector<double> y0 = QVector<double>(0);
    QVector<double> x = QVector<double>(0);
    Ui::Widget1 *ui;
    QPicture* pic;
    QPainter* painter;
    QPixmap* pix;
};

CustomWidgetInterface* createWidget1(QWidget* parent, std::string i);


#endif // WIDGET1_H
