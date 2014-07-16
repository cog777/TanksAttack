#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "settings.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer::singleShot(0, this, SLOT(initializeGUI()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exitButton_clicked()
{
    close();
}

void MainWindow::initializeGUI()
{
    m_scene = new QGraphicsScene(this);
    m_field = new BattleField(QColor(FCOLOR), FSIZEX, FSIZEY, FCELLSIZE);
    m_testTank = new Tank("red", 1, 2); // Adam: 0-val kezdeni a koordinatat elterjedt a programozasban

    m_scene->addItem(m_field);
    m_scene->addItem(m_testTank);

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
}
