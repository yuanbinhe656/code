QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    chooselevelscene.cpp \
    dataconfig.cpp \
    main.cpp \
    mainwindow.cpp \
    mycoin.cpp \
    playscene.cpp \
    spinob.cpp \
    spixd.cpp

HEADERS += \
    button.h \
    chooselevelscene.h \
    dataconfig.h \
    mainwindow.h \
    mycoin.h \
    playscene.h \
    spinob.h \
    spixd.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../QtLearn-master/day4/Code/CoinFlip/res/new.qrc \
    ../QtLearn-master/day4/Code/CoinFlip/res/ress.qrc \
    res.qrc

DISTFILES += \
    ../QtLearn-master/day4/Code/CoinFlip/res/Coin0001.png
