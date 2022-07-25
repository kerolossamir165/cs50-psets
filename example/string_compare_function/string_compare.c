#include <stdio.h>
#include <string.h>

int strCmp(char *s , char *l);

int main (void) {
    printf("Is identical ? %s\n", strCmp("kerolos", "kerolos") == 0 ? "Yes" : "NO");
}


// compare two address of each character
int strCmp (char *s , char *l)
{

    for (int i = 0 , n = strlen(s) ; i < n ; i++ )
    {
        if (&s[i] == &l[i])
        {
            return 0;
        }
    }
    return 1;
}