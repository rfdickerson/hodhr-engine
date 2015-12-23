TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = hodhrengine \
    game

editor.depends = hodhrengine
game.depends = hodhrengine
