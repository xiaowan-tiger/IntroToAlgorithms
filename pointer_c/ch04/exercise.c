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


int main(int argc, char const *argv[])
{
    if(argc > 1) {
        if(*argv[1] == '1') 
            exe01();
        if(*argv[1] == '2') 
            exe02();
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
    char *tmp;
    tmp = string;
    int slow, fast;
    slow = fast = 0;
    int careful = 0;
    while(tmp[fast] != '\0'){
        if(tmp[fast] == ' ') {
            if(careful)
                fast++;
            else {
                string[slow++] = tmp[fast++];
                careful = 1;
            }
        } else {
            careful = 0;
            string[slow++] = tmp[fast++];
        }
    }
    string[slow] = '\0';
}

void exe07() {
    char s1[600] = "abd  bd ;\nha    ha     ha   aksdj a;lksj f     a;lsjd al     a;lsdj                   asdf";
    printf("%s\n", s1);
    deblank(s1);
    printf("  removed repeated blank is: \n%s\n", s1);

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

