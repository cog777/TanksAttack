#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsObject>
#include <QPainter>
#include <settings.h>

const qreal BULLETSIZE = FCELLSIZE / 21;

class Bullet : public QGraphicsObject
{
public:
    Bullet(QGraphicsObject *parent = 0);
    virtual ~Bullet();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BULLET_H
