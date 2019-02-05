#include<iostream>

using namespace std;

int Multiple10(int n, int a)
{
	if(a==0)
		return n;
	else if(a==1)
		return n*10;
	else
		return 10*Multiple10(n, a-1);

}

int main()
{
	cout<<Multiple10(2,0);
	return 0;

}


