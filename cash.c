#import <stdio.h>
#import <cs50.h>
#import <math.h>

// using a greedy algorithm, print the minimum number of coins with which change can be made

int main()
{
    float dollars;
    int cents, quarters, dimes, nickels, pennies, coins;
    do
    {
        dollars = get_float("Change owed?");
    }
    while(dollars<0.0);
    
    cents = round(dollars * 100);
    quarters = cents / 25;
    dimes = (cents % 25) / 10;
    nickels = ((cents % 25) % 10 ) / 5;
    pennies = (((cents % 25) % 10 ) % 5 ) / 1;
    
    printf("%i \n", quarters + dimes + nickels + pennies);   
}
