//
// Created by Bobby on 12/22/2019.
//

#include "addInfo.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_INFO 100
#define MAX_ANSW 20

info createInfo(){
    info q;
    q.info = (char*)malloc(MAX_INFO* sizeof(char));

    return q;
}


void DisplayOrder2(char answerType[][MAX_ANSW], int typeChoice, int type2Choice, info *q, double **prices, double aD, int type3Choice ){

    printf("--Cutlery: %s\n", answerType[type3Choice]);
    printf("Additional information: %s", q->info);
    printf("Payment amount: %.2f\n", prices[typeChoice][type2Choice] + aD);
    printf("-------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}