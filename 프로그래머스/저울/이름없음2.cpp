#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int sig[10000000];
int index_a;
int index_s;

int add(int sum, int index, int n, vector<int> &weight)
{
//    printf("+%d", weight[index]);
    sum+=weight[index];

    if(sum==n)
        return 1;
    
    else if(sum>n)
        return 0;
        
    else if(sum+sig[index-1]<n)
    	return 0;
    
    for(int i=index-1; i>=0; i--)
    {
        if(add(sum, i, n, weight))
            return 1;
    }
    
//    printf("-%d", weight[index]);
    return 0;
}

int judge(int n, vector<int> &weight)
{
    int size=weight.size();
    int higher, lower;
    int temp=0;
    int i;

    for(; index_a<size; index_a++)
    {
        if(weight[index_a]==n)
            return 1;
        
        else if(weight[index_a]>n)
            break;
    }
    higher=index_a-1;
    
    for(; index_s<size; index_s++)
    {   	    	
    	if(sig[index_s]==n)
            return 1;
        
        else if(sig[index_s]>n)
            break;
            
       	sig[index_s+1]=sig[index_s]+weight[index_s+1];
    }
    lower=index_s;
    
    for(int j=higher; j>=lower; j--)
        if(add(0, j, n, weight))
            return 1;
    
    return 0;
}

int solution(vector<int> weight) {
    int answer = 0;
    sort(weight.begin(), weight.end());
    
    sig[0]=weight[0];
    while(1)
    {
        answer++;
        
        if(!judge(answer, weight))
            break;
    }

    return answer;
}
