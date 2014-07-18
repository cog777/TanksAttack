#include "battlefield.h"

BattleField::BattleField(const QColor &gridColor, const qreal &sizeX, const qreal &sizeY, const qreal &cellSize, QGraphicsItem *parent)
    : m_gridColor(gridColor), m_sizeX(sizeX), m_sizeY(sizeY), m_cellSize(cellSize)
{
}

BattleField::~BattleField()
{
}

QRectF BattleField::boundingRect() const
{
    return QRectF(0, 0, m_sizeX * m_cellSize, m_sizeY * m_cellSize);
}

void BattleField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(m_gridColor);
    for(int i = 0; i < m_sizeY; i++)
    {
        for(int j = 0; j < m_sizeX; j++)
        {
            painter->drawRoundedRect(QRectF(j * m_cellSize, i * m_cellSize, m_cellSize, m_cellSize), 3, 3);
        }
    }
}
