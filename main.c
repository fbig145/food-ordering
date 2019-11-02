
#include <stdio.h>



    int main() {
        printf("Welcome to Food Thingies!\n");

        // food data
        int typesOfFood = 4;
        char types[][10] = {"Pizza", "Pasta", "Salad"};
        int noTypes[] = {4, 4, 4};
        char type[4][4][30] = {
                {"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                {"Chicken alfredo", "Mac&cheese"},
                {"Tuna Salad", "Chicken Salad", "Greek Salad", "Cobb"}
        };
        double prices[4][4] = {
                {21, 23, 19},
                {23, 21},
                {23, 22, 19, 21}
        };
        int noOfDrinks = 4;
        char Drinks[][30] = {"CocaCola", "Fanta", "Lipton", "Water"};
        double DrinksPrices[] = {5, 5, 5, 4};

        int answer = 2;
        char answerType[][20]={"Yes!", "No, thanks!"};

        //user input
        char username[20];
        char password[20];
        int choice, typeChoice, type2Choice;
        int nD = 0;
        int cnD[3];
        char info[100];

        int state =0;
        int orderStatus = 0;
        while(!orderStatus){
            switch (state) {
                case 0: {
                    // Input personal data
                    printf("Please sign in to continue!\n");
                    printf("---Username:\n");
                    gets(username);
                    printf("---Password:\n");
                    gets(password);
                    state++;
                    break;
                }
                case 1: {
                    // Choose the type
                    printf("Please choose the food you feel like eating today:\n");
                    for(int i=0; i < typesOfFood-1; i++) {
                        putchar('a'+i);
                        printf(") %s\n", types[i]);
                    }
                    printf("%c) Go back\n", 'a' + typesOfFood);
                    choice = getchar();
                    // consume new line
                    getchar();
                    if(choice == 'a' + typesOfFood) {
                        state--;
                        break;
                    }
                    typeChoice = choice - 'a';
                    state++;
                    break;
                }
                case 2: {
                    // Choose the food type
                    printf("Please choose the type of %s you want:\n", types[typeChoice]);
                    for(int i=0; i < noTypes[typeChoice]; i++) {
                        putchar('a'+i);
                        printf(") %s (%.2f)\n", type[typeChoice][i], prices[typeChoice][i]);
                    }
                    printf("%c) Go back\n", 'a' + noTypes[typeChoice]);
                    choice = getchar();
                    // consume new line
                    getchar();
                    if(choice == 'a' + noTypes[typeChoice]) {
                        state--;
                        break;
                    }
                    type2Choice = choice - 'a';
                    state++;
                    break;
                }
                case 3: {
                    // Choose the drink
                    printf("Please choose a drink to go with your %s:\n", types[typeChoice]);
                    for(int i=0; i < noOfDrinks; i++) {
                        putchar('a'+i);
                        printf(") %s (%.2f)\n", Drinks[i], DrinksPrices[i]);
                    }
                    printf("%c) Go back\n", 'a' + noOfDrinks);

                    choice = getchar();
                    if(choice == 'a' + noOfDrinks) {
                        state--;
                        //consume new line
                        getchar();
                        break;
                    }
                    nD = 0;
                    while (choice !='\n') {

                        cnD[nD] = choice - 'a';
                        nD++;

                        char comma = getchar();
                        if(comma=='\n'){
                            break;
                        }
                        choice = getchar();
                    }
                    state++;
                    break;
                }
                case 4:{
                    printf("Do you want cutlery?\n");

                    for(int i=0; i < answer; i++) {
                        putchar('a'+i);
                        printf(") %s\n", answerType[i]);
                    }
                    printf("%c) Go back\n", 'a' + answer);
                    choice = getchar();
                    // consume new line
                    getchar();
                    if(choice == 'a' + answer) {
                        state--;
                        break;
                    }
                    typeChoice = choice - 'a';
                    state++;
                    break;


                }
                case 5:{
                    printf("Any additional info?\n");
                    fgets(info, 100, stdin);
                }
                case 6:{
                    // Display order
                    printf("This is your order:\n");
                    printf("-------------\n");
                    printf("Username: %s \n", username);


                    printf("Food items:\n");
                    printf("--%s (%.2f) \n", type[typeChoice][type2Choice], prices[typeChoice][type2Choice]);
                    double aD = 0;
                    for(int i=0; i < nD; i++) {
                        aD += DrinksPrices[cnD[i]];
                    }
                    if(nD != 0){
                        for(int i=0; i < nD; i++) {
                            printf("--%s (%.2f)\n", Drinks[cnD[i]], DrinksPrices[cnD[i]]);
                        }
                    }
                    printf("--Cutlery: %s\n", answerType[typeChoice]);
                    printf("Additional information: %s", info);
                    printf("Payment amount: %.2f\n", prices[typeChoice][type2Choice] + aD);
                    printf("-------------\n");
                    printf("a) Confirm order\n");
                    printf("b) Go back\n");
                    choice = getchar();
                    if(choice=='a') {
                        printf("Order confirmed! Thank you for buying from us!");
                        orderStatus = 1;
                    } else {
                        state--;
                    }
                    // consume new line
                    getchar();
                    break;
                }
            }
        }
        return 0;
    }





