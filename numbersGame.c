/*
Outline for Number Guessing Game:
    (1) create the necessary variables
    (2) Display text to inform the user of the game
    (3) create a menu for the user to pick from
    (4) get the users choice/input 
    (5) create individual functions for each option or use switch case - use some input validation
        (a) Option 1: get a random number and have the user guess until they guess correctly
            use looping to continually prompt user to input an integer within the allowed range,
            also allow user to return to main menu.
        (b) Option 2: inform user of the current max value and prompt user to enter a new max value
        (c) Option 3: exit the process
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void main()
{
    // declare necessary variables
    int menuOptionInt, randomInt, userInt, userMaxValueInt = 10;
    const int MAX_INT = 10;

    printf("\nWelcome to a Number Guessing Game!\n");

    do
    {
        printf("\nPlease Choose One:\n\tEnter 1 to play a game\n\tEnter 2 to change the Max Value\n\tEnter 3 to Quit\n");
        scanf("%d", &menuOptionInt);

        switch(menuOptionInt)
        {
            case 1:
                srand(time(NULL));
                randomInt = (rand() % MAX_INT) + 1;
                printf("%d", randomInt);
                printf("\nYou've chosen to play a game\n");//Please guess a number between 1 and %d: ", MAX_INT);
                //scanf("%d", &userInt);
                
                char strArray[1];

                do
                {
                    printf("\nPlease guess a number between 1 and %d: ", MAX_INT);
                    scanf("%s", &strArray);

                    if(tolower(strArray[0]) != 'q')
                    {
                        userInt = atoi(strArray);
                        if(userInt < randomInt)
                        {
                            printf("\nYour guess is too low, try again.");
                        }
                        else if(userInt > randomInt)
                        {
                            printf("\nYour guess is too high, try again.");
                        }
                    }
                } while ((strArray[0] != 'q') && userInt != randomInt);

                if(userInt == randomInt)
                {
                    printf("\nCongratulations! You guess the number correctly! Returning to Main Menu.\n");
                }
                break;

            case 2:
                printf("\nEnter new Max Value from 1 to %d: ", MAX_INT);
                scanf("%d", &userMaxValueInt);
                do
                {
                    if(userMaxValueInt < 1 || userMaxValueInt > 10 )
                    {
                        printf("\nPlease enter a value from 1 to %d", MAX_INT);
                        printf("\nEnter new Max Value: ");
                        scanf("%d", &userMaxValueInt);
                    }
                } while (userMaxValueInt < 1 || userMaxValueInt > 10);
                printf("New max value is set.\n");

                break;
        }

    } while (menuOptionInt != 3);
    printf("Thank you for playing!");
  //  exit (EXIT_FAILURE);
}

/*If option 1 is selected the program should prompt the user to enter a number. 
If the user is correct tell them they won then the program should go back to the menu. 
Otherwise tell them if they were too low or high in there guess and allow them to guess again. 
This should continue until they win. If they enter q instead of a number when prompted the game should end(NOT the program) and return to the menu.

If option 2 is chosen, then tell them the max value they can set the number. Make sure they do not enter a negative number or go above the max value.

If option 3 thank user & quit.

Now create a new branch – call it save_user_max_numberCan you save the users request for the max number where the program is able to remember it the next time it starts?  
*/