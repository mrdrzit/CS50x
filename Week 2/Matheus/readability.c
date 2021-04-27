#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int c_counter(string Text); //initialize char counter
int s_counter(string Text); //initialize sentence counter
int w_counter(string Text); // initialize word counter

int main(void)
{
    
    float L; // The average number of letters per 100 words in the text.
    float S; // The average number of sentences per 100 words in the text.
    string Text = get_string("Type a sentence: ");
    int letters = c_counter(Text);
    int sentences = s_counter(Text);
    int words = w_counter(Text);
    L = (letters * 100.0) / (float)words;
    S = (sentences * 100.0) / (float)words;
    float index = ((0.0588 * L) - (0.296 * S)) - 15.8;
    int score = round(index);

    // printf("Letters: %i\nWords: %i\nSentences: %i\nGrade: %i\n", letters, words, sentences, score);
    if (score >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", score);
    }


}


//Counts the number of alphabetic characters in a string
int c_counter(string Text)
{
    int c_count = 0;

    for (int i = 0, n = strlen(Text); i < n; i++)
    {

        if (isalpha(Text[i]))
        {
            c_count++;
        }
        else
        {
            continue;
        }
    }
    return c_count;
}

//Periods, exclamation points, or question marks indicates the end of a sentence. Counts the number of sentences in a string.
int s_counter(string Text)
{
    int s_count = 0;

    for (int i = 0, n = strlen(Text); i < n; i++)
    {

        if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
        {
            s_count++;
        }
        else
        {
            continue;
        }
    }
    return s_count;
}

// Any sequence of characters separated by a space is a word. Counts the number of words in the string.
int w_counter(string Text)
{
    int w_count = 0;

    for (int i = 0, n = strlen(Text); i <= n; i++)
    {

        char current = Text[i];
        if (Text[i] == ' ')
        {
            w_count++;
        }
        else
        {
            continue;
        }
    }
    return w_count + 1;
}