#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_contain_alpha(string value) ;

int main(int argc, string argv[])
{
    if (argc == 2 && check_contain_alpha(argv[1]) == 0)
    {

        int k = atoi(argv[1]);
        string plainText = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, length = strlen(plainText); i < length; i++)
        {
            int cipherText;
            if (isalpha(plainText[i]))
            {
                if (islower(plainText[i]))
                {
                    cipherText = (plainText[i] + k - 97) % 26 + 97 ;
                }
                else
                {
                    cipherText = (plainText[i] + k - 65) % 26 + 65 ;
                }
            }
            else
            {
                cipherText = plainText[i];
            }
            printf("%c", cipherText);
        }
        printf("\n");
        return 0;

    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

int check_contain_alpha(string value)
{
    int isContainAlpha = 0 ;
    for (int i = 0 ; i < strlen(value); i++)
    {
        if (isalpha(value[i]))
        {
            isContainAlpha += 1;
        }
    }
    return isContainAlpha;
}