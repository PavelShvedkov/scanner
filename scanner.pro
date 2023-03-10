QT     += core gui

include (./libs/qwt-6.2.0/features/qwt.prf)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += qwt

INCLUDEPATH += ./libs/qwt-6.2.0/src
LIBS += -L./libs/qwt-6.2.0/lib/ -lqwtd

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
    distributions.cpp \
    main.cpp \
    mainwindow.cpp \
    noiseparamsdialog.cpp \
    profile.cpp

HEADERS += \
    distributions.h \
    mainwindow.h \
    noiseparamsdialog.h \
    profile.h

FORMS += \
    mainwindow.ui \
    noiseparamsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#win32:CONFIG(release, debug|release): LIBS += -LC:/build-qwt-Desktop_Qt_6_4_2_MinGW_64_bit-Release/lib/ -lqwt
#else:win32:CONFIG(debug, debug|release): LIBS += -LC:/build-qwt-Desktop_Qt_6_4_2_MinGW_64_bit-Release/lib/ -lqwtd
#else:unix: LIBS += -L$$PWD/libs/build-qwt-Desktop_Qt_6_4_2_MinGW_64_bit-Release/lib/ -lqwt

#INCLUDEPATH += C:/qwt-6.2.0/src
#DEPENDPATH += C:/qwt-6.2.0/src
