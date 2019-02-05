#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int size=budgets.size();
    int sum=0;
    
    sort(budgets.begin(), budgets.end());
    for(int i=0; i<size; i++)
        sum+=budgets[i];
    if(sum<=M)
        return budgets[size-1];
    
    while(budgets[0]<=M/size)
    {
        M-=budgets[0];
        budgets.erase(budgets.begin());
        size--;
    }
    answer=M/size;
    return answer;
}
