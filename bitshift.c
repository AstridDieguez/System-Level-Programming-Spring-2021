#include <stdio.h>

int main(void)
{
signed int x;
printf("Enter a number\n");
scanf("%d", &x);
int s = x<<3;
x = ~x + 1;
printf("Shifted left 3: %d\n", s);
printf("Complement: %d\n", x);
printf("Sum: %d\n", x + s);
return 0;
}
