QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Views/calc.cc \
    Views/credit.cc \
    Views/deposit.cpp \
    main.cc \
    qcustomplot.cpp

HEADERS += \
    Controllers/credit_controller.h \
    Controllers/deposit_controller.h \
    Models/calc_model.h \
    Controllers/calc_controller.h \
    Models/credit_model.h \
    Models/deposit_model.h \
    Views/calc.h \
    Views/credit.h \
    Views/deposit.h \
    qcustomplot.h

FORMS += \
    Views/calc.ui \
    Views/credit.ui \
    Views/deposit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
