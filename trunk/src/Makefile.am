# set the include path for X, qt and KDE
INCLUDES = $(all_includes)

# these are the headers for your project
noinst_HEADERS = kuire.h actorsview.h editorsview.h

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(EXTRACTRC) `find . -name \*.ui -o -name \*.rc` > rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/kuire.pot

KDE_ICON = AUTO

#########################################################################
# APPLICATION SECTION
#########################################################################
# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = kuire

# the application source, library search path, and link libraries
kuire_SOURCES = main.cpp kuire.cpp actorsview.cpp editorsview.cpp
kuire_LDFLAGS = $(KDE_RPATH) $(all_libraries)
kuire_LDADD = $(LIB_KIO) -lkmdi $(LIB_KDEUI)

# this is where the desktop file will go 
shelldesktopdir   = $(kde_appsdir)/Utilities
shelldesktop_DATA = kuire.desktop

# this is where the shell's XML-GUI resource file goes
shellrcdir   = $(kde_datadir)/kuire
shellrc_DATA = kuireui.rc

