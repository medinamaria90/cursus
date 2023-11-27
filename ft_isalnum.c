int	isalnum(int param)
{
	if ((param >= 'A' && param <= 'Z') ||  (param >= 'a' && param <= 'z') || (param >= '0' && param <='9'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d",isalnum('6'));
}
*/
