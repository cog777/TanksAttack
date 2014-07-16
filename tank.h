#ifndef TANK_H
#define TANK_H

#include <QGraphicsObject>
#include <QPainter>
#include <QColor>

class Tank : public QGraphicsObject
{
public:
    Tank(QColor tankColor,
         const qint32 &startPosX,
         const qint32 &startPosY,
         QGraphicsObject *parent = 0);
    virtual ~Tank();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

private:
    qreal m_fCellSize, m_fSizeX, m_fSizeY;
    QColor m_tankColor;
    qint32 m_posX, m_posY;

public slots:
    void setGridPos(const qint32 &posX, const qint32 &posY);
};

#endif // TANK_H
