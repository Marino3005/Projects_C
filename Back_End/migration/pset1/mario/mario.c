#include<stdio.h>
#include<cs50.h>

int get_positive_int(void);

int main(void)
{
    //Get positive integer from user
    int n;
    do
    {
        n = get_int("height between 1 and 8: ");
    }
    while (n < 1 || n > 8);


    //build pyramid
    for (int i = 0; i < n; i++)
    {
        //Spaces
        for (int a = 0; a < n - (i + 1); a++)
        {
            printf(" ");
        }

        //1st Hashtag
        for (int b = 0; b <= i; b++)
        {
            printf("#");
        }

        //Middle spaces
        printf("  ");

        //2nd Hashtags
        for (int c = 0; c <= i; c++)
        {
            printf("#");
        }
        printf("\n");
    }

}

~/

