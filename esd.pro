TEMPLATE = app
CONFIG  += qt warn_on debug

SOURCES += src/main.cpp
SOURCES += src/sound_engine.cpp
SOURCES += src/app_settings.cpp

HEADERS += inc/bass.h
HEADERS += inc/sound_engine.h
HEADERS += inc/app_settings.h

LIBS +=  -lbass