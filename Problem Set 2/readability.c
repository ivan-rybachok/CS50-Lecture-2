#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string story = get_string("Text: ");

    float letters = count_letters(story);
    float words = count_words(story);
    float sentences = count_sentences(story);
    //calculating the average
    float L = ((letters / words) * 100);
    float S = ((sentences / words) * 100);
    // using the formula
    float index0 = 0.0588 * L - 0.296 * S - 15.8;

    int index = round(index0);

    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    // printf("Number of letters: %i\n", count_letters(story));
    // printf("Number of words: %i\n", count_words(story));
    // printf("Number of sentences: %i\n", count_sentences(story));

}

int count_letters(string text)
{
    // counting only letters
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(isalpha(text[i]))
        {
            letters++;
        }
    }
    float count_letters = letters;
    return count_letters;

}

int count_words(string text)
{
    // counting only words
    int words = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if(isblank(text[i]))
        {
            words++;
        }
    }
    // adding extra 1 since if there is two blanks it could be 3 words
    float count_words = words + 1;
    return count_words;
}

int count_sentences(string text)
{
    // counting only sentences
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // checking if the words end on anyone of these to start incrementing sentences
        if(text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }

    float count_sentences = sentences;
    return count_sentences;

}



