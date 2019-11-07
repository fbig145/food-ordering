//
// Created by Bobby on 11/8/2019.
//

#include <stdio.h>

int getChoiceIndex(int typesOfFood, int *state){
    int choiceIndex;
    char choice = getchar();
    // consume new line
    getchar();
    if(choice == 'a' + typesOfFood) {
        (*state)--;
    }else{
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}


int drinksT( int choice, int noOfDrinks, int *state, int cnD[]){
    int addDrinkT=0;
    choice = getchar();
    if(choice == 'a' + noOfDrinks) {
        (*state)--;
        getchar();
    }else{
        addDrinkT = 0;
        while (choice !='\n') {
            cnD[addDrinkT] = choice - 'a';
            addDrinkT++;
            char comma = getchar();
            if(comma=='\n'){
                break;
            }
            choice = getchar();
        }
        (*state)++;
    }
    return addDrinkT;
}
