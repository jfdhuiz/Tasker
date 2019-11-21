QT       += charts
QT       += core gui
QT += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CommStatsQWidget.cpp \
    Commitment.cpp \
    CreateCommitmentQWidget.cpp \
<<<<<<< HEAD
    Session.cpp \
    Task.cpp \
=======
    StatsUtility.cpp \
>>>>>>> hardware-audio
    TaskerUIMainWindowQWidget.cpp \
    TempChartQWidget.cpp \
    TestUtils.cpp \
    TimerWindowQWidget.cpp \
    User.cpp \
    main.cpp

HEADERS += \
    CommStatsQWidget.h \
    Commitment.h \
    CreateCommitmentQWidget.h \
<<<<<<< HEAD
    Session.h \
    Task.h \
    TaskerUIMainWindowQWidget.h \
    TempChartQWidget.h \
    TestUtils.h \
    TimerWindowQWidget.h
=======
    Interval.h \
    StatsUtility.h \
    TaskerUIMainWindowQWidget.h \
    TempChartQWidget.h \
    TimerWindowQWidget.h \
    User.h
>>>>>>> hardware-audio

FORMS += \
    CommStatsQWidget.ui \
    CreateCommitmentQWidget.ui \
    TaskerUIMainWindowQWidget.ui \
    TimerWindowQWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
