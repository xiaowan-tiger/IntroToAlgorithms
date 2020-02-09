#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_columns_number( int columns[], int max );
void rearrange( char *output, char const *input, int n_columns, int columns[] );

int main(int argc, char const *argv[])
{
    int columns[MAX_COLS];
    int n_columns;
    char output[MAX_INPUT];
    char input[MAX_INPUT];

    n_columns = read_columns_number( columns, MAX_COLS );

    while( gets( input ) != NULL ){
        printf("original input was: %s\n", input);
        rearrange( output, input, n_columns, columns );
        printf("rearranged line: %s\n", output);
    }

    return 0;
}

int read_columns_number( int columns[], int max ){
    int num = 0;
    int ch;

    while( num < max && scanf( "%d", &columns[num]) == 1 && columns[num] >= 0)
        num += 1;

    while( (ch = getchar()) != EOF && ch != '\n' )
        ;

    return num;
}

void rearrange( char *output, char const *input, int n_columns, int columns[] ){
    int col;
    int output_col;
    int len;
    int nchars;

    len = strlen(input);
    output_col = 0;

    for( col = 0; col < n_columns; col += 2 ){
        if( (n_columns % 2) != 0 && (col + 1) == n_columns )
            nchars = len - columns[col];
        else
            nchars = columns[col + 1] - columns[col] + 1;        
        
        if( output_col == MAX_COLS - 1 || columns[col] > len)
            break;
        if( output_col + nchars >= MAX_COLS )
            nchars = MAX_COLS - 1;

        strncpy( output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
}