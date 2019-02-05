#include <string>
#include <vector>
#include<utility>
#include<map>
using namespace std;
vector<pair<string, string>> db;
vector<pair<int, int>> log;
map<string, int> m;
int find(string &uid)
{
    int size=db.size();
    for(int i=0; i<size; i++)
    {
        if(db[i].first==uid)
            return i;
    }
    return -1;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string command, uid, nickname;
    int size=record.size();
    int index, act, temp;
    for(int i=0; i<size; i++)
    {
        if(record[i][0]=='E')
            act=1;
        else if(record[i][0]=='L')
            act=2;
        else
            act=0;
    
        uid="";
        nickname="";
        
        if(act)
            temp=6;
        else
            temp=7;
        
        while(record[i][temp]!=' ' && temp<record[i].size())
        {
            uid+=record[i][temp];
            temp++;
        }
        temp++;
        
        while(temp<record[i].size())
        {
            nickname+=record[i][temp];
            temp++;
        }
        
        index=find(uid);
        if(index==-1)
        {
            index=db.size();
            db.push_back(pair<string, string>(uid, nickname));
            map.insert(pair<string, int>(uid, index));
            log.push_back(pair<int, int>(index, act));
        }
        
        else
        {
            if(act==1)
            {
                db[index].second=nickname;
                log.push_back(pair<int, int>(index, act));
            }
            else if(act==2)
                log.push_back(pair<int, int>(index, act));
            else
                db[index].second=nickname;
        }
    }
    
    size=log.size();
    string s_t="";
    for(int i=0; i<size; i++)
    {
        s_t="";
        s_t+=db[log[i].first].second;
        
        if(log[i].second==1)
            s_t+="´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        else
            s_t+="´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        answer.push_back(s_t);
    }
    
    return answer;
}
