AUTOMAKE_OPTIONS = subdir-objects serial-tests nostdinc

BUILT_SOURCES = gen-cpp/shared_types.cpp \
                gen-cpp/tutorial_types.cpp

noinst_LTLIBRARIES = libtutorialgencpp.la
nodist_libtutorialgencpp_la_SOURCES = \
	gen-cpp/Calculator.cpp \
	gen-cpp/Calculator.h \
	gen-cpp/SharedService.cpp \
	gen-cpp/SharedService.h \
	gen-cpp/shared_types.cpp \
	gen-cpp/shared_types.h \
	gen-cpp/tutorial_constants.cpp \
	gen-cpp/tutorial_constants.h \
	gen-cpp/tutorial_types.cpp \
	gen-cpp/tutorial_types.h



libtutorialgencpp_la_LIBADD = $(top_builddir)/lib/cpp/libthrift.la

noinst_PROGRAMS = \
	TutorialServer \
	TutorialClient

TutorialServer_SOURCES = \
	CppServer.cpp

TutorialServer_LDADD = \
	libtutorialgencpp.la \
	$(top_builddir)/lib/cpp/libthrift.la

TutorialClient_SOURCES = \
	CppClient.cpp

TutorialClient_LDADD = \
	libtutorialgencpp.la \
	$(top_builddir)/lib/cpp/libthrift.la

#
# Common thrift code generation rules
#
#gen-cpp/Calculator.cpp gen-cpp/SharedService.cpp gen-cpp/shared_types.cpp gen-cpp/tutorial_constants.cpp gen-cpp/tutorial_types.cpp: $(top_srcdir)/mythriftpro/tutorial.thrift
#	$(THRIFT) --gen cpp -r $<

AM_CPPFLAGS = $(BOOST_CPPFLAGS) $(LIBEVENT_CPPFLAGS) -I$(top_srcdir)/lib/cpp/src -Igen-cpp
AM_CXXFLAGS = -Wall -Wextra -pedantic
AM_LDFLAGS = $(BOOST_LDFLAGS) $(LIBEVENT_LDFLAGS)

clean-local:
	$(RM) gen-cpp/*

tutorialserver: all
	./TutorialServer

tutorialclient: all
	./TutorialClient

style-local:
	$(CPPSTYLE_CMD)

EXTRA_DIST = \
	CMakeLists.txt \
	CppClient.cpp \
	CppServer.cpp
