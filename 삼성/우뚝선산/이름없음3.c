#include <stdio.h>
int main(void)
{
	int test_case;
	int T;
	int n, i, j;
	int prev, current;
	int low, high;
	int clime;
	int ttuk;
	int answer;

	/* �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� scanf �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
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
		prev=0;
		current=0;
		low=0;
		high=0;
		clime=1;
		scanf("%d", &n);
		scanf("%d", &current);
		for (i=1; i<n; i++)
		{
			prev=current;
			scanf("%d", &current);
			
			if(clime)
			{
				if(prev<current)
					low++;
				else
				{
					high++;
					if(i==n-1)
					{
						answer+=low;
						low=0;
						high=0;
					}
					else
						clime=0;
				}
					
			}
			
			else
			{
				
				if(prev>current)
				{
					high++;
					if(i==n-1)
					{	
						answer+=low*high;
						low=0;
						high=0;
					}
				}
					
				else
				{
					answer+=low*high;
					low=1;
					high=0;
					clime=1;
				}				
			}
		}
		
		
		printf("#%d %d\n", test_case, answer);

	}
	return 0; //��������� �ݵ�� 0�� �����ؾ� �մϴ�.
}
