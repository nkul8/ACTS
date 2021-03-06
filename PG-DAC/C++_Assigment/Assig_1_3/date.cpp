#include<iostream>
#include "student.h"
using namespace std;
Dates::Dates()
{
	dd = 0;
	mm = 0;
	yyyy = 0;
}	
Dates::Dates(int d,int m,int y)
{
	dd = d;
	mm = m;
	this->yyyy = y;
}
void Dates::accept(int d,int m,int y)
{
	dd = d;
	mm = m;
	yyyy = y;
}
void Dates::show()
{
	cout<<"\n Day "<<dd;
	cout<<"\n Month "<<mm;
	cout<<"\n Year "<<yyyy;
}

void Dates::difference(int d,int m,int y)
{	
	int y_t;
	int t_y;
	int d_y = 0,i;
	int y_d = 0,j;
	int l,n,total_days = 0,total_months = 0;

	(yyyy%4==0)?(y_t = 366):(y_t = 365); // Start Year
	(y%4==0)?(t_y = 366):(t_y = 365); // End Year

	//Start Day
	for(i = mm + 1; i <= 12;i++)
	{
		d_y = d_y + days(i,yyyy);
		total_months = total_months + 1;
	}
		d_y = d_y + (days(mm,yyyy) - dd);

	//End Day
	for(j = 1; j < m ; j++)
	{
		y_d = y_d + days(j,y);
		total_months = total_months + 1;
	}
		y_d =  y_d + d;

	if(y>yyyy && y!=yyyy)
	{
		for(l = yyyy + 1;l < y; l++)
		{
			for(n = 1; n <= 12; n++)	
			{	
				total_days = total_days + days(n,l);
				total_months = total_months + 1;
			}
		}
	}
	
	total_days = total_days + y_d + d_y;	
	
	cout<<total_days<<" Days\n"<<end;
	cout<<total_months<<" Months\n"<<endl;		//Unverified
	cout<<y - yyyy<<" Years\n"<<endl;	
}

int Dates::days(int m,int y)
{
	int tdays;
	if(y%4 == 0)
	{
		if(m == 2)
			tdays = 29; 
	}	
	else
	{
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
			tdays = 31;
		else if(m == 4 || m == 6 || m == 9 || m == 1)
			tdays = 30;
		else
			tdays = 28;
	}
	return tdays;
}

/*
void Date::compare(int d,int m,int y)
{

}
*/





/* Older Implementation || difference()


int tdays,tdays1;
	int d1,m1,d2,m2;

	tdays = days(m,y);
	tdays1 = days(mm,yyyy);

	//Iterator Variables
	int t_days = 0, t_month = 0;
	int i,j,k,l,m,n;
	
	// Year is same
	if(y==yyyy)
	{
		//Month is same
		if(m == mm)
		{	
			if(d>dd)
				t_days = d - dd;
			else
				t_days = dd - d;
		}
		else
		{
			//Month Not Same
		}
	}
	// Year Not Same
	
		
	// Easiest Technique
	/* Formula : (iDay + (153 * (iMonth + 12 * ((14 - iMonth) / 12) - 3) + 2) / 5 + 365 *
        (iYear + 4800 - ((14 - iMonth) / 12)) + (iYear + 4800 - ((14 - iMonth) / 12)) / 4 - 32083);	*/
	
	/*  Older Technique
	if(y>yyyy)
	{
		cout<<"\n"<<y - yyyy<<" years";
		d1 = d;
		m1 = m;
		d2 = dd;
		m2 = mm;
	}
	else if(y<yyyy)
	{
		d1 = dd;
		m1 = mm;
		d2 = d;
		m2 = m;
		cout<<"\n"<<y - yyyy<<" years";
	}
	
	int i,j,temp = 0, temp1 = 0;
	for(i = m1; i<=m2; i++)
	{
		for(j = d1; j <= d2; j++)
		{
			if(d1<=tdays)
			{
				j = 1;
				continue;
			}
			temp++;
			cout<<"Test"<<j<<temp;
		}
		temp1++;
	}
	
	
	
	cout <<"\n"<<temp1<<" month";
	cout <<"\n"<<temp<<" days";
*/
