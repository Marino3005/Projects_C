#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int stringcomp(char *x, char *y);

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    for(int i = 0, n = strlen(s); i <= n; i++)
    {
        *(t + i) = *(s + i);
    }

    t[0] = toupper(t[0]);

    printf("t: %s\n", t);

}

int stringcomp(char *x, char *y)
{
    if( *x == *y)
    {
        if(*x != '\0')
        {
            return stringcomp(x + 1, y + 1);
        }
        else
        {
            return 0;
        }
    }
    else

        if(*x > *y)
        {
            return -1;
        }
        else

            return +1;
}