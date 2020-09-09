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
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

int	ft_strlen(char *c)
{
	int i;

	i = 0;
	while(c[i] != '\0')
		i++;
	return(i);
}

/*
char	*ft_strjoin(char *str1, char *str2)
{
	int 	i;
	int	j;
	int	k;
	char	*join;

	i = 0;
	k = ft_strlen(str1) + ft_strlen(str2);
	if(str1 == NULL || str2 == NULL)
		return(join);
	if(!(join = malloc((k+1)*sizeof(char))))
		return(NULL);
	while (str1[i] != '\0')
	{
		join[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
	{
		join[i + j] = str2[j];
		j++;
	}	
	join[i + j] = '\0';
	return(join);
}*/



int	get_next_line(int fd)
{
	char	*container;
	int	gnlReturn;
	int	x = 0;
	char	*temp;
	int	bs;

	
	container = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	temp = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));

	gnlReturn = read(fd, container, BUFFER_SIZE);

	printf("caracteres até o \\n: %d\n", ft_strlen(container));
	while(x < BUFFER_SIZE)
	{
		while (container[x] != )
			temp[x] = container[x++];
	}
	printf("Esse é o conteúdo da variável temporária: %s\n", temp);
	

	//o read precisa do file descriptor (código encontrado quando é feita a função open
	//depois idsso precisa de um espaço/container, onde é armazenado o que foi lido
	//e ainda, precisa saber quanto ele quer ler desse arquivo
	
	//printf("aqui está o que foi encontrato dentro do arquivo: %s\n", container);
	//printf("aqui está o output do meu temp: %s\n", temp);
	
	//printf("aqui estou armazenando o retorno da função read: %d\n", gnlReturn);
	//printf("aqui estou armazenando o output do meu fd: %d\n", fd);
	return(fd);
}


/////VALIDATION/////
int	ft_openfile(void)
{
	int	fd;
	char	*filename = "test.txt";

	fd = open(filename, O_RDONLY);
	return(fd);
}

int	main(void)
{
	int	fd;
	
	//printf("%d\n", ft_openfile());
	fd = ft_openfile();
	get_next_line(fd);
	return(0);
}
