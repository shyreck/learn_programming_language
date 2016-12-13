#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX_COLS 20 //the max cols
#define  MAX_INPUT 1000 //the max input lines

int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input,
     int n_columns, int const columns[]);

int main()
{
    int n_columns;
    int columns[MAX_COLS]; //columns need to be handled
    char input[MAX_INPUT]; //array holding inputs
    char output[MAX_INPUT]; //array holding outputs

    //read column number
    n_columns = read_column_numbers(columns, MAX_COLS);

    //read, handle and print the rest inputs
    while(gets(input) != EOF)
	{
	printf("Original input : %s\n", input);
	rearrange(output, input, n_columns, columns);
	printf("Rearranged line : %s\n", output);
	}

	return EXIT_SUCCESS;
}

    //read column number, ignore exceeding values
int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;

    while(num < max && scanf("%d", &columns[num]) == 1 
	&& columns[num] >= 0)
	num += 1;

    //ensure number of columns is even
    if(num % 2 != 0)
    {
	puts("Last column number is not paired.");
	exit(EXIT_FAILURE);
    }
    //abandon content after the negative number in this line
    while((ch = getchar()) != EOF && ch != '\n')
	;

    return num;
}

    //handle input line, combine specified chars and end with NUL
void rearrange(char *output, char const *input,
    int n_columns, int const columns[])
{
    int col; //subscript of column
    int output_col; //count output columns
    int len; // length of input line

    len = strlen(input);
    output_col = 0;

    //handle every pair of column
    for(col = 0; col < n_columns; col += 2)
    {
	int nchars = columns[col + 1] - columns[col] + 1;

	//if input line ends or exceed the max, exit
	if(columns[col] >= len || output_col == MAX_INPUT - 1)
	    break;

	//if there is no space for data, end
	if(output_col + nchars > MAX_INPUT - 1)
	    nchars = MAX_INPUT - output_col - 1;

	//copy relative data
	strncpy(output + output_col, input + columns[col], nchars);
	output_col += nchars;
    }
    output[output_col] = '\0';
}
