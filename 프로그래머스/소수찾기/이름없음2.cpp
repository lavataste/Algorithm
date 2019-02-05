#include<stdlib.h>
#include <string>
#include<iostream>
#include <vector>
using namespace std;
char num[10];
char sel[10];
int arr[10000000];
int answer;

int prime(int number)
{
    if(arr[number])
        return 0;

	if(number==2)
	{
		arr[number]=1;
		return 1; 
	}

    if(number%2==0 || number==1)
        return 0;
    
    else
        arr[number]=1;
            
    
    for(int i=3; i<number/2; i=i+2)
    {
        if(number%i==0)
            return 0;
    }
    
    printf("%d prime number\n", number); 
    return 1;
}


void find(string numbers, int start, int length, int count, int size)
{
	int temp=start%length;

    if(count==1)
    {
    	for(int i=0; i<length; i++)
    	{
    		
			if(!sel[temp])
			{	
	    		num[size-count]=numbers[temp];
	    		num[size]=0;
	            cout<<num<<" È®ÀÎ"<<endl;
	            if(prime(atoi(num)))
	                answer++;
	    	}				
    		temp=(temp+1)%length;
    	}
    }
    
    else
    {
    	for(int i=0; i<length; i++)
    	{
    		
    		if(!sel[temp])
    		{
	    		num[size-count]=numbers[temp];
	    		sel[temp]=1;
	    		find(numbers, i+1, length, count-1, size);
	    		sel[temp]=0;
	    	}	    	 	
    		temp=(temp+1)%length;
    	}
    }
    
    return;
}

int solution(string numbers) {
	
    int length=numbers.length();
    
    for(int i=1; i<=length; i++)
        find(numbers, 0, length, i, i);
    
    return answer;
}

int main()
{
	printf("´ä %d", solution("1236542"));
	
	
	return 0;
}
