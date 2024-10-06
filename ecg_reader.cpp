#include "/Users/teapula/Documents/AIM/C++/examples/ecg_plot/ecg_reader.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QVector>
#include <fstream>
#include <algorithm>
#include <QDebug>

using namespace std;

QVector<double> ECGReader::readECGData(const QString &filename){
    QVector<double> ecgData;

    std::ifstream stream(filename.toStdString());

    if(!stream){
        cerr << "ERROR! Could not open the given file.";
        return ecgData;
    }

    copy(istream_iterator<double>(stream), istream_iterator<double>(),
         back_inserter(ecgData));

    return ecgData;
}

double calculateThreshold(const QVector<double> &ecgData) {
    double mean = std::accumulate(ecgData.begin(), ecgData.end(), 0.0) / ecgData.size();
    double stdDev = std::sqrt(std::accumulate(ecgData.begin(), ecgData.end(), 0.0,
                                              [mean](double accum, double x) {
                                                  return accum + (x - mean) * (x - mean);
                                              }) / ecgData.size());
    return mean + 1.5 * stdDev;
}


QVector<int> ECGReader::detectHeartbeats(const QVector<double> &ecgData) {
    double threshold = calculateThreshold(ecgData);
    QVector<int> rPeaks;

    for (int i = 1; i < ecgData.size() - 1; ++i) {
        if (ecgData[i] > threshold && ecgData[i] > ecgData[i - 1] && ecgData[i] > ecgData[i + 1]) {
            rPeaks.append(i);
        }
    }

    return rPeaks;
}

double ECGReader::averageHeartRate(const QVector<double> &ecgData) {
    double duration = ecgData.size() / 360 / 60; // in minutes
    QVector<int> heartbeatIndices = detectHeartbeats(ecgData);

    return heartbeatIndices.size() / duration;
}
