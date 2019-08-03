/*                       PROJECT CALENDAR
this program prints the calendar of the year u enter.this program has
been divided into many divisions(i.e)in the form of functions.each
function performs a particular task.there are separate functins for
finding the first day of the month and for printing each month.*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef int DATEELEM;
enum DAY{SUNDAY=1,MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY};
enum DAY dayof1y(DATEELEM);
enum DAY dayof1m(enum DAY,DATEELEM,DATEELEM);
void printm(DATEELEM,DATEELEM,enum DAY);
void main()
{
	int i;
	char w;
	DATEELEM y;
	enum DAY dy1,dm1;
	while(1)
	{
		clrscr();
		printf("enter the year for which u want the calander:");
		scanf("%d",&y);
		if(y>0)
		{
			dy1=dayof1y(y);
			for(i=1;i<=12;i++)
			{
				dm1=dayof1m(dy1,i,y);
				printm(i,y,dm1);
				getch();
				clrscr();
			}
		}
		else
			printf("sorry!invalid year\n");
		printf("do u want to find for another year(y/n)?");
		fflush(stdin);
		scanf("%c",&w);
		if(w=='n')
			exit();
	}
}
enum DAY dayof1y(DATEELEM ye)
{
	enum DAY y1d=5;
	int di,l=0,i,da;
	if(ye<2004)
	{
		di=2004-ye;
		for(i=ye;i<2004;i++)
			if(i%4==0)
				l++;
		da=di*365+l;
		for(i=1;i<=da;i++)
		{
			y1d--;
			if(y1d==0)
				y1d=7;
		}
	}
	else
	{
		di=ye-2004;
		for(i=2004;i<ye;i++)
			if(i%4==0)
				l++;
		da=di*365+l;
		for(i=1;i<=da;i++)
		{
			y1d++;
			if(y1d>7)
				y1d=1;
		}
	}
	return(y1d);
}
enum DAY dayof1m(enum DAY y1d,DATEELEM m,DATEELEM y)
{
	enum DAY c;
	int da,i;
	switch(m)
	{
		case 1:
			da=0;
			break;
		case 2:
			da=31;
			break;
		case 3:
			if(y%4==0)
				da=60;
			else
				da=59;
			break;
		case 4:
			if(y%4==0)
				da=91;
			else
				da=90;
			break;
		case 5:
			if(y%4==0)
				da=121;
			else
				da=120;
			break;
		case 6:
			if(y%4==0)
				da=152;
			else
				da=151;
			break;
		case 7:
			if(y%4==0)
				da=182;
			else
				da=181;
			break;
		case 8:
			if(y%4==0)
				da=213;
			else
				da=212;
			break;
		case 9:
			if(y%4==0)
				da=244;
			else
				da=243;
			break;
		case 10:
			if(y%4==0)
				da=274;
			else
				da=273;
			break;
		case 11:
			if(y%4==0)
				da=305;
			else
				da=304;
			break;
		case 12:
			if(y%4==0)
				da=335;
			else
			da=334;
			break;
	}
	for(i=1;i<=da;i++)
	{
		y1d++;
		if(y1d>7)
		y1d=1;
	}
	return(y1d);
}
void printm(DATEELEM m,DATEELEM y,enum DAY d)
{
	char mo[10];
	int i,nd,c=d,n=1;
	clrscr();
	switch(m)
	{
		case 1:
			strcpy(mo,"JANUARY");
			nd=31;
			break;
		case 2:
			strcpy(mo,"FEBRUARY");
			if(y%4==0)
				nd=29;
			else
				nd=28;
			break;
		case 3:
			strcpy(mo,"MARCH");
			nd=31;
			break;
		case 4:
			strcpy(mo,"APRIL");
			nd=30;
			break;
		case 5:
			strcpy(mo,"MAY");
			nd=31;
			break;
		case 6:
			strcpy(mo,"JUNE");
			nd=30;
			break;
		case 7:
			strcpy(mo,"JULY");
			nd=31;
			break;
		case 8:
			strcpy(mo,"AUGUST");
			nd=31;
			break;
		case 9:
			strcpy(mo,"SEPTEMBER");
			nd=30;
			break;
		case 10:
			strcpy(mo,"OCTOBER");
			nd=31;
			break;
		case 11:
			strcpy(mo,"NOVEMBER");
			nd=30;
			break;
		case 12:
			strcpy(mo,"DECEMBER");
			nd=31;
			break;
	}
	gotoxy(36,1);
	printf("%d",y);
	gotoxy(35,3);
	printf("%s",mo);
	gotoxy(15,5);
	printf("SUN     MON     TUE     WED     THU     FRI     SAT\n");
	gotoxy(15+8*(d-1),6);
	for(i=1;i<=nd;i++)
	{
		printf("%d\t",i);
		c++;
		if(c>7)
		{
			gotoxy(15,6+n);
			n++;
			c=1;
		}
	}
}
/*the output will be submitted in the final report*/



