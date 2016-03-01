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

using namespace std;

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
    this->day=Day(atoi(tempV));
    j=0;
    while(*s!='-')
    {
        tempV[j]=*s;
        j++;
        s++;
    }
    s++;
    tempV[j]='\0';
    this->mon=Month(atoi(tempV));
    j=0;
    while(*s!='\0')
    {
        tempV[j]=*s;
        j++;
        s++;
    }
    tempV[j]='\0';
    unsigned int year=atoi(tempV);
    this->year=(year<50)?year+2000:(year<100)?year+1900:year;
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

Date Date::operator+(int noOfDays)
{
    for(int i=0;i<noOfDays/7;i++)
    {
        ++(*this);
    }
    for(int i=0;i<noOfDays%7;i++)
    {
        (*this)++;
    }
    return *this;
}

//unsigned int Date::operator-(const Date& otherDate)
//{
//    unsigned int * days=new unsigned int;
//    *days=365*(this->year-otherDate.year);
//    *days+=(this->year-otherDate.year)/4;
//}


Date::operator WeekNumber() const
{
  Date temp(Day(1),Month(1),this->year);
  unsigned int days=temp-*this;
  int years=this->year-1950;
  int x=7;
  while(true)
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
    x=3;break;
  case Tue:
    x=2;break;
  case Wed:
    x=1;break;
  case Thu:
    x=0;break;
  case Fri:
    x=-1;break;
  case Sat:
    x=-2;break;
  case Sun:
    x=-3;break;
  }
  x+=days;
  x/=7;
  return WeekNumber(x);
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
  while(true)
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
