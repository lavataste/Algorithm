#include<iostream>
#include<string.h>

using namespace std;

void Move(int, int);
void Insertnumber(char*);

int rurwk[4][4];

char number[16384][8];
char save[8];
int index_number;


int main()
{
	int T, count, count2, count3;
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
		
		cout<<"#"<<count+1<<" "<<index_number<<endl;
	}
	
	return 0;

}

void Move(int start_index1, int start_index2)
{
	int count, count2, key, index1, index2, judge=0;
	save[7]=0;
	
	save[0]=rurwk[start_index1][start_index2]+48;
	for(count=0;count<4096;count++)
	{
		key=count;
		index1=start_index1;
		index2=start_index2;
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
			save[count2+1]=rurwk[index1][index2]+48;
		}
		if(!judge)
			Insertnumber(save);	
	}
}

void Insertnumber(char* s)
{
	int count;
	for(count=0;count<index_number;count++)
	{
		if(strcmp(number[count], s)==0)
			return;
	}
//	cout<<"save "<<s<<"in"<<index_number<<endl;
	strcpy(number[index_number], s);
	index_number++;
}

