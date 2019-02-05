#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int add(int sum, int index, int n, vector<int> &weight)
{
//    printf("+%d", weight[index]);

    sum+=weight[index];

    if(sum==n)
        return 1;
    
    else if(sum>n)
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
    for(i=0; i<size; i++)
    {
        if(weight[i]==n)
            return 1;
        
        else if(weight[i]>n)
        {
            break;
        }
    }
    higher=i-1;
    
    for(i=0; i<size; i++)
    {
        temp+=weight[i];
        if(temp==n)
            return 1;
        
        else if(temp>n)
            break;
    }
    lower=i-1;
    
    for(int j=higher; j>=lower; j--)
        if(add(0, j, n, weight))
            return 1;
    
    return 0;
}

int solution(vector<int> weight) {
    int answer = 0;
    sort(weight.begin(), weight.end());
    
    while(1)
    {
        answer++;
//        printf("%d ∞À¡ı\n", answer);
        if(!judge(answer, weight))
            break;
    }

    return answer;
}

int main()
{
	vector<int> v={3, 1, 6, 2, 7, 30, 1, 2, 1, 4, 5, 6, 7, 1, 2, 3, 4, 5, 1, 1, 1, 1, 2, 3, 4, 3, 2, 1, 1, 1, 2, 3, 1, 2, 3, 1, 3, 4, 2, 1, 3};	
	printf("%d ", solution(v));
	
	return 0;
}
