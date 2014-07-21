#include "gamecontroller.h"

GameController::GameController(QObject *parent) :
    QObject(parent), m_index(0)
{
}

void GameController::addTankList(const QList<QPointer<TankInfo> > &tankList)
{
    m_tankList = tankList;
}

void GameController::run()
{

}
