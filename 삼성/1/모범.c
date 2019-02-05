#include <stdio.h>
int main(void) {
	int T;
	int test_case;
   	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	   �� �Ʒ����� scanf �Լ��� ����Ͽ� ǥ�� �Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	   ���� ������ PC ���� �׽�Ʈ �� ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �˴ϴ�.
	   ��, �� �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�. */
	// freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	   ����� ������ ���� ǥ�� ��¿� ��ϵ��� �ʰ� ä���� ���� ���� �� �ֽ��ϴ�.
	   ���� ������ ���� �ݵ�� setbuf(stdout, NULL) �Լ��� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++) {
		//	�� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
        int N;
        int i;
        unsigned int result = 0;
        unsigned int input = 0;
        scanf("%d",&N);
        for(i=0;i<N;i++){
            scanf("%d",&input);
            result ^= input;
        }
        
        

		//	�� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case + 1);
        printf("%d\n",result);
	}

	return 0;	//	�������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}
