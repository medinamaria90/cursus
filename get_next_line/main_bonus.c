#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void) 
{
	printf("\nTest4 line 1 --> :\n");
    int file_descriptor2 = open("test4_lines_and_nl.txt", O_RDONLY);
	printf("%s\n", get_next_line(file_descriptor2));

	printf("\nTest5 line 1 --> :\n");
	int file_descriptor3 = open("test5_fewlines.txt", O_RDONLY);
	printf("%s\n", get_next_line(file_descriptor3));

	printf("\nTest4 line 2 --> :\n");
	printf("%s\n", get_next_line(file_descriptor2));

	printf("\nTest5 line 2 --> :\n");
	printf("%s\n", get_next_line(file_descriptor3));

	printf("\nTest4 line 3 --> :\n");
	printf("%s\n", get_next_line(file_descriptor2));

	printf("\nTest5 line 3 --> :\n");
	printf("%s\n", get_next_line(file_descriptor3));

	printf("\nTest4 line 4 --> :\n");
	printf("%s\n", get_next_line(file_descriptor2));

	printf("\nTest5 line 4 --> :\n");
	printf("%s\n", get_next_line(file_descriptor3));

    return (0);
}