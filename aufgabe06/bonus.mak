
TARGET = aufgabe06.tar.gz
RM = rm -f

.PHONY: all clean

all: $(TARGET)

$(TARGET): aufgabe06/bin/Makefile aufgabe06/lib/Makefile aufgabe06/Makefile
    tar -czf $@ aufgabe06

clean:
    $(RM) $(TARGET)
