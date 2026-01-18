#include "cub3d.h"

static void print_map(char **array)
{
	int	i;
	int	j;

	if (!array || !*array)
		return ((void)printf("??\n"));
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			write(STDOUT_FILENO, &array[i][j], 1);
			j++;
		}
		i++;
	}
}

void	print_data(t_map map)
{
	ft_printf_fd(STDOUT_FILENO, "MATRIX\n");
	print_map(map.matrix);
	ft_printf_fd(STDOUT_FILENO, "\n\n");
	ft_printf_fd(STDOUT_FILENO, "CPY MAP\n");
	print_map(map.matrix);
	ft_printf_fd(STDOUT_FILENO, "\n\n");
	ft_printf_fd(STDOUT_FILENO, "LINES\n");
	print_map(map.lines);
	ft_printf_fd(STDOUT_FILENO, "\n\n");
	ft_printf_fd(STDOUT_FILENO, "Start: ");
	ft_putnbr_fd(map.start, STDOUT_FILENO);
	ft_printf_fd(STDOUT_FILENO, "\nWidth: ");
	ft_putnbr_fd(map.width, STDOUT_FILENO);
	ft_printf_fd(STDOUT_FILENO, "\nHeigth ");
	ft_putnbr_fd(map.height, STDOUT_FILENO);
	ft_printf_fd(STDOUT_FILENO, "\n");
	ft_printf_fd(STDOUT_FILENO, "\n\n");
}
