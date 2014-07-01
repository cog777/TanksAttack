#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

const QString FCOLOR = "lightblue";
const qreal FSIZEX = 8;
const qreal FSIZEY = 7;
const qreal FGRIDSIZE = 50;


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
    m_field = new BattleField(QColor(FCOLOR), FSIZEX, FSIZEY, FGRIDSIZE);

    m_scene->addItem(m_field);

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
}
