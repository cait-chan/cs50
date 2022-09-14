#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //TODO set up int so that the grade level ranges from 1 to 16
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = letters / 100.00 * words;
    float S = sentences / 100.00 * words;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (1 <= round(index) && round(index) <= 16)
    {
        printf("Grade %i\n", (int) index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    //this should take a string of text and return an int
    //that is the number of letters in that text
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        letters += 0;
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;
    //should take the total number of spaces in the text
    //then add 1 to that number to account for the last word
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words +=1;
        }
        words +=0;
    }
    return words += 1;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] - 33) == 0 || (text[i] - 46) == 0 || (text[i] - 63) == 0)
        {
            sentences += 1;
        }
        sentences += 0;
    }
    return sentences;
}