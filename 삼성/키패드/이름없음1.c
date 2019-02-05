#include <stdio.h>
#include<string.h>
int main(void)
{
	int test_case;
	int T;
	char S[1000];
	char word[100000];
	int N;
	int i, j;
	int length;
	int answer;
	int keep;
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
		answer=0;
		scanf("%s", S);
		scanf("%d", &N);
		
		length=strlen(S);
		for(i=0; i<N; i++)
		{
			scanf("%s", word);
			keep=1;
			for(j=0; j<length && keep; j++)
			{
				switch(S[j])
				{
					case '2':
						if(!(word[j]=='a' || word[j]=='b' || word[j]=='c'))
							keep=0;
						break;
						
					case '3':
						if(!(word[j]=='d' || word[j]=='e' || word[j]=='f'))
							keep=0;
						break;
						
					case '4':
						if(!(word[j]=='g' || word[j]=='h' || word[j]=='i'))
							keep=0;
						break;
						
					case '5':
						if(!(word[j]=='j' || word[j]=='k' || word[j]=='l'))
							keep=0;
						break;
						
					case '6':
						if(!(word[j]=='m' || word[j]=='n' || word[j]=='o'))
							keep=0;
						break;
						
					case '7':
						if(!(word[j]=='p' || word[j]=='q' || word[j]=='r' || word[j]=='s'))
							keep=0;
						break;
						
					case '8':
						if(!(word[j]=='t' || word[j]=='u' || word[j]=='v'))
							keep=0;
						break;
						
					case '9':
						if(!(word[j]=='w' || word[j]=='x' || word[j]=='y' || word[j]=='z'))
							keep=0;
						break;
				}
			}
			
			if(j==length)
				answer++;
		}
		
		printf("#%d %d\n", test_case, answer);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
