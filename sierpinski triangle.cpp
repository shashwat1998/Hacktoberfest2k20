#include<stdio.h>
int main()
{
	int x,y,i,n;
	scanf("%d",&n);
	for(y=n-1;y>=0;y--)
	{
		for(i=0;i<y;i++)
			printf(" ");
		for(x=0;x+y<n;x++)
			printf((x&y)?"  ":"* ");	
	printf("\n");
		}	
}
