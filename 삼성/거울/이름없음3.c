/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <stdio.h>
#include<malloc.h>

int Answer;
int x, y;
int direction;
char arr[1000][1000];
char arr_arr[1000][1000];
int index_arr_arr;
int N;

void reflect();


void proceed()
{
//	printf("%d %d %d\n", x, y, direction);
		
	if(arr[y][x]!='0')
	{
		reflect();
	}
	
	switch(direction)
	{
		case 1:
			x--;
			break;
		
		case 2:
			y++;
			break;
		
		case 3:
			x++;
			break;
			
		case 4:
			y--;
			break;	
	}
}

void reflect()
{
	if(!(x>=0 && x<N && y>=0 && y<N))
		return;
	
	if(arr[y][x]!=arr_arr[y][x])
	{
		arr_arr[y][x]=arr[y][x];
		index_arr_arr++;	
	}
	
	switch(direction)
	{
		case 1:
			
				if(arr[y][x]=='1')
					direction=2;
				else if(arr[y][x]=='2')
					direction=4;
			
			break;
		
		case 2:

				if(arr[y][x]=='1')
					direction=1;
				else if(arr[y][x]=='2')
					direction=3;
			
			break;
		
		case 3:

				if(arr[y][x]=='1')
					direction=4;
				else if(arr[y][x]=='2')
					direction=2;
			
			break;
			
		case 4:

				if(arr[y][x]=='1')
					direction=3;
				else if(arr[y][x]=='2')
					direction=1;
			
			break;	
	}
}



int main(void)
{
	int T, test_case;
	int count1, count2;
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
		index_arr_arr=0;
		x=y=0;
		direction=3;
		scanf("%d", &N);
		
		for(count1=0;count1<N;count1++)
			for(count2=0;count2<N;count2++)
				arr_arr[count1][count2]=0;
		
		for(count1=0;count1<N;count1++)
		{
			fflush(stdin);
			gets(arr[count1]);
		}
		
		while(x>=0 && x<N && y>=0 && y<N)
		{
			proceed();
		}
		
//		printf("%d %d\n", x, y);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
	
        // Print the answer to standard output(screen).
        
		printf("Case #%d\n", test_case+1);
        printf("%d\n", index_arr_arr);
        
	}

	return 0;//Your program should return 0 on normal termination.
}
