#include <vector>
#include<utility>
#include<functional>
#include<algorithm>
#include<iostream>
using namespace std;
vector<pair<int, int>> d;

int judge(int stock, int index, vector<pair<int, int>> &d, int k)
{
    vector<pair<int, int>> v;
    int day=d[index].second;
    int i=index;
    int j=1;
    int size=d.size();
    int sum;
    int temp=size;
    
    printf("index %d로 judge 시작\n", index);
	 
    if((k-day)<stock)
        return size;
    
    while(1)
    {
        if(i==size)
            break;
        
        if((d[i].second-day)>stock)
            break;
        else
            v.push_back(pair<int, int>(d[i].first, i));
        
        i++;
    }
        
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    sum=v[0].first;
    
//    printf("sum %d stock %d d[i].second-day %d\n", sum, stock, d[i].second-day);
    if(i==size)
    	while(sum+stock<k-day)
		{
			
	        sum+=v[j].first;
	        j++;
	    }
    else
	    while(sum+stock<d[i].second-day)
	    {
//	    	printf("%d + %d\n", sum, v[j].first);
	        sum+=v[j].first;
	        j++;
	    }
    
    for(i=0; i<j; i++)
    	if(v[i].second<temp)
    		temp=v[i].second;
    
    return temp;
}

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int size=dates.size();
    int index_d=0;
    int temp;
    
    for(int i=0; i<size; i++)
        d.push_back(pair<int, int>(supplies[i], dates[i]));
    
    stock-=dates[0];
    for(int i=0; i<size; i++)
    {
        temp=i;
        i=judge(stock, i, d, k);
        if(i==size)
            break;
        
        printf("%d일 %d 수입\n\n", d[i].second, d[i].first); 
        stock+=d[i].first;
        answer++;
        
        if(i<size-1)
            stock-=(dates[i+1]-dates[temp]);
    }
    
    return answer;
}

int main()
{
	vector<int> dates;
	vector<int> supplies;
	
	
/*	dates.push_back(4);
	dates.push_back(5);
	dates.push_back(6);
	dates.push_back(9);
	dates.push_back(10);
	dates.push_back(25);
	
	supplies.push_back(3);
	supplies.push_back(2);
	supplies.push_back(5);
	supplies.push_back(10);
	supplies.push_back(5);
	supplies.push_back(5);
	
	printf("%d \n", solution(10, dates, supplies, 30));*/
	
	dates.push_back(10);
	dates.push_back(15);
	dates.push_back(25);
	dates.push_back(26);
	dates.push_back(27);
	dates.push_back(28);
	
	supplies.push_back(4);
	supplies.push_back(10);
	supplies.push_back(1);
	supplies.push_back(1);
	supplies.push_back(1);
	supplies.push_back(1);
	
	printf("%d \n", solution(15, dates, supplies, 28));
	return 0;
}
