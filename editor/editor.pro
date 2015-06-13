#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T10:45:51
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        glwidget.cpp \
        qtdebugconsole.cpp \
        window.cpp

HEADERS  += mainwindow.h \
            glwidget.h \
            qtdebugconsole.h \
            window.h


unix:INCLUDEPATH += /usr/include/
win32:INCLUDEPATH += e:\developmentlibs\glew-1.12.0\include\

win32:INCLUDEPATH += e:\developmentlibs\glm\

unix:LIBS += -L/usr/lib -lGLEW -lglut -lGLU -lOpenImageIO

INCLUDEPATH += ../hodhrengine
LIBS += -L../hodhrengine -lhodhrengine
DEPENDPATH += . ../hodhrengine

CONFIG += c++11

