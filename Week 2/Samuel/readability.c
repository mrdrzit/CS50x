#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int letters_count(string text);
int words_count(string text);
int sentences_count(string text);

int main(void)
{
    //~get user's input
    string text = get_string("Text: ");

    float letters = letters_count(text);
    float words = words_count(text);
    float sentences = sentences_count(text);

    // the average number of letters per 100 words
    float L = (letters * 100) / words;
    // the average number of sentences per 100 words
    float S = (sentences * 100) / words;

    // formula that calculates the grade level
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // round a number to its nearest integer
    float rounded_number = round(index);

    if (rounded_number < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (rounded_number > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %.0f\n", round(index));
    }

}

// function to count letters
int letters_count(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }

    return count;
}

// function to count words
int words_count(string text)
{
    int count = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }

    return count;
}

// function to count sentences
int sentences_count(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] ==  '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }

    return count;
}

