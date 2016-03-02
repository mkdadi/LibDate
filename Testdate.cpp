/*
*@file : Testdate.cpp
*
*@author (A) : Madhu Kumar Dadi.
*@version : 25-2-2016
*
*This is a TestBench for the class Date and class DateFormat
*
*/
#include <iostream>
#include "Date.h"

using namespace std;

void TestDate();

int main(int argc,char* argv[])
{
  TestDate();
  return 0;
}

void TestDate()
{
  //To check for Date(Day,Month,Year) constructor
  cout<<"Initializing Test Set...\nConstructing Objects of Date class using Date(Day,Month,Year) constructor\n";
  try{
    Date date(Day(27),Month(11),Year(1996));
    cout<<"Succesfully created Date object for Date "<<date<<endl;
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<"Check Failed..\n"<<e;}

  //invalid_argument exception of Date(Day,Month,Year) constructor
  cout<<"\nChecking for exceptions in Date construction...\n";
  try{
    cout<<"Checking for invalid_argument exception...\n";
    Date date(Day(32),Month(13),Year(1995));
    cout<<"Check failed..\n";
  }
  catch(invalid_argument& e){cout<<e<<"Success..\n";}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<"Check Failed..\n"<<e;}

  //domain_error exception of Date(Day,Month,Year) constructor
  try{
    cout<<"\nChecking for domain_error exception...\n";
    Date date(Day(30),Month(2),Year(1995));
    cout<<"Check failed..\n";
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<e<<"Success..\n";}
  catch(out_of_range& e){cout<<"Check Failed..\n"<<e;}

  //out_of_range exception of Date(Day,Month,Year) constructor
  try{
    cout<<"\nChecking for out_of_range exception...\n";
    Date date(Day(26),Month(2),Year(1945));
    cout<<"Check failed..\n";
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<e<<"Success..\n";}

  //To check Date(const char*) constructor
  try{
    cout<<"\nChecking for Date(const char*) constructor..\n";
    Date date("25-Oct-95");
    cout<<"Succesfully created Date object for Date "<<date<<endl;
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<"Check Failed..\n"<<e;}

  //invalid_argument exception for  Date(const char*) constructor
  cout<<"\nChecking for exceptions in Date construction...\n";
  try{
    cout<<"Checking for invalid_argument exception...\n";
    DateFormat df1("dd","mm","yy");
    Date::setFormat(df1);
    Date date("45-13-92");
    cout<<"Check failed..\n";
  }
  catch(invalid_argument& e){cout<<e<<"Success..\n";}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<"Check Failed..\n"<<e;}

  DateFormat df;
  Date::setFormat(df);
  
  //domain_error exception for  Date(const char*) constructor
  try{
    cout<<"\nChecking for domain_error exception...\n";
    Date date("29-Feb-15");
    cout<<"Check failed..\n";
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<e<<"Success..\n";}
  catch(out_of_range& e){cout<<"Check Failed..\n"<<e;}

  //out_of_range exception for  Date(const char*) constructor
  try{
    cout<<"\nChecking out_of_range exception...\n";
    DateFormat df1("dd-mmm-yyyy");
    Date::setFormat(df1);
    Date date("02-Dec-2054");
    cout<<"Check failed..\n";
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<e<<"Success..\n";}

  Date::setFormat(df);
  
  //To check Default constructor
  cout<<"\nChecking default Date Constuctor..\n";

  try{
    Date date;
    cout<<"Successfully created Date "<<date<<endl;
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<e<<"Check Failed..\n";}

  cout<<"\nException in default Date Constructor is expected when current year exceeds 2049,\n"
      <<"So it can't be checked now\nBut expect it to give exception for those conditions\n";
  
  //To check Copy Constructor
  {
    cout<<"\nChecking for Copy constructor...\n";
    Date d1(Day(21),Month(6),Year(1994));
    cout<<"Initialized date1 to "<<d1<<endl;
    Date d2(d1);
    if(d1==d2) cout<<"Success.. both date1 and date2 are "<<d2<<endl;
    else cout<<"Failed.. date2 is "<<d2<<"\n";
  }

  //To check Assignment operator
  {
    cout<<"\nChecking for Assignment operator...\n";
    Date d1(Day(27),Month(3),Year(1987));
    cout<<"Initialized date1 to "<<d1<<endl;
    Date d2;
    d2=d1;
    if(d1==d2) cout<<"Success.. both date1 and date2 are "<<d2<<endl;
    else cout<<"Failed.. date2 is "<<d2<<"\n";
  }

  //To check for operator++
  {
    cout<<"\nChecking for operator++ ...\n";
    Date d1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<d1<<endl;
    Date d2=d1+1;
    ++d1;
    if(d1==d2) cout<<"Success.. after ++date , date is "<<d1<<endl;
    else cout<<"Failed.. date is "<<d1<<"\n";
  }

  //To check for operator++(int)
  {
    cout<<"\nChecking for operator++(int) ...\n";
    Date d1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<d1<<endl;
    Date d2=d1+7;
    d1++;
    if(d1==d2) cout<<"Success.. after date++ , date is "<<d1<<endl;
    else cout<<"Failed.. date is "<<d1<<"\n";
  }
  
  //To check for operator--
  {
    cout<<"\nChecking for operator-- ...\n";
    Date d1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<d1<<endl;
    Date d2=d1+(-1);
    --d1;
    if(d1==d2) cout<<"Success.. after --date , date is "<<d1<<endl;
    else cout<<"Failed.. date is "<<d1<<"\n";
  }

  //To check for operator--(int)
  {
    cout<<"\nChecking for operator--(int) ...\n";
    Date d1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<d1<<endl;
    Date d2=d1+(-7);
    d1--;
    if(d1==d2) cout<<"Success.. after date-- , date is "<<d1<<endl;
    else cout<<"Failed.. date is "<<d1<<"\n";
  }

  //To check for operator-(const Date&)
  {
    cout<<"\nChecking for operator-(const Date&) ...\n";
    Date d1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<d1<<endl;
    Date d2(Day(25),Month(10),Year(2015));
    cout<<"Initialized date2 to "<<d2<<endl;
    int diff=d1-d2;
    cout<<"Success.. no of days between date1 and date2 = "<<diff<<endl;
  }

  //To check for operator+(int) where int is positive
  {
    cout<<"\nChecking for operator+(int) when int is positive ...\n";
    Date d1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<d1<<endl;
    int n=6906;
    cout<<"Initialized n to "<<n<<endl;
    Date d2=d1+n;
    cout<<"Success.. date1 + n = "<<d2<<endl;
  }

  //To check for operator+(int) where int is negative
  {
    cout<<"\nChecking for operator+(int) when int is negative ...\n";
    Date d1(Day(25),Month(10),Year(2015));
    cout<<"Initialized date1 to "<<d1<<endl;
    int n=-6906;
    cout<<"Initialized n to "<<n<<endl;
    Date d2=d1+n;
    cout<<"Success.. date1 + n = "<<d2<<endl;
  }

  //To check for out_of_range exception in operator+(int)
  try{
    cout<<"\nChecking for exceptions in operator+(int) ...\n";
    Date d1(Day(27),Month(11),Year(2041));
    cout<<"Initialized date1 to "<<d1<<endl;
    int n=6906;
    cout<<"Initialized n to "<<n<<endl;
    Date d2=d1+n;
    cout<<"Failed.. date1 + n = "<<d2<<endl;
  }
  catch(invalid_argument& e){cout<<"Check Failed..\n"<<e;}
  catch(domain_error& e){cout<<"Check Failed..\n"<<e;}
  catch(out_of_range& e){cout<<e<<"Success..\n";}
  
  //To check for operator WeekNumber() const
  {
    cout<<"\nChecking for operator WeekNumber() const ...\n";
    Date date(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<date<<endl;
    cout<<"Week Number of date is "<<WeekNumber(date)<<endl<<"Success..\n";
  }

  //To check for operator Month() const
  {
    cout<<"\nChecking for operator Month() const ...\n";
    Date date(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<date<<endl;
    cout<<"Month of date is "<<Month(date)<<endl<<"Success..\n";
  }

  //To check for operator WeekDay() const
  {
    cout<<"\nChecking for operator WeekDay() const ...\n";
    Date date;
    cout<<"Initialized date to "<<date<<endl;
    cout<<"Week Day of date is "<<wstr(WeekDay(date))<<endl<<"Success..\n";
  }

  //To check for operator leapYear() 
  {
    cout<<"\nChecking for leapYear() ...\n";
    Date date(Day(27),Month(11),Year(1996));
    cout<<"Initialized date to "<<date<<endl;
    cout<<"Leap Year check of date says "<<date.leapYear()<<endl<<"Success..\n";
  }

  //To check for operator==(const Date&)
  {
    cout<<"\nChecking for operator==(const Date&) ..\n";
    Date date1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<date1<<endl;
    Date date2(Day(27),Month(10),Year(1996));
    cout<<"Initialized date2 to "<<date2<<endl;
    cout<<"date1==date2 says "<<(date1==date2)<<"\nSuccess...\n";
  }

  //To check for operator!=(const Date&)
  {
    cout<<"\nChecking for operator!=(const Date&) ..\n";
    Date date1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<date1<<endl;
    Date date2(Day(27),Month(10),Year(1996));
    cout<<"Initialized date2 to "<<date2<<endl;
    cout<<"date1!=date2 says "<<(date1!=date2)<<"\nSuccess...\n";
  }

  //To check for operator<(const Date&)
  {
    cout<<"\nChecking for operator<(const Date&) ..\n";
    Date date1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<date1<<endl;
    Date date2(Day(27),Month(10),Year(1996));
    cout<<"Initialized date2 to "<<date2<<endl;
    cout<<"date1<date2 says "<<(date1<date2)<<"\nSuccess...\n";
  }

  //To check for operator<=(const Date&)
  {
    cout<<"\nChecking for operator<=(const Date&) ..\n";
    Date date1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<date1<<endl;
    Date date2(Day(27),Month(10),Year(1996));
    cout<<"Initialized date2 to "<<date2<<endl;
    cout<<"date1<=date2 says "<<(date1<=date2)<<"\nSuccess...\n";
  }

  //To check for operator>(const Date&)
  {
    cout<<"\nChecking for operator>(const Date&) ..\n";
    Date date1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<date1<<endl;
    Date date2(Day(27),Month(10),Year(1996));
    cout<<"Initialized date2 to "<<date2<<endl;
    cout<<"date1>date2 says "<<(date1>date2)<<"\nSuccess...\n";
  }

  //To check for operator>=(const Date&)
  {
    cout<<"\nChecking for operator>=(const Date&) ..\n";
    Date date1(Day(27),Month(11),Year(1996));
    cout<<"Initialized date1 to "<<date1<<endl;
    Date date2(Day(27),Month(10),Year(1996));
    cout<<"Initialized date2 to "<<date2<<endl;
    cout<<"date1>=date2 says "<<(date1>=date2)<<"\nSuccess...\n";
  }
  
  char c;
  char *input=new char[20];
  while(true)
    {
      cout<<"\nDo you want to test for any Date?y/n"<<endl;
      cin>>c;
      if(c!='y')
	{
	  cout<<"I will take that as no.\nExiting..\n";
	  delete[] input;
	  return;
	}
      cout<<"Give a date in \""<<Date::getFormat().dateFormat<<"-"
	  <<Date::getFormat().monthFormat<<"-"<<Date::getFormat().yearFormat
	  <<"\" format: ";
      cin>>input;
      Date date(input);
      cout<<"Initialized as "<<date<<endl;
      ++date;
      cout<<"After ++date "<<date<<endl;
      date++;
      cout<<"After date++ "<<date<<endl;
      date=date+31;
      cout<<"After date=date+31 "<<date<<endl;
      date=date+(-31);
      cout<<"After date=date-(-31) "<<date<<endl;
      cout<<"Week Number of "<<date<<" is "<<WeekNumber(date)<<endl;
      cout<<"Month of "<<date<<" is "<<mstr(Month(date))<<endl;
      cout<<"Week Day of "<<date<<" is "<<wstr(WeekDay(date))<<endl;
      cout<<"Leap Year check of "<<date<<" says "<<date.leapYear()<<endl;
    }
  delete[] input;
}
