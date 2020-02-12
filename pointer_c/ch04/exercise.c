#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CHAR_PER_LINE 128

void exe01();
void exe02();
void exe04();
void exe05();
void exe06();
void exe07();

int main() {
    exe07();
    return 0;
}

void copy_n(char dst[], char src[], int n){
    
    printf("%s, %s\n", dst, src);
    
    int dst_idx, src_idx;
    src_idx = 0;
    for(dst_idx = 0; dst_idx < n; dst_idx++){
        dst[dst_idx] = src[src_idx];
        if(src[src_idx] != '\0')
            src_idx++;
    }
}      

void deblank(char string[]) {
    int i = 0;
    int start = -1;
    size_t len = strlen(string);
    while(string[i++] != '\0') {
        if (string[i] == ' '){
            if((start != -1) && (i - start) == 1) // two continues blank
                if((i + 1) <= len - 1){
                    copy_n(string + i, string + i + 1, len - i - 1);
                }
                else
                    string[i] = '\0';
            else 
                start = i;
        }
        
    }
}

void exe07() {
    char *s1 = "  i";
    deblank(s1);
    printf("%s\n", s1);

}

int substr(char dst[], char src[], int start, int n) {
    size_t len = strlen(src);
    // error case
    if( (start < 0) || (n < 0) || (start >= len) || (len == 0)){
        return 0;
    } else {
        int index = start;
        int i = 0;
        for(; i < n; i++){
            dst[i] = src[start++];
            if(start > len)
                break;
        }
        dst[i] = '\0';
        return i;
    }
}

// implement substr and test it
void exe06() {
    char s1[100] = "";
    char s2[40] = "12345678901234567890";

    int l1 = substr(s1, s2, -5, 10);
    printf("copied %d char into s1, and s1 is %s\n", l1, s1);
    int l2 = substr(s1, s2, 9, 50);
    printf("copied %d char into s1, and s1 is %s\n", l2, s1);
    int l3 = substr(s1, s2, 22, 50);
    printf("copied %d char into s1, and s1 is %s\n", l3, s1);
    int l4 = substr(s1, s2, 0, 50);
    printf("copied %d char into s1, and s1 is %s\n", l4, s1);
}



// print repeated line
void exe05() {

    char buffer[MAX_CHAR_PER_LINE] = "";
    char output[MAX_CHAR_PER_LINE * 10] = "";
    char old[MAX_CHAR_PER_LINE] = "";
    int ch;
    int index = 0;
    while(index < (MAX_CHAR_PER_LINE - 1) && (ch = getchar()) != EOF) {
        buffer[index++] = ch;
        if(ch == '\n') {
            int compare = strcmp(buffer, old);
            if(strcmp(buffer, old) == 0)
                strncat(output, buffer, index);
            else {
                buffer[index++] = '\0';
                strncpy(old, buffer, (size_t)index);
            }
            index = 0;
        }
    }
    printf("%s\n", output);
}

// copy_n(char dst[], char src[], int n);
void exe04() {
    char s1[100] = "";
    char s2[50] = "hello world";

    copy_n(s1, s2, 9);
    printf("%s\n", s1);
}


int sqr_root(int n) {
    double new, old;
    old = 1;

    for(int i = 0; i < 50; i++) {
        new = (old + (n / old) ) / 2;
        if( new == old)
            break;
        old = new;
    }
    return (int)new + 1;
}

// print all the primes btw 1~100
void exe02() {
    printf("1, ");
    int num = 2;
    for(; num <=100; num++){
        int sqrRoot = sqr_root(num);
        int i = 2;
        for(; i < sqrRoot; i++) {
            if(( num % i) == 0)
                break;
        }
        if(i == sqrRoot)
            printf("%d, ", num);
    }
    printf("\n");
}

// use iteration to sovle the squared root of a input number from user
void exe01() {
    double number;
    scanf(" %lf", &number);

    double new, old;
    old = 1;

    for(int i = 0; i < 50; i++) {
        new = (old + (number / old) ) / 2;
        if( new == old)
            break;
        old = new;
        printf("%lf\n", old);
    }
    printf("the squared root of %lf is %lf\n", number, new);
}

