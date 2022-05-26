QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lab10.cpp\
    main.cpp\
    notificare.cpp\
    repo.cpp\
    report.cpp\
    service.cpp


HEADERS += \
    lab10.h\
    locatar.h\
    notificare.h\
    observer.h\
    repo.h\
    report.h\
    service.h\
    undo.h\
    vd.h\
    validator.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
