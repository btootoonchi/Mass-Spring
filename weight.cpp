#include "weight.h"
#include <stdio.h>

Weight::Weight(GLdouble restLen)
{
    _mass = 0.5;                             // Mass defaults to 500gr.
    resetState(restLen);
}

void Weight::resetState(GLdouble restLen) {
    _pos = restLen;                         // Position is initialized to the rest length of the attached spring.
    _velocity = 0;                          // Start with 0 velocity.
}

void Weight::setPos(GLdouble pos) {
    _pos = pos;
}

GLdouble Weight::getPos() {
    return _pos;
}

void Weight::setVelocity(GLdouble v) {
    _velocity = v;
}

GLdouble Weight::getVelocity() {
    return _velocity;
}

void Weight::setMass(GLdouble m) {
    _mass = m;
}

GLdouble Weight::getMass() {
    return _mass;
}

void Weight::draw(){

    // Draw a square
    glColor3d(0.3, 0.7, 0.9);
    glBegin(GL_POLYGON);
    glVertex2d(-0.25, _pos);
    glVertex2d(0.25, _pos);
    glVertex2d(0.25, _pos - 0.5);
    glVertex2d(-0.25, _pos - 0.5);
    glEnd();
}
