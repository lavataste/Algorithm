#include<stdio.h>
#include<stdlib.h>
#include<mem.h>
int main()
{
	int count, N;
	int* a;
	scanf("%d", &N);
	a=malloc(sizeof(int)*N);
	memset(a, 0, sizeof(int)*N);
	printf("--------\n");
	for(count=0;count<N;count++)
	{
		printf("%d\n", a[count]);
	}
	
	return 0;
	
}
