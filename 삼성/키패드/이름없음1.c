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
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
