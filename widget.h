#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <Qvector>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    void plotData(); // Declare the plotData function
    QVector<double> readECGData(QString);
};

#endif // WIDGET_H
