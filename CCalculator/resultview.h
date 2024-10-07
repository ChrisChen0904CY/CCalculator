#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QClipboard>
#include <QMessageBox>

namespace Ui {
class ResultView;
}

class ResultView : public QWidget
{
    Q_OBJECT

public:
    explicit ResultView(QWidget *parent = nullptr);
    explicit ResultView(QWidget *parent = nullptr, QString text = "", QString filePath = "");
    ~ResultView();
    void connects();

public slots:
    // 复制完整结果
    void copy2Clipboard();
    // 打开文件保存配置页面
    void fileSavePage_display();

private:
    Ui::ResultView *ui;
    // 文件保存路径
    QString filePath;
    // 文件名
    QString fileName;
};

#endif // RESULTVIEW_H
