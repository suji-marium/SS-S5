#include <stdio.h>
#include <stdlib.h>
void fcfs(int n,int rq[100],int intial);
void scan(int n,int rq[100],int intial,int size,int move);
void cscan(int n,int rq[100],int intial,int size,int move);
int n,rq[100],i,j,thm=0,intial,move,size,ch;
int main()
{
	printf("Enter the number of request: ");
	scanf("%d",&n);
	printf("Enter the request sequence: \n");
	for(i=0;i<n;i++)
		scanf("%d",&rq[i]);
	printf("Enter intial head position: ");
	scanf("%d",&intial);
	
	printf("Enter size of the disk: ");
	scanf("%d",&size);
	printf("Enter direction of head movement 1->High 2->Low: ");
	scanf("%d",&move);
	
	do
	{
		printf("Disk Scheduling: \n1.FCFS\n2.SCAN\n3.CSCAN\n4.EXIT\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				fcfs(n,rq,intial);
				break;
			case 2:
				scan(n,rq,intial,size,move);
				break;
			case 3:
				cscan(n,rq,intial,size,move);
				break;
			case 4:
				printf("Exiting");
				break;
			default:
				printf("Invalid Entry");
		}
	
	}while(ch!=4);
}

void fcfs(int n,int rq[100],int intial)
{
	int thm=0;
	for(i=0;i<n;i++)
	{
		thm=thm+abs(rq[i]-intial);
		intial=rq[i];
	}
	printf("\nTotal Head Movement: %d\n",thm);
}

void scan(int n,int rq[100],int intial,int size,int move)
{
	int ind,temp,index,thm=0;
	for(i=0;i<n-1;i++)
	{
		ind=i;
		for(j=i+1;j<n;j++)
			if(rq[j]<rq[ind])
				ind=j;
		temp=rq[i];
		rq[i]=rq[ind];
		rq[ind]=temp;
	}
	for(i=0;i<n;i++)
	{
		if(rq[i]>intial)
			{
				index=i;
				break;
			}
	}
	if(move==1)
	{
		for(i=index;i<n;i++)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
		thm=thm+abs(size-1-rq[i-1]);
		intial=size-1;
		for(i=index-1;i>=0;i--)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
	}
	
	else 
	{
		for(i=index-1;i>=0;i--)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
		thm=thm+abs(rq[i+1]-0);
		intial=0;
		for(i=index;i<n;i++)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
	}
	printf("\nTotal Head Movement: %d\n",thm);
}


void cscan(int n,int rq[100],int intial,int size,int move)
{
	int ind,temp,index,thm=0;
	for(i=0;i<n-1;i++)
	{
		ind=i;
		for(j=i+1;j<n;j++)
			if(rq[j]<rq[ind])
				ind=j;
		temp=rq[i];
		rq[i]=rq[ind];
		rq[ind]=temp;
	}
	
	for(i=0;i<n;i++)
	{
		if(rq[i]>intial)
			{
				index=i;
				break;
			}
	}

	if(move==1)
	{
		for(i=index;i<n;i++)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
		thm=thm+abs(size-1-rq[i-1]);
		thm=thm+abs(size-1-0);
		intial=0;
		for(i=0;i<index;i++)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
	}
	
	else 
	{
		for(i=index-1;i>=0;i--)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
		thm=thm+abs(rq[i+1]-0);
		thm=thm+abs(size-1-0);
		intial=size-1;
		for(i=size-1;i>=index;i--)
		{
			thm=thm+abs(rq[i]-intial);
			intial=rq[i];
		}
	}
	printf("\nTotal Head Movement: %d\n",thm);

}





































