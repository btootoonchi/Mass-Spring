/*!
 *  \author    Babak Tootoonchi
 *  \version   1.0
 *  \date      Sept. 2014
 */

#ifndef SPRING_H
#define SPRING_H

#include <QtOpenGL/QGLWidget>
#include <GL/GLU.h>

/*! The Spring class is for simulating spring objects and their behaviour. */
class Spring
{
public:
    //! CONSTRUCTOR
    /*! Initializes spring parameters to default values.
     *  \param unitLen normalized display unit.
     */
    Spring(GLdouble unitLen);

    //! DESTRUCTOR
    ~Spring(){}

    /*! Sets the length of the spring to the given len.
     *  \param len new length of the spring.
     */
    void setLength(GLdouble len);

    /*! Returns the current length of the spring.
     *  \return the length of the spring.
     */
    GLdouble getLength();

    /*! Sets the rest length of the spring to the given value.
     *  \param len new rest length for the spring.
     */
    void setRestLength(GLdouble len);

    /*! Returns the current rest length of the spring.
     *  \return the rest length of the spring.
     */
    GLdouble getRestLength();

    /*! Sets the spring constant to the given value value.
     *  \param ks new spring constant.
     */
    void setSpringConstant(GLdouble ks);

    /*! Returns the spring constant
     *  \return spring constant.
     */
    GLdouble getSpringConstant();

    /*! Sets the spring damping coefficient to the given value.
     *  \param kd damping coefficient.
     */
    void setDampingCoefficient(GLdouble kd);

    /*! Returns the damping coefficient of the spring.
     *  \return damping coefficient.
     */
    GLdouble getDampingCoefficient();

    /*! Draws the spring
     *  \param unitLen normalized display unit.
     */
    void draw(GLdouble unitLen);

 private:
    //! Rest length of the spring.
    GLdouble _restLength;

    //! Length of the spring at time t
    GLdouble _length;

    //! Spring radius
    GLdouble _radius;

    //! Spring constant a.k.a. stiffness.
    int _springConstant;

    //! Damping coefficient
    int _dampingCoeff;
};

#endif // SPRING_H
