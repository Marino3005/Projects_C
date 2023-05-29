#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void draw(int h);

int main(void)
{
    int height = get_int("height; ");
    draw(height);
}

void draw(int h)
{
       if(h == 0)
       {
           return;
       }
       
       draw(h - 1);
       
       for(int i = 0; i < h; i++)
       {
           printf("#");
       }
       printf("\n");
}