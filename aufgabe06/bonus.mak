CXX = g++ -g #-fno-elide-constructors
CXXFLAGS = -fPIC -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=$(STD) -pedantic
STD = c++11


MAKEFILES = \
		/aufgabe06/aufgabe06/bin/Makefile \
		/aufgabe06/aufgabe06/lib/Makefile \
		/aufgabe06/aufgabe06/Makefile \

TARGET = aufgabe6.tar.gz
RM = rm -f


    .PHONY: all clean pack

    all: $(MAKEFILES) $(TARGET)

    clean: $(MAKEFILES)
        $(RM) $(TARGET) $(OBJECTS) depend
        @for makefile in $(MAKEFILES); do \
            $(MAKE) -f $$makefile clean; \
        done

    $(MAKEFILES):
        $(MAKE) -f $@

    pack: $(MAKEFILES)
        mkdir -p aufgabe6
        cp $(MAKEFILES) aufgabe6/
        tar -czvf aufgabe6.tar.gz aufgabe6/

    include depend

