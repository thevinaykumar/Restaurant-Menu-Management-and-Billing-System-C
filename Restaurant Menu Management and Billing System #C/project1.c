#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem
{
char name[50]; 
char type[20];
 float price; 
 float discount;
};

struct MenuItem menu[100];
 int menuCount = 0;

void displayMenu()
{
printf("Menu:\n");
for (int i = 0; i < menuCount; i++)
{
printf("%d. %s (%s) - %.2f\n", i + 1, menu[i].name, menu[i].type, menu[i].price);
}
}

void addItem()
{
char name[50];
 char type[20]; 
float price;88u
 float discount;
printf("Enter name of item: ");
 scanf("%s", name); 
 printf("Enter type of item: ");
  scanf("%s", type);
printf("Enter price of item: ");
 scanf("%f", &price);
printf("Enter discount of item: "); 
scanf("%f", &discount);
struct MenuItem newItem = {.price = price, .discount = discount};
 strcpy(newItem.name, name);
strcpy(newItem.type, type); 
menu[menuCount] = newItem;
 menuCount++;
printf("Item added successfully!\n");
}

void deleteItem()
{
int index;
printf("Enter the item number to delete: "); 
scanf("%d", &index);
if (index < 1 || index > menuCount)
{
printf("Invalid item number.\n"); 
return;
}
for (int i = index - 1; i < menuCount - 1; i++)
{
menu[i] = menu[i + 1];
}
menuCount--;
printf("Item deleted successfully!\n");
}

void applyDiscount()
{
float discount;
printf("Enter the discount percentage: ");
 scanf("%f", &discount);
for (int i = 0; i < menuCount; i++)
{
menu[i].discount = discount;
}
printf("Discount applied successfully!\n");
}

void makePayment()
{
float total = 0;
float discountTotal = 0; char mode[20];
 printf("Menu:\n");
for (int i = 0; i < menuCount; i++)
{
printf("%d. %s (%s) - %.2f\n", i + 1, menu[i].name, menu[i].type, menu[i].price);
total += menu[i].price;
discountTotal += menu[i].price * (menu[i].discount / 100);
}
printf("Total: %.2f\n", total);
 printf("Discount: %.2f\n", discountTotal);
printf("Net Total: %.2f\n", total - discountTotal);
 printf("Enter the payment mode: ");
scanf("%s", mode);
printf("Payment made successfully using %s.\n", mode);
 
}

int main()
{
int choice;

while (1)
{
printf("Welcome to the restaurant menu system.\n");
 printf("Please select an option:\n");
printf("1. Display menu\n");
 printf("2. Add item\n"); 
 printf("3. Delete item\n"); 
 printf("4. Apply discount\n"); 
 printf("5. Make payment\n");
  printf("6. Exit\n");
printf("Enter Your Choice from above : ");
 scanf("%d", &choice);

switch (choice)
{
case 1:
displayMenu(); break;
case 2:
addItem(); break;
case 3:
deleteItem(); break;
case 4:
applyDiscount(); break;
case 5:
makePayment(); break;
case 6:
printf("Thank you for using the restaurant menu system.\n"); 
exit(0);
default:
printf("Invalid choice. Please try again.\n"); break;
}
}

return 0;
}