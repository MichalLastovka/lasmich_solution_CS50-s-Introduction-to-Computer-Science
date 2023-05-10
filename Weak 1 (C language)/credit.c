/*/
In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, 
or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or 
INVALID\n, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have 
leading zeroes. But do not assume that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. 
/*/


#include <cs50.h>
#include <stdio.h>

int luhn_number;
int luhn_test(long cc_number);
int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;
int m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;


int main(void)
{
    long cc_number = get_long("Insert your credit card number: ");

    // Accepting only valid size of input cc_number
    if (cc_number > 4000000000000 && cc_number < 5599999999999999)
    {
        luhn_test(cc_number);

        // cc_number passing luhn_test compares to given conditions
        if (luhn_number % 10 == 0)
        {
            if ((n16 == 0 && n15 == 3 && n14 == 4) || (n16 == 0 && n15 == 3
                && n14 == 7))
            {
                printf("AMEX\n");
            }

            else if ((n16 == 5 && n15 == 1) || (n16 == 5 && n15 == 2) || (n16 ==
                    5 && n15 == 3) || (n16 == 5 && n15 == 4) || (n16 == 5 && n15
                    == 5))
            {
                printf("MASTERCARD\n");
            }

            else if ((n16 == 0 && n15 == 0 && n14 == 0 && n13 == 4) ||
                    (n16 == 4))
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

    else
    {
        printf("INVALID\n");
    }

}

// Fuction returning digits of cc_number (nx) and luhn_number for further analysis
int luhn_test(long cc_number)
{
    n1 = cc_number % 10;
    n2 = ((cc_number - n1) % 100) / 10;
    n3 = ((cc_number - n1 - n2 * 10) % 1000) / 100;
    n4 = ((cc_number - n1 - n2 * 10 - n3 * 100) % 10000) / 1000;
    n5 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000) % 100000) / 10000;
    n6 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000) %
            1000000) / 100000;
    n7 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000) % 10000000) / 1000000;
    n8 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000) % 100000000) / 10000000;
    n9 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000) % 1000000000) / 100000000;
    n10 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000) %
            10000000000) / 1000000000;
    n11 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000 - n10 *
            1000000000) % 100000000000) / 10000000000;
    n12 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000 - n10 *
            1000000000 - n11 * 10000000000) % 1000000000000) / 100000000000;
    n13 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000 - n10 *
            100000000 - n11 * 1000000000 - n12 * 10000000000) % 10000000000000)
            / 1000000000000;
    n14 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000 - n10 *
            100000000 - n11 * 1000000000 - n12 * 10000000000 - n13 * 100000000000)
            % 100000000000000) / 10000000000000;
    n15 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000 - n10 *
            100000000 - n11 * 1000000000 - n12 * 10000000000 - n13 *
            100000000000 - n14 * 1000000000000) % 1000000000000000) /
            100000000000000;
    n16 = ((cc_number - n1 - n2 * 10 - n3 * 100 - n4 * 1000 - n5 * 10000 - n6 *
            100000 - n7 * 1000000 - n8 * 10000000 - n9 * 100000000 - n10 *
            100000000 - n11 * 1000000000 - n12 * 10000000000 - n13 *
            100000000000 - n14 * 1000000000000 - n15 * 10000000000000) %
            10000000000000000) / 1000000000000000;

    m1 = n1;
    m2 = n2 * 2;
    m3 = n3;
    m4 = n4 * 2;
    m5 = n5;
    m6 = n6 * 2;
    m7 = n7;
    m8 = n8 * 2;
    m9 = n9;
    m10 = n10 * 2;
    m11 = n11;
    m12 = n12 * 2;
    m13 = n13;
    m14 = n14 * 2;
    m15 = n15;
    m16 = n16 * 2;

    luhn_number = (m1 + m3 + m5 + m7 + m9 + m11 + m13 + m15) + ((m2 % 10) + ((m2
                 - (m2 % 10)) / 10)) + ((m4 % 10) + ((m4 - (m4 % 10)) / 10)) +
                 ((m6 % 10) + ((m6 - (m6 % 10)) / 10)) + ((m8 % 10) + ((m8 - (m8
                  % 10)) / 10)) + ((m10 % 10) + ((m10 - (m10 % 10)) / 10)) +
                  ((m12 % 10) + ((m12 - (m12 % 10)) / 10)) + ((m14 % 10) + ((m14
                   - (m14 % 10)) / 10)) + ((m16 % 10) + ((m16 - (m16 % 10)) /
                   10));

    return luhn_number;
}
