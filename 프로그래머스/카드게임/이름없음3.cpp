#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int judge(int index_l, int index_r, int max_r, vector<int> &left, vector<int> &right)
{
    int answer=0;
    int size=left.size();
    int l=index_l, r=index_r;
    int temp, temp2;
    
    if(l<size && r<size)
    {
        while(r<size && left[l]>right[r])
        {
            answer+=right[r];
            r++;
        }      
        if(r>=size)
            return answer;
        
        temp=l;
        while(temp<size && left[temp]<=right[r])
            temp++;
        
/*        if(temp<size && left[temp]>max_r)
        {
            for(int i=r; i<size; i++)
                answer+=right[i];
            return answer;
        }*/
        
//        if(l+1<size && r+1<size && left[l+1]<=right[r])
//            l++;
                
        answer+=max(judge(temp, r, max_r, left, right),judge(l+1, r+1, max_r, left, right));
    }
    return answer;
}

int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    int size=left.size();
    int max_l=0, max_r=0;
    
    for(int i=0; i<size; i++)
    {
        max_l=max(max_l, left[i]);
        max_r=max(max_r, right[i]);
    }
        
    if(max_l>max_r)
        for(int i=0; i<size; i++)
            answer+=right[i];
    else
        answer=judge(0, 0, max_r, left, right);    
    
    return answer;
}
