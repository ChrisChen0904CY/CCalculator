#include "helpdialog.h"
#include "ui_helpdialog.h"
#include "qutils.h"

HelpDialog::HelpDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HelpDialog)
{
    ui->setupUi(this);
    // 设置 SpinBox 范围
    this->ui->spinBox->setRange(1, this->helpDocs.size());
    // 设置初始值
    this->ui->spinBox->setValue(1);
    // 设置初始页面
    setDoc();
    // 绑定所有槽函数
    connects();
}

HelpDialog::~HelpDialog()
{
    delete ui;
}

// 绑定所有槽函数
void HelpDialog::connects() {
    connect(this->ui->spinBox,
            &QSpinBox::valueChanged,
            this,
            &HelpDialog::setDoc);
    connect(this->ui->pushButton_2,
            &QPushButton::clicked,
            this,
            &HelpDialog::previous_clicked);
    connect(this->ui->pushButton,
            &QPushButton::clicked,
            this,
            &HelpDialog::next_clicked);
}

// 设置当前页面内容
void HelpDialog::setDoc() {
    // 获取当前页面数
    int pageID = this->ui->spinBox->value();
    // 设置标题
    this->setWindowTitle("Help - "+this->helpDocs[pageID-1][0]);
    // 设置图片
    setupLabel(this->ui->label, this->helpDocs[pageID-1][1]);
    // 设置文本
    this->ui->textBrowser->setText(this->helpDocs[pageID-1][2]);
    // 设置两个按钮是否可用
    this->ui->pushButton_2->setEnabled(this->ui->spinBox->value() != 1);
    this->ui->pushButton->setEnabled(this->ui->spinBox->value() != this->ui->spinBox->maximum());
}

// 点击前一页
void HelpDialog::previous_clicked(){
    this->ui->spinBox->setValue(this->ui->spinBox->value()-1);
}

// 点击后一页
void HelpDialog::next_clicked(){
    this->ui->spinBox->setValue(this->ui->spinBox->value()+1);
}
