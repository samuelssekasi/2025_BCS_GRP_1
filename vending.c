#include"VENDING.h"
#include<stdio.h>
#include <string.h>
void displayMenu(struct menu items[],int size){
printf("****************MENU*******************\n");
printf("%-4s%-15s%-5s\t%s\n","No","ItemName","ItemPrice","ItemStock");
for(int i=0;i<size;i++){
printf("%-4d%-15sUGX %-5d\t%d\n",i+1,items[i].name,items[i].price,items[i].stock);
}
}
 int getChoice(void){
int choice;
 while(1){
printf("Please select an item (1-5): ");
scanf("%d", &choice);
if (choice >= 1 && choice <= 5) {
return choice;
}
 printf("Invalid choice!! Please make a valid choice.\n");
}
}
int getPrice(struct menu items[],int choice){
 printf("You have selected %s.\n",items[choice-1].name);
return items[choice-1].price;
}
int stockCheck(struct menu items[],int choice,int size){
int i=choice-1,quantity,cost=0;
while(1){
 printf("Enter quantity:");
 scanf("%d",&quantity);
 if(quantity<=items[i].stock){
items[i].stock-=quantity;
cost=items[i].price*quantity;
 printf("You bought %d units of %s for UGX %d.\n",quantity,items[i].name,cost);
saveStock(items,size);//permanently saves the updated stock.
return cost;
 }else{
 printf("Sorry,Only %d units of %s are available\n",items[i].stock,items[i].name);
}
}
}
void calculateChange(int change){
printf("----------------\n");
printf("%-10s%-10s\n","Currency","Number");
printf("----------------\n");
int denominations[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
int count,i;
for (i = 0; i < 10; i++) {
count = change / denominations[i];
if (count > 0) {
printf("UGX %-10d%-10d\n", denominations[i], count);
change %= denominations[i];
}
}
if (change > 0) {
printf("Your change is UGX %d\n", change);
}
}
int pinVerfication(){
char pin[5];
int trials=0;
while(trials<3){
    printf("Enter a 4-digit PIN: ");
    scanf("%4s",pin);
if (strcmp(pin,"2262")==0){
 printf("Access granted!\n");
 return 1;
 }
 trials++;
 printf("Incorrect PIN! Attempts left:%d\n",3-trials);
 }
 printf("Too many attempts failed.Try again next time.\n");
 return 0;
}
void restockItems(struct menu items[],int size){
int choice,added_stock;
char more,response;
printf("Do you want to restock any item?(y/n):");
scanf(" %c",&response);
if(response!='y'&& response!='Y'){
 printf("No restock made.\n");
 return;
}
printf("      -----RESTOCK MODE-----\n");
do{
displayMenu(items,size);
printf("Enter the item number to restock(1-%d):",size);
scanf("%d",&choice);
if(choice<1||choice>5){
 printf("Invalid choice! Restock process failed.\n");
 return;
}
printf("Enter number of units to add for %s: ",items[choice-1].name);
scanf("%d",&added_stock);
if(added_stock<=0){
     printf("Invalid quantity!\n");
 return;
}
items[choice-1].stock+=added_stock;
printf("%s has been restocked.New stock=%d\n",items[choice-1].name,items[choice-1].stock);
saveStock(items,size);//permanently saves the updated stock to stock.txt
printf("Do you want to restock another item?(y/n):");
scanf(" %c",&more);
}while(more=='Y'||more=='y');
 printf("Restocking cancelled!\n");
}
void updatePrice(struct menu items[],int size){
char response;
printf("Do you want to update the price of any item?(y/n):");
scanf(" %c",&response);
if(response!='y'&& response!='Y'){
 printf("No price updates made.\n");
 return;
}
int choice,newPrice;
 displayMenu(items,size);
 printf("Enter the item number whose price you want to update:");
 scanf("%d",&choice);
if(choice>=1||choice<=size){
printf("Enter new price for %s:UGX ",items[choice-1].name);
scanf("%d",&newPrice);
items[choice-1].price=newPrice;
saveStock(items,size);
printf("Price for %s updated to UGX %d successfully.\n",items[choice-1].name,newPrice);
}else{
printf("Invalid item number.\n");
}
}
void saveStock(struct menu items[],int size){
FILE*fptr;
fptr=fopen("stock.txt","w");
for(int i=0;i<size;i++){
 fprintf(fptr, "%s %d %d\n",items[i].name,items[i].price,items[i].stock);
}
fclose(fptr);
}
void loadStock(struct menu items[],int size){
FILE*fptr;
fptr=fopen("stock.txt","r");
for(int i=0;i<size;i++){
 fscanf(fptr, "%s %d %d",items[i].name,&items[i].price,&items[i].stock);
}
fclose(fptr);
}
