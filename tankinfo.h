#ifndef TANKINFO_H
#define TANKINFO_H
#include "tankcontroller.h"
#include <QPointer>

struct TankInfo
{
    TankInfo()
    {
        m_actionPoint = m_armor = 0;
    }

    qint32 m_actionPoint;
    qint32 m_armor;
    QPointer<TankController> m_pTank;
};

#endif // TANKINFO_H
