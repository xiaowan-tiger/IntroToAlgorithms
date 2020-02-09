#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_number( int columns[], int max );
void rearrange( char *output, char const *input, int n_columns, int columns[] );

int main( void ){
	int columns[MAX_COLS];
	int n_columns;
	char output[MAX_INPUT];
	char input[MAX_INPUT];

	n_columns = read_column_number( columns, MAX_COLS );

	while( gets( input ) != NULL ){
		printf( "original input was: %s\n", input );
		rearrange( output, input, n_columns, columns );
		printf( "rearranged line: %s\n", output);
	}
}

int read_column_number( int columns[], int max ){
	int num = 0;
	int ch;
	while( num < max && scanf( "%d", &columns[num] ) == 1 && columns[num] >= 0 )
		num += 1;

	if( num % 2 != 0){
		puts( "Last input number was not in pair\n" );
		exit(EXIT_FAILURE);
	}
	
	while( (ch = getchar()) != EOF && ch != '\n' )
		;

	return num;
}

void rearrange( char *output, char const *input, int n_columns, int columns[] ){
	int output_col;
	int len;
	int col;
	int nchars;	
	len = strlen( input );
	output_col = 0;
	for( col = 0; col < n_columns; col += 2 ){
		nchars = columns[col + 1] - columns[col] + 1;

		if( columns[col] > len || output_col == MAX_COLS - 1 )
			break;

		if( output_col + nchars >= MAX_COLS )
			nchars = MAX_COLS - output_col - 1;

		strncpy( output + output_col, input + columns[col], nchars );

		output_col += nchars;	
	} 
}
