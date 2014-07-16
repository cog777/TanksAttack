#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>
#include <QPainter>
#include <QColor>

class Tank : public QGraphicsObject
{
public:
    Tank(QColor tankColor,
         const int startPosX,
         const int startPosY,
         QGraphicsObject *parent = 0);
    virtual ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    qreal m_fGridSize, m_fSizeX, m_fSizeY;
    QColor m_tankColor;
    int m_posX, m_posY;

public slots:
    void setGridPos(int posX, int posY);
};

#endif // TANK_H
