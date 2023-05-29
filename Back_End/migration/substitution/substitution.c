#include<stdio.h>
#include<cs50.h>
#include <ctype.h>
#include <string.h>

int count_letters(string array);
string make_lower(string array);
bool check_alpha(string array);


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        key = make_lower(key);
        if ((strlen(key) == 26) && (check_alpha(key) == true) && (count_letters(key) == 2847))
        {
            // calculate numerical diference between real letters and the key
            int ratio[26];
            ratio[0] = key[0] - 'a';
            ratio[1] = key[1] - 'b';
            ratio[2] = key[2] - 'c';
            ratio[3] = key[3] - 'd';
            ratio[4] = key[4] - 'e';
            ratio[5] = key[5] - 'f';
            ratio[6] = key[6] - 'g';
            ratio[7] = key[7] - 'h';
            ratio[8] = key[8] - 'i';
            ratio[9] = key[9] - 'j';
            ratio[10] = key[10] - 'k';
            ratio[11] = key[11] - 'l';
            ratio[12] = key[12] - 'm';
            ratio[13] = key[13] - 'n';
            ratio[14] = key[14] - 'o';
            ratio[15] = key[15] - 'p';
            ratio[16] = key[16] - 'q';
            ratio[17] = key[17] - 'r';
            ratio[18] = key[18] - 's';
            ratio[19] = key[19] - 't';
            ratio[20] = key[20] - 'u';
            ratio[21] = key[21] - 'v';
            ratio[22] = key[22] - 'w';
            ratio[23] = key[23] - 'x';
            ratio[24] = key[24] - 'y';
            ratio[25] = key[25] - 'z';

            string text = get_string("plaintext: ");
            for (int i = 0; i <= strlen(text); i++)
            {
                if (isalpha(text[i]))
                {
                    if (islower(text[i]))
                    {
                        text[i] = text[i] + ratio[(text[i] - 97)];
                    }
                    else if (isupper(text[i]))
                    {
                        text[i] = text[i] + ratio[(text[i] - 65)];
                    }
                }
                else
                {
                    text[i] = text[i];
                }
            }
            printf("ciphertext: %s\n", text);
        }
        else
        {
            printf("key must contain 26 alphabetic characters and each letter exactly once\n");
            return 1;
        }
    }
    else
    {
        printf("insert one comand-line argument\n");
        return 1;
    }
}


string make_lower(string array)
{
    for (int i = 0; i < 26; i++)
    {
        array[i] = tolower(array[i]);
    }
    return array;
}

int count_letters(string array)
{
    int sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum += array[i];
    }
    return sum;
}

bool check_alpha(string array)
{
    int n = 0;
    for (int i = 0; i < 26;)
    {
        if (isalpha(array[i]))
        {
            i++;
            n++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
for(int i = 0; i < (candidate_count - 1); i++)
    {
       if (candidates[candidate_count - 1].votes == candidates[i].votes)
       {
           printf("%s", candidates[i].name);
       }
       printf("%s", candidates[candidate_count - 1].name);
    }


