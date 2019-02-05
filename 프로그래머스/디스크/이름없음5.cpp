#include<iostream>
#include<queue>
using namespace std;

int main()
{
	priority_queue<int> q;
	printf("%d\n", q.size());
	
	q.push(3);
	printf("%d\n", q.size());
	
	q.push(5);
	printf("%d\n", q.top());
	q.pop();
	printf("%d\n", q.size());

	printf("%d\n", 7/4);

	return 0;
}
