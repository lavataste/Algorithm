/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include<malloc.h>

int Answer;

int main(void)
{
	int T, test_case;
	int N, K, count, i;
	long *stone, temp;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	// freopen("input.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		Answer=0;
		scanf("%d", &N);
		stone=(long*)malloc(sizeof(long)*(N+1));
		stone[0]=0;
		for(count=0;count<N;count++)
			scanf("%lld", stone+count+1);
		
		scanf("%d", &K);
		
		count=0;
		while(1)
		{
		    if(count==N)
				break;
			i=1;
			if(stone[count+1]-stone[count]>K)
			{
				Answer=-1;
				break;
			}
			while(stone[count+i]-stone[count]<=K)
			{
				i++;
				if(count+i==N+1)
					break;
			}
			printf("%d -> %d\n", count, count+i-1);
			count+=(i-1);
			Answer++;

		}


		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        free(stone);
	}

	return 0;//Your program should return 0 on normal termination.
}
