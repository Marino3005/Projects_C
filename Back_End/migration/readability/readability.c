#include<stdio.h>
#include<cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    //Count letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isblank(text[i]))
        {
            words++;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            sentences++;
        }
    }

    //Calculate Coleman index
    float constant = 100 / (float)words;
    float L = letters * constant;
    float S = sentences * constant;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
