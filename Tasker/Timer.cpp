#include "Timer.h"
#include <QTime>
#include <QDebug>
#include <KeyboardListener.h>
using namespace Engine;
Timer::Timer()
{
}
Timer::Timer(Listener::ListenerType newListenerType)
{
    listenerType = newListenerType;
}
Timer::~Timer()
{
    delete listener;
}
/**
 * @brief Timer::run
 * This function is called when the thread starts.
 *Any and all QObjects(such as Listener) MUST be instantiated inside this method.
 * Otherwise, QT's thread management will NOT consider that QObject as part of the Timer
 * thread.
 *The code in &Listener::start, which is the ACTUAL code that listents to hardware,
 * does not run until the startListner() signal is sent
 */
void Timer::run()
{
qDebug()<<"From work thread: "<<currentThreadId();
if(listenerType == Listener::ListenerType::keyboard)
listener = new KeyboardListener();
else if(listenerType == Listener::ListenerType::audio)
    listener = new KeyboardListener(); //obviously we have to change this at some point
connect(this, &Timer::startListener, listener, &Listener::start);

emit startListener();
exec();
}
void Timer::timeSlot()
{
    qDebug()<<"Time slot func :)";
    qDebug()<<"current thread id Timer timeSlot:" << QThread::currentThreadId();
}
QTime Timer::getRealTime(){ //not implemented
    return QTime::currentTime();
}


