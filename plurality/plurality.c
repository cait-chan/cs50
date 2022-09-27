#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;
int voter_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
        return false;
    }
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    //want to compare each of the candidates vote totals to see who has the most
    //base case
    for (int i = 0; i < candidate_count; i += 0)
    {
        if (candidates[i].votes == 0);
        {
            i++;
        }
        return;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidate[i] > candidate[i + 1])
        {
            string winner = candidate[i];
                winner comparison to candidate C
                    ...
                    if winner = candidate[i]
                        printf("%s\n", winner)
                        printf("%s\n", candidate[i]);
                    printf("%s\n", winner)
        candidate B = winner
            winnter comparison to candidate C
                ...
    }

    string winner = 0;

    for (int i = 0; i < candidate_count; i += 0)
    {
        for (int j = 1; j < candidate_count; j += 0)
        {
            if (candidates[i].votes > candidates[j].votes)
            {
                winner = candidates[i].name;
                j++;
            }
            else if (candidates[i].votes < candidates[j].votes)
            {
                winner = candidates[j].name;
                i++;
            }
            
        }
            printf("%s\n", );
    return;
}