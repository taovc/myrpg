/*
** EPITECH PROJECT, 2021
** read_file
** File description:
** Read a file and return a buffer
*/

#include "my.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int open_file(char const *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("COULDNT OPEN THE FILE!\n");
        return 84;
    }
    return fd;
}

char *get_buffer(char *buffer, int size, int fd)
{
    int offset = 0;
    int len = read(fd, buffer + offset, size);

    if (len <= 0)
        return NULL;
    while (len > 0) {
        offset = offset + len;
        len = read(fd, buffer + offset, size - offset);
    }
    buffer[offset] = '\0';
    buffer[offset + 1] = '\0';
    return buffer;
}

char *read_file(char *filepath)
{
    int fd = open_file(filepath);
    struct stat caracnumber;
    char *buffer = NULL;

    if (fd == 84)
        return buffer;
    stat(filepath, &caracnumber);
    buffer = malloc(sizeof(char) * (caracnumber.st_size + 2));
    if (buffer == NULL)
        return buffer;
    buffer = get_buffer(buffer, caracnumber.st_size + 1, fd);
    if (buffer == NULL)
        return buffer;
    close(fd);
    return buffer;
}