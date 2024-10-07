#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QString>
#include <QVector>
#include <QPixmap>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = nullptr);
    ~HelpDialog();

private slots:
    // 设置当前页面内容
    void setDoc();
    // 绑定所有槽函数
    void connects();
    // 点击前一页
    void previous_clicked();
    // 点击后一页
    void next_clicked();

private:
    Ui::HelpDialog *ui;
    // Help 文档信息
    QVector<QVector<QString>> helpDocs = {{"1. 基本按键功能(1/3)",
                                           ":/rcs/help_1_1.png",
                                           R"(<p>如图所示，红色框线内的按钮是基本数据的输入区域，您可以自由地通过点击或快捷键输入想要的数据。</p>
<p>其中 <b>Ans</b> 按钮<b><font style="color: rgb(255, 165, 0);">(快捷键为Ctrl+A)</font></b>表示的是上一次的运算结果。默认值是0，您可以通过这个按钮方便地回调上一次的结果加入下一次的运算中。</p>
<p>此外，需要注意的是，小数点的输入需要遵循以下规则：</p>
<ul>
    <li>不能输入连续的小数点。<br/></li>
    <li>不能在一个浮点数中出现多个小数点</li>
</ul>
<p><b>但是</b>，孤立的小数点是被允许的，它会被视作0处理。</p>)"},
                                          {"1. 基本按键功能(2/3)",
                                           ":/rcs/help_1_2.png",
                                           R"(<p>如图所示，红色框线内是一些操作符按钮以及两个特殊常数按钮。</p>
<p>首先您可以通过点击 π 输入圆周率，或点击 e 输入自然数<b><font style="color: rgb(255, 165, 0);">(快捷键分别是 P 和 E )</font>。</p>
<p>接着您可以通过点击剩下的操作符按钮或按下对应快捷键来完成运算式的构建。完整的快捷键一览表请点击主页面的 About->About 查看。</p>)"},
                                          {"1. 基本按键功能(3/3)",
                                           ":/rcs/help_1_3.png",
                                           R"(<p>如图所示，红色框线内是一些特殊的操作符。</p>
<p>其中:</p>
<ul>
    <li>大写的E按钮是错误自检按钮<b><font style="color: rgb(255, 165, 0);">(快捷键为Ctrl+E)</font></b>，能够帮您检查括号是否正确输入、以及是否有连续输入的运算符等错误输入并标红提示。<br/></li>
    <li>←按钮为退格按钮<b><font style="color: rgb(255, 165, 0);">(快捷键为键盘上的退格键)</font></b>，能够删掉上一个输入的数字/操作符。<br/></li>
    <li>大写的C按钮是清空按钮<b><font style="color: rgb(255, 165, 0);">(快捷键为Ctrl+C)</font></b>，能够清除所有输入。<br/></li>
    <li>=按钮是计算按钮<b><font style="color: rgb(255, 165, 0);">(快捷键为回车Enter)</font></b>，能够计算输入的表达式。</li>
</ul>)"},
                                          {"2. 菜单功能使用(1/5)",
                                           ":/rcs/help_2_1.png",
                                           R"(<p>如图所示，红色框线内的菜单选项 Mode 可以调整计算器的计算模式。</p>
<p>其中:</p>
<ul>
    <li>第一个选项可以实现普通计算模式与包含8个函数计算的科学计算模式切换。<b><font style="color: rgb(255, 165, 0);">(快捷键为Alt+S)</font></b><br/></li>
    <li>第二个选项是切换到复数计算模式（待实现）。<br/></li>
    <li>第三个选项是进行随机的计算练习（待实现）。</li>
</ul>)"},
                                          {"2. 菜单功能使用(2/5)",
                                           ":/rcs/help_2_2.png",
                                           R"(<p>如图所示，红色框线内的菜单选项 Style 可以调整计算器的外观风格。</p>
<p>其中:</p>
<ul>
    <li>提供了三个预设的外观风格，Light（白色背景+彩色按钮），Dark（深色外观），Blue（蓝+粉外观）。<br/></li>
    <li>设置的外观风格会被存储在.ini初始化文件中，下次打开时会是上次设置的风格。<br/></li>
    <li>您可以参考开发者手册方便地向软件中添加各种您想要的外观风格方案。</li>
</ul>)"},
                                          {"2. 菜单功能使用(3/5)",
                                           ":/rcs/help_2_3.png",
                                           R"(<p>如图所示，红色框线内的菜单选项 History 可以调出计算历史记录。</p>
<p>其中:</p>
<ul>
    <li>Current History是本次打开计算器的所有计算记录<b><font style="color: rgb(255, 165, 0);">(快捷键为H)</font></b>。<br/></li>
    <li>All History是下载本计算器以来的所有计算记录<b><font style="color: rgb(255, 165, 0);">(快捷键为Alt+H)</font></b>。<br/></li>
    <li>您还可以通过键盘上的上下按钮来直接调用计算记录。</li>
</ul>)"},
                                          {"2. 菜单功能使用(4/5)",
                                           ":/rcs/help_2_4.png",
                                           R"(<p>如图所示，红色框线内的菜单选项 Settings 可以进行各种相关的设置。</p>
<p>其中:</p>
<ul>
    <li>Angle Mode是所期望使用的角度单位，Deg代表度数，Rad代表弧度制。角度单位会被记忆，即下次打开的角度单位是上次设置的。<br/></li>
    <li>Style DIY是能够直接修改各按钮和软件背景的颜色设置盘（待实现）。<br/></li>
    <li>System Settings是一些更深入的软件配置，比如计算精度等（待实现）。</li>
</ul>)"},
                                          {"2. 菜单功能使用(5/5)",
                                           ":/rcs/help_2_5.png",
                                           R"(<p>如图所示，红色框线内的菜单选项 About 可以获得各种软件信息。</p>
<p>其中:</p>
<ul>
    <li>About是软件简介，类似ReadMe，可以帮助您快速了解本软件。<br/></li>
    <li>Help是软件详细的使用说明，可以帮助您详细地了解本软件。<br/></li>
    <li>Contact us是反馈渠道，点击会自动跳转邮件发送，您可以通过这种方式联系我。</li>
</ul>)"}};
};

#endif // HELPDIALOG_H
