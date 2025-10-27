#include <stdio.h>
#include"VENDING.h"
int main(){
    int choice,quantity,money,inserted_money=0,total=0,change,price;
    char more,mode;
    struct menu items[]={{"Soda",1000,30},{"Water",1000,40},{"Yogurt",4000,15},{"Snacks",3000,30},{"Icecream",2000,25}};
    int size = sizeof(items)/sizeof(items[0]);
    loadStock(items,size);//Loads and reads the stock values saved in the stock.txt
    printf("Enter mode:(C)ustomer or (O)wner:");
    scanf(" %c",&mode);
if(mode=='o'||mode=='O'){
        if(pinVerfication()){
        restockItems(items,size);
        printf("\t\tCurrent stock\n");
        displayMenu(items,size);
        updatePrice(items,size);
        return 0;
}else{
    return 0;
}
}
displayMenu(items,size);
do{
    choice =getChoice();
    price =getPrice(items,choice);
    int cost=stockCheck(items,choice,size);
    total+=cost;
    printf("Your current total is UGX %d\n",total);
    printf("Do you want to purchase another item?(y/n):");
    scanf(" %c",&more);
   } while(more=='Y'||more=='y');
    printf("Final Total = UGX %d\n",total);
    while(money<total){ //Accept money until its atleast enough
    printf("Please insert your money(UGX):");
    scanf("%d",&inserted_money);
    money+= inserted_money;
    if(money<total){
    printf("Insufficient funds!!You need UGX %d more.\n",total-money);
    }
    }
    change = money-total; //Change calculation
    printf("Payment accepted.Transaction being processed.\n");
    printf("Your change = UGX %d\n",change);
    if(change>0){
        calculateChange(change);
}else{
printf("Exact payment received.No change.\n");
}
return 0;
}





