#include <stdio.h>
#include <string.h>
#define MAX_COLS 20

void exe_2();
void exe_3();
void exe_4();
void read_columns_numbers(int[], int); // exe 05
void rearrange(char*, const char*, int, int[]); // exe 06

int main() {
    exe_4();    
    return 0;
}

// exe06
int read_columns_number( int columns[], int max ){
    int num = 0;
    int ch;

    while( num < max && scanf( "%d", &columns[num]) == 1 && columns[num] >= 0)
        num += 1;

    while( (ch = getchar()) != EOF && ch != '\n' )
        ;

    return num;
}

// exe 05
void rearrange( char *output, const char *input, int n_columns, int columns[] ){
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

// read in input from user until EOF, 
// print the maximum char counts of a line
// assume no more than 1000 chars per line
void exe_4() {
    int max_count, count;
    char in[1000];
    max_count = -1;
    while(gets(in) != NULL) {
        count = strlen(in);
        printf("%d\n", count);
        if(count > max_count)
            max_count = count;
    }
    printf("max length is %d\n", max_count);
}

// read in char, and plus it into a signed char -- checksum;
// then print it out
void exe_3() {
    signed char checksum = -1;
    char ch;
    while((ch = getchar()) != EOF)
        checksum += ch;
    printf("%d\n", checksum);
}

//     read user input(multipul lines) and just print it back
//     and starts with line number
void exe_2() {
    char ch;
    int line_number = 0;
    int begining = 1;
    while((ch = getchar()) != EOF) {
        if(begining) {
            begining = 0;
            line_number++;
            printf("%d: ", line_number);
        }
        printf("%c", ch);
        if(ch == '\n')
            begining = 1;
    }
}
