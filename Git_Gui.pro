QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Git_Branch.cpp \
    Git_CheckOut.cpp \
    Git_Cherry_Pick.cpp \
    Git_Clone.cpp \
    Git_Commit.cpp \
    Git_Config.cpp \
    Git_Init.cpp \
    Git_Log.cpp \
    Git_Merge.cpp \
    Git_Pull.cpp \
    Git_Push.cpp \
    Git_Reset.cpp \
    Git_Status.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Git_Branch.h \
    Git_CheckOut.h \
    Git_Cherry_Pick.h \
    Git_Clone.h \
    Git_Commit.h \
    Git_Config.h \
    Git_Init.h \
    Git_Log.h \
    Git_Merge.h \
    Git_Pull.h \
    Git_Push.h \
    Git_Reset.h \
    Git_Status.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
