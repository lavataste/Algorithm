#include <string>
#include <vector>

using namespace std;
int arr[1000001];
int swit[1000001];
int solution(vector<int> money) {
    int answer = 0;
    int size=money.size();
    arr[0]=money[0];
    arr[1]=money[1];
    arr[2]=arr[0]+money[2];
    swit[0]=1;
    swit[2]=1;
    
    for(int i=3; i<size-1; i++)
    {
        if(arr[i-3]>arr[i-2])
        {
            arr[i]=arr[i-3]+money[i];
            swit[i]=swit[i-3];
        }
        else if(arr[i-3]<arr[i-2])
        {
            arr[i]=arr[i-2]+money[i];
            swit[i]=swit[i-2];
        }
        else
        {
            arr[i]=arr[i-3]+money[i];
            if(swit[i-3] && swit[i-2])
                swit[i]=1;
        }
    }
    
    if(arr[size-2]<=arr[size-3])
    {
        answer=arr[size-3];
        if(!swit[size-3])
            answer+=money[size-1];
        
        else
        {
            if(money[0]<money[size-1])
            {
                answer+=money[size-1];
                answer-=money[0];
            }
            //문제, 나머지
        }
        
    }
    else
    {
        if(!swit[size-3] && arr[size-3]+money[size-1]>arr[size-2])
        {
            answer=arr[size-3]+money[size-1];
            //문제, 효율성 5번
        }
        
        else if(swit[size-3] && arr[size-3]+money[size-1]-money[0]>arr[size-2])
            answer=arr[size-3]+money[size-1]-money[0];
        
        else
            answer=arr[size-2];
    }
    return answer;
}
