#include "tank.h"
#include "settings.h"

Tank::Tank(QColor tankColor, const int startPosX,
           const int startPosY, QGraphicsObject *parent)
    : m_fGridSize(FGRIDSIZE), m_fSizeX(FSIZEX), m_fSizeY(FSIZEY),
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
        static qreal halfSize = m_fGridSize / 2;
        static qreal quarterSize = m_fGridSize / 4;
        static qreal oneEightSize = m_fGridSize / 8;

        painter->drawRect(quarterSize, // egy cella negyede, x koordinata
                          oneEightSize, // y koordinata
                          halfSize, // :) cella meret fele (m_fGridSize - ((m_fGridSize / 4) * 2)) = m_fGridSize / 2
                          m_fGridSize - quarterSize);
    }
    painter->drawEllipse(QPointF(m_fGridSize / 2, m_fGridSize / 2), m_fGridSize / 5, m_fGridSize / 5);

    painter->drawLine(m_fGridSize / 2, ((m_fGridSize / 2) + (m_fGridSize / 5)),
                      m_fGridSize / 2, m_fGridSize);
}

void Tank::setGridPos(int posX, int posY)
{
    if((posX > m_fSizeX) && (posY > m_fSizeY))
        return;

    //    if(posX != 1) posX -= 1;
    //    if(posY != 1) posY -= 1;
    setPos(m_fGridSize * posX, m_fGridSize * posY);
}
