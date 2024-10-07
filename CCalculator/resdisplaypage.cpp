#include "resdisplaypage.h"
#include "ui_resdisplaypage.h"

ResDisplayPage::ResDisplayPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ResDisplayPage)
{
    ui->setupUi(this);
}

ResDisplayPage::ResDisplayPage(QWidget *parent, QVector<QString> sys)
    : QWidget(parent)
    , ui(new Ui::ResDisplayPage)
{
    ui->setupUi(this);
    init(sys);
    connects();
}

ResDisplayPage::~ResDisplayPage()
{
    delete ui;
}

void ResDisplayPage::init(QVector<QString> sys) {
    // 初始化显示模式选项
    if(sys[0] == "SCI") {
        this->ui->comboBox->setCurrentIndex(0);
    }
    else if(sys[0] == "Normal") {
        this->ui->comboBox->setCurrentIndex(1);
    }
    else {
        this->ui->comboBox->setCurrentIndex(0);
    }
    // 初始化尾缀零显示选项
    this->ui->checkBox->setChecked(sys[1]=="1");
    // 初始化E幂显示
    this->ui->checkBox_2->setChecked(sys[2]=="1");
}

void ResDisplayPage::connects() {
    connect(this->ui->comboBox,
            &QComboBox::currentIndexChanged,
            this,
            &ResDisplayPage::resDisplayModeUpdate);
    connect(this->ui->checkBox,
            &QCheckBox::stateChanged,
            this,
            &ResDisplayPage::suffixZeroUpdate);
    connect(this->ui->checkBox_2,
            &QCheckBox::stateChanged,
            this,
            &ResDisplayPage::ePowerUpdate);
}

// 更新显示模式
void ResDisplayPage::resDisplayModeUpdate() {
    switch(this->ui->comboBox->currentIndex()) {
    case 0:
        emit sysUpdate({"resDisplayMode", "SCI"});
        break;
    case 1:
        emit sysUpdate({"resDisplayMode", "Normal"});
        break;
    default:
        emit sysUpdate({"resDisplayMode", "SCI"});
        break;
    }
}

// 更新后缀零显示
void ResDisplayPage::suffixZeroUpdate() {
    emit sysUpdate({"suffixZero", this->ui->checkBox->isChecked() ? "1" : "0"});
}

// 更新科学计数法幂表示
void ResDisplayPage::ePowerUpdate() {
    emit sysUpdate({"ePower", this->ui->checkBox_2->isChecked() ? "1" : "0"});
}
