#include <string>
#include <vector>
#include<iostream>

using namespace std;

int judge(vector<int> priorities)
{
    int size=priorities.size();
    int temp=priorities[0];
    
    cout<<priorities[0]<<" 확인"<<endl;
    for(int i=1; i<size; i++)
    {
        if(temp<priorities[i])
        {
        	printf("%d가 %d보다 작음\n", temp, priorities[i]); 
            return 0;
        }
    }
    
    return 1;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int size=priorities.size();
    int temp=0;
    
    
    while(1)
    {
        if(judge(priorities))
        {
            if(location==0)
            {
                answer++;
                break;
            }
            
            priorities.erase(priorities.begin());
            answer++;
            size--;
            location--;
        }
        
        else
        {
            priorities.push_back(priorities[0]);
            priorities.erase(priorities.begin());
            location--;
        }
        
        if(location<0)
            location=size-1;
    }
    
    return answer;
}

int main()
{
	vector<int> v1={2, 1, 3, 2};
	vector<int> v2={1, 1, 9, 1, 1, 1};
	
	cout<<solution(v1, 2)<<endl;
	cout<<solution(v2, 0)<<endl;

	return 0;
}
