//
// Created by Bobby on 11/7/2019.
//

#include <stdio.h>
#define MAX_ANSW 20

void InputPersonalData(char username[], char password[]){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(username);
    printf("---Password:\n");
    gets(password);

}

void DisplayOrder1(char username[]){

    printf("This is your order:\n");
    printf("-------------\n");
    printf("Username: %s \n", username);
    printf("Food items:\n");
}

void DisplayOrder2(char answerType[][MAX_ANSW], int typeChoice, int type2Choice, char info[], double **prices, double aD, int type3Choice ){

    printf("--Cutlery: %s\n", answerType[type3Choice]);
    printf("Additional information: %s", info);
    printf("Payment amount: %.2f\n", prices[typeChoice][type2Choice] + aD);
    printf("-------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}


