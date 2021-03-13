#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int total=0;
int total_quant=0;
float total_gst=0;
float gst,cgst,sgst;

int bf_rate[9][2]={  {0,0},{1,30},{2,35},{3,40},{4,20},{5,15},{6,20},{7,30},{8,80}     };

int lunch_rate[10][2]={   {0,0},{1,80},{2,120},{3,20},{4,120},{5,150},{6,160},{7,30},{8,20},{9,30}   };

int dinner_rate[11][2]={   {0,0},{1,65},{2,20},{3,160},{4,80},{5,65},{6,110},{7,50},{8,20},{9,30},{10,100}    };

int purchased[]={  0,0,0,0,0,0,0,0,0,0,0,0   };

int quantities[]={ 0,0,0,0,0,0,0,0,0,0,0,0 };

float _gst[]={ 0,0,0,0,0,0,0,0,0,0,0,0 };

float _cgst[]={ 0,0,0,0,0,0,0,0,0,0,0,0 };

float _sgst[]={ 0,0,0,0,0,0,0,0,0,0,0,0 };

void display();
void bfast(char bfmenu[][100]);
void display_bfmenu();
void repeatbf(char bfmenu[][100]);
void display_bf_bill(char bfmenu[][100]);
void lunch( char lunchmenu[][100]);
void display_lunchmenu();
void repeatlunch(char lunchmenu[][100]);
void display_lunch_bill(char lunchmenu[][100]);
void dinner(char dinnermenu[][100]);
void display_dinnermenu();
void repeatdinner(char dinnermenu[][100]);
void display_dinner_bill(char dinnermenu[][100]);

//Removal 
void remove_bfast(char bfmenu[][100], int choice);
void remove_lunch(char lunchmenu[][100], int choice);
void remove_dinner(char dinnermenu[][100], int choice);
void final_bfast_bill();
void final_lunch_bill();
void final_dinner_bill();

void main(){
    char bfmenu[][100]={"","Toast","Parantha","Dosa","Upma","Milk","Tea","Coffee","Pasta"};
    char lunchmenu[][100]={"","Veg Biryani","Special meal","Roti","Dal","Paneer Tikka","Veg Mix","Icecream","Tea","Coffee"};
    char dinnermenu[][100]={"","Fried rice","Roti","Veg Mix","Rajma","Noodles","Parantha","Fruit Salad","Tea","Coffee","Daal Makhni"};
    
    char choice;
    
    do
    {
        display();
        printf("\nEnter your choice here (Enter '!' to exit) : ");
        fflush(stdin);
        scanf("%c", &choice);
        
        switch(choice)
        {
            case 'A':
            case 'a':
                bfast(bfmenu);
                //Removal Functionality
                int choice3;
                printf("%s", "\n[1] Remove Items");
                printf("%s", "\n[2] Print final bill");
                printf("%s", "\nPress [1] or [2]: ");
                scanf("%d", &choice3);
                remove_bfast(bfmenu, choice3);        
                break;

            case 'B':
            case 'b':
                lunch(lunchmenu);
                //Removal Functionality
                int choice1;
                printf("%s", "\n[1] Remove Items");
                printf("%s", "\n[2] Print final bill");
                printf("%s", "\nPress [1] or [2]: ");
                scanf("%d", &choice);
                remove_lunch(lunchmenu, choice);
                break;

            case 'C':
            case 'c':
                dinner(dinnermenu);
                //Removal Functionality
                int choice2;
                printf("%s", "\n[1] Remove Items");
                printf("%s", "\n[2] Print final bill");
                printf("%s", "\nPress [1] or [2]: ");
                scanf("%d", &choice2);
                remove_dinner(dinnermenu, choice2); 
                break;

            case '!':
                printf("Exiting Code");
                break;

            default:
                printf("\nWrong choice entered Please enter the valid choice!!\n\n");            
        }
    }while(choice!='!');

    exit(0);
}

