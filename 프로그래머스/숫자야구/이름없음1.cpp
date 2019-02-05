#include<stdlib.h>
#include<string.h>
#include <string>
#include <vector>
#include<iostream> 

using namespace std;

void itoa(char input[], int number)
{
	char str[4];
	str[0]=number/100+'0';
	str[1]=(number-(number/100)*100)/10 + '0';
	str[2]=number-(number/100)*100-((number-(number/100)*100)/10)*10 + '0';
	str[3]=0;
	
	strcpy(input, str);
}

int judge(int obj, vector<int> result)
{
	int strike=0, ball=0;
	char obj_c[4];
	char input[4];
	
	itoa(obj_c, obj);
	itoa(input, result[0]);
	
	printf("%s %s °Ë»ç\n", obj_c, input); 
	
	for(int i=0; i<3; i++)
	{
		if(obj_c[i]==input[i])
			strike++;
	}
	
	printf("strike %d %d\n", strike, result[1]);
	
	if(strike!=result[1])
		return 0;
		
	for(int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if(i==j)
				continue;
		
			if(obj_c[i]==input[j])
				ball++;
		}
	}
		
	printf("ball %d %d\n", ball, result[2]);

	if(ball!=result[2])
		return 0;
		
	return 1;
}


int find(int obj, vector<vector<int> > baseball)
{
    int size=baseball.size();
    
    for(int i=0; i<size; i++)
    {
    	if(!judge(obj, baseball[i]))
			return 0;	
    
    }
    
    return 1;
}


int solution(vector<vector<int> > baseball) {
    int answer = 0;
    char str[4];
    for(int i=123; i<=987; i++)
    {
    	itoa(str, i);
    	if(str[0]==str[1] || str[1]==str[2] || str[2]==str[0] )
    		continue;
    		
    	if(str[0]=='0' || str[1]=='0' || str[2]=='0')
    		continue;
    	
    	else
    	{
    		if(find(i, baseball))
				answer++;
    	}
    }
    
    return answer;
}

