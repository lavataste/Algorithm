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
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	// freopen("input.txt", "r", stdin);
	/* �Ʒ� �ڵ带 �������� ������ �������� ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	����� ������ ���� ǥ�� ��¿� ��ϵ��� ���� �� �ֽ��ϴ�.
	���� ������ ���� �ݵ�� setbuf(stdout, NULL); �� �����Ͻñ� �ٶ��ϴ�.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	���� ���� �׽�Ʈ ���̽��� ó���ϱ� ���� �κ��Դϴ�.
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
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
