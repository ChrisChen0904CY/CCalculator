#include "precisionpage.h"
#include "ui_precisionpage.h"

PrecisionPage::PrecisionPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PrecisionPage)
{
    ui->setupUi(this);
}

PrecisionPage::PrecisionPage(QWidget *parent, QVector<QString> sys)
    : QWidget(parent)
    , ui(new Ui::PrecisionPage)
{
    ui->setupUi(this);
    // 页面初始化
    init(sys);
    connects();
}

PrecisionPage::~PrecisionPage()
{
    delete ui;
}

void PrecisionPage::init(QVector<QString> sys) {
    this->ui->spinBox->setValue(sys[0].toLongLong());
    this->ui->checkBox->setChecked(sys[1]=="1");
}

void PrecisionPage::connects() {
    connect(this->ui->spinBox,
            &QSpinBox::valueChanged,
            this,
            &PrecisionPage::precisionUpdate);
    connect(this->ui->checkBox,
            &QCheckBox::stateChanged,
            this,
            &PrecisionPage::fdUpdate);
}

// 更新计算精度位数
void PrecisionPage::precisionUpdate() {
    emit this->sysUpdate({"precision", QString::number(this->ui->spinBox->value())});
}

// 更新除法优化参数
void PrecisionPage::fdUpdate() {
    emit this->sysUpdate({"fd", this->ui->checkBox->isChecked() ? "1" : "0"});
}
