#include <stdio.h>
#include <errno.h>

int	ft_openfile(void)
{
	FILE *fp;
	fp = fopen("essearquivonexiste.txt", "r");
	if(fp == NULL)
	{
		printf("File not okay, errno = %d\n", errno);
		return (1);
	}
	fclose(fp);
	printf("File okay\n");
	return(0);
}


int	main()
{
	printf("function output %d\n", ft_openfile());
	return(0);
}
