#include "resultview.h"
#include "ui_resultview.h"

ResultView::ResultView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResultView)
{
    ui->setupUi(this);
}

ResultView::ResultView(QWidget *parent, QString text, QString filePath)
    : QWidget(parent)
    , ui(new Ui::ResultView)
{
    ui->setupUi(this);
    this->ui->textBrowser->setText(text);
    this->filePath = filePath;
    // 允许显示框在任何地方换行
    this->ui->textBrowser->setWordWrapMode(QTextOption::WrapAnywhere);
    connects();
}

ResultView::~ResultView()
{
    delete ui;
}

void ResultView::connects() {
    // 复制结果
    connect(this->ui->pushButton,
            &QPushButton::clicked,
            this,
            &ResultView::copy2Clipboard);
    // 打开保存文件配置页面
    connect(this->ui->pushButton_2,
            &QPushButton::clicked,
            this,
            &ResultView::fileSavePage_display);
}

// 复制完整结果
void ResultView::copy2Clipboard() {
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(this->ui->textBrowser->toPlainText());
    // 复制成功后防止重复复制
    this->ui->pushButton->setIcon(QIcon(":/rcs/done.png"));
    this->ui->pushButton->disconnect();
}

// 打开文件保存配置页面
void ResultView::fileSavePage_display() {
    // 打开文件保存对话框
    QString fileName = QFileDialog::getSaveFileName(this, tr("保存文件"), "",
                                                    tr("文本文件 (*.txt)"));

    // 检查用户是否选择了文件
    if (!fileName.isEmpty()) {
        // 创建文件对象
        QFile file(fileName);

        // 尝试打开文件
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            // 将 textBrowser 的内容写入文件
            out << this->ui->textBrowser->toPlainText();
            // 关闭文件
            file.close();
        } else {
            // 如果无法打开文件，给出错误提示
            QMessageBox::warning(this, tr("错误"), tr("无法打开文件进行写入"));
        }
    }
}
