#ifndef DIVISIONBENCHMARKTHREAD_H
#define DIVISIONBENCHMARKTHREAD_H

#include <QThread>
#include <QWidget>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QFile>
#include <QTextStream>
#include "cbignum.h"
#include "cbigmath.h"
#include "qdatetime.h"

class DivisionBenchmarkThread : public QThread {
    Q_OBJECT

public:
    explicit DivisionBenchmarkThread(QObject *parent = nullptr) : QThread(parent) {}

protected:
    void run() override {
        // 初始化
        CBigNum one(1);  // 定义常数除数
        one.setResFracBits(32);
        QVector<long long> denominators;
        QVector<qint64> fdivisionTimes;
        QVector<qint64> normalDivisionTimes;

        // 随机数生成器
        QRandomGenerator localRandom(QDateTime::currentMSecsSinceEpoch());

        // 分母生成
        for (long long i = 3; i <= 1000; ) {
            denominators.append(i);
            long long step = localRandom.bounded(30, 34);  // 随机步增3-33
            i += step;
        }

        // 测试性能
        for (long long denom : denominators) {
            CBigNum currentDenom = denom;
            currentDenom.setResFracBits(16);
            qDebug() << denom;

            // 记录 fdivision 用时
            QElapsedTimer timer;
            timer.start();
            CBigNum a = exp(currentDenom, false, false);  // 优化
            qint64 fdivTime = timer.nsecsElapsed();

            // 记录普通除法用时
            timer.restart();
            a = exp(currentDenom, false, true); // 普通
            qint64 divTime = timer.nsecsElapsed();

            // 保存数据
            fdivisionTimes.append(fdivTime);
            normalDivisionTimes.append(divTime);
        }

        // 导出到 Excel (CSV 格式)
        exportToExcel(denominators, fdivisionTimes, normalDivisionTimes);
    }

private:
    void exportToExcel(const QVector<long long> &denominators,
                       const QVector<qint64> &fdivisionTimes,
                       const QVector<qint64> &normalDivisionTimes) {
        QFile file("division_benchmark.csv");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qWarning() << "Failed to open file for writing.";
            return;
        }

        QTextStream out(&file);
        out << "Denominator,FDivisionTime(ns),NormalDivisionTime(ns)\n";

        for (int i = 0; i < denominators.size(); ++i) {
            out << denominators[i] << ","
                << fdivisionTimes[i] << ","
                << normalDivisionTimes[i] << "\n";
        }

        file.close();
        qDebug() << "Benchmark results exported to division_benchmark.csv.";
    }
};

#endif // DIVISIONBENCHMARKTHREAD_H
