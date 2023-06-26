//
// Created by hermandi on 26.06.23.
//
#define _POSIX_C_SOURCE 1
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <locale.h>

int main(int argc, char *argv[])
{
    setlocale(LC_MESSAGES, "de_DE.UTF-8");

    if (argc != 3)
    {
        fprintf(stderr, "Aufruf mit Parameter source und destination\n");
        return 1;
    }

    int src = open(argv[1], O_RDONLY); // A  call to open() creates a new open file description
    if(src < 0) // open(), openat(), and creat() return the new file descriptor, or -1 if an error occurred
    {
        perror(argv[1]);
        exit(1);
    }

    struct stat st;

    if(fstat(src, &st) != 0) // On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.
    {
        perror(argv[1]);
        exit(1);
    }

    int *size = (int *)malloc(st.st_size);
    if(size == NULL)
    {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen!\n");
        return 1;
    }

    ssize_t reader = 0;
    if((reader = read(src, size, st.st_size)) == -1) // On error, -1 is returned, and errno is set appropriately.
    {
        fprintf(stderr, "Lesefehler %d: %s\n", errno, strerror(errno));
        free(size);
        return 1;
    }
    else if(reader != st.st_size) // On success, the number of bytes read is returned. So st_size must be similar to reader.
    {
        fprintf(stderr, "Lesefehler!\n");
        free(size);
        return 1;
    }

    // mode_t = mode of file
    // S_IRUSR = read permission, owner; S_IWUSR = write permission, owner; S_IRGRP = read permission, group; S_IROTH = read permission, others;
    const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    // O_WRONLY = write only; O_CREAT = If pathname does not exist, create it as a regular file.; O_EXCL = Ensure that this call creates the file
    int dest = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode);
    if(dest < 0) // open(), openat(), and creat() return the new file descriptor, or -1 if an error occurred
    {
        perror(argv[2]);
        exit(1);
    }

    ssize_t writer = 0;
    if((writer = write(dest, size, st.st_size)) == -1) // On success, the number of bytes written is returned.  On error, -1 is returned, and errno is set to indicate the cause of the error.
    {
        fprintf(stderr, "Schreibfehler %d: %s\n", errno, strerror(errno));
        free(size);
        return 1;
    }
    else if(writer != st.st_size) // On success, the number of bytes written is returned. So st_size must be similar to reader.
    {
        fprintf(stderr, "Fehler beim Kopieren!\n");
        free(size);
        return 1;
    }

    close(src);
    close(dest);
    free(size);

    return 0;
}