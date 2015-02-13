/*!
 *  \author    Babak Tootoonchi
 *  \version   1.0
 *  \date      Sept. 2014
 */

#ifndef WEIGHT_H
#define WEIGHT_H

#include <QtOpenGL/QGLWidget>
#include <GL/GLU.h>

/*! The Weight class is for simulating weights and their movement. */
class Weight
{
public:
    /// CONSTRUCTOR
    /*! Initializes weight parameters to default values.
    *  \param unitLen normalized display unit.
    */
    Weight(GLdouble restLen);

    /// DESTRUCTOR
    ~Weight(){}

    /*! Draws the weight. */
    void draw();

    /*! Resets the state of the weight to the starting point of the simulation.
     *  \param restLen rest length of the attached spring.
     */
    void resetState(GLdouble restLen);

    /*! Sets the current position of the weight to the given value.
     *  \param pos new position of the weight.
     */
    void setPos(GLdouble pos);

    /*! Returns the current position of the weight.
     *  \return the position of the weight.
     */
    GLdouble getPos();

    /*! Sets the velocity of the weight to the given value.
     *  \param v new velocity of the weight.
     */
    void setVelocity(GLdouble v);

    /*! Returns the current velocity of the weight.
     *  \return the velocity of the weight.
     */
    GLdouble getVelocity();

    /*! Sets the mass of the weight to the given value.
     *  \param v the mass of the weight.
     */
    void setMass(GLdouble m);

    /*! Returns the mass of the weight.
     *  \return the mass of the weight in kg.
     */
    GLdouble getMass();

private:
    //! Position of the weight at time t
    GLdouble _pos;

    //! Velocity of the weight at time t
    GLdouble _velocity;

    //! Mass of the weight
    GLdouble _mass;
};

#endif // WEIGHT_H
