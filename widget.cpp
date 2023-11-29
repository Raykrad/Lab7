#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
    rect(0, 0, 100, 100),
    move(false)
{
}

void Widget::paintEvent(QPaintEvent* action)
{
    QPainter paint(this);
    paint.setBrush(QBrush(Qt::green));
    paint.drawRect(rect);
}

void Widget::mousePressEvent(QMouseEvent* action)
{
    lastMove = action->pos();
    move = rect.contains(lastMove);
}

void Widget::mouseMoveEvent(QMouseEvent* action)
{
    if (!move)
        return;
    const QPoint curPoint = action->pos();
    const QPoint difference = curPoint - lastMove;
    rect.moveTo(rect.topLeft() + difference);
    lastMove = action->pos();
    update();
}

void Widget::mouseReleaseEvent(QMouseEvent* action)
{
    move = false;
}
