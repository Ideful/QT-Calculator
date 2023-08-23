#ifndef ENTERPROCESSOR_H
#define ENTERPROCESSOR_H
#include <QWidget>
#include <QKeyEvent>

class enterprocessor:public QWidget
{

protected:
    void keyPressEvent(QKeyEvent* event) override;
};

#endif // ENTERPROCESSOR_H
