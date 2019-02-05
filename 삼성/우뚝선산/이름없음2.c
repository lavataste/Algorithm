#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main()
{
	int i;
	srand((int)time(NULL));
	printf("시작\n"); 
	for(i=0; i<50000; i++)
	{
		printf("%d ", rand()/10*rand()/100);
	}
	
	printf("\n%d개 끝", i);
	return 0;	
}

