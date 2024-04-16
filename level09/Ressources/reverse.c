#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    char buff[4096];
    if (argc != 2)
    {
        printf("Usage ./reverse filename\n");
        exit(1);
    }
    int fd_in = open(argv[1], O_RDONLY);
    int read_size = read(fd_in, buff, 4096);
    for (int i = 0; i < read_size - 1; i++) {
        buff[i] -= i;
        write(1,buff + i,1);
    }
    write(1, "\n", 1);
    return (0);
}