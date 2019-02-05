#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

//int arr[100000000];
int solution(int n, vector<int> times) {
    int answer = 0;
    int size=times.size();
    int start=0;
    int end;
    int mid;
    int temp;
    int temp2;
    int count=0;
    sort(times.begin(), times.end());
    end=2147483647;
    mid=end/2;
    
    while(count<50)
    {
//    	printf("%d %d %d\n", start, mid, end);
        temp=0;
        temp2=0;
        for(int i=0; i<size /*&& temp<=n*/; i++)
            temp+=(mid/times[i]);
        
//        arr[mid]=temp;
        if(temp>n)
            end=mid;
        else if(temp<n)
            start=mid;
        else
            break;
        mid=(start+end)/2;
        
        count++;
    }
    
    if(temp!=n)
    {
        
        return mid+1;
        
//        while(arr[mid]<n)
//            mid++;
        
//        temp2=2147483647;
//	    for(int i=0; i<size; i++)
//	        temp2=min(temp2, (mid/times[i]+1)*times[i]);
//	    return temp2;
    }
    

    temp2=0;
    for(int i=0; i<size; i++)
        temp2=max(temp2, (mid/times[i])*times[i]);
	
	    
    
/*
    while(1)
    {
        mid--;
        temp=0;
        for(int i=0; i<size; i++)
            temp+=(mid/times[i]);
        if(temp!=n)
            break;
    }*/
    
    return temp2;
}


int main()
{
	vector<int> times;
	times.push_back(60);
	times.push_back(120);
	times.push_back(201);
	times.push_back(350);
	times.push_back(599);
	times.push_back(240);
	
	cout<<"Á¤´ä "<<solution(44, times)<<endl;	
	return 0;
}

