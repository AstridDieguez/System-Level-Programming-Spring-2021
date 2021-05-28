#include <stdio.h>

int main(void){
int num, quantity;
float price, total;
int m, d, y;
printf("Enter item number: ");
scanf("%d", &num);
printf("\nEnter unit price: ");
scanf("%f", &price);
printf("\nEnter quantity: ");
scanf("%d", &quantity);
printf("\nEnter purchase date (mm/dd/yyyy): ");
scanf("%d/%d/%d", &m, &d, &y);
total = price * quantity;
printf("%s\t%s\t%s\t%s\t%s", "Item", "Unit Price", "QTY", "Purchase Date", "Total Amount");
printf("\n%-4d\t$%9.2f\t%-3d\t%.2d/%.2d/%-8.4d\t$%11.2f\n", num, price, quantity, m, d, y, total);
return 0;
}
