/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>

int Answer;

unsigned long cal(int start, int end)
{
	unsigned long result=1;
	int count;
	for(count=start;count<=end;count++)
	{
		printf("%d\n", result)
		result*=count;
	}
	
	return result;
}


int main(void)
{
	int T, test_case;
	int i, j, N, M;
	unsigned long denominator, numerator, temp=0;
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
		scanf("%d %d", &N, &M);
		
		for(i=0;i<=N;i++)
		{
			for(j=0;j<=M;j++)
			{
				if(i>=j)
				{
					numerator=cal(i+1, i+j);
					denominator=cal(1, j);
				}
				else
				{
					numerator=cal(j+1, i+j);
					denominator=cal(1, i);
				}
				
				temp+=(numerator/denominator);
			}
		}
		
		Answer=temp%1000000007;

		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}
