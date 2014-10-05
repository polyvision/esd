TEMPLATE = app
CONFIG  += qt warn_on debug network

QT -= gui
QT += network

SOURCES += src/main.cpp \
    qtservice/qtservice.cpp \
    qtservice/qtservice_unix.cpp \
    qtservice/qtservice_win.cpp \
    qtservice/qtunixserversocket.cpp \
    qtservice/qtunixsocket.cpp \
    src/esdservice.cpp
SOURCES += src/sound_engine.cpp
SOURCES += src/app_settings.cpp
SOURCES += src/qlogger.cpp
SOURCES += src/psd_server.cpp
SOURCES += src/station_server.cpp
SOURCES += src/station_client.cpp
SOURCES += src/ecycler.cpp

HEADERS += inc/bass.h \
    inc/singleton.h \
    qtservice/qtservice.h \
    qtservice/qtservice_p.h \
    qtservice/qtunixserversocket.h \
    qtservice/qtunixsocket.h \
    inc/esdservice.h
HEADERS += inc/sound_engine.h
HEADERS += inc/app_settings.h
HEADERS += inc/qlogger.h
HEADERS += inc/psd_server.h
HEADERS += inc/station_server.h
HEADERS += inc/station_client.h
HEADERS += inc/ecycler.h

macx {
	message("OSX libraries")
	LIBS += libs/libbass.dylib

	mylib.path = Contents/MacOS
 	mylib.files = libs/libbass.dylib
 	QMAKE_BUNDLE_DATA += mylib
}
LIBS += -L$$PWD/libs/ -lbass

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/
