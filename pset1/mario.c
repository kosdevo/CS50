
#include <stdio.h>
#include <cs50.h>

//create mario pyramids made of hashes '#' by specifying how tall it is aka height, pyramid is split by 2 spaces in the middle

void repeat(char c, int times)
{
    while(--times >=0)
    {
        printf("%c",c);
    }
}

int main()
{
    int height, width;
    do
    {
        height = get_int("How many levels?");
    }
    while(height<1 || height > 8);
    
    for (int i = 0; i < height; i++)
    {
        int num_hashes = i+1;
        int num_spaces = height - num_hashes;
        
        repeat(' ', num_spaces);
        repeat('#', num_hashes);
        printf("  ");
        repeat('#', num_hashes);
        
        printf("\n");
    }
}    
