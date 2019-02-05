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
	
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("sample_input.txt", "r", stdin);
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
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
