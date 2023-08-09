QT       += core gui sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_order.cpp \
    capital.cpp \
    delete_truck.cpp \
    main.cpp \
    mainwindow.cpp \
    purchase_window.cpp \
    report1.cpp \
    report2.cpp \
    report3.cpp \
    report4.cpp \
    report5.cpp \
    reports.cpp

HEADERS += \
    add_order.h \
    capital.h \
    delete_truck.h \
    mainwindow.h \
    purchase_window.h \
    report1.h \
    report2.h \
    report3.h \
    report4.h \
    report5.h \
    reports.h

FORMS += \
    add_order.ui \
    capital.ui \
    delete_truck.ui \
    mainwindow.ui \
    purchase_window.ui \
    report1.ui \
    report2.ui \
    report3.ui \
    report4.ui \
    report5.ui \
    reports.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
