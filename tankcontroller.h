#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include <QObject>
#include "settings.h"
#include <QVector>
#include <QPoint>
/**
 * @brief The TankController class
 * Controls the players represented by a tank on GUI
 */
class TankController : public QObject
{
    Q_OBJECT
public:
    explicit TankController(QObject *parent = 0);
    virtual ~TankController();

    QPoint getPos() const;

signals:
    void lookAround();
    void moveTo(const directionType &direction);
    void shoot(const QPoint &coord);

public slots:
    void getResultForLookAround(const QVector<QVector<fieldType> > &field);
    void setPos(const QPoint &ownPos);
    virtual void run() = 0;

protected:
    QVector<QVector<fieldType> > m_battleField;
    QPoint m_ownPosition;
    QPoint m_enemyPosition;
};

#endif // TANKCONTROLLER_H
