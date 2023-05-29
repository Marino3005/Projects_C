#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("what's the start size of the population?\n");
    }
    while (start < 9);


    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("what's the end size of the population?\n");
    }
    while (end < start);


    // TODO: Calculate number of years until we reach threshold
    int i = 0;

    for (int population = start; population < end; i++)
    {
        population = population + ((population / 3) - (population / 4));
    }


    // TODO: Print number of years
    printf("Years: %i\n", i);
}