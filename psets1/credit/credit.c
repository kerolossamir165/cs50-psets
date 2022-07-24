#include <cs50.h>
#include <stdio.h>

//AMERX 15 STRT 34 OR 37
//MC 16 STRT 51, 52, 53, 54, 55
//VZA 13 OR 16 STRT 4

int get_length_int(long value);
long get_division(int count);

int main(void)
{
    long creditNum ;
    int sum = 0 ;
    do
    {
        creditNum = get_long("give me the credit card number,Please? \n");
    }
    while (creditNum < 0);

    long copyCreditNum = creditNum;

    while (copyCreditNum > 0)
    {
        int lastDigit = copyCreditNum % 10 ;
        sum += lastDigit ;
        copyCreditNum = copyCreditNum / 100;
    }

    copyCreditNum = creditNum / 10 ;

    while (copyCreditNum > 0)
    {
        int lastDigit = copyCreditNum % 10 ;
        int lastDigitTimes2 = lastDigit * 2;
        sum += lastDigitTimes2 % 10  + (lastDigitTimes2 / 10) ;
        copyCreditNum = copyCreditNum / 100;
    }

    copyCreditNum = creditNum;

    int count = get_length_int(copyCreditNum);
    long division = get_division(count) ;

    copyCreditNum = creditNum;

    int firstDigit = copyCreditNum / division ;
    int firstTwoDigit = copyCreditNum / (division / 10);


    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if ((firstTwoDigit == 51 || firstTwoDigit == 52 || firstTwoDigit == 53 || firstTwoDigit == 54 || firstTwoDigit == 55)
                 && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((firstTwoDigit == 34 || firstTwoDigit == 37) && count == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}

int get_length_int(long value)
{
    int count = 0 ;

    while (value != 0)
    {
        value = value / 10 ;
        count++;
    }
    return count ;
}

long get_division(int count)
{
    long division = 10 ;
    for (int i = 0 ; i < count - 2 ; i++)
    {
        division = division * 10 ;
    }
    return division ;
}