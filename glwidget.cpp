#include "glwidget.h"

#include <math.h>
#include <iostream>
#include <stdio.h>

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget( parent ), GRAVITY(-9.8), _unitLen(-0.1), _delta(0.05) {
    spring = new Spring(_unitLen);
    weight = new Weight(spring->getRestLength());
}

GLWidget::~GLWidget() {
    delete spring;
    delete weight;
}

void GLWidget::initializeGL() {
    static const GLfloat lightPos[4] = { 2.0f, 2.0f, 2.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 60.0, 1.0, 0.5, 10.0 );
    gluLookAt( 0.0, -1.8, 5.0, 0.0, -2.7, 0.0, 0.0, 1.0, 0.0 );

    //Draw spring mass system
    weight->draw();
    spring->draw(_unitLen);
}

void GLWidget::resizeGL( int width, int height ) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 60.0, 1.0, 0.5, 10.0 );
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    updateGL();
}

Weight* GLWidget::getWeight()
{
    return weight;
}

Spring* GLWidget::getSpring()
{
    return spring;
}

GLdouble GLWidget::getUnitLen() {
    return _unitLen;
}

GLdouble GLWidget::getDelta() {
    return _delta;
}

void GLWidget::setDelta(GLdouble delta) {
    _delta = delta;
}

GLdouble GLWidget::springForce() {
    GLdouble ks, lt, l0;
    ks = spring->getSpringConstant();
    lt = spring->getLength();
    l0 = spring->getRestLength();

    // spring force = -spring constant * spring length change
    return (-ks * (lt - l0));
}

GLdouble GLWidget::dampingForce() {
    GLdouble kd, v;
    kd = spring->getDampingCoefficient();
    v = weight->getVelocity();

    // damping force = -damping coefficient * velocity
    return (-kd * v);
}

GLdouble GLWidget::gravityForce() {
    GLdouble m = weight->getMass();

    // gravity force = mass * gravity acceleration
    return m * GRAVITY;
}

GLdouble GLWidget::totalForces() {
    GLdouble fs, fd, fg;
    fs = springForce();
    fd = dampingForce();
    fg = gravityForce();

    // total force = spring force + damping force + gravity force
    return fs + fd + fg;
}

GLdouble GLWidget::getCurrentVelocity(GLdouble f) {
    GLdouble vt, m;
    vt = weight->getVelocity();
    m = weight->getMass();
    return vt + ((_delta * f) / m);
}

GLdouble GLWidget::getCurrentPosition(GLdouble f) {
    GLdouble xt, vt, m;
    xt = weight->getPos();
    vt = weight->getVelocity();
    m = weight->getMass();
    return xt + (vt * _delta) + ((pow(_delta,2.0) * f) / (2 * m));
}

void GLWidget::simStep() {

    // Calculate total force
    GLdouble forces = totalForces();

    // Calculate the new velocity and set it
    weight->setVelocity(getCurrentVelocity(forces));

    // Calculate the new positions
    GLdouble newPos = getCurrentPosition(forces);

    // Set the new positions
    weight->setPos(newPos);
    spring->setLength(newPos);

    // Update the screen
    updateGL();
}
