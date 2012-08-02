#ifndef QSQUAREPUSHBUTTON_H
#define QSQUAREPUSHBUTTON_H

#include <QPushButton>

class QSquarePushButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QSquarePushButton(QWidget *parent = 0);
    QSize sizeHint() const;
    
signals:
    
public slots:
    
};

#endif // QSQUAREPUSHBUTTON_H
