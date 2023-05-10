/*/
Task:
The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate.

$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

/*/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("State desired height of the pyramid: ");
    }
    while (height <= 0 || height > 8);
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b > a - (height - 1); b--)
        {
            printf(" ");
        }
        for (int c = 0; c < a + 1; c++)
        {
            printf("#");
        }
        printf("  ");
        for (int d = 0; d < a + 1; d++)
        {
            printf("#");
        }
        printf("\n");
    }
}
