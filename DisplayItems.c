//
// Created by Bobby on 11/8/2019.
//


#include <stdio.h>
#define MAX_TYPES 10
#define MAX_DRINK 30
#define MAX_ANSW 20

void DisplayFood(int typesOfFood, char **types) {
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < typesOfFood ; i++) {
        putchar('a' + i);
        printf(") %s\n", types[i]);
    }
}

void DisplayFoodChoice(char **types, int typeChoice, int *noTypes, char ***type, double **prices){
    printf("Please choose the type of %s you want:\n", types[typeChoice]);
    for(int i=0; i < noTypes[typeChoice]; i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n", type[typeChoice][i], prices[typeChoice][i]);
    }
    printf("%c) Go back\n", 'a' + noTypes[typeChoice]);
}

void DrinksTypes(char **types, int typeChoice, int noOfDrinks, char **Drinks, double *DrinksPrices){
    printf("Please choose a drink to go with your %s:\n", types[typeChoice]);
    for(int i=0; i < noOfDrinks; i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n", Drinks[i], DrinksPrices[i]);
    }
    printf("%c) Go back\n", 'a' + noOfDrinks);
}
void cutlery(int answer, char answerType[][MAX_ANSW] ){
    printf("Do you want cutlery?\n");

    for(int i=0; i < answer; i++) {
        putchar('a'+i);
        printf(") %s\n", answerType[i]);
    }
    printf("%c) Go back\n", 'a' + answer);
}

void Prices(double aD, int nD, double *DrinksPrices, int cnD[], char **Drinks ){
    for(int i=0; i < nD; i++) {
        aD += DrinksPrices[cnD[i]];}
    if(nD != 0){
        for(int i=0; i < nD; i++) {
            printf("--%s (%.2f)\n", Drinks[cnD[i]], DrinksPrices[cnD[i]]);}}
}