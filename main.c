#include <stdio.h>
#include"VENDING.h"
int main(){
    int choice,quantity,money,inserted_money=0,total=0,change,price;
    char more;
    char mode;
    struct menu items[]={{"Soda",1000,30},{"Water",1000,40},{"Yogurt",4000,15},{"Snacks",3000,30},{"Icecream",2000,25}};
    int size = sizeof(items)/sizeof(items[0]);
    loadStock(items,size);
    printf("Enter mode:(C)ustomer or (O)wner:");
    scanf(" %c",&mode);
    if(mode=='O'||mode=='o'){
        restockItems(items,size);
        printf("Updated stock:\n");
        displayMenu(items,size);
        return 0;
}
displayMenu(items,size);
do{
    choice =getChoice();
    price =getPrice(items,choice);
    int cost=stockCheck(items,choice);
    total+=cost;
    printf("Your current total is UGX %d\n",total);
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





