/*/
Task:
https://cs50.harvard.edu/college/2022/fall/psets/2/
/*/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letter(string text);
int count_words(string text);
int count_sentences(string text);
int Coleman_Liau(int letters, int words, int sentences);

int main(void)
{
    // Prompting user to enter the text for analysis
    string text = get_string("Text: ");
    // Passing user input aka text for three functions to return the int(s)
    // (counts) of letters, words and sentences.
    int letters = count_letter(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = Coleman_Liau(letters, words, sentences);
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
        printf("%s%d\n", "Grade ", index);
    }
}

// Function accepting text as an argument, returning num of letters.
int count_letter(string text)
{
    int lenght = strlen(text);
    int letters = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters++;
        }
    }
    return letters;
}

// Function accepting text as an argument, returning num of words.
int count_words(string text)
{
    int lenght = strlen(text);
    int words = 1;
    for (int i = 0; i < lenght; i++)
    {
        if (isspace(text[i]) != 0)
        {
            words++;
        }
    }
    return words;
}

// Function accepting text as an argument, returning num of sentences.
int count_sentences(string text)
{
    int lenght = strlen(text);
    int sentences = 0;
    for (int i = 0; i < lenght; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences ++;
        }
    }
    return sentences;
}

// Function accepting three ints and returing rounded num using Coleman-Liau
// formula. Note that L and S are not actually L and S, but are rather
// multiplied by given coefficients.
int Coleman_Liau(int letters, int words, int sentences)
{
    double L = 0.0588 * letters / words * 100;
    double S = 0.296 * sentences / words * 100;
    int index = round(L - S - 15.8);
    return index;
}
