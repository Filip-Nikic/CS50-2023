#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string sentence = get_string("Enter text: ");
    int letter = count_letters(sentence);
    // printf("%i letters \n", letter);
    int word = count_words(sentence);
    // printf("%i words \n", word);
    int sentences = count_sentences(sentence);
    // printf("%i sentences \n", sentences);
    float index = 0.;
    float l = 100. * letter / word;
    float s = 100. * sentences / word;
    index = 0.0588 * l - 0.296 * s - 15.8;
    // printf("%f is index \n", index);
    // printf("L= %f \n", l);
    // printf("S= %f \n", s);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %g\n", round(index));
    }
}

int count_letters(string text)
{
    int letter = 0;
    char c;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        c = text[i];
        if (isalpha(c))
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string text)
{
    int word = 0;
    char c;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        c = text[i];
        if (c == ' ')
        {
            word++;
        }
    }
    word++;
    return word;
}

int count_sentences(string text)
{
    int sentence = 0;
    char c;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        c = text[i];
        if (c == '.' || c == '!' || c == '?')
        {
            sentence++;
        }
    }
    return sentence;
}