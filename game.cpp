#include "game.h"

Game::Game(QPointer<QGraphicsScene> pScene, QObject *parent) :
    QObject(parent), m_pScene(pScene)
{}

Game::~Game()
{
    m_bTimer->stop();
}

void Game::initialize()
{
    m_bTimer = new QTimer(this);
    m_field = new BattleField(QColor("lightblue"), FSIZEX, FSIZEY, FCELLSIZE);
    m_testTank = new Tank("red", 1, 2);
    m_testBullet = new Bullet();

    connect(m_bTimer, SIGNAL(timeout()), this, SLOT(moveTestBullet()));

    m_bTimer->start(500);

    m_pScene->addItem(m_field);
    m_pScene->addItem(m_testTank);
    m_pScene->addItem(m_testBullet);
}

void Game::moveTestBullet()
{
    m_testBullet->moveBy(1, 1);
}
