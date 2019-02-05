#include <string>
#include <vector>
#include<iostream>
#include<utility>
using namespace std;
vector<int> visit[100000];
vector<pair<pair<int, int>, pair<int, int>>> v;
int x=50000, y=50000;
int flag;

int find()
{
    int size=visit[x].size();
    for(int i=0; i<size; i++)
        if(visit[x][i]==y)
            return 1;
    visit[x].push_back(y);
    return 0;
}

int find_vertex(int temp_x, int temp_y)
{
    int size=v.size();
    for(int i=0; i<size; i++)
    {
        if(v[i].first.first==temp_x && v[i].first.second==temp_y && v[i].second.first==x && v[i].second.second==y)
            return 1;
        else if(v[i].second.first==temp_x && v[i].second.second==temp_y && v[i].first.first==x && v[i].first.second==y)
            return 1;
    }
    return 0;
}

void move(int command)
{
    switch(command)
    {
        case 0:
            y++;
            break;
        case 1:
            x++;
            y++;
            break;
        case 2:
            x++;
            break;
        case 3:
            x++;
            y--;
            break;
        case 4:
            y--;
            break;
        case 5:
            x--;
            y--;
            break;
        case 6:
            x--;
            break;
        case 7:
            x--;
            y++;
            break;
    }
}
int solution(vector<int> arrows) {
    int answer = 0;
    int size=arrows.size();
    int temp_x=x, temp_y=y;
    visit[x].push_back(y);
    for(int i=0; i<size; i++)
    {
        move(arrows[i]);
        if(find())
        {
            if(!find_vertex(temp_x, temp_y))
                answer++;
        }
        v.push_back(pair<pair<int, int>, pair<int, int>>(pair<int, int>(temp_x, temp_y), pair<int, int>(x, y)));
        temp_x=x;
        temp_y=y;
    }
    
    return answer;
}
