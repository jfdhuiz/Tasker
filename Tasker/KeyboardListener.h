#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H
#define LNUX_DEV_PATH "/dev/input/by-id/"
#define LINUX_KEYBOARD_PATH_KEYWORD "-kbd" //This is used for regular expression matching
#include <QtCore>
#include <Listener.h>
static const char *const evval[3] = {
    "RELEASED",
    "PRESSED ",
    "REPEATED"
};
namespace Engine
{
class KeyboardListener;
int startListening();
}

class Engine::KeyboardListener: public Listener
{
public:
    KeyboardListener();
    int startListening(unsigned long int delay =30);
    void start();
    void end();
    void pause();
    void update();
    Listener::ListenerState listen();
private:
    QString activeKeyboardPath;
    void setKeyboardPathsOnLinux(int deviceIndex = 0);
    QVector<QString> keyboardPaths;
};

#endif // KEYBOARDLISTENER_H
