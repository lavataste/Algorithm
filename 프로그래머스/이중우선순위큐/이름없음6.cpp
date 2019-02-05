#include <string>
#include <vector>
#include<stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> q;
    int size=operations.size();
    int length;
    string number;
    
    for(int i=0; i<size; i++)
    {
//    	printf("%s size %d\n", operations[i].c_str(), q.size());
        if(!q.empty())
            sort(q.begin(), q.end());
        
        if(operations[i][0]=='D')
        {
            if(q.empty())
                continue;
            if(operations[i][2]=='-')
                q.erase(q.begin());
            else
                q.erase(q.end()-1);
        }
        
        else
        {
            number="";
            length=operations[i].size();
            for(int j=2; j<length; j++)
                number+=operations[i][j];
            q.push_back(atoi(number.c_str()));
        }
    }
    
    if(q.size())
    {
        answer.push_back(q[q.size()-1]);
        answer.push_back(q[0]);
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}

int main()
{
	vector<int> a;
	vector<string> v;
	
/*	v.push_back("I 7");
	v.push_back("I 5");
	v.push_back("I -5");
	v.push_back("D -1");
	a=solution(v);*/
	
	v.push_back("I 16");
	v.push_back("I -5643");
	v.push_back("D -1");
	v.push_back("D 1");
	v.push_back("D 1");
	v.push_back("I 123");
	v.push_back("D -1"); 
	
	a=solution(v);
//  	["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"]
	
	
	
	printf("%d %d\n", a[0], a[1]);
	printf("dfdf %d", atoi("-32342"));
	return 0;
}
