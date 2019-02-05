#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

int length, a, b, a_c, b_c;
char s[100001], t[100001], c[100001];
queue<int> q1, q2;

int main(int argc, char** argv)
{
	int test_case;
	int T, i, j;
	long long int answer, temp;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		answer=0;
		scanf("%s", s);
		scanf("%s", t);
		
		length=strlen(s);
		for(i=0; i<length; i++)
		{
			if(s[i]==t[i])
				c[i]=0;
				
			else
			{
				if(t[i]=='a')
					c[i]=1;
					
				else
					c[i]=2;
			}
		}
		
		for(i=0; i<length && answer!=-1 ; i++)
		{
			if(c[i]==1)
				q1.push(i);
		
			else if(c[i]==2)
				q2.push(i);
			/*
			if(c[i]==1)
			{
				for(j=i; j<length; j++)
				{
					if(c[j]==2)
					{
						answer+=j-i;
						c[i]=0;
						c[j]=0;
						break;
					}
				}
				if(j==length-1)
					answer=-1;
			}
			
			else if(c[i]==2)		
			{
				for(j=i; j<length; j++)
				{
					if(c[j]==1)
					{
						answer+=j-i;
						c[i]=0;
						c[j]=0;
						break;
					}
				}
				if(j==length-1)
					answer=-1;
			}*/
		}
		
		while(!(q1.empty() || q2.empty()))
		{
			temp=(q1.front()-q2.front());
			if(temp<0)
				temp*=-1;
				
			answer+=temp;
			q1.pop();
			q2.pop();
		}
		
		if(!(q1.empty() && q2.empty()))
			answer=-1;

		printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
