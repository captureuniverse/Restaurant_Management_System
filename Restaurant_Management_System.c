#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

void xBanner(void);
void mainmenu(void);
void front(void);
void hashBanner(void);

int main(void){

    mainmenu();

    int choice;
    printf("%s", "Enter your choice: ");
    scanf("%d", &choice, 1);

    while(choice != 5){
        switch(choice){
            case 1:
                menu();
                hashBanner();
                mainmenu();
                break;    
            case 2:
                int items[22];
        }
    }


    system("pause");
    return 0;
}

void mainmenu(void){
    hashBanner();
    printf("%s", "1. See Menu\n");
    printf("%s", "2. Add Items\n");
    printf("%s", "3. Update Items\n");
    printf("%s", "4. Remove Items\n");
    printf("%s", "5. Exit\n");
    hashBanner();
}

void hashBanner(void){
    printf("*********************************************************************\n");
    printf("*********************************************************************\n");
}

void xBanner(void){
        int row, column, numrows = 5, numcolumns = 17;
        
        for(row = 0; row < numrows; row++){
            for(column = 0; column < numcolumns; column++){
                if((row == column || row + column == 4) && (row < 5 && column < 5))
                    printf("%s", "#");    
                else
                    printf("%s", " ");


                if((column + row == 10) || (column - row == 6))
                    printf("%s", "#");
                else
                    printf("%s", " ");


                if((column + row == 16) || (column - row == 12))
                    printf("%s", "#");
                else
                    printf("%s", " ");
        }
        printf("%s", "\n");
    } 
}

void menu(void){
    puts("");
    printf("%40s\n", "WELCOME TO OUR RESTAURANT");
    printf("%s", "\n\n");

    printf("%s\n", "1. STARTERS");
    printf("%s\n", "  a. Indian Salad   5.00  |  b. Papad         5.00");
    printf("%s\n", "  c. Mineral Water  6.00  |  d. Lassi         10.00");
    printf("%s", "\n");
   
    printf("%s\n", "2. SIDES");
    printf("%s\n", "  e. French Fries   20.00 |  f. Onion Rings   25.00");
    printf("%s\n", "  g. Choco Cake     35.00 |  h. Choco Muffin  40.00");
    printf("%s", "\n");

    printf("%s\n", "3. MAINS");
    printf("%s\n", "  i. Shahi Paneer   70.00 |  j. Dal Makahni   60.00");
    printf("%s\n", "  k. Aloo Dum       50.00 |  l. Mix Veg       70.00");
    printf("%s\n", "  m. Plain Roti     5.00  |  n. Butter Roti   7.00");
    printf("%s\n", "  o. Aloo Nan       10.00 |  p. Missi Roti    20.00");
    printf("%s", "\n");

    printf("%s\n", "4. DRINKS");
    printf("%s\n", "  q. Red Bull       110.00|  r. Monster       120.00");
    printf("%s\n", "  s. Pepsi          30.00 |  t. Mazaa         30.00");
    printf("%s\n", "  u. Chocolate      50.00 |  v. Butterscotch  50.00");
    printf("%s", "\n");
}