#include <string>
#include <vector>
#include<utility>
using namespace std;
pair<int, int> arr[101][2][2];

pair<int, int> judge(int location, int cycle, int time, int K, vector<vector<int>> &travel, int memo)
{
    int benefit;
    pair<int, int> temp;
    
    if(arr[location][cycle][memo].first && arr[location][cycle][memo].second>K-time) 
        return arr[location][cycle][memo];
    
    if(cycle)
    {
        benefit=travel[location][3];
        time+=travel[location][2];
    }
    else
    {
        benefit=travel[location][1];
        time+=travel[location][0];
    }
    
    if(time>K)
    {
        arr[location][cycle][memo]=pair<int, int>(0, 0);
        return arr[location][cycle][memo];
    }
    
    if(location==travel.size()-1)
        return pair<int, int>(benefit, time);
    
    temp=max(judge(location+1, 0, time, K, travel, memo), judge(location+1, 1, time, K, travel, memo));
    temp.first+=benefit;
    arr[location][cycle][memo]=temp;
    return temp;
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    answer=max(judge(0, 0, 0, K, travel, 0), judge(0, 1, 0, K, travel, 1)).first;
    return answer;
}
