// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		int max = 0, result = 0;
		scanf("%d", &T);
		Num = (int*)malloc(sizeof(int) * T);
		for (i = 0; i < T; i++)
		{
			scanf("%d", &n);
			Num[i] = n;
 		}
		qsort(Num, T, sizeof(int), compare);
        /*마지막 일전을 남겨두 남은 점수를 순서대로 정열 해준다. 0~
        가만히 생각을 하면 내가 우승해야하기 때문에 최대한 높은 점수를 받아야 한다. 즉 , T 값(문제 상의 N)
        그러므로 직관적으로 나를 제외한 팀에게 적은 점수를 받은 팀에게 가장 높은 점수를, 가장 높은 점수를 받은 팀에게
        가장 낮은 점수를 주는게 최적의 방법이다. 이미 우리는 qsort를 통해 배열을 크기 순으로 정렬 했다.
        나를 포함 해 가장 낮은 점수부터 높은 점수까지 T 값을 감소 시키며 더 해준다. 이 과정에서 최대 값을 찾는다. 
        */
		for (i = 0; i < T; i++)
		{
			if (Num[i] + T - i >= max) max = Num[i] + T - i;
		}
		for (i = 0; i < T; i++)
		{
			if (Num[i] + T >= max) result++;
		}

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case , result);
		free(Num);

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}
