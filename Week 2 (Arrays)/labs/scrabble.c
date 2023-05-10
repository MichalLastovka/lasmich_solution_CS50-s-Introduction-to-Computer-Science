/*/
Task:

https://cs50.harvard.edu/college/2022/fall/labs/2/
/*/

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1,
                4, 4, 8, 4, 10
               };

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int lenght = strlen(word);
    for (int i = 0; i < lenght; i++)
    {
        // Changing every char to lower for simplicity
        char upper_to_lower = tolower(word[i]);
        // Getting the ASCII num representation as defined in the ASCII table
        int lower_to_num = upper_to_lower;
        // Searching for 1 points chars and adding the score accordingly
        if (lower_to_num == 97 ||
            lower_to_num == 101 ||
            lower_to_num == 105 ||
            lower_to_num == 108 ||
            lower_to_num == 110 ||
            lower_to_num == 111 ||
            lower_to_num == 114 ||
            lower_to_num == 115 ||
            lower_to_num == 116 ||
            lower_to_num == 117)
        {
            score += 1;
        }
        // Searching for 2 points chars and adding the score accordingly
        else if (lower_to_num == 100 ||
                 lower_to_num == 103)
        {
            score += 2;
        }
        // Searching for 3 points chars and adding the score accordingly
        else if (lower_to_num == 98 ||
                 lower_to_num == 99 ||
                 lower_to_num == 109 ||
                 lower_to_num == 112)
        {
            score += 3;
        }
        // Searching for 4 points chars and adding the score accordingly
        else if (lower_to_num == 102 ||
                 lower_to_num == 104 ||
                 lower_to_num == 118 ||
                 lower_to_num == 119 ||
                 lower_to_num == 121)
        {
            score += 4;
        }
        // Searching for 5 points chars and adding the score accordingly
        else if (lower_to_num == 107)
        {
            score += 5;
        }
        // Searching for 8 points chars and adding the score accordingly
        else if (lower_to_num == 106 ||
                 lower_to_num == 120)
        {
            score += 8;
        }
        // Searching for 10 points chars and adding the score accordingly
        else if (lower_to_num == 113 ||
                 lower_to_num == 122)
        {
            score += 10;
        }
        // excluding any other numbers (aka symbols from ASCII)
        else
        {
            score += 0;
        }
    }
    return score;
}
