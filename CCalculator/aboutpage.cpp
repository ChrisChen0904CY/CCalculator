#include "aboutpage.h"
#include "ui_aboutpage.h"

// 丢失页面
QString missingHtmlContent = R"(
<!DOCTYPE html>
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>页面丢失</title>
    <style>
        body, html {
            height: 100%;
            margin: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #ffffff;
            overflow: hidden; /* 防止滚动条 */
        }

        .container {
            text-align: center;
        }

        .container p {
            font-size: 24px;
            font-weight: bold;
        }

        .circles {
            display: flex;
            justify-content: center;
            margin-bottom: 20px;
        }

        .circle {
            width: 20px;
            height: 20px;
            background-color: orange;
            border-radius: 50%;
            margin: 0 5px;
            animation: bounce 1.5s infinite ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.3s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.6s;
        }

        @keyframes bounce {
            0%, 100% {
                transform: translateY(0);
            }
            50% {
                transform: translateY(-20px);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div class="circles">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
        <p>页面丢失！点<a href="https://chrischen0904cy.github.io/CCalculator/CCalculator/about.html">我</a>重新下载！</p>
    </div>
</body>
</html>
)";

AboutPage::AboutPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutPage)
{
    ui->setupUi(this);
}

AboutPage::AboutPage(QWidget *parent, QString htmlFile)
    : QWidget(parent)
    , ui(new Ui::AboutPage)
    , webEngineView(new QWebEngineView(this))
    , progressBar(new QProgressBar(this))
{
    ui->setupUi(this);

    // 调整进度条 QSS
    progressBar->setStyleSheet(
        "QProgressBar {"
        "    border: 1px solid grey;"
        "    border-radius: 5px;"
        "    text-align: center;"
        "}"
        "QProgressBar::chunk {"
        "    background-color: #FFA500;"
        "    width: 20px;"
        "}"
    );

    // 允许 js 控制和跳转
    webEngineView->settings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    webEngineView->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessRemoteUrls, true);
    webEngineView->settings()->setAttribute(QWebEngineSettings::LocalContentCanAccessFileUrls, true);

    // 在 layout 中找到原来的 QTextBrowser
    QLayout *layout = ui->verticalLayout;
    QWidget *oldTextBrowser = ui->textBrowser;

    // 删除原来的 QTextBrowser
    layout->removeWidget(oldTextBrowser);
    oldTextBrowser->deleteLater();

    // 将 QWebEngineView 添加到布局中
    layout->addWidget(progressBar);
    layout->addWidget(webEngineView);
    // 加载完成前导航栏和内容看不见
    webEngineView->setVisible(false);
    this->ui->pushButton->setVisible(false);
    this->ui->pushButton_2->setVisible(false);
    this->ui->lineEdit->setText("./"+htmlFile);
    this->ui->lineEdit->setVisible(false);

    // 连接信号和槽
    connect(webEngineView,
            &QWebEngineView::loadProgress,
            this,
            &AboutPage::onLoadProgress);
    connect(webEngineView,
            &QWebEngineView::loadFinished,
            this,
            &AboutPage::onLoadFinished);
    connect(webEngineView,
            &QWebEngineView::urlChanged,
            this,
            &AboutPage::pageChange);
    connect(this->ui->pushButton,
            &QPushButton::clicked,
            this->webEngineView,
            &QWebEngineView::back);
    connect(this->ui->pushButton_2,
            &QPushButton::clicked,
            this->webEngineView,
            &QWebEngineView::forward);
    connect(this->ui->lineEdit,
            &QLineEdit::returnPressed,
            this,
            &AboutPage::onReturnPressed);

    // 检查 About 页面是否存在
    // 不存在就提示错误并给出下载地址
    if (!QFile::exists(":/"+htmlFile)) {
        this->webEngineView->setHtml(missingHtmlContent);
    }
    // 存在则让窗口变大以便加载
    else {
        this->setFixedSize(1080, 640);
        // 从本地加载
        this->webEngineView->setUrl(QUrl("qrc:/"+htmlFile));
    }

}

AboutPage::~AboutPage()
{
    if (webEngineView) {
        delete webEngineView;
    }
    if (progressBar) {
        delete progressBar;
    }
    delete ui;
}

void AboutPage::pageChange(QUrl url)  {
    qDebug() << url;
    progressBar->setValue(0);
    progressBar->show();
    // 加载完成前导航栏和内容看不见
    webEngineView->setVisible(false);
    this->ui->pushButton->setVisible(false);
    this->ui->pushButton_2->setVisible(false);
    this->ui->lineEdit->setText(url.toString());
    this->ui->lineEdit->setVisible(false);
    webEngineView->load(url);
}

void AboutPage::onLoadFinished(bool success)  {
    if (!success) {
        this->webEngineView->back();
        return;
    }
    progressBar->hide();
    // 加载后显示
    webEngineView->setVisible(true);
    this->ui->pushButton->setVisible(true);
    this->ui->pushButton_2->setVisible(true);
    this->ui->lineEdit->setVisible(true);
    // 每次加载完更新按钮状态
    this->ui->pushButton->setEnabled(this->webEngineView->history()->canGoBack());
    this->ui->pushButton_2->setEnabled(this->webEngineView->history()->canGoForward());
}

void AboutPage::onReturnPressed()  {
    QString url = this->ui->lineEdit->text();
    if (url.mid(3) != "qrc" && url.mid(4) != "http" && url.mid(4) != "mail") {
        url = "https://" + url;
    }
    pageChange(QUrl(url));
}
