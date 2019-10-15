#include<stdio.h>
#include<string.h>
int main()
{   int n;
    scanf("%d",&n);
    if(n==1918)
       printf("26.09.1918");
    if(n<1918)
        {            if(n%4==0)
                {
                    printf("28.10.%d",n);
                }
            if(n%4!=0)
                {
                    printf("13.09.%d",n);
                }
        }
    if(n>1918)
        {
            if((n%4==0 && n%100!=0) || n%400==0)
            {
                printf("12.09.%d",n);
            }
            else
                printf("13.09.%d",n);
        }

    return 0;
}
