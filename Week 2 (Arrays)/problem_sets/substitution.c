/*/
Task:
https://cs50.harvard.edu/college/2022/fall/psets/2/
/*/


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


bool has_two_argc(int argc);
bool enough_chars_in_argv(string argv[]);
bool are_there_letters_in_argv(string argv[]);
bool are_there_doubleganger_in_argv(string argv[]);
string substitution_formula(string plaintext, string argv[]);

// Main basically enables bool functions checking for valid inputs
// and sending arguments to cipher algorithm
int main(int argc, string argv[])
{
    int check1 = has_two_argc(argc);
    if (check1 == 0)
    {
        int check2 = enough_chars_in_argv(argv);
        if (check2 == 0)
        {
            int check3 = are_there_letters_in_argv(argv);
            if (check3 == 0)
            {
                int check4 = are_there_doubleganger_in_argv(argv);
                if (check4 == 0)
                {
                    string plaintext = get_string("plaintext: ");
                    string ciphertext_final = substitution_formula(plaintext,
                                              argv);
                    printf("ciphertext: %s\n", ciphertext_final);
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

// Function taking number of argc returnig bool for 2 argc only
bool has_two_argc(int argc)
{
    if (argc != 2)
    {
        printf("Usage: substitution key\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function checking the lenght of the string(argv[1], aka key)
bool enough_chars_in_argv(string argv[])
{
    int lenght = strlen(argv[1]);
    if (lenght != 26)
    {
        printf("String must contain 26 characters\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Function checking for each char making sure it is a letter
bool are_there_letters_in_argv(string argv[])
{
    int is_letter[26];
    string key = argv[1];
    for (int i = 0; i < 26; i++)
    {
        is_letter[i] = isalpha(key[i]);
        if (is_letter[i] == 0)
        {
            printf("String must contain letters only\n");
            return 1;
        }
    }
    return 0;
}

// Function cheking for duplicates of letters in the key aka string input
bool are_there_doubleganger_in_argv(string argv[])
{

    string key = argv[1];
    char key_lower[26];
    for (int k = 0; k < 26; k++)
    {
        key_lower[k] = tolower(key[k]);
    }
    for (int j = 0; j < 26; j++)
    {
        for (int i = (j + 1); i < 26; i++)
        {
            if (key_lower[i] == key_lower[j])
            {
                printf("The letters must not repeat\n");
                return 1;
            }
        }
    }
    return 0;
}

// Cipher algo itself. Could be split into more functions. Maybe later
string substitution_formula(string plaintext, string argv[])
{
    string key_origin = argv[1];
    int lenght_origin = strlen(key_origin);
    char lowerized_key[26];
    for (int i = 0; i < 26; i++)
    {
        if (isalpha(key_origin[i]) != 0)
        {
            lowerized_key[i] = tolower(key_origin[i]);
        }
    }
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int low_key_ASCII[26];
    for (int i = 0; i < 26; i++)
    {
        low_key_ASCII[i] = lowerized_key[i];
    }
    int alphabet_ASCII[26];
    for (int i = 0; i < 26; i++)
    {
        alphabet_ASCII[i] = alphabet[i];
    }
    int key_num_ASCII[26];
    for (int i = 0; i < 26; i++)
    {
        key_num_ASCII[i] = lowerized_key[i] - alphabet[i];
    }
    int lenght_plaintext = strlen(plaintext);
    char ciphertext[(lenght_plaintext + 1)];
    for (int i = 0; i < (lenght_plaintext + 1); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (isdigit(plaintext[i]) != 0)
            {
                ciphertext[i] = plaintext[i];
                break;
            }
            if (isalnum(plaintext[i]) == 0)
            {
                ciphertext[i] = plaintext[i];
                break;
            }
            if (isalpha(plaintext[i]) != 0)
            {
                if (isupper(plaintext[i]) == 0)
                {
                    if (plaintext[i] == alphabet[j])
                    {
                        ciphertext[i] = plaintext[i] + key_num_ASCII[j];
                    }
                }
                if (isupper(plaintext[i]) != 0)
                {
                    if ((plaintext[i] + 32) == alphabet[j])
                    {
                        ciphertext[i] = plaintext[i] + key_num_ASCII[j];
                    }
                }
            }
        }
    }
    string ciphertext_final = ciphertext;
    printf("");
    return ciphertext_final;
}