//remove_lunch
void remove_lunch(char lunchmenu[][100], int choice){
    if(choice == 1){
        int c;
        int quantity = 0;
        display_lunchmenu();
        printf("%s", "\n[Enter] item number to <remove> :: ");
        scanf("%d", &c);

        if(c >= 1 && c <= 9){
            printf("Enter the quantity to remove :: ");
            scanf("%d", &quantity);
            purchased[c] -= quantity * lunch_rate[c][1];
            quantities[c] -= quantity;
            total_quant -= quantity;
            total -= purchased[c];
            gst = purchased[c] * 0.12;
            _gst[c] -= gst;
            _cgst[c] -= gst / 2;
            _sgst[c] -= gst / 2;
        }else{
            printf("%s", "\n[Invalid] code entered, [Try again]\n\n");
            remove_lunch(lunchmenu, choice);
        }

        printf("%s", "\n[1] Remove Items");
        printf("%s", "\n[2] Print final bill");
        printf("%s", "\nPress [1] or [2]: ");
        scanf("%d", &choice);
        
        remove_lunch(lunchmenu, choice);        

    }

    if(choice == 2){
        puts("\n");
        display_lunch_bill(lunchmenu);
        final_lunch_bill();
    }

    if(choice != 1 && choice != 2){
        puts("\nInvalid code entered [Please] enter a valid code");
        
        printf("%s", "\n[1] Remove Items");
        printf("%s", "\n[2] Print final bill");
        printf("%s", "\nPress [1] or [2]: ");
        scanf("%d", &choice);
        
        remove_lunch(lunchmenu, choice);
    }
}

void remove_dinner(char dinnermenu[][100], int choice){
    if(choice == 1){
        int c;
        int quantity = 0;
        display_dinnermenu();
        printf("%s", "\n[Enter] item number to <remove> :: ");
        scanf("%d", &c);

        if(c >= 1 && c <= 9){
            printf("Enter the quantity to remove :: ");
            scanf("%d", &quantity);
            purchased[c] -= quantity * dinner_rate[c][1];
            quantities[c] -= quantity;
            total_quant -= quantity;
            total -= purchased[c];
            gst = purchased[c] * 0.12;
            _gst[c] -= gst;
            _cgst[c] -= gst / 2;
            _sgst[c] -= gst / 2;
        }else{
            printf("%s", "\n[Invalid] code entered, [Try again]\n\n");
            remove_dinner(dinnermenu, choice);
        }

        printf("%s", "\n[1] Remove Items");
        printf("%s", "\n[2] Print final bill");
        printf("%s", "\nPress [1] or [2]: ");
        scanf("%d", &choice);
        
        remove_dinner(dinnermenu, choice);        

    }

    if(choice == 2){
        puts("\n");
        display_dinner_bill(dinnermenu);
        final_dinner_bill();
    }

    if(choice != 1 && choice != 2){
        puts("\nInvalid code entered [Please] enter a valid code");
        
        printf("%s", "\n[1] Remove Items");
        printf("%s", "\n[2] Print final bill");
        printf("%s", "\nPress [1] or [2]: ");
        scanf("%d", &choice);
        
        remove_dinner(dinnermenu, choice);
    }
}

void remove_bfast(char bfmenu[][100], int choice){
    if(choice == 1){
        int c;
        int quantity = 0;
        display_bfmenu();
        printf("%s", "\n[Enter] item number to <remove> :: ");
        scanf("%d", &c);

        if(c >= 1 && c <= 9){
            printf("Enter the quantity to remove :: ");
            scanf("%d", &quantity);
            purchased[c] -= quantity * bf_rate[c][1];
            quantities[c] -= quantity;
            total_quant -= quantity;
            total -= purchased[c];
            gst = purchased[c] * 0.12;
            _gst[c] -= gst;
            _cgst[c] -= gst / 2;
            _sgst[c] -= gst / 2;
        }else{
            printf("%s", "\n[Invalid] code entered, [Try again]\n\n");
            remove_bfast(bfmenu, choice);
        }

        printf("%s", "\n[1] Remove Items");
        printf("%s", "\n[2] Print final bill");
        printf("%s", "\nPress [1] or [2]: ");
        scanf("%d", &choice);
        
        remove_bfast(bfmenu, choice);        

    }

    if(choice == 2){
        puts("\n");
        display_bf_bill(bfmenu);
        final_bfast_bill();
    }

    if(choice != 1 && choice != 2){
        puts("\nInvalid code entered [Please] enter a valid code");
        
        printf("%s", "\n[1] Remove Items");
        printf("%s", "\n[2] Print final bill");
        printf("%s", "\nPress [1] or [2]: ");
        scanf("%d", &choice);
        
        remove_bfast(bfmenu, choice);
    }
}

