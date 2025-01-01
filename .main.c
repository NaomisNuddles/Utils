#include "get_next_line.h"
#include "ft_printf.h"
#include <sys/stat.h>
#include <fcntl.h>

int	main()
{
	int		fd[10];
	char	*txt[] = {"", "tests/empty.txt", "tests/char.txt", "tests/nlx5.txt", "tests/line.txt", \
	"tests/line_nl.txt", "tests/line_nlx2_line.txt", "tests/line_nlx2_line_nl.txt", \
	"tests/sentences.txt", "tests/random.txt"};
	int		i;
	int		j;
	char	*str;

	i = 1;
	str = 0;
	fd[0] = -1;
	while (i <= 9)
	{
		fd[i] = open(txt[i], O_RDONLY);
		i++;
	}
	i = 0;
	ft_printf("\033[1;34mFOR BUFFER_SIZE: %i\n\n\033[0;39m", BUFFER_SIZE);
	while (i <= 9)
	{
		j = 1;
		ft_printf("Testing fd % i at %s ...\n\n", fd[i], txt[i]);
		str = get_next_line(fd[i]);
		while (str && *str)
		{
			ft_printf("	line %.1i:%s$\n", j, str);
			str = get_next_line(fd[i]);
			j++;
		}
		ft_printf("	line %.1i:%s$\n\n", j, str);
		ft_printf("... DONE\n\n");
		i++;
	}
	i--;
	ft_printf("Testing fd % i at %s ...\n\n", fd[i], txt[i]);
	fd[i] = open(txt[i], O_RDONLY);
	ft_printf("	line 1:%s$\n", get_next_line(fd[i]));
	ft_printf("	line 2:%s$\n", get_next_line(fd[i]));
	close(fd[i]);
	ft_printf("> CLosed - Read\n");
	ft_printf("	line 0:%s$\n", get_next_line(fd[i]));
	fd[i] = open(txt[i], O_RDONLY);
	ft_printf("	line 1:%s$\n", get_next_line(fd[i]));
	ft_printf("	line 2:%s$\n", get_next_line(fd[i]));
	close(fd[i]);
	fd[i] = open(txt[i], O_RDONLY);
	ft_printf("> CLosed - Opened - Read\n");
	ft_printf("	line 0:%s$\n", get_next_line(fd[i]));
	ft_printf("... DONE\n\n");

	ft_printf("\033[1;34mEND OF BUFFER_SIZE: %i\n\n\033[0;39m", BUFFER_SIZE);
}
