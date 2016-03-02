/*
*@file : Date.cpp
*
*@author (A) : Madhu Kumar Dadi.
*@version : 25-2-2016
*
*Write about your Project
*
*This work is licensed under the
*Creative Commons Attribution-NonCommercial-ShareAlike 4.0
*International License. To view a copy of this license,
*visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
*
*/

#include <iostream>
#include "Date.h"
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

DateFormat Date::format;

DateFormat::DateFormat(const char *dateFormat, const char *monthFormat, const char *yearFormat)
{
    this->dateFormat=new char[3];
    this->monthFormat=new char[4];
    this->yearFormat=new char[5];
    strcpy(this->dateFormat,dateFormat);
    strcpy(this->monthFormat,monthFormat);
    strcpy(this->yearFormat,yearFormat);
}

DateFormat::DateFormat(const char *format)
{
    char *s;
    char *c=new char[20];
    strcpy(c,format);
    int j;
    j=0;
    s=new char[3];
    while(*c!='-')
    {
        s[j++]=*c;
        c++;
    }
    c++;
    s[j]='\0';
    this->dateFormat=s;
    j=0;
    s=new char[4];
    while(*c!='-')
    {
        s[j++]=*c;
        c++;
    }
    c++;
    s[j]='\0';
    this->monthFormat=s;
    j=0;
    s=new char[5];
    while(*c!='\0')
    {
        s[j++]=*c;
        c++;
    }
    s[j]='\0';
    this->yearFormat=s;
}


DateFormat::DateFormat()
{
    this->dateFormat=new char[3];
    this->monthFormat=new char[4];
    this->yearFormat=new char[5];
    strcpy(this->dateFormat,"dd");
    strcpy(this->monthFormat,"mmm");
    strcpy(this->yearFormat,"yy");
}

DateFormat::~DateFormat()
{
    delete[] this->dateFormat;
    delete[] this->monthFormat;
    delete[] this->yearFormat;
}

Date::Date(Day d, Month m, Year y)
{
    this->day=d;
    this->mon=m;
    this->year=y;
}

Date::Date(const char *date)
{
  char *c=new char[12];
  char *d=new char[8];
  char *m=new char[8];
  char *yr=new char[8];
  strcpy(c,date);
  int j;
  char *s=c;
  char *tempV=new char[5];
  j=0;
  while(*s!='-')
    {
      tempV[j]=*s;
      j++;
      s++;
    }
  s++;
  tempV[j]='\0';
  strcpy(d,tempV);
  j=0;
  while(*s!='-')
    {
      tempV[j]=*s;
      j++;
      s++;
    }
  s++;
  tempV[j]='\0';
  strcpy(m,tempV);
  j=0;
  while(*s!='\0')
    {
      tempV[j]=*s;
      j++;
      s++;
    }
  tempV[j]='\0';
  strcpy(yr,tempV);
  
  this->day=Day(atoi(d));

  if(strcmp(Date::format.monthFormat,"m")==0
     ||strcmp(Date::format.monthFormat,"mm")==0)
    this->mon=Month(atoi(m));
  else if(strcmp(Date::format.monthFormat,"mmm")==0)
    { 
      this->mon=ToMonth(m);
    }

  if(strcmp(Date::format.yearFormat,"yy")==0)
    {
      int y=atoi(yr);
      this->year=(y>=50)?y+=1900:y+=2000;
    }
  else if(strcmp(Date::format.yearFormat,"yyyy")==0)
    this->year=atoi(yr);
}

Date::Date()
{
    time_t t;
    time(&t);
    struct tm *temp_time=localtime(&t);
    this->day=Day(temp_time->tm_mday);
    this->mon=Month(temp_time->tm_mon+1);
    this->year=temp_time->tm_year+1900;
}

Date::Date(const Date& date)
{
    this->day=date.day;
    this->mon=date.mon;
    this->year=date.year;
}

Date::~Date()
{}

Date& Date::operator =(const Date& date)
{
    this->day=date.day;
    this->mon=date.mon;
    this->year=date.year;
    return *this;
}

Date& Date::operator ++()
{
    if(this->day<28){
        this->day=Day((int)this->day+1);
    }
    else if(this->day==28&&(this->year%4==0||this->mon!=2))
    {
        this->day=Day(29);
    }
    else if(this->day==28&&this->mon==2)
    {
        this->day=Day(1);
        this->mon=Month(3);
    }
    else if(this->day==29&&this->mon==2)
    {
        this->day=Day(1);
        this->mon=Month(3);
    }
    else if(this->day==29)
    {
        this->day=Day(30);
    }
    else if(this->day==30&&(this->mon==4||this->mon==6||this->mon==9||this->mon==11))
    {
        this->day=Day(1);
        this->mon=Month((int)this->mon+1);
    }
    else if(this->day==31&&(this->mon!=12))
    {
        this->day=Day(1);
        this->mon=Month((int)this->mon+1);
    }
    else if(this->day==31)
    {
        this->mon=Month(1);
        this->day=Day(1);
        this->year++;
    }
    else
    {
        this->day=Day(31);
    }

    return *this;
}

