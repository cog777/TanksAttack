#include "game.h"

Game::Game(QPointer<QGraphicsScene> pScene, QObject *parent) :
    QObject(parent), m_pScene(pScene)
{}

Game::~Game()
{}

void Game::initialize()
{
    m_pBulletTimer = new QTimer(this);
    m_pField = new BattleField(QColor("lightblue"), FSIZEX, FSIZEY, FCELLSIZE);
    m_pTestTank = new Tank("red", 1, 2);
    m_pBullet = new Bullet();

    connect(m_pBulletTimer, SIGNAL(timeout()), this, SLOT(moveBullet()));

    m_pScene->addItem(m_pField);
    m_pScene->addItem(m_pTestTank);

    shoot(1, 2, 4, 3);
}

void Game::shoot(const qint32 &x, const qint32 &y,
                 const qint32 &targetX, const qint32 &targetY)
{
    m_source.setX((x * FCELLSIZE) + (FCELLSIZE / 2));
    m_source.setY((y * FCELLSIZE) + (FCELLSIZE / 2));
    m_target.setX((targetX * FCELLSIZE) + (FCELLSIZE / 2));
    m_target.setY((targetY * FCELLSIZE) + (FCELLSIZE / 2));

    m_pBulletTimer->start(200);
    m_pScene->addItem(m_pBullet);

    if (qAbs(m_source.x() - m_target.x()) > qAbs(m_source.y() - m_target.y())) m_xIndex = true;
    else m_xIndex = false;

    if (m_source.x() < m_target.x()) m_leftToRight = true;
    else m_leftToRight = false;

    if(m_source.y() < m_target.y()) m_upToDown = true;
    else m_upToDown = false;

    m_x = m_source.x();
    m_y = m_source.y();
}

void Game::moveBullet()
{
    if(m_xIndex)
    {
        qreal y = (((m_x - m_source.x()) * (m_target.x() - m_target.x())) / (m_y - m_source.x())) + m_y;

        if(m_leftToRight && m_x > m_target.x()) m_pBulletTimer->stop();
        else if(m_x < m_target.x()) m_pBulletTimer->stop();

        m_pBullet->setPos(m_x, y);

        if(m_leftToRight) m_x++;
        else m_x--;
    }
    else
    {
        qreal x = (m_y * (m_target.x() - m_source.x()) - m_source.y()) / (m_target.y() - m_source.y()) + m_target.x();

        if(m_upToDown && m_y > m_target.y()) m_pBulletTimer->stop();
        else if(m_y < m_target.y()) m_pBulletTimer->stop();

        m_pBullet->setPos(x, m_y);

        if(m_upToDown) m_y++;
        else m_y--;
    }
}
