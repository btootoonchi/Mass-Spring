/*!
 *  \author    Babak Tootoonchi
 *  \version   1.0
 *  \date      Sept. 2014
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    //! Action item for changing the mass value
    /*! Sets the weight's mass to the new value.
     *  \param mass new mass value.
     */
    void on_MassValue_valueChanged(double mass);

    //! Action item for changing the spring constant
    /*! Sets the spring constant to the new value.
     *  \param ks new spring constant.
     */
    void on_StiffnessValue_valueChanged(double ks);

    //! Action item for changing the simulation time intervals
    /*! Sets the delta time between simulation steps
     *  \param delta simulation interval in seconds.
     */
    void on_TimeStepValue_valueChanged(double delta);

    //! Action item for changing the spring rest length
    /*! Sets the spring rest length to the new value.
     *  \param len new spring rest length.
     */
    void on_RestLengthValue_valueChanged(double len);

    //! Action item for clicking the restart simulation button
    /*! Restarts the simulation preserving the parameter changes. */
    void on_restartButton_clicked();

private:
    //! UI object
    Ui::MainWindow *ui;

    //! Simulation timer
    QTimer *timer;

    // ADD YOUR CODE
};

#endif // MAINWINDOW_H
