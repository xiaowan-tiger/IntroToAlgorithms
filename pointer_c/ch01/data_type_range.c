#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "limits.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

#define MAX_DIGIT_LENGTH 32
#define MAX_PRINT_LENGTH 66


void print_binary(uint32 num) {
    uint32 arr[MAX_DIGIT_LENGTH];
    uint32 d = 0;
    int len = 0;
    while(num != 0) {
        arr[len] = num % 2;
        len++;
        num /= 2;
    }
    int len0 = MAX_DIGIT_LENGTH - len;
    while(len0 > 0){
        arr[len++] = 0;
        len0--;
    }    
    len--;
    while(len >= 0) {
        printf("%u", arr[len]);
        if ((len % 8 == 0) && (len != 0))
            printf(",");
        len--;
    }
    printf("\n");
    memset(arr,0,(unsigned long)sizeof(arr));
}

void print_title(char* title){
    int len = strlen(title);
    char *star = "*";
    int len_s1 = (MAX_PRINT_LENGTH - len) / 2;
    int len_s2 = MAX_PRINT_LENGTH - len - len_s1;

    char *s1 = malloc(len_s1 + 1);
    memset(s1, 0, len_s1 + 1);
    char *s2 = malloc(len_s2 + 1);
    memset(s2, 0, len_s2 + 1);

    while(len_s1--)
        strcat(s1,star);
    while(len_s2--)
        strcat(s2,star);
    printf("%s", s1);
    printf("%s", title);
    printf("%s\n", s2);
}

int main(int argc, char const *argv[])
{
    // char: signed & unsigned   
    unsigned char a_u8 = 255;
    signed char a_8 = -128;
    signed char a2_8 = 127;

    printf("var_name \t | value \t| Binary                               |\n");
    printf("\n");
    
    // print_title("                                                                                                  ");
    printf("unsigned a_u8:\t | %d\t\t| ", a_u8);
    print_binary(a_u8);

    printf("signed a_8:\t | %d\t\t| ", a_8);
    print_binary(a_8);

    printf("signed a2_8:\t | %d\t\t| ", a2_8);
    print_binary(a2_8);
    printf("\n");
    
    unsigned short a_u16 = 65535;
    signed short a_16 = -65536 / 2 ;
    signed short a2_16 = 65536 / 2 - 1;
    printf("unsigned a_u16:\t | %d\t| ", a_u16);
    print_binary(a_u16);

    printf("signed a_16:\t | %d\t| ", a_16);
    print_binary(a_16);
    printf("signed a2_16:\t | %d\t| ", a2_16);
    print_binary(a2_16);

    printf("\n");
    unsigned long int bb;
    printf("%lu", sizeof(bb));
    return 0;
}
