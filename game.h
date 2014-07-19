#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QPointer>
#include <tank.h>
#include <battlefield.h>
#include <settings.h>
#include <QPointer>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QPointer<QGraphicsScene> pScene, QObject *parent = 0);
    virtual ~Game();

signals:

public slots:
    void initialize();

private:
    QPointer<QGraphicsScene> m_pScene;

    Tank *m_testTank;
    BattleField *m_field;
};

#endif // GAME_H
