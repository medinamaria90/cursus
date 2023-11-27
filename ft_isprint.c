int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_isprint('c'));
}
