#include "get_next_line.h"

int main(void)
{
    int i;
    int fd1;
    int fd2;
    int fd3;
    char *line;
    int b;

    i = 1;
    b = 1;

    printf("%d\n", fd1 = open("teste1", O_RDONLY));
    // printf("%d\n", fd2 = open("teste2", O_RDONLY));
    // printf("%d\n", fd3 = open("teste3", O_RDONLY));

    while (i || b)
    {
        i = get_next_line(fd1, &line);
        printf("%s\n", line); 
        // b = get_next_line(fd2, &line);
        // printf("%s\n", line);
        // get_next_line(fd3, &line);
        // printf("%s\n", line); 
    }
}
