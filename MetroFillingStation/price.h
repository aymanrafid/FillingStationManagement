

//take inputs a integer referring to Petrol/CNG/Diesel/Octane
//fetch their current price from Prices.txt file
//returns price according to input
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

        if(n==1) {
            return p;
        }
        else if(n==2) return c;
        else if(n==3) return d;
        else if(n==4) return o;
    }
    return -1;
}

//take input updated prices from user
//updates the prices in Prices.txt file
//returns 0 for failure and 1 for success.
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
