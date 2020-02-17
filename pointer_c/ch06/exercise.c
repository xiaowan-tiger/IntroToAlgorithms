#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    char *tmp = str;

    for (; *tmp != '\0'; tmp++)
        ;
    tmp--;

    
    while(str < tmp){
        char c;
        c = *str;
        *str++ = *tmp;
        *tmp-- = c;
    }
}

char* find_char(char const *source, char const *chars) {
    const char *tmp = source;
    while(*chars != '\0'){
        while(*tmp != '\0'){
            if(*chars == *tmp)
                return (char *)tmp;
            else
                tmp++;
        }
        tmp = source;
        chars++;
    }
    return NULL;
}

int del_substr(char *str, char const *substr) {
    const char *tmp = substr;
    char *source = str;
    int offset = -1;

    // find offset
    while(*source != '\0') {
        while(*tmp != '\0') {
            if(*source == *tmp){
                if(offset == -1)
                    offset = source - str;
                source++;
                tmp++;
            } else{
                if(offset != -1)
                    source = str + offset;
                break;
            }
        }
        if (*tmp == '\0'){
            // substr loop complete -> substr found, exit loop
            break;
        } else {
            // tmp loop break in the middle, increase source and check from next char, reset tmp
            tmp = substr;
            source++;
        }
    }
    if(offset != -1){
        source = str + offset;
        tmp = substr;
        char *fast = source;

        while(*tmp != '\0'){
            fast++;
            tmp++;
        }
        while(*fast != '\0') 
            *source++ = *fast++;
        *source = '\0';
        return 1;
    } else 
        return 0;
}

int main() {
    char s1[] = "12345890";
    //reverse_string(s1);
    char s2[] = "458";
    //printf("Found %s in %s\n", find_char(s1, "420sfjoaisj"), s1);
    printf("original string is %s\n", s1);
    int found = del_substr(s1, s2);
    if(found)
        printf("After delete %s is: %s\n",s2, s1);
    else
        printf("not found!\n");
    return 0;
}
