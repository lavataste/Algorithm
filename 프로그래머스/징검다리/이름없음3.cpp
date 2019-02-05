#include <string>
#include <vector>
#include<algorithm>
#include<utility>
#include<iostream>

using namespace std;

int judge(int index, vector<pair<int, int>> &v)
{
    int size=v.size();
    int i++;
    if(index==0)
        return 1;
    else if(index==size-1);
        return -1;
    
    while(1)
    {
        if(v[index+i].first>v[index-i].first)
            return -1;
        else if(v[index+i].first>v[index-i].first)
    }
    
}

int find_min(vector<pair<int, int>> &v)
{
    int temp=1000000001;
    int temp2, temp3;
    int index;
    int size=v.size();
    for(int i=0; i<size; i++)
        if(temp>v[i].first)
        {
            temp=v[i].first;
            index=i;
            if(i==0)
                temp2=v[1].first;
            else if(i==size-1)
                temp2=v[size-2].first;
            else
                temp2=min(v[i-1].first, v[i+1].first);
        }
        else if(temp==v[i].first)
        {
            if(i==0)
                temp3=v[1].first;
            else if(i==size-1)
                temp3=v[size-2].first;
            else
                temp3=min(v[i-1].first, v[i+1].first);

            if(temp2>temp3)
            {
                temp=v[i].first;
                index=i;
                temp2=temp3;
            }
        }
        
    return index;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size=rocks.size();
    int temp;
    int index;
    vector<pair<int, int>> d;

    sort(rocks.begin(), rocks.end());    
    d.push_back(pair<int, int>(rocks[0], 0));
    for(int i=1; i<size; i++)
        d.push_back(pair<int, int>(rocks[i]-rocks[i-1], i));
    d.push_back(pair<int, int>(distance-rocks[size-1], size-1)); 
    
    for(int i=0; i<n; i++)
    {
        size=d.size();
        temp=find_min(d);
        if(temp>0 && temp<size-1)
        {
            if(d[temp+1].first>d[temp-1].first)
                index=-1;
            else if(d[temp+1].first<d[temp-1].first)
                index=1;
            else
            {
                if(d[temp+2].first>=d[temp-2].first)
                    index=-1;
                else if(d[temp+2].first>d[temp-2].first)
                    index=1;
            }
        }
        else if(temp==0)
            index=1;
        else if(temp==size-1)
            index=-1;
        
        d[temp].first+=d[temp+index].first;
        d.erase(d.begin()+temp+index);
    }
    answer=d[find_min(d)].first;
    return answer;
}
