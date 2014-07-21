#include "bullet.h"

const qreal BULLETSIZE = FCELLSIZE / 35;

Bullet::Bullet(QGraphicsObject *parent)
{}

Bullet::~Bullet()
{}

QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, BULLETSIZE, BULLETSIZE);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(QColor("black"));
    painter->drawEllipse(QPointF(BULLETSIZE / 2, BULLETSIZE / 2), BULLETSIZE, BULLETSIZE);
}
