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
        	if(arr[current]<=count)
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
    
    if(recursive(count+1, N, current*10+N, number))
        return 1;
    if(recursive(count+1, N, current*N, number))
        return 1;
    if(recursive(count+1, N, current/N, number))
        return 1;
    if(recursive(count+1, N, current+N, number))
        return 1;
    if(recursive(count+1, N, current-N, number))
        return 1;
}

int solution(int N, int number) {
    int answer = 0;
    
    recursive(1, N, N, number);
    
    if(arr[number]>=8)
        arr[number]=-1;
    return arr[number];
}



int main()
{
	solution(3, 5550);
//	printf("arr[%d] %d\n", current, arr[current]);
	
	return 0;
	
}
