/*/
Taks:
https://cs50.harvard.edu/college/2022/fall/psets/2/
/*/


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

string ciphermagic(string plaintext, int key);

// Main loop checking for validity of the key, then passing the key and
// plaintext
int main(int argc, string argv[])
{
    // checking for ivalid num of arguments from user
    if (argc != 2)
    {
        printf("Usage: ./caesar + key\n");
        return 1;
    }
    // since atio DOES accept "2x" as argv[1] and treats it as int 2, these
    // lines are checking every char of argv[1] for nums
    string argv_key = argv[1];
    int get_length = strlen(argv_key);
    for (int j = 0; j < get_length; j++)
    {
        int is_digit = isdigit(argv_key[j]);
        if (is_digit == 0)
        {
            printf("Usage: ./caesar + key\n");
            return 1;
        }
    }
    // changing string to int, excluding "0" from valid nums
    int key = atoi(argv[1]);
    if (key < 1)
    {
        printf("Usage: ./caesar + key\n");
        return 1;
    }
    else
    {
        // activating the ciphermagic based on valid argument
        string plaintext = get_string("plaintext: ");
        string ciphertext = ciphermagic(plaintext, key);
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
}

string ciphermagic(string plaintext, int key)
{
    // function treats digit, letters, non-letters in different ways. It also
    // ensures case sensitivity
    int length = strlen(plaintext);
    char cipherletters[(length + 1)];
    for (int i = 0; i < (length +1); i++)
    {
        int is_letter = isalpha(plaintext[i]);
        int is_digit = isdigit(plaintext[i]);
        if (is_letter == 0 && is_digit == 0)
        {
            cipherletters[i] = plaintext[i];
        }
        else if (is_letter == 0 && is_digit != 0)
        {
            cipherletters[i] = plaintext[i];
        }
        else if (is_letter != 0)
        {
            int is_upper =  isupper(plaintext[i]);
            if (is_upper == 0)
            {
                int ci_small_ltr = ((plaintext[i] - 97 + key) % 26) + 97;
                cipherletters[i] = ci_small_ltr;
            }
            else
            {
                int ci_cap_ltr = ((plaintext[i] - 65 + key) % 26) + 65;
                cipherletters[i] = ci_cap_ltr;
            }
        }
    }
    string ciphertext = cipherletters;
    printf("");
    return (ciphertext);
}
