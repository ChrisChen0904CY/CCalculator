#include "historyview.h"
#include "ui_historyview.h"

#define one_page_rows 15

HistoryView::HistoryView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HistoryView)
{
    ui->setupUi(this);
}

HistoryView::HistoryView(QWidget *parent, bool all)
    : QWidget(parent)
    , ui(new Ui::HistoryView)
{
    ui->setupUi(this);
    // 标题设置
    this->setWindowTitle(all ? "All" : "Current");
    this->ui->label->setText(all ? "所有计算记录" : "当前计算记录");
    // 连接所有槽函数
    this->connects();
}

HistoryView::~HistoryView()
{
    delete ui;
}

// 根据给定的查询历史记录结果具体构造页面
void HistoryView::page_create(QVector<QVector<QString>> res) {
    this->res = res;
    if (this->res.size() > 0) {
        // 设置 spinBox 的范围
        this->ui->spinBox->setRange(1, ceil(this->res.size() / one_page_rows)+1);
        // 加载第一页
        page_load();
    }
    else {
        this->ui->spinBox->setRange(0, 0);
    }
}

// 构建当前页面的表格
void HistoryView::page_load() {
    if (this->cur_page_id == 0) {
        return;
    }
    // 清除 tableWidget 中现有的数据
    this->ui->tableWidget->clearContents();
    this->ui->tableWidget->setRowCount(0);

    // 设置 tableWidget 的列数和表头
    this->ui->tableWidget->setColumnCount(3);
    QStringList headers;
    headers << "输入" << "结果" << "时间";
    this->ui->tableWidget->setHorizontalHeaderLabels(headers);

    // 向 tableWidget 中添加本页数据
    // 计算本页该有的起始 id 和结束 id
    int start_id = (this->cur_page_id-1) * one_page_rows;
    int end_id = start_id+one_page_rows;
    // 修正结束 id
    end_id = end_id <= this->res.size() ? end_id : this->res.size();
    this->ui->tableWidget->setRowCount(end_id-start_id);

    for (int i = start_id; i < end_id; i++) {
        // 获取当前行的数据
        QVector<QString> row = this->res[i];

        // 调试输出当前行的数据
        // qDebug() << "Row" << i << ":" << row;

        // 创建并设置每个单元格的值
        QTableWidgetItem *inputFormulaItem = new QTableWidgetItem(row[0]);
        QTableWidgetItem *calResultItem = new QTableWidgetItem(row[1]);
        QTableWidgetItem *timestampItem = new QTableWidgetItem(row[2]);

        // 设置单元格不可编辑但可选择和复制
        inputFormulaItem->setFlags(inputFormulaItem->flags() & ~Qt::ItemIsEditable);
        calResultItem->setFlags(calResultItem->flags() & ~Qt::ItemIsEditable);
        timestampItem->setFlags(timestampItem->flags() & ~Qt::ItemIsEditable);

        // 设置背景颜色，灰色和白色交替
        QColor backgroundColor = ((i&1)==0) ? QColor(230, 230, 230) : QColor(255, 255, 255);
        inputFormulaItem->setBackground(backgroundColor);
        calResultItem->setBackground(backgroundColor);
        timestampItem->setBackground(backgroundColor);

        // 将单元格添加到表格中
        this->ui->tableWidget->setItem(i-start_id, 0, inputFormulaItem);
        this->ui->tableWidget->setItem(i-start_id, 1, calResultItem);
        this->ui->tableWidget->setItem(i-start_id, 2, timestampItem);
    }
}

// 连接所有槽函数
void HistoryView::connects() {
    // 左翻页
    connect(this->ui->pushButton,
            &QPushButton::clicked,
            this,
            &HistoryView::turn_left);
    // 右翻页
    connect(this->ui->pushButton_2,
            &QPushButton::clicked,
            this,
            &HistoryView::turn_right);
    // 页数通过 spinbox 改变
    connect(this->ui->spinBox,
            &QSpinBox::valueChanged,
            this,
            &HistoryView::page_change);
}

// 左翻页
void HistoryView::turn_left() {
    // 已经在第一页了 那么就翻到最后一页
    if (this->ui->spinBox->value() == this->ui->spinBox->minimum()) {
        this->cur_page_id = this->ui->spinBox->maximum();
    }
    // 否则往前翻页
    else {
        this->cur_page_id--;
    }
    // 改变 SpinBox 大小并触发页面重载
    this->ui->spinBox->setValue(this->cur_page_id);
}

// 右翻页
void HistoryView::turn_right() {
    // 已经在最后一页了 那么就翻到第一页
    if (this->ui->spinBox->value() == this->ui->spinBox->maximum()) {
        this->cur_page_id = this->ui->spinBox->minimum();
    }
    // 否则往后翻页
    else {
        this->cur_page_id++;
    }
    // 改变 SpinBox 大小并触发页面重载
    this->ui->spinBox->setValue(this->cur_page_id);
}

// 页数通过 spinbox 改变
void HistoryView::page_change() {
    this->cur_page_id = this->ui->spinBox->value();
    page_load();
}
