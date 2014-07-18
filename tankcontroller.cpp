#include "tankcontroller.h"

TankController::TankController(QObject *parent) :
    QObject(parent)
{
}

TankController::~TankController()
{

}

void TankController::getResultForLookAround(const QVector<QVector<fieldType> > &field)
{
    m_battleField = field;
}
