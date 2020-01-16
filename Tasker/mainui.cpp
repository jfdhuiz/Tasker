#include "mainui.h"
#include <User.h>
#include <UdataUtils.h>
#include <QDebug>
TaskerUIMainWindowQWidget* MainUI::Instance = nullptr;

using namespace udata;
/**
 * @brief MainUI::MainUI
 */
MainUI::MainUI() {
}

/**
 * @brief MainUI::getInstance
 * @return
 */
TaskerUIMainWindowQWidget *MainUI::getInstance() {
    if (Instance == nullptr) {
        Instance = new TaskerUIMainWindowQWidget();
    }
    return Instance;
}
MainUI::~MainUI()
{
    qDebug()<<"MainUI destructor#1\n";
    delete Instance;
    qDebug()<<"MainUI destructor#2";
}
/**
 * @brief MainUI::saveTaskerState
 * Stores the state of Tasker on disk.
 * This includes all commitments,sessions or anything
 * that the user has changed since the last time that state was loaded.
 * This is called every time the application is about to be closed.
 */
void MainUI::saveTaskerStateSlot()
{
    qDebug()<<"Saving state";
    UdataUtils::saveUserData(*User::getInstance());
}
