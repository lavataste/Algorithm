#include <string>
#include <vector>
using namespace std;
int arr[1000001];

int recursive(int count, int N, int current, int number)
{
    if(current>=32000 || current<=0)
        return 0;
    else
    {
        if(arr[current])
        {
        	if(arr[current]<=count && current!=N)
        		return 0;
        	else
	            arr[current]=count;
        }
        else
            arr[current]=count;
    }
    
    
	printf("arr[%d] %d\n", current, arr[current]);
    if(current==number)
    	return 1;
    
    recursive(count+1, N, current*N, number);
    recursive(count+1, N, current/N, number);
    recursive(count+1, N, current+N, number);
    recursive(count+1, N, current-N, number);

}

int solution(int N, int number) {
    int answer = 2147483647;
    int ten=N;
    
    arr[N]=1;
    for(int i=0; i<4; i++)
    {
    	ten=ten*10+N;
    	recursive(arr[ten/10]+1, ten, N, number);
    }
    
    
    recursive(1, N, N, number);
    
    if(!arr[number])
    {
    	for(int i=1; i<number; i++)
		{
			if(arr[number-i] && arr[i])
				answer=min(answer, arr[number-i]+arr[i]);
		}
    }
    
    
    if(arr[number]>=8)
        answer=-1;
    return answer;
}



int main()
{
	solution(3, 5550);
//	printf("arr[%d] %d\n", current, arr[current]);
	
	return 0;
	
}
