/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteixeir <jteixeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:01:14 by jteixeir          #+#    #+#             */
/*   Updated: 2020/09/05 20:55:33 by jteixeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif






int	main(void)
{
	int fd;
	char *file = "teste1.txt";

	fd = open(file, O_RDONLY);
	printf("%d\n", fd);

	
	if((fd < 0) || (BUFFER_SIZE <= 0)) //incluir o tratamento da !line
		return(-1);

	int rr;
	char buffer[5];
	
	while((rr = read(fd, buffer, BUFFER_SIZE)>0))
	{
		printf("%s", buffer);
		--rr;
	}


	return (0);
}
