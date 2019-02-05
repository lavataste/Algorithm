#include <string>
#include <vector>

using namespace std;
vector<string> answer;
int use[1000000];
void DFS(string current, vector<vector<string>> &tickets)
{
    printf("-> %s", current.c_str());
    int size=tickets.size();
    vector<string> v_s;
    vector<int> v_i;
    string temp_s="ZZZ";
    int temp_i=-1;
    for(int i=0; i<size; i++)
    {
        if(!use[i] && tickets[i][0]==current)
        {
            v_s.push_back(tickets[i][1]);
            v_i.push_back(i);
        }
    }
    size=v_i.size();
    
    for(int i=0; i<size; i++)
    {
        if(v_s[i]<temp_s)
        {
            temp_s=v_s[i];
            temp_i=v_i[i];
        }
    }
    
    if(temp_i!=-1)
    {
        answer.push_back(temp_s);
        use[temp_i]=1;
        DFS(temp_s, tickets);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    
    answer.push_back("ICN");
    DFS("ICN", tickets);
    return answer;
}

int main()
{
	vector<vector<string>> t;
	
	vector<string> v[5];
	v[0].push_back("ICN");
	v[0].push_back("SFO");
	v[1].push_back("ICN");
	v[1].push_back("ATL");
	v[2].push_back("SFO");
	v[2].push_back("ATL");
	v[3].push_back("ATL");
	v[3].push_back("ICN");
	v[4].push_back("ATL");
	v[4].push_back("SFO");
	
	for(int i=0; i<5; i++)
		t.push_back(v[i]);
	
	solution(t);
	
	return 0;
}
