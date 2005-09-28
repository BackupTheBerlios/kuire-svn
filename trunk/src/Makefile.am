## Makefile.am for kuire

# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = kuire kuire_client

# set the include path for X, qt and KDE
INCLUDES         = $(all_includes)

# the library search path. 
kuire_LDFLAGS = $(KDE_RPATH) $(all_libraries)

# the libraries to link against.
kuire_LDADD = -lkmdi $(LIB_KFILE) $(LIB_KDEPRINT)

# which sources should be compiled for kuire
kuire_SOURCES = main.cpp kuire.cpp kuireview.cpp \
		      pref.cpp kuireiface.skel

# these are the headers for your project
noinst_HEADERS = kuire.h kuireview.h pref.h

# client stuff
kuire_client_LDFLAGS = $(KDE_RPATH) $(all_libraries)
kuire_client_LDADD   = $(LIB_KDECORE)
kuire_client_SOURCES = kuire_client.cpp

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(EXTRACTRC) `find . -name \*.ui -o -name \*.rc` > rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/kuire.pot

KDE_ICON = AUTO

# this is where the kdelnk file will go 
kdelnkdir   = $(kde_appsdir)/Utilities
kdelnk_DATA = kuire.desktop

# this is where the XML-GUI resource file goes
rcdir = $(kde_datadir)/kuire
rc_DATA = kuireui.rc
