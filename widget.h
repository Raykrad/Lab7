#pragma once
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget* parent = nullptr);

    void paintEvent(QPaintEvent *action) override;
    void mousePressEvent(QMouseEvent *action) override;
    void mouseMoveEvent(QMouseEvent *action) override;
    void mouseReleaseEvent(QMouseEvent *action) override;

private:
    QRect rect;
    QPoint lastMove;
    bool move;
};
