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
int voter_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

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
    voter_count = get_int("Number of voters: ");

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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
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
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    //should utilize recurssion
    //bubblesort

    pair temp;
    for (int i = 0; i < (pair_count - 1); i++)
    {
        for (int j = 0; j < (pair_count - i - 1); j++)
        {
            if ((pairs[j].winner - pairs[j].loser) > (pairs[j+1].winner - pairs[j+1].loser))
            {
                temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }
        }
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    locked[pairs[0].winner][pairs[0].loser] = true;

    for (int i = 1; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;

        for (int j = i - 1; j >= 0; j--)
        {
            if ((locked[pairs[j].winner][pairs[j].loser] == true) && (pairs[i].winner != pairs[j].winner))
            {
                if ()
            }
            else if (locked[pairs[j].winner][pairs[j].loser] == true)
            {
                if (pairs[i].loser == pairs[j].winner)
                {
                    locked[pairs[i].winner][pairs[i].loser] = false;
                }
                else if (pairs[i].loser == pairs[j].loser)
                {
                    locked[pairs[i].winner][pairs[i].loser] = false;
                }
                //need to have it so that if it is false ever it cannot be true
                //else
                //{
                    //locked[pairs[i].winner][pairs[i].loser] = true;
                //}
            }
        }
    }
}

// Print the winner of the election
void print_winner(void)
{
    int winner_votes = 0;
    int winners = 0;
    string winner[candidate_count];

    for (int i = 0; i <= candidate_count; i++)
    {
        if (pairs[i].winner >= winner_votes)
        {
            winners++;
            winner[i] = candidates[i];
            winner_votes = pairs[i].winner;
        }
    }
    for (int j = 0; j <= winners; j++)
    {
        printf("%s\n", winner[j]);
    }
}