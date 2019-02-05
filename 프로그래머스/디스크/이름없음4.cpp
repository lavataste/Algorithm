#include <string>
#include <vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int size=jobs.size();
    int endtime;
    int index=0;
    int sum=0;
    int temp;
    int time=0;
    vector<pair<int, int>> v;
    priority_queue<int> q;
    
    for(int i=0; i<size; i++)
        v.push_back(pair<int, int>(jobs[i][0], jobs[i][1]));
    sort(v.begin(), v.end());
    
    while(!(index==size && q.empty()))
    {
        while(index<size && v[index].first==time)
        {
            q.push(-1*v[index].second);
            index++;
        }
        
        if(!q.empty())
        {
            temp=q.top();
            q.pop();
            if(temp+1)
                q.push(temp+1); 
            else
                sum++;
        }
        
        sum+=q.size();
        time++;
    }
//    printf("sum %d\n", sum);
    answer=sum/size;
    return answer;
}
