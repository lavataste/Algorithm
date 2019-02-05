#include <string>
#include <vector>
#include<queue>
using namespace std;
priority_queue<int, vector<int>> q;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int size=scoville.size();
    int temp;
    
    for(int i=0; i<size; i++)
        q.push(scoville[i]);
    
    while(q.front()<K)
    {
        temp=q.front();
        q.pop();
        q.push(temp+q.front()*2);
        q.pop();
    }
    q.
    
    return answer;
}
