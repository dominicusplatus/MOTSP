QT += qml quick opengl
QT += widgets
CONFIG += c++11

SOURCES += main.cpp \
    Model/tspevosolverviewmodel.cpp \
    Model/tspevofitnesshistorydatamodel.cpp \
    tsppathgraphview.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tspevosolverviewmodel.h \
    Model/tspevosolverviewmodel.h \
    Model/tspevofitnesshistorydatamodel.h \
    tsppathgraphview.h

DISTFILES +=

LIBS += -L/usr/lib64 -lcma -leo -les -leoutils -lga -lmoeo -lltsp

INCLUDEPATH += /usr/include/paradiseo/eo \
                /usr/include/paradiseo/mo  \
                /usr/include/paradiseo/moeo \
                /usr/include/paradiseo
