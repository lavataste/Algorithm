#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int T, N, temp, count1, count2, count3, index;
	int **number1, **number2, *XOR;
	setbuf(stdout, NULL);
	scanf("%d", &T);
	number1=malloc(sizeof(int*)*T);
	number2=malloc(sizeof(int*)*T);
	XOR=malloc(sizeof(int)*T);
	memset(XOR, 0, sizeof(int)*T);
	for(count1=0;count1<T;count1++)
	{
		scanf("%d", &N);
		*(number1+count1)=malloc(sizeof(int)*N);
		memset(*(number1+count1), 0, sizeof(int)*N);
		*(number2+count1)=malloc(sizeof(int)*N);
		memset(*(number2+count1), 0, sizeof(int)*N);
		for(count2=0;count2<N;count2++)
		{
			scanf("%d", &temp);
			for(count3=0;count3<N;count3++)
			{
				if(number1[count1][count3]==temp)
				{
					number2[count1][count3]++;
					break;
				}
				else if(number1[count1][count3]==0)
				{
					number1[count1][count3]=temp;
					number2[count1][count3]++;
					break;
				}
			}
		}
	}
	for(count1=0;count1<T;count1++)
	{
		for(count2=0;count2<N;count2++)
		{
			if(number2[count1][count2]%2==1)
			{
/*				printf("number1[%d]=%d\n", count2, number1[count2]);
				printf("%d XOR %d\n", XOR, number1[count2]);*/
				XOR[count1]=XOR[count1]^number1[count1][count2];
			}
			else if(number2[count1][count2]==0)
			{
				break;
			}
		}
		printf("Case #%d\n", count1+1);
		printf("%d\n", XOR[count1]);
	}
	
	free(XOR);
	for(count1=0;count1<T;count1++)
	{
		free(*(number1+count1));
		free(*(number2+count1));
	}
	free(number1);
	free(number2);
	
	return 0;
}
