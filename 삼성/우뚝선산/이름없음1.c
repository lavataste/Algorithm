#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	int n, i, j;
	int ttuk;
	int answer;
	int key;
	long long int mountain[50000];
	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
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
		ttuk=0;
		scanf("%d", &n); 
		for (i=0; i<n; i++)
			scanf("%lld", &mountain[i]);
		
		for(i=0; i<n-2; i++)
		{
			key=1;
			if(mountain[i]<mountain[i+1])
			{
				if(mountain[i+1]>mountain[i+2])
				{
					ttuk=i+1;
					key=0;
					if(i+2==n-1)
					{
						answer=1;
						continue;	
					}
				}
				
				else if(mountain[i+1]==mountain[i+2])
					continue;
					
			}
			
			else
				continue;
			
			for(j=i+2; j<n-1; j++)
			{
				if(key)
				{
					if(mountain[j]>mountain[j+1])
					{
						ttuk=j;
						key=0;
					}
					
					else if(mountain[j]==mountain[j+1])
						break;
				}
				
				else
				{
					answer++;
					if(mountain[j]<=mountain[j+1])
					{
						break;
					}
				}	
			}
		}
		printf("#%d %d\n", test_case, answer);

	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
