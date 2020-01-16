#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "addInfo.h"
#include "DisplayItems.h"
#include "index.h"
#include "UserStruct.h"
#define LOAD_DATA "Please load the data\n"
#define MAX_ANSW 20
#define MAX_FOOD_NAME 100
#define MAX_DRINK_NAME 100
#define MAX_TYPE_NAME 50
#define MAX_LINE 100

int main() {
    char delim1[]=" ";
    char delim2[]="(";
    char delim3[]=":)-";
    char *token;
    printf(LOAD_DATA);
    int typesOfFood;
    char line[MAX_LINE];
    gets(line);
    token = strtok(line, delim3);
    typesOfFood=atoi(token);

    char ** types = (char**)malloc(typesOfFood * sizeof(char*));
    int * noTypes= (int*)malloc(typesOfFood * sizeof(int));
    char *** type = (char***)malloc(typesOfFood * sizeof(char**));
    double ** prices = (double**)malloc(typesOfFood * sizeof(double*));

    for(int i=0; i < typesOfFood; i++) {
        types[i] = (char*)malloc(MAX_FOOD_NAME * sizeof(char));
        gets(line);
        token=strtok(line, delim1);
        strcpy(types[i], token);
        token = strtok(NULL, delim3);
        noTypes[i]=atoi(token);

        type[i] = (char**)malloc(noTypes[i] * sizeof(char*));
        prices[i] = (double*)malloc(noTypes[i] * sizeof(double));

        for(int j=0; j < noTypes[i]; j++)
        {
            type[i][j] = (char*)malloc(MAX_TYPE_NAME * sizeof(char));
            token = strtok(NULL, delim2);
            token = strtok(NULL, delim3);
            strcpy(type[i][j], token);
            token=strtok(NULL, delim3);
            prices[i][j]=atoi(token);

        }
    }
    int noOfDrinks;
    gets(line);
    token = strtok(line, delim3);
    noOfDrinks=atoi(token);

    char ** Drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    double * DrinksPrices = (double*)malloc(noOfDrinks * sizeof(double));

    gets(line);
    for(int i=0;i<noOfDrinks;i++) {

        Drinks[i] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        if(i==0)
        {
            token=strtok(line, delim3);
            strcpy(Drinks[i], token + 1);
        }
        else{
            token=strtok(NULL,delim3);
            strcpy(Drinks[i], token + 3);
        }
        token=strtok(NULL, delim3);
        DrinksPrices[i]=atoi(token);

        }

  /*  printf("The food is:\n");
    for(int i=0; i < typesOfFood; i++) {

        printf("%s: ", types[i]);
        for(int j=0; j < noTypes[i]; j++) {
            printf("%s (%.2lf)", type[i][j], prices[i][j]);
            if(j < noTypes[i] - 1){
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("The drinks are:\n");
    printf("Drinks: ");
    for(int i=0;i<noOfDrinks;i++){
        printf("%s (%.2lf)", Drinks[i], DrinksPrices[i]);
        if(i<noOfDrinks-1){
            printf(", ");
        }
    }
    printf("\n"); */

    user u = createUser();
    info q = createInfo();

    printf("Welcome to Food Thingies!\n");
    char answerType[][MAX_ANSW]={"Yes!", "No, thanks!"};
    int choice, typeChoice, type2Choice, type3Choice, nD = 0, cnD[3], answer = 2 ;
    int state = 0, orderStatus = 0;
    while(!orderStatus){
        switch (state) {
                case 0: {
                InputPersonalData(&u);
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
                    fgets(q.info, 100, stdin);}
                case 6:{
                    DisplayOrder1(&u);
                    printf("--%s (%.2f) \n", type[typeChoice][type2Choice], prices[typeChoice][type2Choice]);
                    double aD = 0;
                    Prices(aD, nD, DrinksPrices, cnD, Drinks);
                    DisplayOrder2(answerType, typeChoice, type2Choice, &q, prices, nD, type3Choice);
                    choice = getchar();
                    if(choice=='a') {
                        printf("Order confirmed! Thank you for buying from us!");
                        orderStatus = 1;} else {
                        state--;}
                    getchar();
                    break;}
            }
        }

    for(int i=0;i<typesOfFood;i++) {
        for(int j=0;j<noTypes[i];j++) {
            free(type[i][j]);
        }
        free(type[i]);
        free(prices[i]);
        free(types[i]);
    }
    free(type);
    free(prices);
    free(types);
    free(noTypes);
    for(int i=0;i<noOfDrinks;i++){
        free(Drinks[i]);
    }
    free(Drinks);
    free(DrinksPrices);
    free(u.password);
    free(u.username);
    free(q.info);

    return 0;
}
