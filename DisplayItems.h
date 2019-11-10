//
// Created by Bobby on 11/8/2019.
//

#ifndef XOR_BIT_PROBLEM_DISPLAYITEMS_H
#define XOR_BIT_PROBLEM_DISPLAYITEMS_H
#define MAX_TYPES 10
#define MAX_DRINK 30
#define MAX_ANSW 20

void DisplayFood(int typesOfFood, char types[][MAX_TYPES]);
void DisplayFoodChoice(char types[][MAX_TYPES], int typeChoice, int noTypes[], char type[4][4][30], double prices[4][4]);
void DrinksTypes(char types[][MAX_TYPES], int typeChoice, int noOfDrinks, char Drinks[][MAX_DRINK], double DrinksPrices[]);
void cutlery(int answer, char answerType[][MAX_ANSW]);
void Prices(double aD, int nD, double DrinksPrices[], int cnD[], char Drinks[][MAX_DRINK]);

#endif //XOR_BIT_PROBLEM_DISPLAYITEMS_H