Date& Date::operator ++(int i)
{
    if(this->day<22){
        this->day=Day((int)this->day+7);
    }
    else if(this->day==22&&(this->year%4==0||this->mon!=2))
    {
        this->day=Day(29);
    }
    else if(this->day==22&&this->mon==2)
    {
        this->day=Day(1);
        this->mon=Month(3);
    }
    else if(this->mon==2&&this->year%4==0)
    {
        this->day=Day((int)this->day-29+7);
        this->mon=Month(3);
    }
    else if(this->mon==2)
    {
        this->day=Day((int)this->day-28+7);
        this->mon=Month(3);
    }
    else if(this->day==23)
    {
        this->day=Day(30);
    }
    else if(this->mon==4||this->mon==6||this->mon==9||this->mon==11)
    {
        this->day=Day((int)this->day-30+7);
        this->mon=Month((int)this->mon+1);
    }
    else if(this->day==24)
    {
        this->day=Day(31);
    }
    else if(this->mon==12)
    {
        this->mon=Month(1);
        this->day=Day((int)this->day-31+7);
        this->year++;
    }
    else
    {
        this->day=Day((int)this->day-31+7);
        this->mon=Month((int)this->mon+1);
    }
    return *this;
}

Date& Date::operator--()
{
   if(this->day>1)
     {
       this->day=Day((int)this->day-1);
     }
   else if(this->year%4==0&&this->mon==3)
     {
       this->day=Day(29);
       this->mon=Month(2);
     }
   else if(this->mon==3)
     {
       this->day=Day(28);
       this->mon=Month(2);
     }
   else if(this->mon==5||this->mon==7||this->mon==10||this->mon==12)
     {
       this->day=Day(30);
       this->mon=Month((int)this->mon-1);
     }
   else if(this->mon!=1)
     {
       this->day=Day(31);
       this->mon=Month((int)this->mon-1);
     }
   else
     {
       this->day=Day(31);
       this->mon=Month(12);
       this->year--;
     }
   return *this;
}

Date& Date::operator--(int)
{

  if(this->day>7)
    {
      this->day=Day((int)this->day-7);
    }
  else if(this->year%4==0&&this->mon==3)
    {
      this->day=Day(29+(int)this->day-7);
      this->mon=Month(2);
    }
  else if(this->mon==3)
    {
      this->day=Day(28+(int)this->day-7);
      this->mon=Month(2);
    }
  else if(this->mon==5||this->mon==7||this->mon==10||this->mon==12)
    {
      this->day=Day((int)this->day+30-7);
      this->mon=Month((int)this->mon-1);
    }
  else if(this->mon!=1)
    {
      this->mon=Month((int)this->mon-1);
      this->day=Day((int)this->day+31-7);
    }
  else
    {
      this->day=Day((int)this->day+31-7);
      this->mon=Month(12);
      this->year--;
    }
  return *this;
}

Date Date::operator+(int noOfDays)
{
  if(noOfDays>0)
    {
      for(int i=0;i<noOfDays/7;i++)
	{
	  (*this)++;
	}
      for(int i=0;i<noOfDays%7;i++)
	{
	  ++(*this);
	}
    }
  else
    {
      noOfDays*=-1;
      for(int i=0;i<noOfDays/7;i++)
	{
	  (*this)--;
	}
      for(int i=0;i<noOfDays%7;i++)
	{
	  --(*this);
	}
    }
    return *this;
}

unsigned int Date::operator-(const Date& otherDate)
{
    unsigned int days;
    if(otherDate<(*this))
      {
	days=365*(this->year-otherDate.year);
	days+=(this->year-otherDate.year)/4;
      }
}


Date::operator WeekNumber() const
{
  Date temp(Day(1),Month(1),this->year);
  unsigned int days=temp-*this;
  int years=this->year-1950;
  int x=7;
  while(years!=0)
    {
      years--;x++;
      if(years==0) break;
      years--;x++;
      if(years==0) break;
      years--;x++;x++;
      if(years==0) break;
      years--;x++;
      if(years==0) break;
    }
  WeekDay d=WeekDay((x%7==0)?7:x%7);
  switch(d){
  case Mon:
    x=0;break;
  case Tue:
    x=1;break;
  case Wed:
    x=2;break;
  case Thu:
    x=3;break;
  case Fri:
    x=-3;break;
  case Sat:
    x=-2;break;
  case Sun:
    x=-1;break;
  }
  x+=days;
  x/=7;
  return WeekNumber(x+1);
}

