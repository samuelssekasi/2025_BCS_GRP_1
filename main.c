#include <stdio.h>
#include <stdlib.h>

int main()
{
   int choice,quantity,money,price,total;
   char more;

    //Display menu
printf("******MENU******\n");
printf("1.Water(shs.1000)\n");
printf("2.Soda(shs.1000)\n");
printf("3.Juice(shs.2500)\n");
printf("4.Icecream(shs.2000)\n");
printf("5.Yoghurt(shs.3500)\n");
printf("***************\n");

//Ask the customer for choice
printf("ENTER THE PRODUCT NO(1-5):  ");
scanf("%d", &choice);

// Select the price from the customers choice
 if(choice == 1){
        price = 1000;
    printf("You have selected Water.\n");
    }else if(choice == 2){
    price = 1000;
    printf("You have selected Soda.\n");
    }else if(choice == 3){
    price = 2500;
    printf("You have selected Juice.\n");
    }else if(choice == 4){
    price = 2000;
    printf("You have selected Icecream.\n");
    }else if(choice == 5){
    price = 3500;
    printf("You have selected Yoghurt.\n");
    }else{
    printf("Invalid choice!!! Please try again.\n");

}

// Ask the customer for quantity
printf("ENTER THE QUANTITY OF THE PRODUCT: ");
scanf("%d",&quantity);

// Calculate the total
total += quantity * price;
printf("Totalcost = UGX %d\n",total);

//Ask the customer if they want more
printf("Do you want another item?(yes/no):");
scanf(" %c", &more);
while(more == 'yes');


//Ask the customer for the money
printf("Please insert money (UGX): ");
scanf("%d",&money);

// Check payment
if(money == total){
  printf("Payment accepted. Transaction processing.\n");
}else if(money >  total){
printf("Payment accepted. Transaction processing.\n");
printf("Your change is UGX %d.\n",money-total);
}else{
printf("Insufficient funds!! You need UGX %d more.\n",total-money);
printf("Transaction failed.\n");
}
return 0;
}

