#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "tankinfo.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QObject *parent = 0);
    void addTankList(const QList<QPointer<TankInfo> > &tankList);
    void run();

signals:

public slots:
private:
    QList<QPointer<TankInfo> > m_tankList;
    qint32 m_index;
};

#endif // GAMECONTROLLER_H
