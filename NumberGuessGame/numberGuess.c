/*
    KEANA DE PADUA - QUIZ 1
    QUESTION 2

    Note:   Unfortunately, there are errors with the code that I could not resolve. If you don't mind, professor, I would appreciate any 
            feedback you have for this program. I apologize for the messy code and lack of desired output. Listed below are the issues 
            with my program (at least the ones I've been able to catch).
            -   Since I am reading in user input as a char to try and detect a possible 'q' input, then converting the char to an int if it isn't 'q',
                it doesn't allow me to read in any guesses that are more than one digit (only reads 1-9 correctly). I have tried doing vice versa, 
                since I know chars can be stored as ints (in ASCII form), but I don't seem to get the correct output. This was the best I was able
                to come up with.
                -   I was able to verify that option 2 (changing the max number) does indeed work through setting breakpoints and checking the actual
                    values, but since my program can't even handle numbers > 9, there's not really any other way of showing it in the output.


*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum gameResult{lost, won}; // Create enums

// declare functions
static int getMenuChoice();
static char getGameInput();
static int getUserMax();

int main(int argc, char *argv[]){
    int currentNumGuesses = 0, currentGame = 0;
    int gameMax = 10;
    int userMenuChoice = getMenuChoice();
    int games[10][2];
//      This is assuming that the max amount of games a player will play is 10 games...
//      1st column = Whether that game was won or lost (1 or 2)
//      2nd column = Number of guesses made until the end of the game (so either until the player won or quit)

    while(userMenuChoice != 3){
        switch(userMenuChoice){
            case 1:
                srand(time(0));
                int gameVal = (rand() % gameMax) + 1;
                int currentNumGuesses = 0;
                int userGameInputInt;
                
                char userGameInputChar = getGameInput();
                if(userGameInputChar != 'q')
                    userGameInputInt = atoi(&userGameInputChar);
                
                currentNumGuesses++;
                
                while(userGameInputInt != gameVal && userGameInputChar != 'q') {   
                    if(userGameInputInt > gameVal)
                        printf("Your guess was too high. \n");
                    else 
                        printf("Your guess was too low.\n");
            
                    userGameInputChar = getGameInput();
                    if(userGameInputChar != 'q')
                        userGameInputInt = atoi(&userGameInputChar);
            
                    currentNumGuesses++;
                }
        
                if(userGameInputInt == gameVal) {
                    printf("You won!\n");
                    games[currentGame][0] = won;
                }
                else if(userGameInputChar == 'q') {
                    printf("You lost.\n");
                    games[currentGame][0] = lost;
                }

                games[currentGame][1] = currentNumGuesses;

                currentGame++;

                break;

            case 2:
                gameMax = getUserMax();
                break;

            default:
                break;
        }   
        userMenuChoice = getMenuChoice();
    }

    printf("Thank you for playing!\n");
    int i;
    for(i = 0; i < currentGame; i++) {
        int temp = i;
        printf("\nGAME %d", temp + 1);
        printf(":\n");

        printf("Result: ");
        if(games[i][0] == won)
            printf("Game won!\n");
        else if(games[i][0] == lost)
            printf("Game lost.\n");
        
        printf("Guesses made: %d", games[i][1]);
    }

    // Saving the current max to a file
    FILE* fptr;

    fptr = fopen("save_user_max_number.txt", "w");     // Will open a new file or overwrite existing one
    if(fptr != NULL){
        char str[10];
        sprintf(str, "%d", gameMax);
        fputs(str, fptr);
    }

    return 0;
}

static int getMenuChoice()
{
    int userInput;
    printf("--- MENU ---\n");
    printf("Press 1 to play a game\n");
    printf("Press 2 to change the max number\n");
    printf("Press 3 to quit\n");
    printf("Enter your choice: ");
    scanf("%d", &userInput);
    
    return userInput;
}

static char getGameInput() {
    char userInputChar;
    printf("Input your guess: ");
    scanf("%c", &userInputChar);    // clear buffer from prev newline
    scanf("%c", &userInputChar);
    return userInputChar;
}

static int getUserMax() {
    int max;
    printf("The maximum value you can pick is %d\n", INT_MAX);
    printf("Enter the max: ");
    scanf("%d", &max);
    
    while(max < 0 || max > INT_MAX) {
        printf("Invalid max\n");
        printf("Enter the max: ");
        scanf("%d", &max);
    }

    printf("The new max is: %d\n", max);

    return max;
}