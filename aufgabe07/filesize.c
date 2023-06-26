//
// Created by hermandi on 26.06.23.
//

#define _POSIX_C_SOURCE 1   //Wenn man POSIX-Funktionen benutzt soll man diesen symbolischen Namen setzen
#include "fcntl.h"
#include "stdio.h"
#include "stdint.h"
#include "unistd.h"
#include "sys/stat.h"
#include "errno.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "de_DE");

    if(argc < 2)    // solange argc kleiner 2 d.h. ohne Kommandozeilenargument
    {
        uintmax_t n = 0;    //Auf z.B. einer LP64-Plattform kann man mit unsigned int nur die Bytes in Dateien korrekt zählen, die maximal 4 GiB groß sind.
        unsigned char b;
                        //solange der file-pointer einen neuen Eintraǵ liest bleibt er in der while-Schleife
                  while (read(0, &b, 1) > 0)//Im Falle eines Errors liefert die Funktion -1 und errno wird hochgezählt
                      {
                          ++n;
                      }
        printf("Size: %"PRIuMAX" Byte\n, n);
        return 0;
    }
    
    struct stat buf;

    for (int i = 0; i < argc; ++i)
    {
        if(stat(argv[i], &buf) != 0)
        {
            perror(argv[i]);
            continue;
        }
        printf("%s: %"PRIuMAX" Byte\n", argv[i], (uintmax_t) buf.st_size );
    }
    return 0;

}


