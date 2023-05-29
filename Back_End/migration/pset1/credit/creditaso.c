#include<stdio.h>
#include<cs50.h>

bool valid_triangle(float x , float y , float z);

int main(void)
{
    float side1 = get_float("side 1:");
    float side2 = get_float("side 2:");
    float side3 = get_float("side 3:");
    
    bool boolean = valid_triangle(side1 , side2 , side3);
    printf("%u\n", boolean);
    
}

bool valid_triangle(float x , float y , float z)
{
    string output;
    
    if (x && y && z > 0)
    {
        if ((x + y <= z) || (x + z <= y) || (y + z <= x))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else 
    {
        return false;
    }
}