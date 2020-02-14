#include <libc.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int *fd;
	int *ret;
	int nb; //nombre file descriptor
	int v;
	int i;

	if (ac < 2)
		return (-1);
	if (!(fd = malloc(sizeof(int) * ac - 1)))
		return (-1);
	if (!(ret = malloc(sizeof(int) * ac - 1)))
		return (-1);
	nb = 0;
	i = 0;
	while (nb < ac)
	{
		fd[nb] = open(av[nb + 1], O_RDONLY);
		nb++;
	}
	do
	{
		i++;
		printf("Ligne %d --------------\n", i);
		nb = 0;
		v = 0;
		while (nb < ac - 1)
		{
			ret[nb] = get_next_line(fd[nb], &line);
			printf(" FD %d   | %s\n", nb + 1, line);
			if (ret[nb] > 0)
				v++;
			nb++;
		}
	} while (v > 0);
	return (0);
}
