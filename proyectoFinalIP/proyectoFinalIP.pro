TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Logic/logic.c \
    Interface/Entradas.c \
    Interface/menu.c \
    Interface/Salidas.c

HEADERS += \
    Logic/logic.h \
    Logic/data.h \
    Interface/Entradas.h \
    Interface/menu.h \
    Interface/Salidas.h

