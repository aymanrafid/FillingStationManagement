void show_menu(){
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
                return;
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
                return ;
            }

        }
    }
}
