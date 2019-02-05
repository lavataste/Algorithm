#include <string>
#include <vector>
#include<utility>
#include<functional>
#include<algorithm>
using namespace std;
vector<pair<int, int>> d;
vector<pair<int, int>> s;

int judge(int stock, int index, vector<pair<int, int>> d, int k)
{
    int day=d[index].second;
    int i=index+1;
    int temp=index;
    int size=d.size();
    
    if(k-day<stock)
        return 0;
    
    while(1)
    {
        if(i==size)
            break;
        if((d[i].second-day)>stock)
            break;
        else
            if(d[i].first>d[index].first)
                temp=i;
        i++;
    }

    return temp;
    
/*    if(temp==index)
    {
        printf("%d일 수입\n", day);
        return 1;
    }
    else
    {
        printf("%d일 수입 안 함\n", day);
        return 0;
    }*/
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int size=dates.size();
    int index_d=0;
    
    for(int i=0; i<size; i++)
        d.push_back(pair<int, int>(supplies[i], dates[i]));
    
    stock-=dates[0];
    for(int i=0; i<size; i++)
    {
        if(d[index_d].second==dates[i])
        {
            if(judge(stock, index_d, d, k))
            {
                stock+=d[index_d].first;
                answer++;
            }
            index_d++;
            if(index_d==size)
                break;
        }
        if(i<size-1)
            stock-=(dates[i+1]-dates[i]);
    }
    
    return answer;
}
