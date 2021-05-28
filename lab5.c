#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int bintodec (int binary);
int bina(int bin);
int powerfunction(int base, int power);
int main()
{
	int num;
	printf("Enter a number\n");
	scanf("%d",&num);
	printf("Result is %d\n",bina(num));
}

int bina(int bin)
{
	int sum=0;
	int dec=1;
	for(int i=0;i<bintodec(bin)-1;i++)
		dec*=10;
	sum=bin;
	if(bin)
	{
		bin=bin%dec;
		sum+=powerfunction(bin, 1);
		sum+=bina(bin);
	}
	return sum;
}
int bintodec (int binary)
{
	int dec=0;
	if(binary)
	{
		dec++;
		binary/=10;
		dec+=bintodec(binary);
	}
	return dec;
}

int powerfunction(int base, int power)
{
	if(base)
	{
		base/=10;
		power*=2;
	}
	return power;
}
