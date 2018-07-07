#include <stdio.h>
#include "factorization.h"
#include <math.h>
void printingFoo (int base,int amount)
{
for (int i =0;i<amount;i++)
{	
	if(i == 0)
	printf("\n%i",base);
	if(i>0)
	printf("x%i",base);
	
}
}
void NumFactor(int Num)
{
int tmp = Num;
for(int i =2;i<=sqrt(Num);i++)
{
if (Num%i == 0)
{
int cnt = 0;
	while(Num%i==0)
{
Num=Num/i;
cnt++;
}
printingFoo(i,cnt);
}
}
if(Num!=1)
printingFoo(Num,1);
printf(" that was the number : %i\n",tmp);
}


