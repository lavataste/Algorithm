#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int release=0;
    int size=progresses.size();
    int temp;
    
    while(release<size)
    {
    	printf("release %d %d\n", release, size);
        temp=0;
        for(int i=release; i<size; i++)
            progresses[i]+=speeds[i];
        
        for(int i=release; i<size; i++)
        {
        	printf("%d %d\n", progresses[i], 100);
            if(progresses[i]<100)
                break;
            temp++;
            printf("¤µ¤² %d\n", temp); 
        }
        
        if(temp)
        {
        	printf("¶ì¿ë\n"); 
            answer.push_back(temp);
            release+=temp;
        }
        
        for(int i=0; i<size; i++)
            printf("%d %d \n", i, progresses[i]);
    }
    
    
    return answer;
}

int main()
{
	vector<int> p={93, 30, 55};
	vector<int> s={1, 30, 5};
	
	solution(p, s);
	
	return 0;
}
