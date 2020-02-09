#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"


int main(int argc, char const *argv[])
{
    int ch = 0;
    
#if 0
    // 1.2
    int line = 0, at_begining = 1;
    while( (ch = getchar()) != EOF ){
        if( at_begining ){
            at_begining = 0;
            line += 1;
            printf("%d: ", line);
        }
        putchar(ch);
        if( ch == '\n' )
            at_begining = 1;
    }

#endif  

#if 0 
    // 1.3
    signed char checksum = -1;
    

    while( (ch = getchar()) != EOF ){
        checksum += ch;
        if( ch == '\n' )
            printf( "%d\n", checksum );
    }
#endif


#if 0
    char input[1000];
    char longest_line[1000];
    int longest_len = 0;

    while( gets(input) ){
        int len = strlen(input);
        if( len > longest_len ){
            longest_len = len;
            strcpy(longest_line, input);
        }
    }
    printf("longest line is: %s\n", longest_line);

#endif

#if 1
    printf("char: %d ~ %d; %d\n", SCHAR_MIN, SCHAR_MAX, UCHAR_MAX); 
    printf("short: %d ~ %d; %d\n", SHRT_MIN, SHRT_MAX, USHRT_MAX); 
    printf("int: %d ~ %d; %u\n", INT_MIN, INT_MAX, UINT_MAX); 
    printf("long: %ld ~ %ld; %lu\n", LONG_MIN, LONG_MAX, ULONG_MAX); 
#endif
    return 0;
}
