#ifndef TANKCONTROLLER_H
#define TANKCONTROLLER_H

#include <QObject>
#include "settings.h"
#include <QVector>
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

signals:
    void lookAround();
public slots:
    void getResultForLookAround();
};

#endif // TANKCONTROLLER_H
