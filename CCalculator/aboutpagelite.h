#ifndef ABOUTPAGELITE_H
#define ABOUTPAGELITE_H

#include <QWidget>
#include <QFile>

namespace Ui {
class AboutPage;
}

class AboutPageLite : public QWidget
{
    Q_OBJECT

public:
    explicit AboutPageLite(QWidget *parent = nullptr);
    explicit AboutPageLite(QWidget *parent = nullptr, QString htmlFile="about.html");
    ~AboutPageLite();
    void ui_init();

private:
    Ui::AboutPage *ui;

};

#endif // ABOUTPAGELITE_H
