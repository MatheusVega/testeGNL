#include "get_next_line.h"

int main(void)
{
    int fd;
    int g;
    char *line;

    fd = open("./teste1", O_RDONLY);
    printf("fd = %d\n", fd);
    while (g)
    {
        g = get_next_line(fd, &line);
        printf("%s\n", line);
    }
    return (0);
}
