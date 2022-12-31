#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"

void Bill_ing(){
    int n;
    char NAME[20];
    printf("COSTOMER NAME: ");
    fflush(stdin);
    fgets(NAME, sizeof(NAME),stdin);

    printf("Enter\n  1 -> PATROL\n  2 -> CNG\n  3 -> DIESEL\n  4 -> OCTANE\n\n");
    printf("Enter:");
    scanf("%d",&n);

    if(n==1){
        printf("Item: PATROl\n");
        double unit;
        printf("Purchase Amount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
    else if(n==2){
        printf("Item: CNG \n");
        double unit;
        printf("Purchase Amount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
    else if(n==3){
        printf("Item: DIESEL \n");
        double unit;
        printf("Purchase Ammount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
    else if(n==4){
        printf("Item: OCTANE \n");
        double unit;
        printf("Purchase amount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
}

double price(int n) {
    FILE *pointer;

    pointer=fopen("Prices.txt","r");
    if(pointer == NULL){
        printf("Prices file couldn't be opened\n");
        return -1;
    }
    else{
        double p, c, d, o;
        fscanf(pointer,"%lf %lf %lf %lf",&p,&c,&d,&o);
        fflush(stdin);
        fclose(pointer);

        if(n==1) return p;
        else if(n==2) return c;
        else if(n==3) return d;
        else if(n==4) return o;
    }
    return -1;
}


void invoice_for_patrol(int n, char* name, double quantity){
    double rate1=price(1);
    double rate2=price(2);
    double rate3=price(3);
    double rate4=price(4);
    system("cls");

    printf("METRO FEELING STATION\n\n\n");
    printf("   INVOICE\n");
    printf("CUSTOMAR:%s\n",name);
    if(n==1){
        printf("ITEM: PATROL\n");
        printf("RATE: %lf\n",rate1);
        printf("QUANTITY: %lf\n",quantity);
        printf("AMMOUNT: %lf\n",rate1*quantity*(1.0));
    }
    else if(n==2){
        printf("ITEM: GAS\n");
        printf("RATE: %lf\n",rate2);
        printf("QUANTITY: %lf\n",quantity);
        printf("AMMOUNT: %lf\n",rate2*quantity*(1.0));
    }
    else if(n==3){
        printf("ITEM: DIESEL\n");
        printf("RATE: %lf\n",rate3);
        printf("QUANTITY: %lf\n",quantity);
        printf("AMMOUNT: %lf\n",rate3*quantity*(1.0));
    }
    else if(n==4){
        printf("ITEM: OCTANE\n");
        printf("RATE: %lf\n",rate4);
        printf("QUANTITY: %lf\n",quantity);
        printf("AMMOUNT: %lf\n",rate4*quantity*(1.0));
    }
    printf("      \n\nTHANK YOU, PLEASE VISIT AGAIN\n\n\n");
    printf("Press Enter to Continue");
    fflush(stdin);

    char temp[100];
    fgets(temp, sizeof(temp),stdin);

}

int update_prices() {
     system("cls");
     printf("      Update new Prices\n\n\n");

     double p, c, d, o;
     printf("PETROL: ");
     scanf("%lf",&p);
     printf("CNG: ");
     scanf("%lf",&c);
     printf("DIESEL: ");
     scanf("%lf",&d);
     printf("OCTANE: ");
     scanf("%lf",&o);


     FILE *pointer;
     pointer=fopen("Prices.txt","w");
     if(pointer == NULL){
        printf("Prices file couldn't be opened\n");
        return 0;
     }
     else{
        fprintf(pointer,"%lf %lf %lf %lf",p,c,d,o);
     }

     fclose(pointer);
     return 1;
}

int main(){
    while(1){
        //not loggedIn
        // 1 -> logIn
        // 2 -> signUP
        // 3 -> Exit
        if(userLoggedIn==0){
            //system("cls");
            printf("Enter\n  1 -> logIn\n  2 -> signUP\n  3 -> Exit\n\n");

            int n;
            printf("Enter:");
            scanf("%d",&n);
            if(n==1){
                int loginsucess=logIn();
                if(loginsucess==1){
                    userLoggedIn=1;
                    system("cls");
                    printf("login Successful \n");
                }
                else if (loginsucess == -1){
                    system("cls");
                    printf("No user Registered, Please Sign Up First\n");
                } else {
                    system("cls");
                    printf("Invalid User Name or Password, Try Again\n");
                }
            }
            else if(n==2){
                int signsuccess=signUP();
                system("cls");
                if(signsuccess==1){
                    printf("Sign-Up Successful. \n try login now\n");
                }
                else {
                    printf("Sign-Up Failed\n");
                }
            }
            else if (n==3){
                return 0;
            }

        }
        else{
            // 1->logOut
            // bill
            // update_prices
            // 2->Exit
            system("cls");
            printf("Enter\n  1 -> logOut\n  2 -> billing\n  3 -> Update Prices\n  4 -> Exit\n\n");
            int n;
            scanf("%d",&n);

            if(n==1){
                userLoggedIn=0;
                system("cls");
                printf("LOGOUT SUCCESSSFULL\n");
            }
            else if(n==2){
                system("cls");
                Bill_ing();
            }
            else if(n==3) {
                system("cls");
                int status = update_prices();
                if (status == 1) {
                    printf("Price Updated\n");
                }
                else {
                    printf("Price Update Failed, Try again later.\n");
                }
            }
            else if(n==4){
                system("cls");
                return 0;
            }

        }
    }

    return 0;
}
