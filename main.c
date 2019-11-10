#include <stdio.h>
#include "DisplayCustomer.h"
#include "DisplayItems.h"
#include "index.h"
#define MAX_TYPES 10
#define MAX_DRINK 30
#define MAX_ANSW 20
    int main() {
        printf("Welcome to Food Thingies!\n");
        int typesOfFood = 4, noTypes[] = {4, 4, 4}, noOfDrinks = 4;
        char types[][MAX_TYPES] = {"Pizza", "Pasta", "Salad"} , type[4][4][30] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},{"Chicken alfredo", "Mac&cheese"},{"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}};
        double prices[4][4] = {{21, 23, 19},{23, 21},{23, 22, 19, 21}};
        char Drinks[][MAX_DRINK] = {"CocaCola", "Fanta", "Lipton", "Water"};
        double DrinksPrices[] = {5, 5, 5, 4};
        char answerType[][MAX_ANSW]={"Yes!", "No, thanks!"}, username[20], password[20];
        int choice, typeChoice, type2Choice, type3Choice, nD = 0, cnD[3], answer = 2 ;
        char info[100];
        int state = 0, orderStatus = 0;
        while(!orderStatus){
            switch (state) {
                case 0: {
                    InputPersonalData(username, password);
                    state++;
                    break;}
                case 1: {
                   DisplayFood(typesOfFood, types);
                   typeChoice = getChoiceIndex(typesOfFood, &state);
                    break;}
                case 2: {
                    DisplayFoodChoice(types, typeChoice, noTypes, type, prices);
                    type2Choice = getChoiceIndex(noOfDrinks, &state);
                    break;}
                case 3: {
                    DrinksTypes(types, typeChoice,noOfDrinks, Drinks, DrinksPrices);
                    nD=drinksT(choice, noOfDrinks, &state, cnD);
                    break;}
                case 4:{
                   cutlery(answer, answerType);
                    type3Choice = getChoiceIndex(answer, &state);
                    break;}
                case 5:{
                    printf("Any additional info?\n");
                    fgets(info, 100, stdin);}
                case 6:{
                    DisplayOrder1(username);
                    printf("--%s (%.2f) \n", type[typeChoice][type2Choice], prices[typeChoice][type2Choice]);
                    double aD = 0;
                    Prices(aD, nD, DrinksPrices, cnD, Drinks);
                    DisplayOrder2(answerType, typeChoice, type2Choice, info, prices, nD, type3Choice);
                    choice = getchar();
                    if(choice=='a') {
                        printf("Order confirmed! Thank you for buying from us!");
                        orderStatus = 1;} else {
                        state--;}
                    getchar();
                    break;}}}
        return 0;}