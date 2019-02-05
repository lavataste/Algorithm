#include<stdio.h>
int array[1000000];
int f(int n)
{
	int i, r, k;
    r=1;
    k=n;
    
    while(k%2==0)
    {
     	k/=2;
     	if(array[k])
	    {
	    	array[n]=array[k];
	        return array[n];
		}
    }
    
    
    
    if(k==1)
    	return 1;
/*    
    if(array[k])
    {
    	array[n]=array[k];
        return array[n];
	}
*/
	
    for(i=3;i<=k/2;i+=2)
    {
        if(!(k%i))
        {
            r+=i;
            printf("%d ", i);
        }
    }

    r+=k;

    array[n]=r;
    printf("\n");
    return r;
}


int main()
{
	int i;
	while(1)	
	{
		scanf("%d", &i);
		printf("%d\n\n", f(i));
	}
	
	return 0;
}
