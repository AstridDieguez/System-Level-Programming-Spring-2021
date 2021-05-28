#include <stdio.h>
#include <stdlib.h>
void split_time(long total_sec, int *hr, int *min, int *sec)
{
        *hr = total_sec / 3600;
        total_sec = total_sec % 3600;
        *min =  total_sec / 60;
        total_sec = total_sec % 60;
        *sec = total_sec;
}
int main(void)
{
int n, hr, min, sec;
printf("Enter seconds: \n");
scanf("%d", &n);

split_time(n, &hr, &min, &sec);

printf("Converted format: %d hour %d mins %d secs\n", hr, min ,sec);
return 0;
}
