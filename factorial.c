#include <stdio.h>

int main(void)
{
int num, new, i;
printf("Enter a number\n");
scanf("%d", &num);
if (num == 0){
new = 1;
}
else {
new=1;

for (i=1; i<=num; i++){
new = new * i;
}

}

printf("Factorial: %d\n", new);
return 0;
}