void display(){
    printf("                   Welcome to APNA Restaurant.          \n ");
    printf("        +###########################################+          \n\n");
    printf("    Please select the meal that you would like to purchase.\n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] Lunch\n");
    printf("\t\t      [C] Dinner\n");
}

void bfast(char bfmenu[][100]){
    //local variables
    int quantity = -1;
    int c;
    display_bfmenu();
    printf("\nEnter the code (Enter 0 to go back):: ");
    fflush(stdin);
    scanf("%d", &c);
    if(c>=1&&c<=8)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[c]= quantity*bf_rate[c][1]; 
        quantities[c]=quantity;
        total_quant+=quantity;
        total+=purchased[c];
        gst=purchased[c]*0.12;
        _gst[c]=gst;
        total_gst+=gst;
        _cgst[c]=gst/2;
        _sgst[c]=gst/2;
    }
    else if (c==0)
    {   
        printf("\n");
        main();
    }
    
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bfast(bfmenu);
    }
    repeatbf(bfmenu);
}

void display_bfmenu(){
    printf("                    Welcome to APNA Restaurant.          \n ");
    printf("         +###########################################+          \n\n");
    printf("                      $  Breakfast Menu  $ \n\n");
    printf("     Please select the food that you would like to purchase.  \n\n");
    printf("\t\t   [1] Toast     -   Rs 30.00\n");
    printf("\t\t   [2] Parantha  -   Rs 35.00\n");
    printf("\t\t   [3] Dosa      -   Rs 40.00\n");
    printf("\t\t   [4] Upma      -   Rs 20.00\n");
    printf("\t\t   [5] Milk      -   Rs 15.00\n");
    printf("\t\t   [6] Tea       -   Rs 20.00\n");
    printf("\t\t   [7] Coffee    -   Rs 30.00\n");
    printf("\t\t   [8] Pasta     -   Rs 80.00\n");
}

void repeatbf(char bfmenu[][100]){   
    int again = 0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    fflush(stdin);
    scanf("%d",&again);
    if (again == 1)
    {
            printf("\n");
            bfast(bfmenu);
    }
    else if (again == 2 )
    {   
        printf("\n");
        display_bf_bill(bfmenu);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Choice Entered\n\n");
        repeatbf(bfmenu);
    }
}

void display_bf_bill(char bfmenu[][100]){
    int i;
    printf("+###################################################################################################+\n\n");
    printf("                                  ## APNA RESTAURANT ##                  \n\n");
    printf("                                 --BILLING INFORMATION--                \n\n");
    printf("  |ITEMS            |QUANTITY     |PRICE(Rs.)     |SGST            |CGST          |GST (CGST+SGST) |\n");
    printf("  --------------------------------------------------------------------------------------------------\n");  
   
    for(i=1;i<=8;i++)
    {
        if(purchased[i]!=0)
        {
            printf("  |%-15s  ",bfmenu[i]);
            printf("|%-5d\t  ", quantities[i]);
            printf("|%-5d\t  ",purchased[i]);
            printf("|%-5.2f\t   ", _sgst[i]);
            printf("|%-5.2f\t   ", _cgst[i]);
            printf("|%-16.2f|\n", _gst[i]);
        }

    }    

    printf("  --------------------------------------------------------------------------------------------------\n");
    printf("  |TOTAL PRICE (Cost + GST) -> %.2f                                                              |\n",total+total_gst);
    printf("  --------------------------------------------------------------------------------------------------\n");
    printf("\n                          ## Thank You, Please visit again ! ##                           \n"); 
    printf("\n\n+###################################################################################################+\n\n");
}


