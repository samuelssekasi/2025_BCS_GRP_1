struct menu {char name[20];int price;int stock};//STRUCT DEFINITION FOR THE MENU
void displayMenu(struct menu items[],int size);//FUNCTION TO DISPLAY THE MENU
int getChoice(void);//FUNCTION TO ALLOW CHOICE SELECTION
int getPrice(struct menu items[],int choice);// FUNCTION THAT RETURNS PRICE
void calculateChange(int change);//FUNCTION TO CALCULATE AND DISPLAY THE CHANGE
int stockCheck(struct menu items[],int choice,int size);//FUNCTION TO CHECK THE STOCK AND CALCULATE THE COST
void restockItems(struct menu items[],int size);
void saveStock(struct menu items[],int size);
void loadStock(struct menu items[],int size);
int pinVerfication(void);
void updatePrice(struct menu items[],int size);
