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
    
    // different seed for rand function for each execution 
    srand(time(NULL));
    // generate a random number from 0 to 3
    int meal = rand() % 4;
    // printf("meal price = %.2f\n", mealCosts[meal]);

    // 
    printf("\nMenu: \n (1) Salad: $%.2f\n (2) Soup: $%.2f\n (3) Sandwich: $%.2f\n (4) Pizza: $%.2f\n\n",
        mealCosts[0], mealCosts[1], mealCosts[2], mealCosts[3]);


    // ask user for tax percent
    printf("Enter Tax percent: ");
    scanf("%f", &tax);
    // ask user for tip percent
    printf("enter Tip percent: ");
    scanf("%f", &tip);

    // print out the complete bill to the console
    printf("\n   **Total Bill**\n");
    printf("Subtotal:\t$%.2f\n", mealCosts[meal]);              // get meal cost
    printf("Tax:\t\t$%.2f\n", (mealCosts[meal]*(tax/100)));     // calculate tax from meal cost
    printf("Tip:\t\t$%.2f\n", (mealCosts[meal]*(tip/100)));     // calculate tip from meal cost
    printf("Total:\t\t$%.2f\n\n", (mealCosts[meal]+(mealCosts[meal]*(tax/100))+(mealCosts[meal]*(tip/100))));   // calculate bill total

    return 0;
}