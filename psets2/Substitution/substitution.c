#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        bool valid = false;
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            for (int j = i + 1 ; j < len ; j++)
            {
                if (isalpha(argv[1][i]) && tolower(argv[1][i]) != tolower(argv[1][j]))
                {
                    valid = true;
                }
                else
                {
                    printf("Usage: ./substitution key\n");
                    return 1;
                }
            }
        }

        if (valid)
        {
            string key = argv[1];
            string plain_text = get_string("Plain Text: ");
            printf("ciphertext: ");
            for (int i = 0 ; i < strlen(plain_text) ; i++)
            {
                int ciphertext = 0;
                if (islower(plain_text[i]))
                {
                    ciphertext = tolower(argv[1][plain_text[i] - 97]);
                }
                else if (isupper(plain_text[i]))
                {
                    ciphertext = toupper(argv[1][plain_text[i] - 65]);
                }
                printf("%c", ciphertext);
            }
            printf("\n");
        }


    }
    else
    {
        printf("./substitution : User key \n");
        return 1;
    }
}