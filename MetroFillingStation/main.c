#include <stdio.h>
#include <stdlib.h>

int userLoggedIn = 0;
int main(){
    while(1){
        //not loggedIn
        // 1 -> logIn
        // 2 -> signUP
        // 3 -> Exit
        if(userLoggedIn==0){
            printf("Enter\n  1 -> logIn\n  2 -> signUP\n  3 -> Exit\n\n");
            //signUP()

        }
        else{
            // 1->logOut
            // bill
            // update_prices
            // 2->Exit
            system("cls");
            printf("Enter\n  1 -> logOut\n  2 -> billing\n  3 -> Update Prices\n  4 -> Exit\n\n");
            //logIn()
        }
    }

    return 0;
}
