#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QGraphicsScene>
#include <QPainter>
#include <QColor>
#include <battlefield.h>
#include <tank.h>
#include <game.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief on_exitButton_clicked event of the close button
     */
    void on_exitButton_clicked();
    /**
     * @brief initializeGUI
     */
    void initializeGUI();

private:
    Ui::MainWindow *ui;

    Game *m_game;
    QGraphicsScene *m_pScene;
};

#endif // MAINWINDOW_H
