#include <string>
#include <vector>
#include<utility>
using namespace std;
vector<vector<int>> arr[101];

pair<int, int> judge(int location, int cycle, int time, int K, vector<vector<int>> &travel)
{
    int benefit;
    int temp_b=0, temp_t;
    int flag=0;
    int travel_time;
    int size=travel.size();
    vector<int> v;
    
    int temp=arr[location].size();
    if(temp)
    {
        for(int i=0; i<temp; i++)
        {
            if(arr[location][i][1]<=K-time && temp_b<arr[location][i][2])
            {
                temp_b=arr[location][i][2];
                temp_t=arr[location][i][1];
                
                if(arr[location][i][0]<time)
                    flag=1;  
                else
                    flag=0;
            }
        }
    }
    
    if(flag)
        return pair<int, int>(temp_b, temp_t);
    
    if(cycle)
    {
        benefit=travel[location][3];
        travel_time=travel[location][2];
    }
    else
    {
        benefit=travel[location][1];
        travel_time=travel[location][0];
    }
    
    if(time+travel_time>K)
        return pair<int, int>(0, 0);
    
    if(location==travel.size()-1)
        return pair<int, int>(benefit, travel_time);
 
    pair<int, int> f1, f2;
    f1=judge(location+1, 0, time+travel_time, K, travel);
    f2=judge(location+1, 1, time+travel_time, K, travel);
    
    if(f1.first<f2.first)
        f1=f2;
    else if(f1.first==f2.first)
    {
        if(f1.second>f2.second)
            f1=f2;
    }
    
    v.push_back(time);
    v.push_back(f1.second+travel_time);
    v.push_back(f1.first+benefit);
    arr[location].push_back(v);
    return pair<int, int>(f1.first+benefit, f1.second+travel_time);
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    pair<int, int> temp1, temp2;
    temp1=judge(0, 0, 0, K, travel);
    temp2=judge(0, 1, 0, K, travel);
    
    answer=max(temp1.first, temp2.first);
//    answer=max(judge(0, 0, 0, K, travel), judge(0, 1, 0, K, travel));
    return answer;
}
