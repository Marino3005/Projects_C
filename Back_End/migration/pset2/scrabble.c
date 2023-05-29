#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score2  < score1)
    {
        printf("Player 1 wins!\n");
    }
    else 
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0;
    for (int i = 0, n = strlen(word) ; i  < n ; i++)
    {
        if (islower(word[i]))
        {
            int letpoint = word[i] - 97;
            sum = sum + POINTS[letpoint];
        }
        else if (isupper(word[i]))
        {
            int letpoint = word[i] - 65;
            sum = sum + POINTS[letpoint];
        }
        else 
        {
            sum = sum + 0;
        }
    }
    return sum;
}
  ratio[0] = argv[1][0] - 'a';
            ratio[1] = argv[1][1] - 'b';
            ratio[2] = argv[1][2] - 'c';
            ratio[3] = argv[1][3] - 'd';
            ratio[4] = argv[1][4] - 'e';
            ratio[5] = argv[1][5] - 'f';
            ratio[6] = argv[1][6] - 'g';
            ratio[7] = argv[1][7] - 'h';
            ratio[8] = argv[1][8] - 'i';
            ratio[9] = argv[1][9] - 'j';
            ratio[10] = argv[1][10] - 'k';
            ratio[11] = argv[1][11] - 'l';
            ratio[12] = argv[1][12] - 'm';
            ratio[13] = argv[1][13] - 'n';
            ratio[14] = argv[1][14] - 'o';
            ratio[15] = argv[1][15] - 'p';
            ratio[16] = argv[1][16] - 'q';
            ratio[17] = argv[1][17] - 'r';
            ratio[18] = argv[1][18] - 's';
            ratio[19] = argv[1][19] - 't';
            ratio[20] = argv[1][20] - 'u';
            ratio[21] = argv[1][21] - 'v';
            ratio[22] = argv[1][22] - 'w';
            ratio[23] = argv[1][23] - 'x';
            ratio[24] = argv[1][24] - 'y';
            ratio[25] = argv[1][25] - 'z';