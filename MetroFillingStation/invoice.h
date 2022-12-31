
void Bill_ing(){
    int n;
    char NAME[20];
    printf("COSTOMER NAME: ");
    fflush(stdin);
    fgets(NAME, sizeof(NAME),stdin);
    //choose item
    printf("Enter\n  1 -> PATROL\n  2 -> CNG\n  3 -> DIESEL\n  4 -> OCTANE\n\n");
    printf("Enter:");
    scanf("%d",&n);

    if(n==1){
        printf("Item: PATROl\n");
        double unit;
        //input quantity in litre
        printf("Purchase Amount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
    else if(n==2){
        printf("Item: CNG \n");
        double unit;
        //input quantity in litre
        printf("Purchase Amount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
    else if(n==3){
        printf("Item: DIESEL \n");
        double unit;
        //input quantity in litre
        printf("Purchase Ammount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
    else if(n==4){
        printf("Item: OCTANE \n");
        double unit;
        //input quantity in litre
        printf("Purchase amount: ");
        scanf("%lf",&unit);
        printf("\n\n\n");
        invoice_for_patrol(n, &NAME ,unit);
    }
}













    //take input item ,customer name ,and quantity of item;
    //create bill according to item
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
        printf("ITEM: CNG\n");
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

