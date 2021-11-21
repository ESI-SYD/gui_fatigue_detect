QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#dlib19.22_MinGW73&&MSVC编译

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../DFD/Dlib19.22_MinGW73_build/dlib/lib/ -ldlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../DFD/Dlib19.22_MinGW73_build/dlib/lib/ -ldlibd
else:unix: LIBS += -L$$PWD/../../../DFD/Dlib19.22_MinGW73_build/dlib/lib/ -ldlib

INCLUDEPATH += $$PWD/../../../DFD/Dlib19.22_MinGW73_build/dlib/include
DEPENDPATH += $$PWD/../../../DFD/Dlib19.22_MinGW73_build/dlib/include

#opencv4.5.1_MinGW73&&MSVC编译
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../DFD/CV/opencv/MinGW73_build/lib/ -llibopencv_world451.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../DFD/CV/opencv/MinGW73_build/lib/ -llibopencv_world451.dlld
else:unix: LIBS += -L$$PWD/../../../DFD/CV/opencv/MinGW73_build/lib/ -llibopencv_world451.dll

INCLUDEPATH += $$PWD/../../../DFD/CV/opencv/MinGW73_build/include
DEPENDPATH += $$PWD/../../../DFD/CV/opencv/MinGW73_build/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../DFD/CV/opencv/build/x64/vc15/lib/ -lopencv_world451
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../DFD/CV/opencv/build/x64/vc15/lib/ -lopencv_world451d
else:unix: LIBS += -L$$PWD/../../../DFD/CV/opencv/build/x64/vc15/lib/ -lopencv_world451

INCLUDEPATH += $$PWD/../../../DFD/CV/opencv/build/include
DEPENDPATH += $$PWD/../../../DFD/CV/opencv/build/include

RESOURCES += \
    res.qrc


