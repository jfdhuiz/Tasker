#ifndef MAINUI_H
#define MAINUI_H
#include <TaskerUIMainWindowQWidget.h>
#include <memory>

/**
 * @brief The MainUI class
 */
class MainUI {
private:
    MainUI();
    static TaskerUIMainWindowQWidget *Instance;

public:
    static TaskerUIMainWindowQWidget *getInstance();
    ~MainUI();
public slots:
    static void saveTaskerStateSlot();
};

#endif // MAINUI_H
