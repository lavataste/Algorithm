#include <string>
#include <vector>
#include<iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index=0;
    int temp='0';
    int size=number.size();
    int j=0;
    int l=0;
    int k_save=k;
    
    while(k>0 && index+k<size)
    {
        temp='0' - 1 ;
        j=index;
        for(int i=index; i<index+k+1 ; i++)
        {
            if(temp<number[i])
            {
                temp=number[i];
                j=i;
                if(temp==9 +'0')
                    break;
            }
        }
        
        for(int i=index; i<j; i++)
            number[i]='0' - 1;
        
        k-=(j-index);
        index=j+1;
    }
       
    if(k)
    {
    	for(int i=0; i<k; i++)
    		number[size-1-i]='0'-1;    
    }
    
    j=0;
    while(j<size-k_save)
    {
        if(number[l]=='0'-1)
            l++;
        else
        {
            answer+=number[l];
            j++;
            l++;
        }
    }
    answer[size-k_save]=0;

    return answer;
}

int main()
{
	string a;
	a=solution("123123143234312", 5);
	
	cout<<a<<endl;
	a[0]='0';
	cout<<a<<endl;
	a[9]='9';
	cout<<a<<endl;
	a[10]='A';
	cout<<a<<endl;
	printf("%s\n", a.c_str());
	a[11]=0;
	cout<<a<<endl;
	printf("%s\n", a.c_str());
	return 0;
}
