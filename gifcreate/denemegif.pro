QT += core gui

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp
INCLUDEPATH += /opt/homebrew/opt/imagemagick/include/ImageMagick-7

LIBS += -L/opt/homebrew/opt/imagemagick/lib -lMagick++-7.Q16HDRI -lMagickWand-7.Q16HDRI -lMagickCore-7.Q16HDRI
DEFINES += MAGICKCORE_HDRI_ENABLE=1
QMAKE_CXXFLAGS += -DMAGICKCORE_QUANTUM_DEPTH=16

TRANSLATIONS += \
    denemegif_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
