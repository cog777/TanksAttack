#ifndef SETTINGS_H
#define SETTINGS_H

// Adam: Olyan gyakran hasznalt valtozokat teszunk ide, amelyek sok helyen elofordulnak.
// Pl a csatamezonel szintugy mint a tank osztalynal. Ezert nem kell atadni parameterkent
// ezeket a valtozokat, eleg ha include-olod.

// For battlefield
const QString FCOLOR = "lightblue";
const qreal FSIZEX = 8;
const qreal FSIZEY = 7;
const qreal FCELLSIZE = 50;

// For tankcontroller
enum fieldType{EMPTY, PLAYER1, PLAYER2};
enum directionType{UP, DOWN, LEFT, RIGHT};
const qint32 SHOOTRANGE = 3;
const qint32 RADAR_RANGE = 5;
#endif // SETTINGS_H
