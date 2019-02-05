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
            j.push_back(pair<int, int>(cost, end));
            return 0;
        }
    }
    return 1;
}

void DFS(int n)
{
	int size=v[n].size();
	
    printf("%d\n", n);
	for(int i=0; i<size; i++)
	{
		if(!visit[v[n][i].second] && judge(n, v[n][i].second, v[n][i].first))
        {
            visit[v[n][i].second]=1;
            answer+=v[n][i].first;
            printf("%d -> ", n);
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
    	sort(j.begin(), j.end());
        if(visit[j.front().second])
            j.erase(j.begin());
        
        else
        {
        	temp=j.front().first;
        	for(int i=1; i<j.size(); i++)
        	{
        		if((j.front().second==j[i].second) && (j[i].first<temp))
        			temp=j[i].first;	
        	}
        	
            answer+=temp;
            visit[j.front().second]=1;
            DFS(j.front().second);
            j.erase(j.begin());
        }
    }
    
    return answer;
}

int main()
{
	int a[100][3]={{0, 1, 1}, {0, 5, 20}, {1, 2, 1}, {1, 3, 30}, {3, 4, 1}, {3, 5, 1}};
//15	int a[100][3]={{0, 1, 1}, {0, 2, 6}, {0, 3, 4}, {1, 2, 2}, {1, 5, 30}, {2, 3, 100}, {2, 4, 23}, {4, 5, 35}, {4, 6, 1}, {5, 6, 555}, {5, 8, 1}, {1, 4, 10}, {3, 6, 1}, {5, 7, 100}, {1, 7, 10}};
	vector<vector<int>> v;
	
	for(int i=0; i<6; i++)
	{
		vector<int> b;
		b.push_back(a[i][0]);
		b.push_back(a[i][1]);
		b.push_back(a[i][2]);
		v.push_back(b);	
	}
	
	printf("%d ", solution(6, v));
	
	return 0;	
	
}
