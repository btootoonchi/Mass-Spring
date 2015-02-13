#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect the timer timeout signal to the simStep slot and start the timer.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), ui->glwidget, SLOT(simStep()));

    // Set the timer interrupts to 50 miliseconds.
    timer->start(50);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_MassValue_valueChanged(double mass)
{
    Weight *w = ui->glwidget->getWeight();
    w->setMass(mass);
}

void MainWindow::on_StiffnessValue_valueChanged(double ks)
{
    Spring *s = ui->glwidget->getSpring();
    s->setSpringConstant(ks);
}

void MainWindow::on_TimeStepValue_valueChanged(double delta)
{
    ui->glwidget->setDelta(delta);
}

void MainWindow::on_RestLengthValue_valueChanged(double len)
{
    Spring *s = ui->glwidget->getSpring();
    Weight *w = ui->glwidget->getWeight();
    GLdouble restLen = len * ui->glwidget->getUnitLen();
    s->setRestLength(restLen);
    s->setLength(restLen);
    w->resetState(restLen);
}


void MainWindow::on_restartButton_clicked()
{
    // Reset the position of the spring.
    ui->glwidget->getSpring()->setLength(ui->glwidget->getSpring()->getRestLength());

    // Reset the position of the weight.
    ui->glwidget->getWeight()->resetState(ui->glwidget->getSpring()->getRestLength());

    // Draw the initial state.
    ui->glwidget->repaint();

    //Restart the simulation after 1s.
    QThread::sleep(1);
}
