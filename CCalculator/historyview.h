#ifndef HISTORYVIEW_H
#define HISTORYVIEW_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVector>

namespace Ui {
class HistoryView;
}

class HistoryView : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryView(QWidget *parent = nullptr);
    explicit HistoryView(QWidget *parent = nullptr, bool all = false);
    // 根据给定的查询历史记录结果具体构造页面
    void page_create(QVector<QVector<QString>> res);
    // 构建当前页面的表格
    void page_load();
    // 连接所有槽函数
    void connects();
    ~HistoryView();

public slots:
    // 左翻页
    void turn_left();
    // 右翻页
    void turn_right();
    // 页数通过 spinbox 改变
    void page_change();

private:
    Ui::HistoryView *ui;
    QVector<QVector<QString>> res;
    int cur_page_id = 1;
};

#endif // HISTORYVIEW_H
