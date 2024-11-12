#ifndef PRECISIONPAGE_H
#define PRECISIONPAGE_H

#include <QWidget>

namespace Ui {
class PrecisionPage;
}

class PrecisionPage : public QWidget
{
    Q_OBJECT

public:
    explicit PrecisionPage(QWidget *parent = nullptr);
    explicit PrecisionPage(QWidget *parent = nullptr, QVector<QString> sys = {"8"});
    ~PrecisionPage();
    void init(QVector<QString> sys);
    void connects();

signals:
    // 参数更新信号
    void sysUpdate(QPair<QString, QString> newParam);

public slots:
    // 更新计算精度位数
    void precisionUpdate();
    // 更新除法优化参数
    void fdUpdate();

private:
    Ui::PrecisionPage *ui;
};

#endif // PRECISIONPAGE_H
