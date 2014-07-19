#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QPointer>
#include <tank.h>
#include <battlefield.h>
#include <settings.h>
#include <QPointer>
#include <QTimer>
#include <bullet.h>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QPointer<QGraphicsScene> pScene, QObject *parent = 0);
    virtual ~Game();

signals:

public slots:
    void initialize();

private slots:
    void moveTestBullet();

private:
    QPointer<QGraphicsScene> m_pScene;

    Tank *m_testTank;
    BattleField *m_field;
    Bullet *m_testBullet;
    QTimer *m_bTimer;
};

#endif // GAME_H
