# Makefile

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic
CPPCHECK = cppcheck --enable=warning,style --std=$(STD)
STD = c11
RM = rm -f

TARGET = \
		filesize \
		filecopy \
		a.out \
		filecopy-kopie \

.PHONY: all clean cppcheck

all: $(TARGET)
clean:
		$(RM) $(TARGET)

cppcheck: $(TARGET:=.c)
		$(CPPCHECK) $^	#Regel wird angewendet auf das Quelle
