#
# Makefile
#

#lib
CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -Wall -Wextra - Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STD = c++11
STATIC = ar crs
DYNAMIC = g++ shared -o

TARGET = lib$(LIBNAME).$(LIBTYPE)
LIBNAME = aufgabe6
LIBTYPE = a

SOURCES = \
		benotung.cpp \
		fachnote.cpp \
		fachnoten_liste.cpp \

HEADERS = $(SOURCES:.cpp=.h)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean	#unechte Ziele, sog. pseudoziele

all:
		lib$(LIBNAME).$(LIBTYPE)
clean:
		rm -f lib$(LIBNAME).a lib$(LIBNAME).so $(OBJECTS) depend

# eine explizite Regel zum Erstellen der statischen Bibliothek
lib$(LIBNAME).a : $(OBJECTS)
	$(STATIC) $@ $^
			#  ^
			# Das ist das Ziel auf die die Regel angewendet wird

# eine explizite Regel zum Erstellen der dynamischen Bibliothek
lib$(LIBNAME).so : $(OBJECTS)
	$(DYNAMIC) $(CXXFLAGS) -o $@ $^
						#	   ^Hier ist es auch das Ziel auf das es angewendet wird, in diesem Fall dann die .so-Datei

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<
						# ^ ist die Quelle auf die die Regel angewendet wird, in dem Fall dann die .cpp-Dateien

depend:
		$(SOURCES) $(HEADERS)
		$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $@
							#^
							# Das MM schreibt die Regeln mittels Umlenkung der Standardausgabe in die Datei depend,
							# die Datei depend kann dann per include in das Makefile integriert werden
include depend