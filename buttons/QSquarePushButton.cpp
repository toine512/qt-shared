#include "QSquarePushButton.h"

QSquarePushButton::QSquarePushButton(QWidget *parent) :
    QPushButton(parent)
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
}

QSize QSquarePushButton::sizeHint() const
{
    QSize size = QPushButton::sizeHint();
    size.setWidth(height());
    return size;
}
