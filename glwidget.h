/*!
 *  \author    Babak Tootoonchi
 *  \version   1.0
 *  \date      Sept. 2014
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <GL/GLU.h>
#include <QTimer>
#include "weight.h"
#include "spring.h"

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
    //! CONSTRUCTOR
    GLWidget(QWidget *parent = 0);

    //! DESTRUCTOR
    ~GLWidget();

    /*! Calculates the spring force.
     * \return the spring force.
     */
    GLdouble springForce();

    /*! Calculates the damping force.
     * \return the damping force.
     */
    GLdouble dampingForce();

    /*! Calculates the gravity force.
     * \return the gravity force.
     */
    GLdouble gravityForce();

    /*! Calculates the total force on the spring.
     * \return the total force.
     */
    GLdouble totalForces();

    /*! Calculates the velocity of the mass at time t+dt.
     * \param f total force on the mass
     * \return the velocity at time t+dt
     */
    GLdouble getCurrentVelocity(GLdouble f);

    /*! Calculates the position of the mass at time t+dt.
     * \param f total force on the mass
     * \return the new position at time t+dt
     */
    GLdouble getCurrentPosition(GLdouble f);

    /*! Returns the simulation time step
     * \return the time step
     */
    GLdouble getDelta();

    /*! Set the simulation time step to the given value
     * \param delta set the time step
     */
    void setDelta(GLdouble delta);

    /*! Returns the weight object pointer
     * \return pointer to the weight object
     */
    Weight *getWeight();

    /*! Returns the spring object pointer
     * \return pointer to the spring object
     */
    Spring *getSpring();

    /*! Returns the display unit length
     * \return the display unit
     */
    GLdouble getUnitLen();

private:
    //! Gravity acceleration
    const GLdouble GRAVITY;

    //! Display unit
    GLdouble _unitLen;

    //! Simulation time step
    GLdouble _delta;

    //! Weight attribute
    Weight *weight;

    //! Spring attribute
    Spring *spring;

protected:
    /// OPENGL
    void initializeGL();
    void paintGL();
    void resizeGL( int width, int height );

signals:

public slots:
    /*! Performs the simulation for the next time interval. */
    void simStep();

private slots:

protected slots:


};

#endif // GLWIDGET_H
