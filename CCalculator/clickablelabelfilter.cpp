#include "clickablelabelfilter.h"

bool ClickableLabelFilter::eventFilter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            QLabel *label = qobject_cast<QLabel *>(watched);
            if (label) {
                emit labelClicked(label);
                return true; // 事件已处理
            }
        }
    }
    return QObject::eventFilter(watched, event); // 继续处理其他事件
}
