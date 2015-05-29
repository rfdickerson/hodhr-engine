TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = hodhrengine \
    editor \
    game

editor.depends = hodhrengine
game.depends = hodhrengine
