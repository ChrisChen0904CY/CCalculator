#ifndef SETTINGPAGE_H
#define SETTINGPAGE_H

#include <QWidget>
#include <QTreeWidget>
#include <QVector>
#include <QMap>
#include <QLayout>
#include <QPushButton>
#include <QMessageBox>

#include "precisionpage.h"
#include "resdisplaypage.h"

namespace Ui {
class SettingPage;
}

class SettingPage : public QWidget
{
    Q_OBJECT

public:
    explicit SettingPage(QWidget *parent = nullptr);
    explicit SettingPage(QWidget *parent = nullptr, QMap<QString, QString> sysParam = {});
    ~SettingPage();
    void connects();

signals:
    void sysParaChanged(QMap<QString, QString> sysParam);
    void searchTextConfirmed(const QString &text);

public slots:
    void sysUpdate(QPair<QString, QString> sys);
    // 应用当前设置
    void settingApply();
    // 应用当前设置并关闭窗口
    void settingConfirm();
    void hideItemsNotMatching(QTreeWidgetItem *item, const QString &text);
    void showAllItems(QTreeWidgetItem *item);
    // 搜索条目
    void search();
    void filterItems(const QString &text);
    // 复原所有条目
    void resetItems();

private:
    Ui::SettingPage *ui;
    QVector<QTreeWidgetItem*> items;
    PrecisionPage* precisionPage = nullptr;
    ResDisplayPage* resDisplayPage = nullptr;
    QHBoxLayout* hbox = nullptr;
    QPushButton* searchButton = nullptr;
    QMap<QString, QString> sysParam = {};
};

#endif // SETTINGPAGE_H
