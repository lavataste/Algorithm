#include <string>
#include <vector>
using namespace std;
int bound;
int sum_benefit[101];
int sum_time[101];
int judge(int location, int cycle, int money, int time, int K, vector<vector<int>> &travel)
{
    int benefit;
    int temp=0;
    int size=travel.size();
    
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
    
    if(time+sum_time[location]>K)
        return 0;
    
    if(location==size-1)
        return benefit;
    
    money+=benefit;
    if(bound>=sum_benefit[location]+money)
        return 0;
        
    temp=benefit + max(judge(location+1, 0, money, time, K, travel), judge(location+1, 1, money, time, K, travel));
    bound=max(bound, temp);
    return temp;
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    int size=travel.size();
    int temp_benefit=0;
    int temp_time=0;
    int temp=0;
    for(int i=0; i<size; i++)
    {
        temp_benefit+=travel[i][1];
        temp_time+=travel[i][2];
    }
    for(int i=0; i<size; i++)
    {
        temp_benefit-=travel[i][1];
        sum_benefit[i]=temp_benefit;
        temp_time-=travel[i][2];
        sum_time[i]=temp_time;
    }

    answer=max(judge(0, 0, 0, 0, K, travel), judge(0, 1, 0, 0, K, travel));
    return answer;
}