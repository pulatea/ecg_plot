#ifndef ECG_READER_H
#define ECG_READER_H

#include <QString>
#include <QVector>

class ECGReader{
public: static QVector<double> readECGData(const QString &filename);
        static QVector<int> detectHeartbeats(const QVector<double> &ecgData);
        static double averageHeartRate(const QVector<double> &ecgData);
};

#endif // ECG_READER_H
