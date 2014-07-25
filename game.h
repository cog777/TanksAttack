#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <tank.h>
#include <battlefield.h>
#include <settings.h>
#include <QPointer>
#include <QPoint>
#include <QTimer>
#include <bullet.h>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QPointer<QGraphicsScene> pScene, QObject *parent = 0);
    virtual ~Game();

signals:
    void finishedShoot();

public slots:
    void initialize();
    void shoot(const qint32 &x, const qint32 &y,
               const qint32 &targetX, const qint32 &targetY);

private slots:
    void moveBullet();

private:
    QPointer<QGraphicsScene> m_pScene;

    Tank *m_pTestTank;
    BattleField *m_pField;
    Bullet *m_pBullet;
    QTimer *m_pBulletTimer;

    QPoint m_source;
    QPoint m_target;
    qreal m_x;
    qreal m_y;
    bool m_leftToRight;
    bool m_upToDown;
    bool m_xIndex;
};

#endif // GAME_H
