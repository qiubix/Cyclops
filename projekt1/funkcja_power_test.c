#include <stdio.h>


double mean;
int n=4;

double power(double x)
{
       double pot = 1.0;
       int k;
       for(k=1;k<n;k++)
       {
               pot = pot*x;
               }
       return pot;
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
    mean = product;
    double x_y;
    x_y = power(mean);
    
    int i;
    for(i=0;i<20;i++)
    {
            printf("%d    %lf\n",i,mean);
                         
            printf("%d    %lf\n",i,x_y);
            
            mean = ((n-1)*mean + product/x_y)/n;
            printf("%d    %lf\n",i,mean);
            
            x_y = power(mean);
            printf("potega mean %lf\n",x_y);
            
            printf("Koniec petli nr %d\n",i);
            }
    printf("Srednia to: %lf\n",mean);
    }
