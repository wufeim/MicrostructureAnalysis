TEMPLATE = app
TARGET = MicrostructureAnalysis

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    featuredialog.cpp \
    main.cpp \
    window.cpp

HEADERS += \
    featuredialog.h \
    window.h

DISTFILES += \
    README.md
