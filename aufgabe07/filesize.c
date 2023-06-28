#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <inttypes.h>
#include <sys/stat.h>

//file
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "de_DE");

    if (argc < 2)
    {
        uintmax_t n = 0;
        unsigned char b;
        while (read(0, &b, 1) > 0) // On error, -1 is returned, and errno is set appropriately. 0 means EOF.
        {
            ++n;
        }
        printf("Size: %"PRIuMAX" ByteKekse\n", n);
        return 0;
    }

    struct stat buf;

    for (int i = 1; i < argc; ++i)
    {
        //"stat" ist eine POSIX-Verzeichnisfuntion
        //stat liefert statusinformationen zu einer Datei(Dateityp, Zugriffsrechte,...)
        if (stat(argv[i], &buf) != 0) // On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
        {
            perror(argv[i]);
            continue;
        }
        printf("%s: %"PRIuMAX" Byte\n", argv[i], (uintmax_t)buf.st_size);
    }
    return 0;
}