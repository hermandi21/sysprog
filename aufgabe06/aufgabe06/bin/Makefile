#
# Makefile
#

#bin
CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -I$(LIBRARY) -Wall -Wextra -Werror -std=$(STD) -pedantic
STD = c++11
LDFLAGS=-L$(LIBRARY)
LIBRARY=../lib/
LDLIBS=-l$(LIBNAME)
LIBTYPE = a
LIBNAME = aufgabe6
RM = rm -f

TARGET = notenspiegel

HEADERS = \
	$(LIBRARY)benotung.h \
	$(LIBRARY)fachnote.h \
	$(LIBRARY)fachnoten_liste.h \

SOURCES = $(TARGET).cpp
OBJECTS = $(TARGET).o

 .PHONY: all clean

all: $(TARGET)

clean:
	$(RM) $(TARGET) $(OBJECTS) depend

$(TARGET): $(OBJECTS) $(LIBRARY)lib$(LIBNAME).$(LIBTYPE)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $< $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) -c  $< -o $@

depend: $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -MM $(SOURCES) > $@

include depend
