#include <string>
#include <vector>
#include<algorithm>
using namespace std;
pair<int, int> arr[101][2];
vector<pair<float, float>> efficiency;
vector<pair<float, float>> efficiency2;

int judge(int location, int cycle, int time, int K, vector<vector<int>> &travel)
{
    int benefit;
    int temp;
    int flag1=0, flag2=0;
    int size=travel.size();
    
//  if(arr[location][memo].first<=time && arr[location][memo].second>=money)
//      return 0;
    
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
        return 0;
    
    if(location==travel.size()-1)
        return benefit;
    
    for(int i=0; i<size && !(flag1 && flag2); i++)
    {
        if(efficiency[i].second==location)
        {
            if(i>=size/70)
                flag1=1;
        }
        
        if(efficiency2[i].second==location)
        {
            if(i>=size/70)
                flag2=1;
        }
    }
    if(flag1)
        flag1=judge(location+1, 0, time, K, travel);
    
    if(flag2)
        flag2=judge(location+1, 1, time, K, travel);
    
    temp=benefit+ max(flag1, flag2);    
//    temp=benefit + max(judge(location+1, 0, time, K, travel), judge(location+1, 1, time, K, travel));
    return temp;
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    int size=travel.size();
    for(int i=0; i<size; i++)
    {
        efficiency.push_back(pair<float, float>(travel[i][1]/travel[i][0], i));
        efficiency2.push_back(pair<float, float>(travel[i][3]/travel[i][2], i));
    }
    sort(efficiency.begin(), efficiency.end());
    sort(efficiency2.begin(), efficiency2.end());
    
    answer=max(judge(0, 0, 0, K, travel), judge(0, 1, 0, K, travel));
    return answer;
}
