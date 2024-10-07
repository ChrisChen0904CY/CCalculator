#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>
#include <QResource>
#include <QFile>
#include <QUrl>
#include <QProgressBar>
#include <QWebEngineView>
#include <QWebEngineHistory>
#include <QWebEngineSettings>
#include <QMessageBox>

namespace Ui {
class AboutPage;
}

class AboutPage : public QWidget
{
    Q_OBJECT

public:
    explicit AboutPage(QWidget *parent = nullptr);
    explicit AboutPage(QWidget *parent = nullptr, QString htmlFile="about.html");
    ~AboutPage();

private slots:
    void onLoadProgress(int progress) {
        progressBar->setValue(progress);
    }

    void onLoadFinished(bool success);

    void pageChange(QUrl url);

    void onReturnPressed();

private:
    Ui::AboutPage *ui;
    QWebEngineView *webEngineView;
    QProgressBar *progressBar;
};

#endif // ABOUTPAGE_H
