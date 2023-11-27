#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%zu\n", ft_strlen("hola que pasa"));
}
*/
