/*  
    KEANA DE PADUA - QUIZ 1
    QUESTION 1, PART A 
*/

// Include the stdio library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare enum meals{salad, soup, sandwich, pizza} (0 - 3)
enum meals{salad, soup, sandwich, pizza};

// Declare functions
static void print_meal(int, float, float);

int main(int argc, char *argv[]){
    float tax, tip;     // Declare 2 floats to hold tax and tip percentages 
    int meal;           // Declare an int meal
    srand(time(0));     // Have to seed random num generator

    tax = atof(argv[1]);
    tip = atof(argv[2]);
    meal = rand() % 4;

    print_meal(meal, tax, tip);    // Call print_meal()
}

static void print_meal(int meal, float tax, float tip){
    char mealName[9];
    float price;        // Declare float for meal price
    float taxAmt;       // Declare float for tax amount
    float tipAmt;       // Declare float for tip amount

    switch(meal){ // Switch statement to determine which meal was picked
        case 0:
            strcpy(mealName, "Salad");
            price = 9.95;
            break;
        case 1:
            strcpy(mealName, "Soup");
            price = 4.55;
            break;
        case 2:
            strcpy(mealName, "Sandwich");
            price = 13.25;
            break;
        case 3:
            strcpy(mealName, "Pizza");
            price = 22.35;
            break;
        default:
            strcpy(mealName, "Invalid");
            price = -1;
    }

    taxAmt = price * tax;   // Calculate tax amount
    tipAmt = price * tip;   // Calculate tip amount

    printf("Meal: %s\n", mealName);                           // Print meal name
    printf("Meal cost: %.2f\n", price);                       // Print meal cost
    printf("Tax Amount: %.2f\n", taxAmt);                     // Print tax amount
    printf("Tip Amount: %.2f\n", tipAmt);                     // Print tip amount
    printf("Total Bill: %.2f\n", (price + taxAmt + tipAmt));  // Print total bill

}