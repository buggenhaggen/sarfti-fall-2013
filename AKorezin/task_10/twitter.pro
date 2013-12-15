#-------------------------------------------------
#
# Project created by QtCreator 2013-11-07T19:13:21
#
#-------------------------------------------------

QT       += core declarative

QT       -= gui

TARGET = twitter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    transport.cpp \
    wall.cpp \
    transportleft.cpp \
    transportright.cpp

HEADERS += \
    transport.h \
    wall.h \
    transportleft.h \
    transportright.h \

test {
    #message(Test build)

    QT += testlib
    SOURCES -= main.cpp

    HEADERS += \
	tests/test.h \

    SOURCES += \
	tests/main.cpp \
	tests/test.cpp \
} else {
    #message(Normal build)
}
