#include<iostream>
#include<string.h>

using namespace std;

void Move(int, int);
int Insertnumber(int, int);
int Multiple10(int, int);

int rurwk[4][4];
int number[16384];
int index_number;


int main()
{
	int T, count, count2, count3, answer=0;
	cin>>T;
	for(count=0;count<T;count++)
	{	
		memset(number, 0, sizeof(int)*16384);
		index_number=0;
		
		for(count2=0;count2<4;count2++)
			for(count3=0;count3<4;count3++)
				cin>>rurwk[count2][count3];
	
		for(count2=0;count2<4;count2++)
			for(count3=0;count3<4;count3++)
				Move(count2, count3);
		
		answer=index_number;
		
		cout<<"#"<<count+1<<" "<<answer<<endl;
	}
	
	return 0;

}

void Move(int start_index1, int start_index2)
{
	int count, count2, key, index1, index2, save=0, judge=0;
	
	for(count=0;count<4096;count++)
	{
		key=count;
		index1=start_index1;
		index2=start_index2;
		save=rurwk[index1][index2];
		judge=0;
		
		for(count2=0;count2<6;count2++)
		{
			if(key%4==0)
				index1--;
			else if(key%4==1)
				index1++;
			else if(key%4==2)
				index2--;
			else
				index2++;
			
			key/=4;
			
			if(index1<0 || index1>3 || index2<0 || index2>3)
			{
				judge=1;
				break;
			}
				
			save+=Multiple10(rurwk[index1][index2], count2+1);
		}
		if(!judge)
			index_number+=Insertnumber(save, index_number);	
	}
}

int Insertnumber(int n, int index)
{
	int count;
	for(count=0;count<index;count++)
	{
		if(n==number[count])
			return 0;
	}
//	cout<<"save "<<n<<"in"<<index<<endl;
	number[index]=n;
	return 1;
}

int Multiple10(int n, int a)
{
	if(a==0)
		return n;
	else if(a==1)
		return n*10;
	else
		return 10*Multiple10(n, a-1);
}
