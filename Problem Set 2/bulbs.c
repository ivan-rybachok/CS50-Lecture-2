#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // getting input from user
    string text = get_string("Please Enter Text Here: ");

    // setting ASCII to 0
    int ASCII = 0;

    int bit[8];
    // using loop to figure out the size of the words and assign each letter with
    // ASCII number to our ASCII
    for(int i = 0, len = strlen(text); i < len; i++)
    {
        // updating ASCII value
        ASCII = text[i];

        for(int j = 0; j < BITS_IN_BYTE; j++)
        {
            // looping through 8 times
            // getting the remainder by using % 2 and moving the number to the array
            // so if number is 72 or letter H in this case
            // it will be 00010010 the number that will be passed into the array
            bit[j] = ASCII % 2;
            // getting the quotient for the next round when we are looping through
            // updating  ASCII value
            ASCII = ASCII / 2;
        }
        // reversing the binary number from 00010010 to 01001000
        for(int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            // here we run that number from the array backwards by targeting the number with array numbers
            print_bulb(bit[k]);
        }
        printf("\n");
        // printf("%d\n", ASCII);
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
