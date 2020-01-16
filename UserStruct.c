//
// Created by Bobby on 12/22/2019.
//

#include "UserStruct.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_USERNAME 20
#define  MAX_PASSWORD 20


user createUser(){
    user u;
    u.username = (char*)malloc(MAX_USERNAME* sizeof(char));
    u.password = (char*)malloc(MAX_PASSWORD* sizeof(char));

    return u;
}



void InputPersonalData(user *u){
    printf("Please sign in to continue!\n");
    printf("---Username:\n");
    gets(u->username);
    printf("---Password:\n");
    gets(u->password);

}

void DisplayOrder1(user *u){

    printf("This is your order:\n");
    printf("-------------\n");
    printf("Username: %s \n", u->username);
    printf("Food items:\n");
}