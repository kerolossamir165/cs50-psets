#include <stdio.h>
#include <string.h>

int strCmp(char *s , char *l);

int main (void) {
    printf("Is identical ? %s\n", strCmp("kerolos", "kerolos") == 0 ? "Yes" : "NO");
}


// compare two address of each character
int strCmp (char *s , char *l)
{
    int isIdentical = 0;
    while(*s != '\0' && *l != '\0') {
        if(*s == *l) {
            s++;
            l++;
        } else if (*s > *l) {
           isIdentical = 1;
           break;
        } else {
          isIdentical = -1;
          break;
        }
    }
    return isIdentical;
}


