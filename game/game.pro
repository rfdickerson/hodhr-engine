TARGET = game
TEMPLATE = app

HEADERS += \
    game.h

SOURCES += \
    game.cpp \
    main.cpp

INCLUDEPATH += ../hodhrengine
LIBS += -L../hodhrengine -lhodhrengine
#LIBS += ../hohdrengine/libhodhrengine.a
DEPENDPATH += . ../hodhrengine
PRE_TARGETDEPS += ../hodhrengine/libhodhrengine.a


unix:INCLUDEPATH += /usr/include/
win32:INCLUDEPATH += e:\developmentlibs\glew-1.12.0\include\
win32:INCLUDEPATH += e:\developmentlibs\glm\

LIBS += -L/usr/lib -lGLEW -lglut -lGL -lGLU -lSDL2 -lOpenImageIO -lassimp

CONFIG += c++11
