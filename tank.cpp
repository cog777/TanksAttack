#include "tank.h"

Tank::Tank(const qreal fieldGridSize, const qreal fieldSizeX,
           const qreal fieldSizeY, QColor tankColor, const int startPosX,
           const int startPosY, QGraphicsObject *parent)
    : m_fGridSize(fieldGridSize), m_fSizeX(fieldSizeX), m_fSizeY(fieldSizeY),
      m_tankColor(tankColor), m_posX(startPosX), m_posY(startPosY)
{
    setGridPos(m_posX, m_posY);
}

Tank::~Tank()
{}

QRectF Tank::boundingRect() const
{
    return QRectF(0, 0, m_fGridSize, m_fGridSize);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(m_tankColor);
    painter->drawRect(m_fGridSize / 4, ((m_fGridSize / 4) / 2),
                      (m_fGridSize - ((m_fGridSize / 4) * 2)),
                      (m_fGridSize - (((m_fGridSize / 4) / 2) * 2)));

    painter->drawEllipse(QPointF(m_fGridSize / 2, m_fGridSize / 2), m_fGridSize / 5, m_fGridSize / 5);

    painter->drawLine(m_fGridSize / 2, ((m_fGridSize / 2) + (m_fGridSize / 5)),
                      m_fGridSize / 2, m_fGridSize);
}

void Tank::setGridPos(int posX, int posY)
{
    if((posX > m_fSizeX) && (posY > m_fSizeY))
        return;

    if(posX != 1) posX -= 1;
    if(posY != 1) posY -= 1;
    setPos(m_fGridSize * posX, m_fGridSize * posY);
}
