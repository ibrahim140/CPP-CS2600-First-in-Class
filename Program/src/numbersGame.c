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
    (6) add file I/O to save the users max value for the program to read in
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void main()
{
    // declare necessary variables
    FILE *maxNumFile;
    int menuOptionInt, randomInt, userInt, fileSize, userMaxValueInt=10;
    // initialize a constant
    const int MAX_INT = 10;
    
    // open a file for reading
    maxNumFile = fopen(".txt", "r");

    // check if file is not empty
    if (maxNumFile != NULL)
    {
        // move file pointer to specified position
        fseek(maxNumFile, 0, SEEK_END);
        // get position of the file pointer
        fileSize = ftell(maxNumFile);

        // check if file size is empty
        if (fileSize != 0)
        {
            // else read in value from file
            fscanf(maxNumFile, "%d", &userMaxValueInt);
        }
    }
    else
    {
        // set max value to 10 if file doesn't exist
        userMaxValueInt = 10;
    }
    // close the file
    fclose(maxNumFile);

    // print a welcome message
    printf("\nWelcome to a Number Guessing Game!\n");

    // do-while loop
    do
    {
        // ask user to input a choice
        printf("\nPlease Choose One:\n\tEnter 1 to play a game\n\tEnter 2 to change the Max Value\n\tEnter 3 to Quit\n");
        printf("Choice: ");
        // store user choice in variable
        scanf("%d", &menuOptionInt);
        // clear the new line from buffer
        fflush(stdin);

        // use switch case method for different options
        switch(menuOptionInt)
        {
            // case 1 for playing the game
            case 1:
                // new seed for the random number generator
                srand(time(NULL));
                // get a random number from 1 to 10
                randomInt = (rand() % userMaxValueInt) + 1;
                // print message informing them of game start
                printf("\nYou've chosen to play a game");
                // get a character array to hold the users input
                char strArray[10];

                do
                {
                    // inform user of the limits 
                    printf("\nPlease guess a number between 1 and %d: ", MAX_INT);
                    
                    // get user input and store into char array
                    fgets(strArray, sizeof(strArray), stdin);                    

                    // check if user input the character 'q'
                    if(tolower(strArray[0]) != 'q')
                    {
                        // convert to int if not 'q'
                        userInt = atoi(strArray);
                        // check user input value with the random integer
                        if(userInt < randomInt)
                        {
                            // inform if user input is too low
                            printf("\nYour guess is too low, try again.");
                        }
                        else if(userInt > randomInt)
                        {
                            // inform if user input is too high
                            printf("\nYour guess is too high, try again.");
                        }
                    }
                    // repeat loop body while the conditions below are true
                } while ((strArray[0] != 'q') && userInt != randomInt);

                // check if users input is correct
                if(userInt == randomInt)
                {
                    // return user to main menu and end game
                    printf("\nCongratulations! You guess the number correctly! Returning to Main Menu.\n");
                }
                break;

            case 2:
                // ask user to set a new max value
                do
                { 
                    // ask user to input a max value if input is invalid
                    printf("\nPlease enter a value from 1 to %d", MAX_INT);
                    printf("\nEnter new Max Value: ");
                    scanf("%d", &userMaxValueInt);
                    // repeat loop body while the conditions below are true
                } while (userMaxValueInt < 1 || userMaxValueInt > 10);

                // open a file, this time for writing
                maxNumFile = fopen(".txt", "w");
                // write value read in from console to the file
                fprintf(maxNumFile, "%d", userMaxValueInt);
                // close file
                fclose(maxNumFile);
                // inform user of new max value
                printf("New max value is set.\n");
                break;
        }
        // repeat everything above as long as the condition below is true
    } while (menuOptionInt != 3);
    // when menu option is 3: exit the loop above and display a thanks to user
    printf("Thank you for playing!");
    // exit program
    exit (EXIT_FAILURE);
}