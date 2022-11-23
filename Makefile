#############################################################################
# Makefile for building: m_STLlib
# Generated by qmake (2.01a) (Qt 4.7.4) on: ?? 11? 23 16:17:34 2022
# Project:  m_STLlib.pro
# Template: app
# Command: f:\qtcreator\qtopen\bin\qmake.exe -spec f:\qtcreator\qtopen\mkspecs\win32-g++ -o Makefile m_STLlib.pro
#############################################################################

first: debug
install: debug-install
uninstall: debug-uninstall
MAKEFILE      = Makefile
QMAKE         = f:\qtcreator\qtopen\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = del
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = move
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
SUBTARGETS    =  \
		debug \
		release

debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: m_STLlib.pro  f:/qtcreator/qtopen/mkspecs/win32-g++/qmake.conf f:/qtcreator/qtopen/mkspecs/qconfig.pri \
		f:/qtcreator/qtopen/mkspecs/modules/qt_webkit_version.pri \
		f:/qtcreator/qtopen/mkspecs/features/qt_functions.prf \
		f:/qtcreator/qtopen/mkspecs/features/qt_config.prf \
		f:/qtcreator/qtopen/mkspecs/features/exclusive_builds.prf \
		f:/qtcreator/qtopen/mkspecs/features/default_pre.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/default_pre.prf \
		f:/qtcreator/qtopen/mkspecs/features/debug.prf \
		f:/qtcreator/qtopen/mkspecs/features/debug_and_release.prf \
		f:/qtcreator/qtopen/mkspecs/features/default_post.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/default_post.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/console.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/rtti.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/exceptions.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/stl.prf \
		f:/qtcreator/qtopen/mkspecs/features/shared.prf \
		f:/qtcreator/qtopen/mkspecs/features/warn_on.prf \
		f:/qtcreator/qtopen/mkspecs/features/win32/thread_off.prf \
		f:/qtcreator/qtopen/mkspecs/features/resources.prf \
		f:/qtcreator/qtopen/mkspecs/features/uic.prf \
		f:/qtcreator/qtopen/mkspecs/features/yacc.prf \
		f:/qtcreator/qtopen/mkspecs/features/lex.prf \
		f:/qtcreator/qtopen/mkspecs/features/incredibuild_xge.prf \
		f:/qtcreator/qtopen/mkspecs/features/include_source_dir.prf
	$(QMAKE) -spec f:\qtcreator\qtopen\mkspecs\win32-g++ -o Makefile m_STLlib.pro
f:\qtcreator\qtopen\mkspecs\qconfig.pri:
f:\qtcreator\qtopen\mkspecs\modules\qt_webkit_version.pri:
f:\qtcreator\qtopen\mkspecs\features\qt_functions.prf:
f:\qtcreator\qtopen\mkspecs\features\qt_config.prf:
f:\qtcreator\qtopen\mkspecs\features\exclusive_builds.prf:
f:\qtcreator\qtopen\mkspecs\features\default_pre.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\default_pre.prf:
f:\qtcreator\qtopen\mkspecs\features\debug.prf:
f:\qtcreator\qtopen\mkspecs\features\debug_and_release.prf:
f:\qtcreator\qtopen\mkspecs\features\default_post.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\default_post.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\console.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\rtti.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\exceptions.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\stl.prf:
f:\qtcreator\qtopen\mkspecs\features\shared.prf:
f:\qtcreator\qtopen\mkspecs\features\warn_on.prf:
f:\qtcreator\qtopen\mkspecs\features\win32\thread_off.prf:
f:\qtcreator\qtopen\mkspecs\features\resources.prf:
f:\qtcreator\qtopen\mkspecs\features\uic.prf:
f:\qtcreator\qtopen\mkspecs\features\yacc.prf:
f:\qtcreator\qtopen\mkspecs\features\lex.prf:
f:\qtcreator\qtopen\mkspecs\features\incredibuild_xge.prf:
f:\qtcreator\qtopen\mkspecs\features\include_source_dir.prf:
qmake: qmake_all FORCE
	@$(QMAKE) -spec f:\qtcreator\qtopen\mkspecs\win32-g++ -o Makefile m_STLlib.pro

qmake_all: FORCE

make_default: debug-make_default release-make_default FORCE
make_first: debug-make_first release-make_first FORCE
all: debug-all release-all FORCE
clean: debug-clean release-clean FORCE
distclean: debug-distclean release-distclean FORCE
	-$(DEL_FILE) Makefile

check: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile