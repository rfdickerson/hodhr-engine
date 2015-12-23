#-------------------------------------------------
#
# Project created by QtCreator 2015-04-13T10:45:51
#
#-------------------------------------------------

#QT       += core gui opengl

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = lib
TARGET = hodhrengine
CONFIG += staticlib
CONFIG += c++11


SOURCES +=  debug.cpp  \
    renderer.cpp \
    camera.cpp \
    behavior.cpp \
    component.cpp \
    object.cpp \
    transform.cpp \
    color.cpp \
    rendertexture.cpp \
    texture.cpp \
    material.cpp \
    meshrenderer.cpp \
    gameobject.cpp \
    display.cpp \
    renderbuffer.cpp \
    graphics.cpp \
    mesh.cpp \
    shader.cpp \
    rect.cpp \
    resources.cpp \
    materialpropertyblock.cpp \
    meshfilter.cpp \
    scene.cpp \
    light.cpp \
    consoledebug.cpp \
    commandbuffer.cpp \
    texture2d.cpp

HEADERS  +=    debug.h \
    renderer.h \
    camera.h \
    behavior.h \
    component.h \
    object.h \
    transform.h \
    color.h \
    rendertexture.h \
    texture.h \
    material.h \
    meshrenderer.h \
    gameobject.h \
    display.h \
    renderbuffer.h \
    graphics.h \
    mesh.h \
    shader.h \
    rect.h \
    resources.h \
    materialpropertyblock.h \
    meshfilter.h \
    scene.h \
    light.h \
    common.h \
    consoledebug.h \
    commandbuffer.h \
    texture2d.h

#FORMS    +=

INCLUDEPATH += /usr/include/
win32:INCLUDEPATH += e:\developmentlibs\glew-1.12.0\include\
win32:INCLUDEPATH += e:\developmentlibs\glm\

LIBS += -L/usr/lib -lGLEW -lglut -lGLU -lOpenImageIO \
    -lHalf -lOpenColorIO -lboost_system -lOpenEXR -ltiff -ljpeg -lz -lrt -lassimp