Date::operator Month() const
{
  return this->mon;
}

Date::operator WeekDay() const
{
  Date temp(Day(1),Month(1),this->year);
  unsigned int days=temp-*this;
  int years=this->year-1950;
  int x=7;
  while(years!=0)
    {
      years--;x++;
      if(years==0) break;
      years--;x++;
      if(years==0) break;
      years--;x++;x++;
      if(years==0) break;
      years--;x++;
      if(years==0) break;
    }
  x+=days;
  x=x%7;
  return WeekDay((x==0)?7:x);
}

bool Date::leapYear() const
{
  if((int)this->year%4==0)
    return true;
  else return false;
}

bool Date::operator==(const Date& d)
{
  if(this->day==d.day&&this->mon==d.mon
     &&this->year==d.year)
    return true;
  else return false;
}

bool Date::operator!=(const Date& d)
{
  Date d1(d);
  return !(d1==*this);
}

bool Date::operator<(const Date& date)
{
  Date d(date);
  if(this->year<d.year) return true;
  else if(this->year==d.year)
    {
      if(this->mon<d.mon) return true;
      else if(this->mon==d.mon&&this->day<d.day)return true;
      else return false;
    }
  else return false;
}

bool Date::operator<=(const Date& date)
{
  Date d(date);
  return !(d>*this);
}

bool Date::operator>(const Date& date)
{
  Date d(date);
  if(this->year>d.year) return true;
  else if(this->year==d.year)
    {
      if(this->mon>d.mon) return true;
      else if(this->mon==d.mon&&this->day>d.day)return true;
      else return false;
    }
  else return false;
}

bool Date::operator>=(const Date& date)
{
  Date d(date);
  return !(d<*this);
}

char* ToString(Month m)
{
  switch(m)
    {
    case Jan:return (char*)"Jan";
    case Feb:return (char*)"Feb";
    case Mar:return (char*)"Mar";
    case Apr:return (char*)"Apr";
    case May:return (char*)"May";
    case Jun:return (char*)"Jun";
    case Jul:return (char*)"Jul";
    case Aug:return (char*)"Aug";
    case Sep:return (char*)"Sep";
    case Oct:return (char*)"Oct";
    case Nov:return (char*)"Nov";
    case Dec:return (char*)"Dec";
    }
}

ostream& operator<<(ostream& os,const Date& date)
{
  if(strcmp(Date::format.dateFormat,"d")==0)
    os<<date.day;
  else if(strcmp(Date::format.dateFormat,"dd")==0)
    os<<right<<setfill('0')<<setw(2)<<date.day;

  os<<"-";

  if(strcmp(Date::format.monthFormat,"m")==0)
    os<<date.mon;
  else if(strcmp(Date::format.monthFormat,"mm")==0)
    os<<right<<setfill('0')<<setw(2)<<date.mon;
  else if(strcmp(Date::format.monthFormat,"mmm")==0)
    os<<ToString(date.mon);

  os<<"-";

  if(strcmp(Date::format.yearFormat,"yy")==0)
    os<<(((int)date.year<2000)?date.year-1900:date.year-2000);
  else if(strcmp(Date::format.yearFormat,"yyyy")==0)
    os<<date.year;

  return os;
}

Month ToMonth(char * m)
{
  if(strcmp(m,"Jan")==0) return (Month)Jan;
  else if(strcmp(m,"Feb")==0) return (Month)Feb;
  else if(strcmp(m,"Mar")==0) return (Month)Mar;
  else if(strcmp(m,"Apr")==0) return (Month)Apr;
  else if(strcmp(m,"May")==0) return (Month)May;
  else if(strcmp(m,"Jun")==0) return (Month)Jun;
  else if(strcmp(m,"Jul")==0) return (Month)Jul;
  else if(strcmp(m,"Aug")==0) return (Month)Aug;
  else if(strcmp(m,"Sep")==0) return (Month)Sep;
  else if(strcmp(m,"Oct")==0) return (Month)Oct;
  else if(strcmp(m,"Nov")==0) return (Month)Nov;
  else if(strcmp(m,"Dec")==0) return (Month)Dec;
}


istream& operator>>(istream& is,Date& date)
{
  char * input=new char[20];
  is>>input;
  Date d(input);
  date.day=d.day;
  date.mon=d.mon;
  date.year=d.year;
  return is;
}

void Date::setFormat(DateFormat& df)
{
  strcpy(Date::format.dateFormat,df.dateFormat);
  strcpy(Date::format.monthFormat,df.monthFormat);
  strcpy(Date::format.yearFormat,df.yearFormat);
}

DateFormat& Date::getFormat()
{
  return Date::format;
}