void lunch(char lunchmenu[][100]){
    //local variables
    int quantity = -1;
    int c;
    display_lunchmenu();
    printf("\nEnter the code (Enter 0 to go back):: ");
    fflush(stdin);
    scanf("%d", &c);

    if(c>=1&&c<=9){
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[c] += quantity*lunch_rate[c][1];
        quantities[c] += quantity;
        total_quant += quantity;
        total += purchased[c];
        gst = purchased[c]*0.12;
        _gst[c] += gst;
        total_gst += gst;
        _cgst[c] += gst/2;
        _sgst[c] += gst/2;
    }
    else if (c==0)
    {   
        printf("\n");
        main();
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        lunch(lunchmenu);
    }
    repeatlunch(lunchmenu);
}

void display_lunchmenu(){
    printf("                     Welcome to APNA Restaurant.          \n ");
    printf("           +##########################################+          \n\n");
    printf("                          $  Lunch Menu  $ \n\n");
    printf("       Please select the food that you would like to purchase.  \n\n");
    printf("\t\t   [1] Veg Biryani   -   Rs 80.00\n");
    printf("\t\t   [2] Special Meal  -   Rs 120.00\n");
    printf("\t\t   [3] Roti          -   Rs 20.00\n");
    printf("\t\t   [4] Dal tadka     -   Rs 120.00\n");
    printf("\t\t   [5] Paneer Tikka  -   Rs 150.00\n");
    printf("\t\t   [6] Veg Mix       -   Rs 160.00\n");
    printf("\t\t   [7] Ice cream     -   Rs 30.00\n");
    printf("\t\t   [8] Tea           -   Rs 20.00\n");
    printf("\t\t   [9] Coffee        -   Rs 30.00\n");
}

void repeatlunch(char lunchmenu[][100]){   
    int again=0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    fflush(stdin);
    scanf("%d",&again);
    if (again == 1)
    {
            printf("\n");
            lunch(lunchmenu);
    }
    else if (again == 2 )
    {   
        printf("\n");
        display_lunch_bill(lunchmenu);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatlunch(lunchmenu);
    }
}

void display_lunch_bill(char lunchmenu[][100]){
    int i;
    printf("+###################################################################################################+\n\n");
    printf("                                  ## APNA RESTAURANT ##                  \n\n");
    printf("                                 --BILLING INFORMATION--                \n\n");
    printf("  |ITEMS            |QUANTITY     |PRICE(Rs.)     |SGST            |CGST          |GST (CGST+SGST) |\n");
    printf("  --------------------------------------------------------------------------------------------------\n");  
    
    for(i=1;i<=9;i++)
    {
        if(purchased[i]!=0)
        {
            printf("  |%-15s  ",lunchmenu[i]);
            printf("|%-5d\t  ", quantities[i]);
            printf("|%-5d\t  ",purchased[i]);
            printf("|%-5.2f\t   ", _sgst[i]);
            printf("|%-5.2f\t   ", _cgst[i]);
            printf("|%-16.2f|\n", _gst[i]);
        }

    }
}

void final_lunch_bill(){
    puts("  --------------------------------------------------------------------------------------------------\n");
    printf("  |TOTAL PRICE (Cost + GST) -> %.2f                                                              |\n",total+total_gst);
    puts("  --------------------------------------------------------------------------------------------------\n");
    puts("\n                          ## Thank You, Please visit again ! ##                           \n"); 
    puts("\n\n+###################################################################################################+\n\n");
    exit(0);
}

