/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/
#include <stdio.h>
#include<malloc.h>
#include<string.h>

unsigned long long Answer;
int puzzle[100000][100000];
int x, y;

void Next(int order, int N)
{
	if((x+y)%2==1)
	{
		if(x==0 && y!=N-1)
		{
			y++;
		}
		else if(y==N-1)
		{
			x++;
		}
		else
		{
			x--;
			y++;
		}
	}
	
	else
	{
		if(y==0 && x!=N-1)
		{
			x++;
		}
		else if(x==N-1)
		{
			y++;
		}
		else
		{
			x++;
			y--;
		}
	}
//	printf("puzzle[%d][%d]=%d\n", y, x, order);
	puzzle[y][x]=order;
}


int main(void)
{
	int T, test_case;
	int N, K, count, count2;
	char *move;
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
		Answer=1;
		scanf("%d %d", &N, &K);
		move=(char*)malloc(sizeof(char)*(K+1));
		x=0;
		y=0;
		puzzle[0][0]=1;
		
		for(count=2;count<=N*N;count++)
		{
			Next(count, N);
		}
		
//		fflush(stdin);
		scanf("%s", move);
		x=0;
		y=0;
		for(count=0;count<K;count++)
		{
			if(move[count]=='U')
			{
				y--;
			}
			else if(move[count]=='D')
			{
				y++;
			}
			else if(move[count]=='L')
			{
				x--;
			}
			else if(move[count]=='R')
			{
				x++;
			}
			Answer+=puzzle[y][x];
		}
		
/*		for(count=0;count<N;count++)
		{
			for(count2=0;count2<N;count2++)
			{
				printf("%d  ", puzzle[count][count2]);
			}
			printf("\n");
		}*/
		
		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%lld\n", Answer);
        

		free(move);
	}

	return 0;//Your program should return 0 on normal termination.
}
