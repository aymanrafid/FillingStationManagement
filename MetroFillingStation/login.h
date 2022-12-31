
int userLoggedIn = 0;

struct User {
    char id[100];
    char pass[20];
};

//Takes userName and password from user
//Creates a new user
//sign up succeeds returns 1
//if fails returns 0
int signUP(){
    char id[100];
    char pass[20];
    FILE *pointer;

    pointer=fopen("logIn.txt","a");
    if(pointer == NULL){
        printf("LogIn file couldn't be oppened\n");
        return 0;
    }
    else{
        fflush(stdin);
        printf("Enter UserName:\t");
        fgets(id,sizeof id,stdin);
        fprintf(pointer, "%s",id);

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

    struct User users[50];
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
            char* inputStatus = fgets(users[i].id,sizeof users[i].id,pointer);
            if(inputStatus == NULL) break;
            char* inputStatus2 = fgets(users[i].pass,sizeof users[i].pass,pointer);
            if(inputStatus == NULL || inputStatus2 == NULL) break;
            i++;
            size++;
        }


        struct User user1;

        fflush(stdin);

        printf("Enter UserName:");
        char* nr=fgets(user1.id,sizeof(user1.id),stdin);
        printf("Enter Password:");
        char* gs=fgets(user1.pass,sizeof(user1.pass),stdin);

        for(int j=0;j<size;j++) {
            if(strcmp(user1.id,users[j].id)==0 && strcmp(user1.pass,users[j].pass)==0){
                return 1;
            }
        }
    }

    fclose(pointer);
    return 0;
}

