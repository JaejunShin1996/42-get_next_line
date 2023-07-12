/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 16:12:21 by jaeshin           #+#    #+#             */
/*   Updated: 2023/07/12 22:52:08 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_fd(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	return (fd);
}

int	main(void)
{
	int		fd;
	char	*one_line;

	fd = read_fd("text.txt");
	while ((one_line = get_next_line(fd)))
	{
		printf("%s", one_line);
	}
	return (0);
}
