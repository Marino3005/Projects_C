#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool avoid_cycle(int x, int y);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int m = 0; m < (candidate_count - 1); m++)
    {
        for (int i = 0 + m; i < (candidate_count - 1); i++)
        {
            preferences[ranks[m]][ranks[i + 1]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int arraynumber = 0;
    for (int m = 0; m < candidate_count; m++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (preferences[m][i] > preferences[i][m])
            {
                pairs[arraynumber].winner = m;
                pairs[arraynumber].loser = i;
                arraynumber++;
                pair_count++;
            }
        }
    }
    return;

}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO

    int swap = -1;
    for (int steps = 0; steps < pair_count; steps++)
    {
        while (swap != 0)
        {
            for (int i = 0; i < (pair_count - 1) - steps; i++)
            {
                swap = 0;
                if ((preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner]) <
                    (preferences[pairs[i + 1].winner][pairs[i + 1].loser] - preferences[pairs[i + 1].loser][pairs[i + 1].winner]))
                {
                    pair holder = pairs[i];
                    pairs[i] = pairs[i + 1];
                    pairs[i + 1] = holder;
                    swap++;
                }
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (avoid_cycle(i, i))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO

    for (int m = 0; m < pair_count; m++)
    {
        int count = 0;
        for (int i = 0; i < pair_count; i++)
        {
            if (locked[i][m] == false)
            {
                count++;
            }
            if (count == pair_count)
            {
                printf("%s\n", candidates[m]);
            }
        }
    }
    return;
}

//avoid cycles with recursion.
bool avoid_cycle(int x, int y)
{
    for (int m = 0; m < pair_count; m++)
    {
        if (locked[pairs[m].winner][pairs[x].winner] == true)
        {
            if (pairs[m].winner != pairs[y].loser)
            {
                return avoid_cycle(m, y);
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}