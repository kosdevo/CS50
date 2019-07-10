#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("./ceasar key");
        return 1;
    }
    
    int k = atoi(argv[1]);
    string plaintext = get_string("Plaintext: "); //original message
    
    //keep track of upper and lower case alphabet in ASCII, length of alphabet
    int ASCII_A = 65;
    int ASCII_a = 97;
    int abc_length = 26;
    
    printf("Ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Add key to uppercase letters, ensure that it is wrapped
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - ASCII_A + k) % abc_length + ASCII_A);
        }
        // Add key to lowercase letters, ensure it is wrapped
        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - ASCII_a + k) % abc_length + ASCII_a);
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
