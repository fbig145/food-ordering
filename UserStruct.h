//
// Created by Bobby on 12/22/2019.
//

#ifndef XOR_BIT_PROBLEM_USERSTRUCT_H
#define XOR_BIT_PROBLEM_USERSTRUCT_H

typedef struct _user{
    char *username;
    char *password;
} user;
user createUser();

void InputPersonalData(user *u);
void DisplayOrder1(user *u);

#endif //XOR_BIT_PROBLEM_USERSTRUCT_H
