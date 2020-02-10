#include <stdio.h>

int main() {
    char ch;
    int braces = 0;

    while((ch = getchar()) != EOF) {
        if(ch == '{'){
            braces++;
        }
        if(ch == '}'){
            if(braces == 0)
                printf("extra } exists\n");
            else
                braces--;
        }
    }
    if(braces >0)
        printf("%d unmatched opening brace(s)!\n", braces);

    return 0;
}
