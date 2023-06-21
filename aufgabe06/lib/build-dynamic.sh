#!/bin/sh
for s in benotung.cpp fachnote.cpp fachnoten_liste.cpp ; do
  compile_command="g++ -fpic -Wall -Wextra -Werror -Weffc++ -Wold-style-cast -std=c++11 -pedantic -c $s"
  echo $compile_command
  eval $compile_command
  if [ $? -ne 0 ] ; then
    echo build failed
    exit 1
  fi
  done
  link_command="g++ -shared -o libaufgabe6.so benotung.o fachnote.o fachnoten_liste.o"
  echo $link_command
  eval $link_command
  if [ $? -ne 0 ]; then
      echo build failed
      exit 1
  fi
  echo build succesful