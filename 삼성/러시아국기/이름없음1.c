#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	int N, M;
	int i, j, k;
	int temp;
	int answer;
	char gukgi[50][50];
	char current;
	int W[50], B[50], R[50];
	
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("sample_input.txt", "r", stdin);
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
		answer=0;
		scanf("%d %d", &N, &M);
		
		for(i=0; i<N; i++)
		{
			W[i]=0;
			B[i]=0;
			R[i]=0;	
		}
		
		for(i=0; i<N; i++)
		{
			scanf("%s", gukgi[i]);
			
			
			for(j=0; j<M; j++)
			{
				current=gukgi[i][j];
				switch(current)
				{
					case 'W': 
							B[i]++;
							R[i]++;
							break;
							
					case 'B':
							W[i]++;
							R[i]++;
							break;
						
					case 'R':
							W[i]++;
							B[i]++;
							break;
				}
			}
		}
		

		
		for(i=1; i<N-1; i++)
		{
			
			for(j=i+1; j<N; j++)
			{
				temp=0;
				
				for(k=0; k<i; k++)
					temp+=W[k];
				
				for(k=i; k<j; k++)
					temp+=B[k];
					
				for(k=j; k<N; k++)
					temp+=R[k];
					
				if(temp<answer || !answer)
					answer=temp;
			}
		}
		
		printf("#%d %d\n", test_case, answer);

		printf("%d %d \n\n", N, M);

	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
