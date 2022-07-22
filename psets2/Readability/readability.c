#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

long calculate_letters(string text) ;
long calculate_words(string text);
long calculate_sentences(string text);

int main(void)
{
    string text;
    do
    {
        text = get_string("Text: \n");
    }
    while (strlen(text) < 0);

    long letterCount = calculate_letters(text);
    long sentenceCount = calculate_sentences(text) ;
    long wordCount = calculate_words(text);

    float averge_letter_per_100 = (float)letterCount / wordCount * 100 ;
    float average_sentence_per_100 = (float)sentenceCount / wordCount * 100;

    float index = 0.0588 * averge_letter_per_100 - 0.296 * average_sentence_per_100 - 15.8;

    int roundedIndex = round(index);

    if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundedIndex >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}

long calculate_letters(string text)
{
    long letters = 0;
    for (long i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}


long calculate_words(string text)
{
    long words = 1;
    for (long i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words;
}

// calculate the sentences
long calculate_sentences(string text)
{
    long sentences = 0;
    for (long i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}