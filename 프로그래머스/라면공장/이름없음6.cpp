#include <vector>
#include<utility>
#include<functional>
#include<algorithm>
#include<iostream>
using namespace std;
vector<pair<int, int>> d;
vector<pair<int, int>> s;
vector<pair<int, int>> n;

int findlist(pair<int, int> list)
{
    int size=s.size();
    for(int i=0; i<size; i++)
        if(list==s[i])
            return 1;
    
    return 0;
}

int judge(int stock, int index, int size, int k)
{   
    int i=index;
    int day=d[i].second;
    int temp_i=index;
    int temp_d;
    
    printf("index %d로 judge 시작\n", index);
    
    if((k-day)<stock)
        return size;
    
    while(1)
    {
        if(i==size)
            return i;
        
        if((d[i].second-day)>stock)
        {
        	printf("못 찾았으니 이거 쓰장\n"); 
            n.push_back(d[temp_i]);
            return temp_i;
        }
        
        if(findlist(d[i]))
        {
        	printf("%d 찾았땅\n", i); 
            return i;
        }
            
        else
        {
        	if(temp_d<d[i].second)
        	{
        		temp_d=d[i].second;
        		temp_i=i;
        	}		
        }
        
        i++;
    }
    
    printf("비정상 종료\n");
    return 0;
}
    
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int size=dates.size();
    int index=0;
    int sum=0;
    int temp;
    
    for(int i=0; i<size; i++)
    {
        if(k-dates[i]<supplies[i])
            supplies[i]=k-dates[i];
        
        d.push_back(pair<int, int>(supplies[i], dates[i]));
        s.push_back(pair<int, int>(supplies[i], dates[i]));
    }
    sort(s.begin(), s.end());
    
 //   printf("1\n");
    
    for(index=0; sum+stock<k; index++)
        sum+=s[size-index-1].first;
    
    for(int i=0; i<size-index; i++)
        s.erase(s.begin());
    
 //   printf("2.5\n");
    stock-=dates[0];
    for(int i=0; i<size; i++)
    {
    	temp=i;
        i=judge(stock, i, size, k);
        if(i==size)
        	break;
        
        stock+=d[i].first;
        printf("%d일 %d 수입\n\n", d[i].second, d[i].first); 
        stock-=(dates[i]-dates[temp]);
    }
    
//    printf("3\n");
    int sizen=n.size();
	printf("예상외 수입 %d\n", sizen); 
    for(int i=0; i<sizen; i++)
        sum+=n[i].first;
    
//    printf("4\n");
    for(int i=0; sum<=0; i++)
    {
//    	printf("%d번째 제거\n", i); 
        sum-=s[i].first;
        s.erase(s.begin());
    }
    
    answer=s.size();
    return answer;
}


