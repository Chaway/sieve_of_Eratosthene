//numerial integration.cpp
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define sigma 15.0
#define miu 50.0
#define A 50
#define epson 0.001

double f(double x)
{
   return 1/(sigma*sqrt(2*M_PI))*exp(-0.5*(x + A - miu)*(x + A - miu)/sigma/sigma);
}

int main(int argc, char const *argv[])
{
	int i = 1;
	int n ;
	double s_last = 0 , s_current;
	double RP = f(-A) + f(A);
	printf("%lf\n",RP);
	//return 0;
	double RC = 0;
	double H = 2*A; 
	double D;
	while(1)
	{
		n = i + 1;
        RC = 0;
        while(i--)
        {
        	RC = RC + f(-A - H/2 + i*H);
        	//printf("RC = %lf\n", RC);
        }
        //prepare for next cycle;
        printf("RC = %lf\n", RC);
        i = (n << 1) - 1;
        s_current = H/6*(RP + 4*RC);
        H = H/2;
        RP = RP + 2*RC;

        switch  (fabs(s_current) < 1 ? 1 :0)
        {
          case 0: 
                 D = (s_last - s_current)/s_current;
                 printf("case 0 \n");
                 break;
          case 1:
                 D =  s_last - s_current;
                 printf("case 1 \n");
                 break;
        }
        
        s_last = s_current;
         printf("n = %d , D = %lf ,  V = %lf\n",n,D,s_current);
        if(fabs(D)< epson)
        	{       		
        		printf("stop here\n");
        		break;
        	}
	}
    
	return 0;
}
