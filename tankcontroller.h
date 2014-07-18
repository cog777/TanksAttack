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
    void getResultForLookAround(const QVector<QVector<fieldType> > &field);

private:
    QVector<QVector<fieldType> > m_battleField;
};

#endif // TANKCONTROLLER_H
