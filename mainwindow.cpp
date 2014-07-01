#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString fColor = "lightblue";
const qreal fSizeX = 8;
const qreal fSizeY = 7;
const qreal fGridSize = 50;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(ui->graphicsView);
    field = new BattleField(QColor(fColor), fSizeX, fSizeY, fGridSize);

    scene->addItem(field);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
