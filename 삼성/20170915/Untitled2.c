// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <stdio.h>
#include <stdlib.h>

int *Num;

int static compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int main(void) {

	int TC, T, i, n; //TC = test case , T = team number
	int test_case;
	int R = 0;
	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		int max = 0, result = 0;
		scanf("%d", &T);
		Num = (int*)malloc(sizeof(int) * T);
		for (i = 0; i < T; i++)
		{
			scanf("%d", &n);
			Num[i] = n;
 		}
		qsort(Num, T, sizeof(int), compare);
        /*������ ������ ���ܵ� ���� ������ ������� ���� ���ش�. 0~
        ������ ������ �ϸ� ���� ����ؾ��ϱ� ������ �ִ��� ���� ������ �޾ƾ� �Ѵ�. �� , T ��(���� ���� N)
        �׷��Ƿ� ���������� ���� ������ ������ ���� ������ ���� ������ ���� ���� ������, ���� ���� ������ ���� ������
        ���� ���� ������ �ִ°� ������ ����̴�. �̹� �츮�� qsort�� ���� �迭�� ũ�� ������ ���� �ߴ�.
        ���� ���� �� ���� ���� �������� ���� �������� T ���� ���� ��Ű�� �� ���ش�. �� �������� �ִ� ���� ã�´�. 
        */
		for (i = 0; i < T; i++)
		{
			if (Num[i] + T - i >= max) max = Num[i] + T - i;
		}
		for (i = 0; i < T; i++)
		{
			if (Num[i] + T >= max) result++;
		}

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case , result);
		free(Num);

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
