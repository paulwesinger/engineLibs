CONFIG -= qt

TEMPLATE = lib
DEFINES += INITGL_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Base/base.cpp \
    Defaults/defaults.cpp \
    GL/init.cpp \
    base2d/base2d.cpp \
    baseobject/baseobject.cpp \
    camera/camera.cpp \
    error/error.cpp \
    fileutils/fileutil.cpp \
    imageloader/loadimage.cpp \
    initgl.cpp \
    lights/light.cpp \
    projection/projection.cpp \
    shaders/shader.cpp \
    utils/utils.cpp \
    vecmath/vecmath.cpp

HEADERS += \
    Base/base.h \
    Defaults/defaults.h \
    GL/init.h \
    InitGL_global.h \
    base2d/base2d.h \
    baseobject/baseobject.h \
    camera/camera.h \
    defines.h \
    error/error.h \
    fileutils/fileutil.h \
    imageloader/loadimage.h \
    initgl.h \
    lights/light.h \
    projection/projection.h \
    shaders/shader.h \
    utils/utils.h \
    vecmath/vecmath.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/release/ -lGLEW
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/debug/ -lGLEW
else:unix: LIBS += -L$$PWD/../../../../usr/lib64/ -lGLEW

INCLUDEPATH += $$PWD/../../../../usr/include/GL
DEPENDPATH += $$PWD/../../../../usr/include/GL

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/release/ -lSDL2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/debug/ -lSDL2
else:unix: LIBS += -L$$PWD/../../../../usr/lib64/ -lSDL2

INCLUDEPATH += $$PWD/../../../../usr/include/SDL2
DEPENDPATH += $$PWD/../../../../usr/include/SDL2

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/release/ -lSDL2_image
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib64/debug/ -lSDL2_image
else:unix: LIBS += -L$$PWD/../../../../usr/lib64/ -lSDL2_image

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/Logger/release/ -lLogger
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/Logger/debug/ -lLogger
else:unix: LIBS += -L$$PWD/../libs/Logger/ -lLogger

INCLUDEPATH += $$PWD/../includes
DEPENDPATH += $$PWD/../includes

INCLUDEPATH += $$PWD/../../../../usr/include/glm
DEPENDPATH += $$PWD/../include/glm
