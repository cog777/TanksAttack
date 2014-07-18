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
    m_pScene = new QGraphicsScene(this);
    m_game = new Game(m_pScene, this);
    m_game->initialize();

    ui->graphicsView->setScene(m_pScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing, true);
}
