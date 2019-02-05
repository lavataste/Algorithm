#include <string>
#include <vector>
#include<algorithm>
#include<utility>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size=rocks.size();
    int temp;
    vector<pair<int, int>> d;
    vector<pair<int, int>> d2;
    sort(rocks.begin(), rocks.end());
    
    d.push_back(pair<int, int>(rocks[0], 0));
    for(int i=1; i<size; i++)
        d.push_back(pair<int, int>(rocks[i]-rocks[i-1], i));
    
    d.push_back(pair<int, int>(distance-rocks[size-1], size-1));
    d2=d;
    sort(d.begin(), d.end());
    
    for(int i=0; i<n; i++)
    {
        temp=d[0].second;
        d2[temp].first+=d2[temp+1].first;
        d2.erase(d2.begin()+temp+1);
        d[0]=d2[temp];
        sort(d.begin(), d.end());
    }
    answer=d[0].first;
    return answer;
}
