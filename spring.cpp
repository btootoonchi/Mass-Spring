#include "spring.h"

Spring::Spring(GLdouble unitLen)
{
    _restLength = 10 * unitLen;     // Rest length defaults to 10 points.
    _length = _restLength;          // Initial length is same as rest length.
    _radius = 0.15;
    _springConstant = 10;
    _dampingCoeff = 0.1;
}

void Spring::setLength(GLdouble len) {
    _length = len;
}

GLdouble Spring::getLength() {
    return _length;
}

void Spring::setRestLength(GLdouble len) {
    _restLength = len;
}

GLdouble Spring::getRestLength() {
    return _restLength;
}

void Spring::setSpringConstant(GLdouble ks) {
    _springConstant = ks;
}

GLdouble Spring::getSpringConstant() {
    return _springConstant;
}

void Spring::setDampingCoefficient(GLdouble kd) {
    _dampingCoeff = kd;
}

GLdouble Spring::getDampingCoefficient() {
    return _dampingCoeff;
}

void Spring::draw(GLdouble unitLen)
{
    // If rest length is set to 0 draw nothing.
    if (_restLength == 0)
        return;

    int pointCount = _restLength / unitLen;     // Point count is the number of loops in the spring
    GLdouble step = _length / pointCount;       // Distance between two points
    GLdouble y = 0;                             // Start from the top of the screen

    glColor3d(1, 0.2, 0.2);
    glLineWidth(2);
    glBegin(GL_LINES);
    for(int i = 0; i < pointCount; i++)
    {
        // Draw a backslash
        glVertex2d(-_radius, y);
        glVertex2d(_radius, y + step/2);

        // Draw a slash
        glVertex2d(_radius, y + step/2);
        glVertex2d(-_radius, y + step);
        y +=step;
    }
    glEnd();
}
