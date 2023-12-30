#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf("compiló\n");
	char *str = "soy";
	char *str2 = "Maria";
	char char1 = 'M';
	//char char2 = 'C';
	int	bytes;

	printf("Test1 \n");
	bytes = printf("Hola %s %s, adios\n", str, str2);
	printf("Bytes --> %d\n", bytes);	
	bytes = ft_printf("Hola %s %s, adios\n", str, str2);
	printf("Bytes --> %d\n", bytes);

	printf("Test2 \n");
	bytes = printf("La letra es %c\n", '0' - 256);
	printf("Bytes --> %d\n", bytes);	
	bytes = ft_printf("La letra es %c\n", '0' - 256);
	printf("Bytes --> %d\n", bytes);

	printf("Test3 \n");
	bytes = printf("Num %i \n", 12345678);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Num %i \n", 12345678);
	printf("Bytes --> %d\n", bytes);

	printf("Test4 \n");
	bytes = printf("El puntero esta en %p\n", &char1);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("El puntero esta en %p\n", &char1);
	printf("Bytes --> %d\n", bytes);

	printf("Test5 \n");
	bytes = printf("UI es %u\n", (unsigned int)INT_MAX);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("El UI es %u\n", (unsigned int)INT_MAX);
	printf("Bytes --> %d\n", bytes);

	printf("Test6 \n");
	bytes = printf("Un hexadecimal es %x\n", 1234);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Un hexadecimal es %x\n", 1234);
	printf("Bytes --> %d\n", bytes);

	printf("Test7 \n");
	bytes = printf("Un hexadecimal MAYUS es %X\n", 1234);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Un hexadecimal MAYUS es %X\n", 1234);
	printf("Bytes --> %d\n", bytes);

	printf("Test8 \n");
	printf("Doble porcentaje %% \n");
	ft_printf("Doble porcentaje %% \n");

	printf("Test10 \n");
	bytes = printf("Ptr: %p\n", (void *)-1);
	printf("Bytes --> %d\n", bytes);
	bytes = ft_printf("Ptr: %p\n", (void *)-1);
	printf("Bytes --> %d\n", bytes);

	printf("Test11 \n");
	printf("%p-%p-%p\n", (void *)LONG_MAX, (void *)0, (void *)INT_MAX);
	ft_printf("%p-%p-%p\n",(void *)LONG_MAX,(void *)0,(void *)INT_MAX);

	printf("Testing 12.0 --> -1\n");
	printf("-1 is %x\n", -1);
	ft_printf("-1 is %x\n", -1);

	printf("Testing 12.0 --> INT MAX + 1\n");
	printf("-1 is %x\n", INT_MAX);
	ft_printf("-1 is %x\n", INT_MAX);
	
	printf("Testing 12.0 --> INT MAX + 1356\n");
	printf("-1 is %x\n", INT_MIN);
	ft_printf("-1 is %x\n", INT_MIN);

	//printf("Test12.1 --> LONG MAX %li \n", LONG_MAX);
	//printf(" The num is %x \n", LONG_MAX);
	//ft_printf(" The num is %x\n", LONG_MAX);

	//printf("Test12.3 LONG MIN \n");
	//printf(" The num is %x \n", LONG_MIN);
	//ft_printf(" The num is %x\n", LONG_MIN);

	return (1);
}