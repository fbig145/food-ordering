//
// Created by Bobby on 12/22/2019.
//

#ifndef XOR_BIT_PROBLEM_ADDINFO_H
#define XOR_BIT_PROBLEM_ADDINFO_H
#define MAX_ANSW 20

typedef struct _info{
    char *info;
} info;

info createInfo();

void DisplayOrder2(char answerType[][MAX_ANSW], int typeChoice, int type2Choice, info *q, double **prices, double aD, int type3Choice );

#endif //XOR_BIT_PROBLEM_ADDINFO_H
