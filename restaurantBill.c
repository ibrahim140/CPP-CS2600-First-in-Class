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

// meal type function
const char* mealType(int meal)
{
    // return the appropriate meal type where the function is called
    if (meal == 0)
    {
        return "Salad";
    }
    else if (meal == 1)
    {
        return "Soup";
    }
    else if (meal == 2)
    {
        return "Sandwich";
    }
    else if (meal == 3)
    {
        return "Pizza";
    }
}

int main(void)
{
    // declare necessary variables
    float taxFloat, tipFloat;

    /* create array which holds the prices for each of the meals
                        salad, soup, sandwich, pizza */
    float mealCosts[4] = {9.95, 4.55, 13.25, 22.35};

    // different seed for rand function for each execution
    srand(time(NULL));
    // generate a random number from 0 to 3
    int mealChoice = rand() % 4;

    // print out the  menu items and their prices
    printf("\nMenu:\n (1) Salad: $%.2f\n (2) Soup: $%.2f\n (3) Sandwich: $%.2f\n (4) Pizza: $%.2f\n\n",
        mealCosts[0], mealCosts[1], mealCosts[2], mealCosts[3]);

    // ask user for tax percentage
    do
    {
        // get tax % from user
        printf("Enter Tax percent: ");
        scanf("%f", &taxFloat);
        // input validation on tax
        if(taxFloat <= 0)
        {
            printf("Please enter a valid tax amount.\n");
        }
    }while(taxFloat <= 0);

    // ask user for tip percentage
    do
    {
        // get tip % from user
        printf("Enter Tip percent: ");
        scanf("%f", &tipFloat);
        // input validation on tip percentage
        if(tipFloat <= 0)
        {
            printf("Please enter a valid tax amount.\n");
        }
    }while(tipFloat <= 0);

    // print out the complete bill to the console
    printf("\n   **Total Bill**\n");
    printf("Item:\t\t%s\n", mealType(mealChoice));                      // print meal type
    printf("Subtotal:\t$%.2f\n", mealCosts[mealChoice]);                // get meal price
    printf("Tax:\t\t$%.2f\n", (mealCosts[mealChoice] * (taxFloat/100)));     // calculate tax from meal cost
    printf("Tip:\t\t$%.2f\n", (mealCosts[mealChoice] * (tipFloat/100)));     // calculate tip from meal cost
    printf("Total:\t\t$%.2f\n\n", (mealCosts[mealChoice] + (mealCosts[mealChoice] * (taxFloat/100)) +        // calculate bill total
                (mealCosts[mealChoice] * (tipFloat/100))));

    return 0;
}