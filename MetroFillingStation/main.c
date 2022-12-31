#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#include "login.h"
#include "price.h"
#include "invoice.h"
#include "menu.h"
#include"splash.h"


int main(void){
      splash();
      sleep(5);
      system("cls");
      show_menu();
      return 0;
}
