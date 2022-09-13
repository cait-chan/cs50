#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%s\n", text);

    int count = count_letters(text);
    printf("%i letters\n", count);

    int words = count_words(text);
    printf("%i words\n", words);

    int sentences = count_sentences(text);
    printf("%i sentences\n", sentences);

    //TODO set up int so that the grade level ranges from 1 to 16
    //printf("Grade %i\n", int );
    //maybe set up an array of grade levels?
   // else if
        //printf("Grade 16+\n");
        //this should print if the index number is greater than a senior undergraduate reading level
    //else
        //printf("Before Grade 1\n");
        //this should print if the index number is less than one
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
        if ((text[i] - 33) == 0)
        {
            sentences += 1;
        }
        else if ((text[i] - 46) == 0)
        {
            sentences += 1;
        }
        else if ((text[i] - 63) == 0)
        {
            sentences += 1;
        }
        sentences += 0;
    }
    return sentences;
}