#include <stdio.h>

int main()
{
int a=10 , b=30 , c=20;

int res=0;

res= (a>b)?((a>c)?a:c):((b>c)?b:c);
printf("\n Result=%d\n",res);

return 0;
}
