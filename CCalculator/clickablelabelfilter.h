#ifndef CLICKABLELABELFILTER_H
#define CLICKABLELABELFILTER_H

#include <QObject>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QDebug>

class ClickableLabelFilter : public QObject
{
    Q_OBJECT
public:
    explicit ClickableLabelFilter(QObject *parent = nullptr) : QObject(parent) {}

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

signals:
    void labelClicked(QLabel *label);
};


#endif // CLICKABLELABELFILTER_H
