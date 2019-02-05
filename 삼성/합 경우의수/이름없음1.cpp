#include<iostream>

using namespace std;
int main()
{
 	int T, N, K, count[20], count3, answer;
    int number[100];
    cin>>T;
    for(count=0;count<T;count++)
    {
        answer=0;
     	cin>>N>>K;
        for(count2=0;count2<N;count2++)
        {
         	cin>>number[count2];
        }
        
        for(count2=0;count2<N-1;count2++)
        {
            for(count3=count2;count3<N;count3++)
            {
                if(number[count2]+number[count3]==K)
                    answer++;
            }
        }
        
        cout<<"#"<<count+1<<" "<<answer<<endl;
    }
    
    return 0;
}
