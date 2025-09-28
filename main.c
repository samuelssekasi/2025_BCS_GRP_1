#include <stdio.h>
//FUNCTION DECLARATIONS
void displayMenu();//FUNCTION TO DISPLAY THE MENU
int getChoice();//FUNCTION TO ALLOW CHOICE SELECTION
int getPrice(int choice);// FUNCTION RETURN PRICE
void calculateChange(int change);//FUNCTION TO CALCULATE AND DISPLAY THE CHANGE

int main(){
    int choice,quantity,money,inserted_money,total,change,price;
    char more;
    //VENDING MACHINE ORDER
    displayMenu();
do{
    choice =getChoice();
    price =getPrice(choice);
    printf("Enter quantity:");
    scanf("%d",&quantity);
    total+=price*quantity;
    printf("You have added UGX %d to your bill.Current bill = UGX %d\n",price*quantity,total);
    printf("Do you want to purchase another item?(y/n):");
    scanf(" %c",&more);
   } while(more=='Y'||more=='y');
    printf("Final Total = UGX %d\n",total);
    //Accept money until its atleast enough
    while(money<total){
    printf("Please insert your money(UGX):");
    scanf("%d",&inserted_money);
    money+= inserted_money;
    if(money<total){
    printf("Insufficient funds!!You need UGX %d more.\n",total-money);
    }
    }
    //Change calculation
    change = money-total;
    printf("Payment accepted.Transaction being processed.\n");
    printf("Your change = UGX %d\n",change);
    if(change>0){
        calculateChange(change);
}else{
printf("Exact payment received.No change.\n");
}
return 0;
}
//FUNCTION DEFINITIONS
void displayMenu(){
    printf("*****MENU*****\n");
    printf("1.Soda (UGX 1000)\n");
    printf("2.Water (UGX 1000)\n");
    printf("3.Yogurt (UGX 4000)\n");
    printf("4.Snacks (UGX 3000)\n");
    printf("5.Icecream (UGX 2000)\n");
    printf("*****THANKS*****\n");
    }
int getChoice(){
 int choice;
    while (1) {
        printf("Please select an item (1-5): ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 5) {
            return choice;
        }
        printf("Invalid choice!! Please make a valid choice.\n");
}
}
int getPrice(int choice){
switch (choice) {
        case 1: printf("You have selected Soda.\n");return 1000;
        case 2: printf("You have selected Water.\n");return 1000;
        case 3: printf("You have selected Yogurt.\n");return 4000;
        case 4: printf("You have selected Snacks.\n");return 3000;
        case 5: printf("You have selected Icecream.\n");return 2000;
        default: return 0;

}
}
void calculateChange(int change){
printf("*****change breakdown*****\n");
    printf("Currency\tNumber\n");
    printf("----------------------\n");
    int denominations[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
    int count,i;
    for (i = 0; i < 10; i++) {
        count = change / denominations[i];
        if (count > 0) {
            printf("UGX %d\t%d\n", denominations[i], count);
            change %= denominations[i];
        }
    }

    if (change > 0) {
        printf("Your change is UGX %d\n", change);
    }
}



