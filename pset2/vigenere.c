#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int shift(char c);

int main(int argc, string argv[])
{
    //check if user did not enter keyword (which can only be one word)
    string keyword = argv[1]; //keyword
    if (argc != 2)
    {
        printf("./vigenere key \n");
        return 0;
    }
    //check if user has any numbers in the keyword (can only be alphabet)
    else 
    {
        for(int i = 0, n = strlen(keyword); i<n; i++)
        {
            if(isdigit(keyword[i]))
            {
                printf("./vigenere keyword should not have numbers \n");
                return 0;
            }
        }
    }    
    int k = atoi(argv[1]);
    string plaintext = get_string("Plaintext: "); //original message
       
    //keep track of upper and lower case alphabet in ASCII, length of alphabet
    int ASCII_A = 65;
    int ASCII_a = 97;
    int abc_length = 26;
    int keyword_counter = 0;
    
    printf("Ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        int j = shift(keyword[keyword_counter % strlen(keyword)]);
        // Add key to uppercase letters, ensure that it is wrapped
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - ASCII_A + j) % abc_length + ASCII_A);
            keyword_counter++;
        }
        // Add key to lowercase letters, ensure it is wrapped
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - ASCII_a + j) % abc_length + ASCII_a);
            keyword_counter++;
        }
        // Non-alphabet characters are not changed and just returned
        else
        {
            printf("%c", plaintext[i]);
        }
    }  
    printf("\n");
    return 0;
}

//converts character to amount to shift by; A or a is 0, B or b is 1, etc.
int shift (char c)
{
    int ASCII_A = 65;
    int ASCII_a = 97;
    int abc_length = 26;

    if(isupper(c))
    {
        c -= ASCII_A;
    }
    else if (islower(c))
    {
        c -= ASCII_a;
    }
    return c;
}
