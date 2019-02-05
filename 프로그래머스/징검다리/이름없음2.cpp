#include <string>
#include <vector>
#include<algorithm>
#include<utility>
#include<iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size=rocks.size();
    int temp;
    int index;
    vector<pair<int, int>> d;
    vector<pair<int, int>> d2;
  
  	for(int i=0; i<size; i++)
        printf("%d ", rocks[i]);
    cout<<endl;
    
    
    sort(rocks.begin(), rocks.end());
    
    for(int i=0; i<size; i++)
        printf("%d ", rocks[i]);
    cout<<endl;
    
    
    d.push_back(pair<int, int>(rocks[0], 0));
    for(int i=1; i<size; i++)
        d.push_back(pair<int, int>(rocks[i]-rocks[i-1], i));
    d.push_back(pair<int, int>(distance-rocks[size-1], size-1));
    
    d2=d;
    for(int i=0; i<d.size(); i++)
        printf("%d ", d[i].first);
    cout<<endl;
    
    sort(d.begin(), d.end());
    
    for(int i=0; i<size; i++)
        printf("%d ", d[i].first);
    cout<<endl;
    
    for(int i=0; i<size; i++)
        printf("%d ", d2[i].first);
    
    cout<<endl;
    
    for(int i=0; i<n; i++)
    {
        temp=d[0].second;
        index=1;
        while(!d2[temp+index].first)
            index++;
        d2[temp].first+=d2[temp+index].first;
        d2[temp+index].first=0;
        d[0]=d2[temp];
        sort(d.begin(), d.end());
        
        
        for(int i=0; i<size-1; i++)
            printf("%d ", d[i].first);
        cout<<endl;
    }
    answer=d[0].first;
    return answer;
}

int main()
{
	vector<int> v;
	v.push_back(2);
	v.push_back(14);
	v.push_back(11);
	v.push_back(21);
	v.push_back(17);
	solution(25, v, 2); 	
	
	
}
