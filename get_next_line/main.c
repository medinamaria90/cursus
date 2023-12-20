# include <stdio.h>
#include "get_next_line.h"

int main(void) 
{
	printf("\nTest Invalid --> User input:\n\n");
    printf("%s\n", get_next_line(-2));

	printf("\nTest 0 --> empty:\n\n");
    char *line;
    int file_descriptor = open("test0_empty_file.txt", O_RDONLY);
    int line_number = 1;
    while ((line = get_next_line(file_descriptor)) != NULL//
	 && (line_number < 15)) 
	{
        printf("%d: %s\n", line_number, line);
        line_number++;
    }

	printf("\nTest 1 --> NL:\n\n");
    file_descriptor = open("test1_nl.txt", O_RDONLY);
	line_number = 1;
    while ((line = get_next_line(file_descriptor)) != NULL//
	 && (line_number < 15)) 
	{
        printf("%d: %s\n", line_number, line);
        line_number++;
    }

	printf("\nTest 2 --> OneLine:\n\n");
    file_descriptor = open("test2_one_line.txt", O_RDONLY);
	line_number = 1;
    while ((line = get_next_line(file_descriptor)) != NULL//
	 && (line_number < 15)) 
	{
        printf("%d: %s\n", line_number, line);
        line_number++;
    }

	printf("\nTest 3 --> FewLines:\n\n");
    file_descriptor = open("test3_few_empty_lines.txt", O_RDONLY);
	line_number = 1;
    while ((line = get_next_line(file_descriptor)) != NULL//
	 && (line_number < 15)) 
	{
        printf("%d: %s\n", line_number, line);
        line_number++;
    }

	printf("\nTest 4 --> Lines and NLs:\n\n");
    file_descriptor = open("test4_lines_and_nl.txt", O_RDONLY);
    line_number = 1;
    while ((line = get_next_line(file_descriptor)) != NULL) 
	{
        printf("%d: %s\n", line_number, line);
        line_number++;
    }

	printf("\nTest 5 --> Fewlines:\n\n");
    file_descriptor = open("test5_fewlines.txt", O_RDONLY);
    line_number = 1;
    while ((line = get_next_line(file_descriptor)) != NULL) 
	{
        printf("%d: %s\n", line_number, line);
        line_number++;
    }
    
    //printf("\nTest Stdin --> User input:\n\n");
    //printf("%s\n", get_next_line(0));

    return (0);
}