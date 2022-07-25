#include <stdio.h>

typedef char* string;
int strCmp(char *s , char *l);

int main (void) {
    printf("Is identical ? %s\n", strCmp("kerolos", "kerolos") == 0 ? "Yes" : "NO");
}

int strCmp (char *s , char *l)
{
    for (int i = 0 ; i < 3 ; i++ )
    {
        if (&s[i] == &l[i])
        {
            return 0;
        }
    }
    return 1;
}