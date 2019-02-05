/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>

int Answer;

int compare(const void * first, const void * second) 
{ 
    if (*(int*)first > *(int *)second) 
        return 1; 
    else if (*(int*)first < *(int *)second) 
        return -1; 
    else 
        return 0; 
} 

int main(void)
{
	int T, test_case;
	int N, K, count;
	int* score;
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
		scanf("%d %d", &N, &K);
		score=(int*)malloc(sizeof(int)*N);
		
		for(count=0;count<N;count++)
		{
			scanf("%d", score+count);
		}
		
		qsort(score, N, sizeof(int), compare);
		
		for(count=1;count<=K;count++)
		{
			Answer+=score[N-count];
		}
		
		
		
		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}
