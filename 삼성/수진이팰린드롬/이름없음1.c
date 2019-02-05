#include <stdio.h>
#include<string.h>
void quickSort(char arr[], int left, int right)
{
	int i, j, pivot, temp;
	i=left;
	j=right;
	pivot=arr[(i+j)/2];
	
	do
	{
	
		while(arr[i]<pivot)
			i++;
		
		while(arr[j]>pivot)
			j--;
			
		if(i<=j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
		
	} while(i<=j);
	
	if(j>left)
		quickSort(arr, left, j);
	
	if(i<right)
		quickSort(arr, i, right);
	
	
}

int main(void)
{
	int test_case;
	int T;
	int i, length, count, answer;
	int fact[11]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	char input[10];
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	// freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%s", input);
		length=strlen(input);
		count=1;
		answer=0;
		quickSort(input, 0, length-1);
		
		
		for(i=1; i<=length; i++)
		{
			
			if(i==length)
			{
				answer+=(count*(count+1)/2);
				break;
			}
					
			if(input[i]!=input[i-1])
			{
				answer+=(count*(count+1)/2);
				count=1;
			}
			
			else if(input[i]==input[i-1])
				count++;
		}
		printf("#%d %d\n", test_case, answer);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
