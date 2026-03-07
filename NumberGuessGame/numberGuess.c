/*
    KEANA DE PADUA - QUIZ 1
    QUESTION 2
*/

//  Include needed libraries

//  Create enums
//      gameResult{lost, won}

// Declare functions

/*  START main() FUNCTION */

//  Declare + assign int currentNumGuesses = 0, currentGame = 0
//  Declare int 2d array games[] w/ 2 rows, 50 colums
//      This is assuming that the max amount of games a player will play is 50 games...
//      1st row = Whether that game was won or lost (1 or 2)
//      2nd row = Number of guesses made until the end of the game (so either until the player won or quit)

//  START WHILE LOOP
//      Declare and assign int gameMax = 10;
//      Declare int variable for userMenuChoice
//
//      Call getMenuChoice()
//
//      START SWITCH STATEMENT
//          Case 1:
//              Call playGame()
//              Break out of switch statement
//          Case 2:
//              Assign gameMax = getUserMax();
//              Break out of switch statement
//          Default:
//              Break out of switch statement
//      END SWITCH STATEMENT
//      Break out of loop
//  END WHILE LOOP

//  Call printEnd()

/*  END main() FUNCTION */

/*  START getMenuChoice() FUNCTION */
//      Declare int for userInput
//      Print menu
//      Prompt user for input
//      Return user input
/*  END getMenuChoice() FUNCTION */

/*  START getGameInput() FUNCTION */
//      Declare int for userInput
//      Prompt user for input
//      Return user input
/*  END getGameInput() FUNCTION */

/* START playGame() FUNCTION */
//  Declare and assign gameVal = (rand() % gameMax) + 1;
//  Declare and assign int variable for userGameInput = getGameInput()
//  Increment currentNumGuesses
//      While user is wrong AND userGameInput != 'q'...
//          Tell them they were too low/high
//          Call getGameInput()
//          Increment currentNumGuesses
//          If user is right OR userGameInput == 'q'
//              Break out of loop
//      If user is correct
//          Tell them they won
//          Count game as a win
//      Else (User enters 'q')
//          Count game as a loss
//      Increment currentGame
/* END playGame() FUNCTION */

/*  START getUserMax() FUNCTION */
//      Tell the user the max value they can enter
//      Validate input is NOT a negative number or above the max value
/*  END getUserMax() FUNCTION*/

/* START printEnd() FUNCTION */
//  Thank user for playing
//  Print out the result of all games played + number of guesses required to win
//  End the game/program
/* END printEnd() FUNCTION */