void dinner(char dinnermenu[][100]){
    //local variables
    int quantity = 0;
    int c;
    display_dinnermenu();

    printf("\nEnter the code (Enter 0 to go back):: ");
    fflush(stdin);
    scanf("%d", &c);

    if(c>=1 && c<=10)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[c]= quantity*dinner_rate[c][1];
        quantities[c]=quantity;
        total_quant+=quantity;
        total+=purchased[c];
        gst=purchased[c]*0.12;
        _gst[c]=gst;
        total_gst+=gst;
        _cgst[c]=gst/2;
        _sgst[c]=gst/2;
    }
    else if (c==0)
    {   
        printf("\n");
        main();
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu);
    }
    repeatdinner(dinnermenu);
}

void display_dinnermenu(){
    printf("                    Welcome to APNA Restaurant.          \n ");
    printf("         +###########################################+          \n\n");
    printf("                        $  Dinner Menu  $ \n\n");
    printf("      Please select the food that you would like to purchase.  \n\n");
    printf("\t\t   [1]  Fried Rice   -   Rs 65.00\n");
    printf("\t\t   [2]  Roti         -   Rs 50.00\n");
    printf("\t\t   [3]  Veg Mix      -   Rs 70.00\n");
    printf("\t\t   [4]  Rajma        -   Rs 80.00\n");
    printf("\t\t   [5]  Noodles      -   Rs 65.00\n");
    printf("\t\t   [6]  Parantha     -   Rs 110.00\n");
    printf("\t\t   [7]  Fruit Salad  -   Rs 50.00\n");
    printf("\t\t   [8]  Tea          -   Rs 20.00\n");
    printf("\t\t   [9]  Coffee       -   Rs 30.00\n");
    printf("\t\t   [10] Daal Makhni  -   Rs 30.00\n");
}

void repeatdinner(char dinnermenu[][100]){
    int again=0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    fflush(stdin);
    scanf("%d",&again);
    if (again == 1)
    {
        printf("\n");
        dinner(dinnermenu);
    }
    else if (again == 2 )
    {   
        printf("\n");
        display_dinner_bill(dinnermenu);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatdinner(dinnermenu);
    }
}

void display_dinner_bill(char dinnermenu[][100]){
    int i;
    printf("+###################################################################################################+\n\n");
    printf("                                  ## APNA RESTAURANT ##                  \n\n");
    printf("                                 --BILLING INFORMATION--                \n\n");
    printf("  |ITEMS            |QUANTITY     |PRICE(Rs.)     |SGST            |CGST          |GST (CGST+SGST) |\n");
    printf("  --------------------------------------------------------------------------------------------------\n");  
    
    for(i=1;i<=9;i++)
    {
        if(purchased[i]!=0)
        {
            printf("  |%-15s  ",dinnermenu[i]);
            printf("|%-5d\t  ", quantities[i]);
            printf("|%-5d\t  ", purchased[i]);
            printf("|%-5.2f\t   ", _sgst[i]);
            printf("|%-5.2f\t   ", _cgst[i]);
            printf("|%-16.2f|\n", _gst[i]);
        }
    }

}

void final_dinner_bill(){
    puts("  --------------------------------------------------------------------------------------------------\n");
    printf("  |TOTAL PRICE (Cost + GST) -> %.2f                                                              |\n",total+total_gst);
    puts("  --------------------------------------------------------------------------------------------------\n");
    puts("\n                          ## Thank You, Please visit again ! ##                           \n"); 
    puts("\n\n+###################################################################################################+\n\n");
    exit(0);
}

void final_bfast_bill(){
    puts("  --------------------------------------------------------------------------------------------------\n");
    printf("  |TOTAL PRICE (Cost + GST) -> %.2f                                                              |\n",total+total_gst);
    puts("  --------------------------------------------------------------------------------------------------\n");
    puts("\n                          ## Thank You, Please visit again ! ##                           \n"); 
    puts("\n\n+###################################################################################################+\n\n");
    exit(0);  
}