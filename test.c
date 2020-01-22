/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:54:49 by julnolle          #+#    #+#             */
/*   Updated: 2020/01/22 16:01:52 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strchr_pos(const char *s, int c)
{
	// max BUF 8384551
	size_t pos;

	pos = 0;
	while (*s != c)
	{
		if (*s == '\0')
			return (-1);
		s++;
		pos++;
	}
	return (pos);
}

int main(int ac, char const *av[])
{
	if (ac == 2)
	{
		printf("%d\n", ft_strchr_pos(av[1], 'a'));
	}
	return 0;
}