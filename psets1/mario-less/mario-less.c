#include <cs50.h>
#include <stdio.h>
// less
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int row = 0 ; row < height  ; row++)
    {
        for (int column = 1 ; column <= height ; column++)
        {
            if (column > height - row - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

}