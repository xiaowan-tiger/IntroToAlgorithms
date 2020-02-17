#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR_PER_LINE 128

void exe01();
void exe02();
void exe03();
void exe04();
void exe05();
void exe06();
void exe07();


int main(int argc, char const *argv[])
{
    if(argc > 1) {
        if(*argv[1] == '1') 
            exe01();
        if(*argv[1] == '2') 
            exe02();
        if(*argv[1] == '3') 
            exe03();
        if(*argv[1] == '4') 
            exe04();
        if(*argv[1] == '5') 
            exe05();
        if(*argv[1] == '6') 
            exe06();
        if(*argv[1] == '7') 
            exe07();
    }
    return 0;
}

void exe07() {
}

void exe06() {
}

void exe05() {
}

void exe04() {

}

// implement reverse bits
void exe03() {
    unsigned int ui = 25;

    printf("%u\n", reverse_bits(ui));
}

// shift letter 13 position 
void exe02() {
    int c; 

    while((c = getchar()) != EOF) {
        if ('A' <= c && c <= 'Z'){
            c = (c - 'A' + 13) % 26 + 'A';
        }

        if ('a' <= c && c <= 'z'){
            c = (c - 'a' + 13) % 26 + 'a';
        }
            
        printf("%c", c);
    }
}

// print everything back, except: convert capital letter into small one 
void exe01() {
    int c; 

    while((c = getchar()) != EOF) {
        if ('A' <= c && c <= 'Z')
            c += 32;
        printf("%c", c);
    }
}
