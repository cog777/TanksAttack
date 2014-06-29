#include "battlefield.h"

BattleField::BattleField(const QColor &gridColor, const qreal &sizeX, const qreal &sizeY, const qreal &gridSize, QGraphicsItem *parent)
    : m_gridColor(gridColor), m_sizeX(sizeX), m_sizeY(sizeY), m_gridSize(gridSize)
{
}

BattleField::~BattleField()
{
}

QRectF BattleField::boundingRect() const
{
    return QRectF(0, 0, m_sizeX * m_gridSize, m_sizeY * m_gridSize);
}

void BattleField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(m_gridColor);
    for(int i = 0; i < m_sizeY; i++)
    {
        for(int j = 0; j < m_sizeX; j++)
        {
            painter->drawRoundedRect(QRectF(j * m_gridSize, i * m_gridSize, m_gridSize, m_gridSize), 3, 3);
        }
    }
}
