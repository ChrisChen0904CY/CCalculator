#ifndef RESDISPLAYPAGE_H
#define RESDISPLAYPAGE_H

#include <QWidget>

namespace Ui {
class ResDisplayPage;
}

class ResDisplayPage : public QWidget
{
    Q_OBJECT

public:
    explicit ResDisplayPage(QWidget *parent = nullptr);
    explicit ResDisplayPage(QWidget *parent = nullptr, QVector<QString> sys = {"SCI"});
    ~ResDisplayPage();
    void init(QVector<QString> sys);
    void connects();

signals:
    // 参数更新信号
    void sysUpdate(QPair<QString, QString> newParam);

public slots:
    // 更新显示模式
    void resDisplayModeUpdate();
    // 更新后缀零显示
    void suffixZeroUpdate();
    // 更新科学计数法幂表示
    void ePowerUpdate();

private:
    Ui::ResDisplayPage *ui;
};

#endif // RESDISPLAYPAGE_H
