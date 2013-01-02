TEMPLATE = app
CONFIG  += qt warn_on debug network

QT -= gui
QT += network

SOURCES += src/main.cpp
SOURCES += src/sound_engine.cpp
SOURCES += src/app_settings.cpp
SOURCES += src/qlogger.cpp
SOURCES += src/psd_server.cpp

HEADERS += inc/bass.h
HEADERS += inc/sound_engine.h
HEADERS += inc/app_settings.h
HEADERS += inc/qlogger.h
HEADERS += inc/psd_server.h


macx {
	message("OSX libraries")
	LIBS += libs/libbass.dylib

	mylib.path = Contents/MacOS
 	mylib.files = libs/libbass.dylib
 	QMAKE_BUNDLE_DATA += mylib
}
else{
	LIBS +=  -lbass
}