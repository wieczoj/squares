TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += main.cpp \
    game.cpp \
    plansza.cpp \
    kratka.cpp \
    logic.cpp \
    ustawienia.cpp
#LIBS += -L"/opt/sdk/ndk-bundle/sources/sfml/lib/armeabi"
#LIBS += -L"/opt/sdk/ndk-bundle/sources/sfml/lib/armeabi-v7a"
#LIBS += -L"/opt/sdk/ndk-bundle/sources/sfml/lib/x86"


#INCLUDEPATH += "/opt/sdk/ndk-bundle/sources/sfml/include"
#DEPENDPATH += "/opt/sdk/ndk-bundle/sources/sfml/include"

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

HEADERS += \
    game.h \
    plansza.h \
    wspolne.h \
    kratka.h \
    logic.h \
    ustawienia.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android



