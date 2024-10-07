#include "aboutpagelite.h"
#include "ui_aboutpage.h"

// 丢失页面
QString missingHtmlContentLite = R"(
<!DOCTYPE html>
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>页面丢失</title>
</head>
<body style="height: 100%; margin: 0; display: flex; justify-content: center; align-items: center; background-color: #ffffff; overflow: hidden;">
    <div style="height: 50%;">
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
        <p>&nbsp;</p>
    </div>
    <div style="text-align: center;">
        <p style="font-size: 24px; font-weight: bold;">页面丢失！点<a href="https://chrischen0904cy.github.io/CCalculator/CCalculator/about.html">我</a>重新下载！</p>
    </div>
</body>
</html>
)";

AboutPageLite::AboutPageLite(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutPage)
{
    ui->setupUi(this);
    ui_init();
}

AboutPageLite::AboutPageLite(QWidget *parent, QString htmlFile)
    : QWidget(parent)
    , ui(new Ui::AboutPage)
{
    ui->setupUi(this);
    ui_init();
    // 检查 About 页面是否存在
    // 不存在就提示错误并给出下载地址
    if (!QFile::exists(":/"+htmlFile)) {
        this->ui->textBrowser->setHtml(missingHtmlContentLite);
    }
    // 存在则让窗口变大以便加载
    else {
        this->setFixedSize(1080, 640);
        // 从本地加载
        this->ui->textBrowser->setSource(QUrl("qrc:/"+htmlFile));
    }
}

AboutPageLite::~AboutPageLite() {
    delete ui;
}

void AboutPageLite::ui_init() {
    // 移除导航栏中按钮、弹簧、输入行
    delete this->ui->pushButton;
    delete this->ui->pushButton_2;
    delete this->ui->lineEdit;
    delete this->ui->horizontalSpacer_2;
    delete this->ui->horizontalSpacer_3;
    // 移除掉导航栏
    this->ui->verticalLayout->removeItem(this->ui->horizontalLayout);
    // 允许外部链接
    this->ui->textBrowser->setOpenExternalLinks(true);
}
