/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:01:14 by jteixeir          #+#    #+#             */
/*   Updated: 2020/12/13 18:50:23 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif


int a_line_exists(char *s)
{
	int i;

	i = 0;

	while(s[i])
	{
		if(s[i] == '\n')
		{
			printf("A line has been found\nThe position is %d\n", i);
			return(1);
		}
		i++;
	}
	return(0);
}

int reading_file(int fd)
{
	int read_return;
	char *buffer;

	buffer = (char*)malloc(BUFFER_SIZE + 1);

	printf("This is my test file context:\n");
	while((read_return = read(fd, buffer, BUFFER_SIZE)>0))
	{
		printf("%s", buffer);
		read_return--;
	}
	printf("\n\n");
	a_line_exists(buffer);
	return(0);
}



int	main(void)
{
	int fd;
	char *file = "teste1.txt";

	fd = open(file, O_RDONLY);
	printf("This is my File Descriptor: %d\n\n", fd);

	reading_file(fd);
	return (0);
}
