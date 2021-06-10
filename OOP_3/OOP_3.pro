QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    config/config_manager_creator.cpp \
    draw/drawer.cpp \
    facade.cpp \
    load/builder.cpp \
    load/load_director.cpp \
    load/loader.cpp \
    main.cpp \
    mainwindow.cpp \
    managers/draw_manager.cpp \
    managers/draw_manager_creator.cpp \
    managers/load_manager.cpp \
    managers/load_manager_creator.cpp \
    managers/reform_manager.cpp \
    managers/reform_manager_creator.cpp \
    managers/scene_manager.cpp \
    managers/scene_manager_creator.cpp \
    managers/visitor.cpp \
    object/camera.cpp \
    object/composite.cpp \
    object/details.cpp \
    object/link.cpp \
    object/model.cpp \
    object/scene.cpp \

HEADERS += \
    base_manager.h \
    builder.h \
    camera.h \
    command.h \
    composite.h \
    config/config_manager.h \
    config/load_solution.h \
    config/loader_creator.hpp \
    config/registration_maker.h \
    details.h \
    draw/drawer.h \
    draw/drawer_factory_creator.h \
    draw/drawer_solution.h \
    draw/factory.h \
    draw_manager.h \
    drawer_factory_creator.h \
    drawer_solution.h \
    exceptions/base_exception.h \
    exceptions/load_exceptions.h \
    exceptions/model_exceptions.h \
    exceptions/ui_exceptions.h \
    facade.h \
    factory.h \
    iterator.h \
    iterator.hpp \
    link.h \
    load/builder.h \
    load/load_director.h \
    load/loader.h \
    load_director.h \
    load_exceptions.h \
    load_manager.h \
    load_manager_creator.h \
    load_solution.h \
    loader.h \
    loader_creator.hpp \
    mainwindow.h \
    managers/base_manager.h \
    managers/draw_manager.h \
    managers/draw_manager_creator.h \
    managers/load_manager.h \
    managers/load_manager_creator.h \
    managers/reform_manager.h \
    managers/reform_manager_creator.h \
    managers/scene_manager.h \
    managers/scene_manager_creator.h \
    managers/visitor.h \
    model.h \
    object.h \
    object/camera.h \
    object/composite.h \
    object/details.h \
    object/link.h \
    object/model.h \
    object/object.h \
    object/point.hpp \
    object/scene.h \
    point.hpp \
    reform_manager.h \
    scene.h \
    scene_manager.h \
    vector.h \
    vector.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    config/camera_cfg \
    config/model_cfg \
    config/scene_cfg \
    model1.txt \
    model_cfg \
    points.txt
