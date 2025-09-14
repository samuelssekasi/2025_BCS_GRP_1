#include <stdio.h>
#include <stdlib.h>

int main() {
 int choice, quantity, money, price, total  , change;
 char more;

 // Displaying the vending machine items
 printf("**** MENU ******\n");
 printf("1. Soda (UGX 1000)\n");
 printf("2. Water (UGX 1000)\n");
 printf("3. Yogurt (UGX 4000)\n");
 printf("4. Snacks (UGX 3000)\n");
 printf("5.Icecream (UGX 2000)\n");
 printf("***** THANKS ***** \n");

do {
 // Asking the user to make a choice
 printf("Please select an item (1-5): ");
 scanf("%d", &choice);

 if(choice == 1) {
 price = 1000; printf("You selected Soda.\n");
 }
 else if(choice == 2) {
 price = 1000; printf("You selected Water.\n");
 }
 else if(choice == 3) {
 price = 4000; printf("You selected Yogurt.\n");
 }
 else if(choice == 4) {
 price = 3000; printf("You selected Snacks.\n");
 }
 else if(choice == 5) {
 price = 2000; printf("You selected Icecream.\n");
 }
 else {
 printf("Invalid choice!Please try again.\n");
 continue;
}

 // Ask for quantity
 printf("Enter quantity: ");
 scanf("%d", &quantity);

 // Calculate the total price
 total += price * quantity;
 printf("Added UGX %d to your bill. Current total = UGX %d\n", price * quantity, total);

 // Ask if they want to purchase another item
 printf("Do you want another item? (y/n): ");
 scanf(" %c", &more);
} while(more == 'y' || more == 'Y');

 // Accept money
 printf("Final total = UGX %d\n", total);
 printf("Please insert money (UGX): ");
 scanf("%d", &money);

 // Check payment
 if(money < total) {
 printf("Insufficient funds! You need UGX %d more.\n", total - money);
 printf("Transaction failed.\n");
 }else{
printf("Payment accepted. Processing transaction...\n");
 }

 // Calculate change
 change = money - total;
 if(change > 0) {
 printf("Your change is UGX %d\n", change);
 printf("**** Change Breakdown ****\n");
 printf("Currency\           number\n");
 printf("--------------------------\n");
 int denominations[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50};
 int count, i;
 for(i = 0; i < 10; i++) {
 count = change / denominations[i];
 if(count > 0) {
 printf("UGX %d\t\t%d\n", denominations[i], count);
 change %= denominations[i];
 }
 }
 } else {
 printf("Exact payment received. No change.\n");
 }
 return 0;

}
