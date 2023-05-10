/*/
Task:
Suffice it to say, no matter how you compile or execute this program, it only ever prints hello, world. Let’s personalize it a bit, just as we did in class.

Modify this program in such a way that it first prompts the user for their name and then prints hello, so-and-so, where so-and-so is their actual name.
/*/


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name? ");
    printf("Hello, %s\n", name);
}
