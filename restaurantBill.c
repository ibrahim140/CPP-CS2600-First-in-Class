/*
Outline for Restaurant Bill:
    1) create necessary variablies
    2) Get a random number from 1 to 4 for picking a random meal - use rand function
    3) Get  tax percentage, and tip percentage from user.
    4) Perform calculations to get tax amount, tip amount and total bill.
    5) Display bill information in console for user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // declare necessary variables
    float tax, tip, billTotal;
    /* create array which holds the prices for each of the meals
                        salad, soup, sandwich, pizza */
    float mealCosts[4] = {9.95, 4.55, 13.25, 22.35};
    // create limit(s) for the random number
    int upperLimit = 3, lowerLimit = 0;
    
    // different seed for rand function for each execution 
    srand(time(NULL));
    //generate a random number from 1 to 4
    int meal = rand() % 4;
    //printf("meal price = %.2f\n", mealCosts[meal]);

    // ask user for tax percent
    printf("Enter Tax percent: ");
    scanf("%2f", &tax);
    // ask user for tip percent
    printf("enter Tip percent: ");
    scanf("%2f", &tip);

    printf("\nTotal Bill:\n");

    return 0;
}