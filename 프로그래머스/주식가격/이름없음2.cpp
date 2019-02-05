#include <string>
#include <vector>
#include<stack>
#include<utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int, int>> s;
    int arr[100001];
    int size=prices.size();
    int temp;
    
    s.push(pair<int, int>(prices[0], 0));
    
    for(int i=1; i<size; i++)
    {
        if(s.top().first<=prices[i])
            s.push(pair<int, int>(prices[i], i));
        
        else
        {
          while(s.empty() || s.top().first>prices[i])
          {
              answer.push_back(i-s.top().second);
              s.pop();
          }
        }
    }

    temp=s.size();
    for(int j=temp; j>0; j--)
        answer.push_back(j-1);
    
    return answer;
}


