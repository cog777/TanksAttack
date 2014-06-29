#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QColor>

class BattleField : public QGraphicsItem
{
public:
    BattleField(const QColor &gridColor, const qreal &sizeX, const qreal &sizeY, const qreal &gridSize, QGraphicsItem *parent = 0);
    virtual ~BattleField();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal m_sizeX, m_sizeY, m_gridSize;
    QColor m_gridColor;
};

#endif // BATTLEFIELD_H
