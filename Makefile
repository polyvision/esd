#############################################################################
# Makefile for building: esd.app/Contents/MacOS/esd
# Generated by qmake (2.01a) (Qt 4.8.4) on: Mi. Feb 20 07:56:37 2013
# Project:  esd.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/local/Qt4.8/mkspecs/macx-g++ -o Makefile esd.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.8/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtNetwork.framework/Versions/4/Headers -I/usr/include/QtNetwork -I/usr/include -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks libs/libbass.dylib -framework QtNetwork -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/main.cpp \
		src/sound_engine.cpp \
		src/app_settings.cpp \
		src/qlogger.cpp \
		src/psd_server.cpp \
		src/station_server.cpp \
		src/station_client.cpp \
		src/ecycler.cpp moc_sound_engine.cpp \
		moc_qlogger.cpp \
		moc_psd_server.cpp \
		moc_station_server.cpp \
		moc_station_client.cpp \
		moc_ecycler.cpp
OBJECTS       = main.o \
		sound_engine.o \
		app_settings.o \
		qlogger.o \
		psd_server.o \
		station_server.o \
		station_client.o \
		ecycler.o \
		moc_sound_engine.o \
		moc_qlogger.o \
		moc_psd_server.o \
		moc_station_server.o \
		moc_station_client.o \
		moc_ecycler.o
DIST          = /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.8/mkspecs/features/debug.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		esd.pro
QMAKE_TARGET  = esd
DESTDIR       = 
TARGET        = esd.app/Contents/MacOS/esd

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile esd.app/Contents/PkgInfo esd.app/Contents/Resources/empty.lproj esd.app/Contents/Info.plist esd.app/Contents/MacOS/libbass.dylib $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) esd.app/Contents/MacOS/ || $(MKDIR) esd.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: esd.pro  /usr/local/Qt4.8/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.8/mkspecs/features/debug.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtNetwork.framework/QtNetwork.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl
	$(QMAKE) -spec /usr/local/Qt4.8/mkspecs/macx-g++ -o Makefile esd.pro
/usr/local/Qt4.8/mkspecs/common/unix.conf:
/usr/local/Qt4.8/mkspecs/common/mac.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf:
/usr/local/Qt4.8/mkspecs/common/g++-base.conf:
/usr/local/Qt4.8/mkspecs/common/g++-macx.conf:
/usr/local/Qt4.8/mkspecs/qconfig.pri:
/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Qt4.8/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.8/mkspecs/features/qt_config.prf:
/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.8/mkspecs/features/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf:
/usr/local/Qt4.8/mkspecs/features/debug.prf:
/usr/local/Qt4.8/mkspecs/features/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf:
/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.8/mkspecs/features/warn_on.prf:
/usr/local/Qt4.8/mkspecs/features/qt.prf:
/usr/local/Qt4.8/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.8/mkspecs/features/moc.prf:
/usr/local/Qt4.8/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.8/mkspecs/features/resources.prf:
/usr/local/Qt4.8/mkspecs/features/uic.prf:
/usr/local/Qt4.8/mkspecs/features/yacc.prf:
/usr/local/Qt4.8/mkspecs/features/lex.prf:
/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtNetwork.framework/QtNetwork.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/local/Qt4.8/mkspecs/macx-g++ -o Makefile esd.pro

esd.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) esd.app/Contents || $(MKDIR) esd.app/Contents 
	@$(DEL_FILE) esd.app/Contents/PkgInfo
	@echo "APPL????" >esd.app/Contents/PkgInfo
esd.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) esd.app/Contents/Resources || $(MKDIR) esd.app/Contents/Resources 
	@touch esd.app/Contents/Resources/empty.lproj
	
esd.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) esd.app/Contents || $(MKDIR) esd.app/Contents 
	@$(DEL_FILE) esd.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,esd,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.8/mkspecs/macx-g++/Info.plist.app >esd.app/Contents/Info.plist
esd.app/Contents/MacOS/libbass.dylib: /Users/ghostrifle/entwicklung/esd/libs/libbass.dylib
	@$(CHK_DIR_EXISTS) esd.app/Contents/MacOS || $(MKDIR) esd.app/Contents/MacOS 
	@$(DEL_FILE) esd.app/Contents/MacOS/libbass.dylib
	@$(COPY_FILE) /Users/ghostrifle/entwicklung/esd/libs/libbass.dylib esd.app/Contents/MacOS/libbass.dylib
