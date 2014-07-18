#include "game.h"

Game::Game(QPointer<QGraphicsScene> pScene, QObject *parent) :
    QObject(parent), m_pScene(pScene)
{}

Game::~Game()
{}

void Game::initialize()
{
    m_field = new BattleField(QColor("lightblue"), FSIZEX, FSIZEY, FCELLSIZE);
    m_testTank = new Tank("red", 1, 2);
    m_testBullet = new Bullet();

    m_pScene->addItem(m_field);
    m_pScene->addItem(m_testTank);
    m_pScene->addItem(m_testBullet);
}
