#include "tankcontroller.h"

TankController::TankController(QObject *parent) :
    QObject(parent)
{
}

TankController::~TankController()
{

}

QPoint TankController::getPos() const
{
    return m_ownPosition;
}

void TankController::getResultForLookAround(const QVector<QVector<fieldType> > &field)
{
    m_battleField = field;
}

void TankController::setPos(const QPoint &ownPos)
{
    m_ownPosition = ownPos;
}
