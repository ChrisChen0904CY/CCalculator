#include "settingpage.h"
#include "ui_settingpage.h"

SettingPage::SettingPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingPage)
{
    ui->setupUi(this);
}

SettingPage::SettingPage(QWidget *parent, QMap<QString, QString> sysParam)
    : QWidget(parent)
    , ui(new Ui::SettingPage)
{
    ui->setupUi(this);
    this->sysParam = sysParam;
    // 添加搜索按钮
    hbox = new QHBoxLayout();
    searchButton = new QPushButton();
    searchButton->setFixedSize(30, 30);
    searchButton->setStyleSheet(
        "QPushButton {"
        "border: none;"
        "background-color: transparent;}"
        "QPushButton:hover {"
        "background-color: rgba(173, 216, 230, 70);}"
    );
    searchButton->setCursor(Qt::PointingHandCursor);
    searchButton->setIcon(QIcon(":/rcs/search.png"));
    hbox->addStretch();
    hbox->addWidget(searchButton);
    hbox->setAlignment(Qt::AlignCenter);
    hbox->setContentsMargins(0, 0, 0, 0);
    this->ui->lineEdit->setLayout(hbox);

    // 开始搜索
    connect(searchButton,
            &QPushButton::clicked,
            this,
            &SettingPage::search);

    // 字体设置
    QFont font = this->ui->treeWidget->headerItem()->font(0);
    font.setPointSize(10);
    // 添加树状结构
    // 计算设置
    QTreeWidgetItem *item1 = new QTreeWidgetItem(this->ui->treeWidget,
                                                 QStringList() << "计算设置");
    QTreeWidgetItem *subItem1 = new QTreeWidgetItem(item1, QStringList() << "精度&算法");
    QTreeWidgetItem *subItem2 = new QTreeWidgetItem(item1, QStringList() << "结果显示");

    // 添加到QVector便于释放和管理
    items.append(item1);
    items.append(subItem1);
    items.append(subItem2);

    // 默认展开所有设置选项
    this->ui->treeWidget->expandAll();

    // 删除默认页面
    this->ui->stackedWidget->removeWidget(this->ui->page);
    this->ui->stackedWidget->removeWidget(this->ui->page_2);

    // 设置精度和算法的设置页面
    precisionPage = new PrecisionPage(nullptr, {sysParam["precision"]});
    this->ui->stackedWidget->addWidget(precisionPage);

    // 设置显示方法的设置页面
    resDisplayPage = new ResDisplayPage(nullptr, {sysParam["resDisplayMode"],
                                                  sysParam["suffixZero"],
                                                  sysParam["ePower"]});
    this->ui->stackedWidget->addWidget(resDisplayPage);

    // 批量设置字体
    for(auto item:items) {
        item->setFont(0, font);
    }

    // 页面切换槽函数绑定
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, [this](QTreeWidgetItem *item) {
        if (item == items[0]) { // item1
            ui->stackedWidget->setCurrentWidget(precisionPage);
        } else if (item == items[1]) { // subItem1
            ui->stackedWidget->setCurrentWidget(precisionPage);
        } else if (item == items[2]) { // subItem2
            ui->stackedWidget->setCurrentWidget(resDisplayPage);
        }
    });

    connects();
}

SettingPage::~SettingPage()
{
    delete ui;
}

void SettingPage::connects() {
    // 参数设置
    connect(this->ui->pushButton,
            &QPushButton::clicked,
            this,
            &SettingPage::settingApply);
    connect(this->ui->pushButton_2,
            &QPushButton::clicked,
            this,
            &SettingPage::settingConfirm);
    // 精度设置页面参数更新
    connect(this->precisionPage,
            &PrecisionPage::sysUpdate,
            this,
            &SettingPage::sysUpdate);
    // 显示设置页面参数更新
    connect(this->resDisplayPage,
            &ResDisplayPage::sysUpdate,
            this,
            &SettingPage::sysUpdate);
    // 搜索条目
    connect(this,
            &SettingPage::searchTextConfirmed,
            this,
            &SettingPage::filterItems);
    // 清空时复原
    connect(this->ui->lineEdit,
            &QLineEdit::textChanged,
            this,
            &SettingPage::resetItems);
}

void SettingPage::sysUpdate(QPair<QString, QString> sys) {
    sysParam[sys.first] = sys.second;
}

// 应用当前设置
void SettingPage::settingApply() {
    emit sysParaChanged(this->sysParam);
}

// 应用当前设置并关闭窗口
void SettingPage::settingConfirm() {
    emit sysParaChanged(this->sysParam);
    this->close();
}

void SettingPage::hideItemsNotMatching(QTreeWidgetItem *item, const QString &text) {
    bool hasVisibleChild = false;

    for (int i = 0; i < item->childCount(); ++i) {
        QTreeWidgetItem *child = item->child(i);
        hideItemsNotMatching(child, text);
        if (!child->isHidden()) {
            hasVisibleChild = true;
        }
    }

    item->setHidden(!hasVisibleChild && !item->text(0).contains(text, Qt::CaseInsensitive));
}

void SettingPage::showAllItems(QTreeWidgetItem *item) {
    item->setHidden(false);
    for (int i = 0; i < item->childCount(); ++i) {
        showAllItems(item->child(i));
    }
}

// 开始搜索
void SettingPage::search() {
    emit searchTextConfirmed(this->ui->lineEdit->text());
}

// 搜索条目
void SettingPage::filterItems(const QString &text) {
    if (text.isEmpty()) {
        showAllItems(this->ui->treeWidget->invisibleRootItem());
    } else {
        hideItemsNotMatching(this->ui->treeWidget->invisibleRootItem(), text);
    }
}

// 复原所有条目
void SettingPage::resetItems() {
    if (this->ui->lineEdit->text().isEmpty()) {
        showAllItems(this->ui->treeWidget->invisibleRootItem());
    }
}
