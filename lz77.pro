TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    enc.c \
    globals.c \
    dec.c \
    maindec.c

HEADERS += \
    enc.h \
    globals.h \
    dec.h

