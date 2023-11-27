int	isalpha(int param)
{
	if (param >= 'A' && param <= '>')
		return (1);
	else if (param >= 'a' && param <= 'z')
		return (2);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d",isalpha('w'));
}
*/
