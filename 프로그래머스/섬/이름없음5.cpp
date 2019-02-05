#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int visit[101];
int answer;
vector<pair<int, int>> v[101];
vector<pair<int, int>> j;

int judge(int start, int end, int cost)
{
    if(v[start].size()==1)
        return 1;
    
    int size=v[end].size();
    
    for(int i=0; i<size; i++)
    {
        if(v[end][i].first<cost)
        {
            j.push_back(pair<int, int>(end, cost));
            return 0;
        }
    }
    return 1;
}

void DFS(int n)
{
	int size=v[n].size();
	
//    printf("%d\n", n);
	for(int i=0; i<size; i++)
	{
		if(!visit[v[n][i].second] && judge(n, v[n][i].second, v[n][i].first))
        {
            visit[v[n][i].second]=1;
            answer+=v[n][i].first;
//            printf("%d -> ", n);
            DFS(v[n][i].second);
        }
	}
}

int solution(int n, vector<vector<int>> costs) {
    int size=costs.size();
    int temp;
    vector<pair<int, int>> stack;
    
    for(int i=0; i<size; i++)
    {
        v[costs[i][0]].push_back(pair<int, int>(costs[i][2], costs[i][1]));
        v[costs[i][1]].push_back(pair<int, int>(costs[i][2], costs[i][0]));
    }
    
    for(int i=0; i<n; i++)
    	sort(v[i].begin(), v[i].end());
    
    visit[0]=1;
    DFS(0);
    
    while(!j.empty())
    {
        if(visit[j.front().first])
            j.erase(j.begin());
        
        else
        {
            answer+=j.front().second;
            visit[j.front().first]=1;
            DFS(j.front().first);
            j.erase(j.begin());
        }
    }
    
    return answer;
}
