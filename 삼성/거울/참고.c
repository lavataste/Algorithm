#include <stdio.h>

char map[1005][1005]={0};
int check[1005][1005]={0};

int main(void)
{
	int TC,test;
	int n,x,y;
	int ax,ay;
	int vx,vy;
	int res,s;


	scanf("%d",&TC);

	for(test=1 ; test<=TC ; test++)
	{

	scanf("%d",&n);
	
	for(y=0 ; y<n ; y++)
	{
		scanf("%s",map[y]);
		for(x=0 ; x<n ; x++)
		{
			check[y][x]=0;
		}
	}

	ax=0;
	ay=0;
	vx=1;
	vy=0;
	res=0;

	while(1)
	{
		printf("%d %d\n", ax, ay);

		if((ax<0) || (ax>n) || (ay<0) || (ay>n))
		{
			break;
		}

		if(map[ay][ax] == '1')
		{
			s=vx;
			vx=-vy;
			vy=-s;
			if(check[ay][ax]==0)
			{
				check[ay][ax]++;
				res++;
			}
		}

		if(map[ay][ax] == '2')
		{
			s=vx;
			vx=vy;
			vy=s;
			if(check[ay][ax]==0)
			{
				check[ay][ax]++;
				res++;
			}
		}
		ax+=vx;
		ay+=vy;
	}



	printf("Case #%d\n%d\n",test,res);
	}

	

	return 0;
}
