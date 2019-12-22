QT -= gui

CONFIG += c++11 console
CONFIG += c++17 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        action_controller.cpp \
        actions.cpp \
        application.cpp \
        args_builder.cpp \
        command_builder.cpp \
        command_controller.cpp \
        command_parser.cpp \
        commands.cpp \
        iaction.cpp \
        icommand.cpp \
        iobject.cpp \
        ishape.cpp \
        main.cpp \
        object.cpp \
        shape_library.cpp \
        shapes.cpp \
        slide.cpp \
        slideshow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    action_controller.h \
    actions.h \
    application.h \
    args_builder.hpp \
    basic_types.h \
    command_builder.h \
    command_controller.h \
    command_parser.h \
    command_type_enums.h \
    command_types.h \
    commands.h \
    declaration.h \
    iaction.h \
    icommand.h \
    iobject.h \
    ishape.h \
    object.h \
    property.h \
    shape_library.h \
    shapes.h \
    slide.h \
    slideshow.h \
    token.h \
    utility.h
