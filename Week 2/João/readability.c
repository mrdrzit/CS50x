#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//postulando as funções
int number_of_letters(string text);
int number_of_words(string text);
int number_of_sentences(string text);

int main(void)
{
//pegando texto do usuário e calculando fórmula pra dar output da grade do texto
    string text = get_string("Text: ");
    float L = (number_of_letters(text) / (float) number_of_words(text)) * 100;
    float S = (number_of_sentences(text) / (float) number_of_words(text)) * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
//dando output da grade do texto
    if (index >= 0 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}
//função pra calcular número de letras no texto
int number_of_letters(string text)
{
    int letters = 0;
    int i = 0;
    
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++; 
        }
    }
    return letters;
}
//função pra calcular número de palavras no texto
int number_of_words(string text)
{
    int words = 0;
    int i = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if ((i == 0 && text[i] != ' ')
            || (i != '\0' - 1 && text[i] == ' ' && text[i + 1] != ' '))
        {
            words++;
        }
    }
    return words;
}
//função pra calcular número de frases no texto
int number_of_sentences(string text)
{
    int sentences = 0;
    int i = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}
