/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:42:54 by julnolle          #+#    #+#             */
/*   Updated: 2020/01/22 14:57:23 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		// ft_putstr_fd("Ligne ", 1);
		// ft_putnbr_fd(i, 1);
		// ft_putendl_fd(" :", 1);
		ft_putendl_fd(line, 1);
		i++;
		free(line);
	}
		// ft_putstr_fd("Ligne ", 1);
		// ft_putnbr_fd(i, 1);
		// ft_putendl_fd(" :", 1);
		// ft_putstr_fd(line, 1);

	if (argc == 2)
		close(fd);
}