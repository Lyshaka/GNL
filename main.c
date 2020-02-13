#include <libc.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	(void)ac;
    char *line;
    int fd1 = open(av[1], O_RDONLY);
    int ret1;
	do
	{
		ret1 = get_next_line(fd1, &line);
		printf("1 | %s\n", line);
	} while (ret1);
}
