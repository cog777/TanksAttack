#include "tank.h"
#include "settings.h"

Tank::Tank(QColor tankColor, const qint32 &startPosX,
           const qint32 &startPosY, QGraphicsObject *parent)
    : m_fCellSize(FCELLSIZE), m_fSizeX(FSIZEX), m_fSizeY(FSIZEY),
      m_tankColor(tankColor), m_posX(startPosX), m_posY(startPosY)
{
    setGridPos(m_posX, m_posY);
}

Tank::~Tank()
{}

QRectF Tank::boundingRect() const
{
    return QRectF(0, 0, m_fCellSize, m_fCellSize);
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(m_tankColor);
    // Adam:  A szamolas jo, de ahogyan emlitetted, optimalizalhatjuk a dolgot.
    // (m_fGridSize / 4) / 2 -> m_fGridSize / 8

    //    painter->drawRect(m_fGridSize / 4, // egy cella negyede, x koordinata
    //                      ((m_fGridSize / 4) / 2), // y koordinata
    //                      (m_fGridSize - ((m_fGridSize / 4) * 2)), // :) cella meret fele (m_fGridSize - ((m_fGridSize / 4) * 2)) = m_fGridSize / 2
    //                      (m_fGridSize - (((m_fGridSize / 4) / 2) * 2)));

    // Optimalizalt verzio:
    // Csinalsz egy blokkot, az ebben letrehozott valtozokat senki nem lathatja
    // Lasd adatrejtes elve. Igy igyekszunk modularizalni a dolgokat, kevesebb a hibalehetoseg
    {
        // static: megorzi a valtozo erteket 2 metodus hivas kozott is.
        // pl: static valtozo = 5; Igy a kezdo erteke 5 lesz.
        static qreal halfSize = m_fCellSize / 2;
        static qreal quarterSize = m_fCellSize / 4;
        static qreal oneEightSize = m_fCellSize / 8;

        painter->drawRect(quarterSize, // egy cella negyede, x koordinata
                          oneEightSize, // y koordinata
                          halfSize, // :) cella meret fele (m_fGridSize - ((m_fGridSize / 4) * 2)) = m_fGridSize / 2
                          m_fCellSize - quarterSize);
    }
    painter->drawEllipse(QPointF(m_fCellSize / 2, m_fCellSize / 2), m_fCellSize / 5, m_fCellSize / 5);

    painter->setPen(QPen(QColor("black"), FCELLSIZE / 32));
    painter->drawLine(m_fCellSize / 2, ((m_fCellSize / 2) + (m_fCellSize / 5)),
                      m_fCellSize / 2, m_fCellSize);
}

void Tank::setGridPos(const qint32 &posX, const qint32 &posY)
{
    if((posX > m_fSizeX) && (posY > m_fSizeY))
        return;

    //    if(posX != 1) posX -= 1;
    //    if(posY != 1) posY -= 1;
    setPos(m_fCellSize * posX, m_fCellSize * posY);
}
