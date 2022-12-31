
int userLoggedIn = 0;

//Takes userName and password from user
//Creates a new user
//sign up succeeds returns 1
//if fails returns 0
int signUP(){
    char user[100];
    char pass[8];
    FILE *pointer;

    pointer=fopen("logIn.txt","a");
    if(pointer == NULL){
        printf("LogIn file couldn't be oppened\n");
        return 0;
    }
    else{
        fflush(stdin);
        printf("Enter UserName:\t");
        fgets(user,sizeof user,stdin);
        fprintf(pointer, "%s",user);

        printf("Enter Password:\t");
        fgets(pass,sizeof pass,stdin);
        fprintf(pointer, "%s",pass);
    }

    fclose(pointer);
    return 1;
}


//Takes userName and password from user
//If it matches with previous user information
//log in succeeds and returns 1
//if fails returns 0
int logIn(){
    char user[50][100];
    char pass[50][8];
    int size = 0;
    int i=0;
    FILE *pointer;

    pointer=fopen("logIn.txt","r");
    if(pointer == NULL){
        printf("LogIn file couldn't be oppened\n");
        return -1;
    }
    else{
        while(1){
            char* inputStatus = fgets(user[i],sizeof user[i],pointer);
            if(inputStatus == NULL) break;
            char* inputStatus2 = fgets(pass[i],sizeof pass[i],pointer);
            if(inputStatus == NULL || inputStatus2 == NULL) break;
            i++;
            size++;
        }

        char nuser[100];
        char gpass[8];

        fflush(stdin);

        printf("Enter UserName:");
        char* nr=fgets(nuser,sizeof(nuser),stdin);
        printf("Enter Password:");
        char* gs=fgets(gpass,sizeof(gpass),stdin);

        for(int j=0;j<size;j++) {
            if(strcmp(nuser,user[j])==0 && strcmp(gpass,pass[j])==0){
                return 1;
            }
        }
    }

    fclose(pointer);
    return 0;
}

