#include "widget.h"
#include "ui_widget.h"
#include <QList>
#include <QVector>
#include "/Users/teapula/Documents/AIM/C++/examples/ecg_plot/ecg_reader.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setText("");
    ui->load_ecg_button->setText("Plot");
    ui->load_ecg_button->setStyleSheet("background-color: blue; color: white; radius:5;");

    connect(ui->load_ecg_button, &QPushButton::clicked, this, &Widget::plotData);

    // plotData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::plotData() {
    QString filename = "/Users/teapula/Documents/AIM/C++/exercises/03/ekg.txt";
    QVector<double> ecgData = ECGReader::readECGData(filename);

    if (ecgData.empty()) {
        qDebug() << "No data loaded from the given filename.";
        return;
    }

    QVector<double> x(ecgData.size()), y(ecgData.size());
    for (int i = 0; i < ecgData.size(); ++i) {
        x[i] = i / 360.0; // time in seconds based on sampling rate
        y[i] = ecgData[i]; // amplitude values
    }

    ui->qcpwidget->addGraph();
    ui->qcpwidget->graph(0)->setData(x, y);
    ui->qcpwidget->xAxis->setLabel("Time (s)");
    ui->qcpwidget->yAxis->setLabel("Amplitude");

    ui->qcpwidget->xAxis->setRange(0, x.last());
    ui->qcpwidget->yAxis->setRange(*std::min_element(y.begin(), y.end()), *std::max_element(y.begin(), y.end())); // y-axis range

    QVector<int> heartbeatIndices = ECGReader::detectHeartbeats(ecgData);

    // plot heartbeats as red dots
    QVector<double> heartbeatX, heartbeatY;
    for (int index : heartbeatIndices) {
        heartbeatX.push_back(index / 360.0); // time in seconds
        heartbeatY.push_back(ecgData[index]); // amplitude at the heartbeat
    }

    ui->qcpwidget->addGraph(); // new graph for heartbeats
    ui->qcpwidget->graph(1)->setData(heartbeatX, heartbeatY);
    ui->qcpwidget->graph(1)->setPen(QPen(Qt::red));
    ui->qcpwidget->graph(1)->setLineStyle(QCPGraph::lsNone); // ensure no line is drawn between points
    ui->qcpwidget->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 6)); // set scatter style and size

    // show average heart rate label
    double averageHeartRate = ECGReader::averageHeartRate(ecgData);

    ui->label->setText(QString("Average Heart Rate:<br>%1 bpm").arg(averageHeartRate));

    ui->qcpwidget->rescaleAxes();
    ui->qcpwidget->replot();

}
