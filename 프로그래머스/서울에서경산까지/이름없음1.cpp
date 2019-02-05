#include <string>
#include <vector>

using namespace std;
int arr[101][2];
int judge(int location, int cycle, int time, int K, vector<vector<int>> &travel)
{
    int benefit;
    int temp;
    
/*    if(arr[location][cycle])
        return arr[location][cycle];*/
    
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
    
    temp=benefit + max(judge(location+1, 0, time, K, travel), judge(location+1, 1, time, K, travel));
//    arr[location][cycle]=temp;
    return temp;
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    answer=max(judge(0, 0, 0, K, travel), judge(0, 1, 0, K, travel));
    return answer;
}
