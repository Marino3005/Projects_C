#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //Separating user numer into digits
    long n = get_long("introduce card number: ");
    int a = (n % 10);
    int b = (n % 100) / 10;
    int c = (n % 1000) / 100;
    int d = (n % 10000) / 1000;
    int e = (n % 100000) / 10000;
    int f = (n % 1000000) / 100000;
    int g = (n % 10000000) / 1000000;
    int h = (n % 100000000) / 10000000;
    int i = (n % 1000000000) / 100000000;
    int j = (n % 10000000000) / 1000000000;
    int k = (n % 100000000000) / 10000000000;
    int l = (n % 1000000000000) / 100000000000;
    int m = (n % 10000000000000) / 1000000000000;
    int q = (n % 100000000000000) / 10000000000000;
    int o = (n % 1000000000000000) / 100000000000000;
    int p = (n % 10000000000000000) / 1000000000000000;

    //Checksum algorithm
    int B = b * 2;
    int D = d * 2;
    int F = f * 2;
    int H = h * 2;
    int J = j * 2;
    int L = l * 2;
    int Q = q * 2;
    int P = p * 2;

    //Dividing product into digits
    int aB = B % 10;
    int bB = B / 10;
    int aD = D % 10;
    int bD = D / 10;
    int aR = F % 10;
    int bR = F / 10;
    int aH = H % 10;
    int bH = H / 10;
    int aJ = J % 10;
    int bJ = J / 10;
    int aS = L % 10;
    int bS = L / 10;
    int aQ = Q % 10;
    int bQ = Q / 10;
    int aP = P % 10;
    int bP = P / 10;

    int Ichecksum = (aB + bB + aD + bD + aR + bR + aH + bH + aJ + bJ + aS + bS + aQ + bQ + aP + bP);
    int Fchecksum = (Ichecksum + a + c + e + g + i + k + m + o);

    //Card identifier
    if (Fchecksum % 10 == 0)
    {
        //Amex Range
        if (((n >= 340000000000000) && (n < 350000000000000)) || ((n >= 370000000000000) && (n < 380000000000000)))
        {
            printf("AMEX\n");
        }
        //MasterCard Range
        else if (((n > 5100000000000000) && (n < 5600000000000000)))
        {
            printf("MASTERCARD\n");
        }
        //Visa Range
        else if (((n >= 4000000000000) && (n < 5000000000000)) || ((n >= 4000000000000000) && (n < 5000000000000000)))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}