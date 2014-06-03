#include <stdio.h>

double pot = 1.0;
double mean;
int n=4;

double power(double x, int m)
{
	if(m%2==1)
	{
		double b;
		b = x*power(x,m-1);
		return b;
	}
	else
	{
		double a;
		a = power(x,m/2);
		return a*a;
	}
}


int main()
{
	double product = 1.0;
	double x;
	printf("Wprowadz 4 liczby:\n");
	int j;
	for(j=0;j<4;j++)
	{
		scanf("%lf",&x);
		product *= x;
	}
	printf("Product to %lf\n", product);
	mean = (int) product;
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d    %lf\n",i,mean);
		double x_n;
		x_n = power(mean,n-1);
		printf("%d    %lf\n",i,x_n);
		double temp;
		temp = product/x_n;
		mean = (3*mean + temp)/n;
	}
	printf("Srednia to: %lf\n",mean);
}

