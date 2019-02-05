#include <string>
#include <vector>
#include<iostream>

using namespace std;

int fun(int garo, int sero, int brown, int red)
{
    int m, n;
    for(int i=2; i<sero; i++)
    {
        n=sero-i;
        m=red/n;
        if(m*n==red && m<garo-1)
        {
        	printf("m n %d %d\n", m, n);
            return 1;
        }
    }

    return 0;
}

int main() {
    vector<int> answer;
    int brown, red;
    
    scanf("%d %d", &brown, &red);
    int sum=brown+red;
    int temp;
    for(int i=3; i<sum/2; i++)
    {
        temp=sum/i;
        if(sum!=temp*i)
            continue;
        
        if(fun(temp, i, brown, red))
        {
            answer.push_back(temp);
            answer.push_back(i);
            break;
        }
    }
    
    printf("³¡\n"); 
    printf("%d %d\n", answer[0], answer[1]);
    
    return 0;
}
