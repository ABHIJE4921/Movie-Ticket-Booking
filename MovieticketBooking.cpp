#include <stdio.h>
#include <stdlib.h>
int ar1[5][10],newar[50],booked[50];
void value()
{
	int i,k=1;
	for(i=0;i<50;i++)
	{		
		booked[i]=k;
		k++;		
	}
	
}
void displayed()
{	
	int i,k=0;
	printf("                           CARNIVAL CINEMAS SEAT STATUS         \n");
	for(i=0;i<50;i++)
	{
		k++;
		printf("%d\t",booked[i]);
		if(k%10==0)
		{
			printf("\n");
		}
	}	
}
void emptying(int a)
{
	int i,pos;
	for(i=0;i<50;i++)
	{
	if(booked[i]==a)
	{
		booked[i]=0;
		break;
	}
    }	
}
int search(int ar[],int ticket)
{
	int i;
	for(i=0;i<50;i++)
	{
		if(ar[i]==ticket)
		{
			return 1;
		}
	}
	
}
void main()
{
	int n,ar[5],c=50,i,j=0;
	value();
	displayed();
	while(c!=0)
	{	
	printf("\nEnter number of tickets to be booked maximum 5 allowed .......price of ticket is Rs150/seat\n");
	scanf("%d",&n);
	if(n>5)
	{
		printf("\nSingle booking is maximum for 5 person Please! limit you seats\n\n");
		continue;
	}
	if(n>c)
	{
		printf("\nsorry! %d seats are left only\n",c);
		continue;
	}
	for(i=0;i<n;i++)
	{
		if(c!=0)
		{		
		printf("Enter seat number for ticket %d\n",i+1);
		scanf("%d\a",&ar[i]);
		if(ar[i]>50||ar[i]==0)
		{
			printf("\noops! Seat range is from 1 to 50 and you entered an invalid seat...... Please select within range\n\n");
			i--;
			continue;
		}
		if(search(newar,ar[i]))
		{
			printf("\nsorry!this seat is already booked select another,you may check above status \n\n");
			i--;
			continue;			
		}
	//	printf("CONGRATS!YOUR SEATS ARE SUCCESSFULLY BOOKED ENJOY YOU MOVIE.............\n");		
		newar[j]=ar[i];
		emptying(ar[i]);
		j++;
		c--;
	    }
	//printf("CONGRATS!YOUR SEATS ARE SUCCESSFULLY BOOKED ENJOY YOU MOVIE.............\n");	
	    else
	    {		
		   break;
	    }
	}
	printf("\nCONGRATS!YOUR SEATS ARE SUCCESSFULLY BOOKED ENJOY YOUR MOVIE.............Please pay Rs.%d\n\n\n\n",(150*n));
	displayed();
   }
printf("\nPlease try another day today is housefull\n");
}
