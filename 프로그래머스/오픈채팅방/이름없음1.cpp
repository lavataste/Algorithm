#include <string>
#include <vector>
#include<utility>
#include<iostream>
#include<map>
using namespace std;
vector<pair<string, int>> log;
map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string command, uid, nickname, nickname2;
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
        
        nickname2=m[uid];
        cout<<"nickname2 "<<nickname2<<endl;
        if(nickname2=="")
        {
            m.insert(pair<string, string>(uid, nickname));
            cout<<uid<<" "<<nickname<<" tq "<<m[uid]<<endl;
            log.push_back(pair<string, int>(uid, act));
        }
        
        else
        {
            if(act==1)
            {
                m[uid]=nickname;
                log.push_back(pair<string, int>(uid, act));
            }
            else if(act==2)
                log.push_back(pair<string, int>(uid, act));
            else
               m[uid]=nickname;
        }
    }
    
    size=log.size();
    string s_t="";
    for(int i=0; i<size; i++)
    {
        s_t="";
        s_t+=m[log[i].first];
        
        if(log[i].second==1)
            s_t+="´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        else
            s_t+="´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        answer.push_back(s_t);
    }
    
    return answer;
}

int main()
{
	vector<string> v;
	v.push_back("Enter uid1234 Muzi"); 
	v.push_back("Enter uid4567 Prodo");
	v.push_back("Leave uid1234");
	v.push_back("Enter uid1234 Prodo");
	v.push_back("Change uid4567 Ryan");
	solution(v);
	return 0;
}