dist: 
	@$(CHK_DIR_EXISTS) .tmp/esd1.0.0 || $(MKDIR) .tmp/esd1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/esd1.0.0/ && $(COPY_FILE) --parents inc/bass.h inc/sound_engine.h inc/app_settings.h inc/qlogger.h inc/psd_server.h inc/station_server.h inc/station_client.h inc/ecycler.h .tmp/esd1.0.0/ && $(COPY_FILE) --parents src/main.cpp src/sound_engine.cpp src/app_settings.cpp src/qlogger.cpp src/psd_server.cpp src/station_server.cpp src/station_client.cpp src/ecycler.cpp .tmp/esd1.0.0/ && (cd `dirname .tmp/esd1.0.0` && $(TAR) esd1.0.0.tar esd1.0.0 && $(COMPRESS) esd1.0.0.tar) && $(MOVE) `dirname .tmp/esd1.0.0`/esd1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/esd1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r esd.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_sound_engine.cpp moc_qlogger.cpp moc_psd_server.cpp moc_station_server.cpp moc_station_client.cpp moc_ecycler.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_sound_engine.cpp moc_qlogger.cpp moc_psd_server.cpp moc_station_server.cpp moc_station_client.cpp moc_ecycler.cpp
moc_sound_engine.cpp: inc/bass.h \
		inc/singleton.h \
		inc/sound_engine.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ inc/sound_engine.h -o moc_sound_engine.cpp

moc_qlogger.cpp: inc/singleton.h \
		inc/qlogger.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ inc/qlogger.h -o moc_qlogger.cpp

moc_psd_server.cpp: inc/singleton.h \
		inc/psd_server.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ inc/psd_server.h -o moc_psd_server.cpp

moc_station_server.cpp: inc/singleton.h \
		inc/station_server.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ inc/station_server.h -o moc_station_server.cpp

moc_station_client.cpp: inc/station_client.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ inc/station_client.h -o moc_station_client.cpp

moc_ecycler.cpp: inc/ecycler.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ inc/ecycler.h -o moc_ecycler.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: src/main.cpp inc/sound_engine.h \
		inc/bass.h \
		inc/singleton.h \
		inc/app_settings.h \
		inc/psd_server.h \
		inc/station_server.h \
		inc/qlogger.h \
		inc/ecycler.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o src/main.cpp

sound_engine.o: src/sound_engine.cpp inc/sound_engine.h \
		inc/bass.h \
		inc/singleton.h \
		inc/app_settings.h \
		inc/qlogger.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sound_engine.o src/sound_engine.cpp

app_settings.o: src/app_settings.cpp inc/app_settings.h \
		inc/sound_engine.h \
		inc/bass.h \
		inc/singleton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o app_settings.o src/app_settings.cpp

qlogger.o: src/qlogger.cpp inc/qlogger.h \
		inc/singleton.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qlogger.o src/qlogger.cpp

psd_server.o: src/psd_server.cpp inc/psd_server.h \
		inc/singleton.h \
		inc/qlogger.h \
		inc/sound_engine.h \
		inc/bass.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o psd_server.o src/psd_server.cpp

station_server.o: src/station_server.cpp inc/station_server.h \
		inc/singleton.h \
		inc/qlogger.h \
		inc/app_settings.h \
		inc/station_client.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o station_server.o src/station_server.cpp

station_client.o: src/station_client.cpp inc/station_client.h \
		inc/qlogger.h \
		inc/singleton.h \
		inc/app_settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o station_client.o src/station_client.cpp

ecycler.o: src/ecycler.cpp inc/ecycler.h \
		inc/qlogger.h \
		inc/singleton.h \
		inc/app_settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ecycler.o src/ecycler.cpp

moc_sound_engine.o: moc_sound_engine.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sound_engine.o moc_sound_engine.cpp

moc_qlogger.o: moc_qlogger.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qlogger.o moc_qlogger.cpp

moc_psd_server.o: moc_psd_server.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_psd_server.o moc_psd_server.cpp

moc_station_server.o: moc_station_server.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_station_server.o moc_station_server.cpp

moc_station_client.o: moc_station_client.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_station_client.o moc_station_client.cpp

moc_ecycler.o: moc_ecycler.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ecycler.o moc_ecycler.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

