#include<stdio.h>

long array[100000];


int f(int n)
{
	int i, r;
    r=1;
    
    while(n%2==0)
    {
     	n/=2;   
    }
    
    if(n==1)
    	return 1;
    
    if(array[n])
        return array[n];
    
    for(i=3;i<=n/2;i+=2)
    {
        if(n%i==0)
            r+=i;
    }
    if(n%2)
        r+=n;
//    printf("%d %d\n", n, r);
//    array[n]=r;
    return r;
}


int main()
{

	int i;
	array[1]=1;
	for(i=1; i<=100000; i++)
	{
		printf("%d %d \n", i, f(i));
	}
	
	return 0;
}
