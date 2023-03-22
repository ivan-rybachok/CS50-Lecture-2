#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // checking if user put anything, first argument is argv[0] or 1 is the command line
    // argc is always at least 1 because of the command-line so if it doesn't = to
    // 2 means that user didn't put anything and it will run the statement and throw out
    // an error
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        // quit program
        return 1;
    }
    // getting the length of the character to see if it's a digit or not
    // going 1 at a time starting at 0
    //
    for(int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        // [j] because we are checking each character
        if(!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key\n");
            // quit program
            return 1;
        }
    }

    // turning number character into a number after it's been checked that it's
    // a digit
    int k = atoi(argv[1]);

    // checking if a number is less than 0 if it is than throw error
    if (k < 0)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        // getting input from user
        string plaintext = get_string("plaintext:  ");
        printf("ciphertext: ");

        // looping through depending on the length of the text
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            //check if the letter is uppercase or lowercase then convert
            if (islower(plaintext[i]))
            {   
                // using the formula to print ciphertext
                // ex: if plaintext[i](ASCII value of the letter so like lowercase z would be 122) - 97 + whatever the number
                // the user put in so like 1 would be 97 + 1
                // but if the user put z which is 122 - 97 and 1 it would be 26
                // so we need to reset the alphabet so that it starts with 0
                // we also need to mod 26, whatever the remainder is take that as an
                // int and thats the value of the mod, so when it reaches over 26 characters 
                // we want it to loop back to the beginning
                // and after we need to bring it back to its original ASCII value
                // in the end 26 mod 26 would have remainder of 0 + 97 would bring our ASCII value back and it would be lowercase a
                // so z becomes the new a in ciphertext
                printf("%c", (plaintext[i] - 97 + k) % 26 + 97);
            }
            else if (isupper(plaintext[i]))
            {
                // same thing here but with uppercase letters
                // ex: Z which ASCII value is 90 - 65 = 25 and key is 1 so 25 + 1 = 26
                // now 26 mod 26 will give us remainder of 0 and we add back to 65 so now its A
                // so ciphertext will print A for a Z
                printf("%c", (plaintext[i] - 65 + k) % 26 + 65);
            }
            //if neither then just print whatever it is
            else
            {
                // ignoring symbols and printing them here
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }

    // printf("hello, %s\n", argv[1]);
    // int k = atoi(argv[1]);
    // printf("User put in, %i\n", k);


}