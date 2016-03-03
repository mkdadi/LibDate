#ifndef My_Date_h
#define My_Date_h 

/*
*@file : Date.h
*
*@author (A) : Madhu Kumar Dadi.
*@version : 25-2-2016
*
*header file for the Date Class and DateFormat class and their exceptions
*
*This work is licensed under the
*Creative Commons Attribution-NonCommercial-ShareAlike 4.0
*International License. To view a copy of this license,
*visit http://creativecommons.org/licenses/by-nc-sa/4.0/.
*
*/

#include <iostream>
#include <exception>

using namespace std;

typedef enum Day{
  D01= 1,D02= 2,D03= 3,D04= 4,D05= 5,D06= 6,D07= 7,D08= 8,D09= 9,D10=10,
  D11=11,D12=12,D13=13,D14=14,D15=15,D16=16,D17=17,D18=18,D19=19,D20=20,
  D21=21,D22=22,D23=23,D24=24,D25=25,D26=26,D27=27,D28=28,D29=29,D30=30,
  D31=31 }Day;

typedef enum WeekDay {
  Mon=1,Tue=2,Wed=3,Thu=4,Fri=5,Sat=6,Sun=7 }WeekDay;

typedef enum WeekNumber{
  W01= 1,W02= 2,W03= 3,W04= 4,W05= 5,W06= 6,W07= 7,W08= 8,W09= 9,W10=10,
  W11=11,W12=12,W13=13,W14=14,W15=15,W16=16,W17=17,W18=18,W19=19,W20=20,
  W21=21,W22=22,W23=23,W24=24,W25=25,W26=26,W27=27,W28=28,W29=29,W30=30,
  W31=31,W32=32,W33=33,W34=34,W35=35,W36=36,W37=37,W38=38,W39=39,W40=40,
  W41=41,W42=42,W43=43,W44=44,W45=45,W46=46,W47=47,W48=48,W49=49,W50=50,
  W51=51,W52=52,W53=53 }WeekNumber;

typedef enum Month {
  Jan= 1,Feb= 2,Mar= 3,Apr= 4,May= 5,Jun= 6,
  Jul= 7,Aug= 8,Sep= 9,Oct=10,Nov=11,Dec=12 }Month;

typedef unsigned int Year;

class DateFormat {
 public:
  DateFormat(const char* dateFormat, const char* monthFormat, const char* yearFormat);

  DateFormat(const char* format);

  DateFormat();

  ~DateFormat();


  //Whenever you use these functions you have to manually delete the pointers
  char* getdateFormat(); //To provide dateFormat with making it changeable
  char* getmonthFormat();//To provide monthFormat with making it changeable
  char* getyearFormat(); //To provide yearFormat with making it changeable

  void swap(DateFormat&); //To swap Pointers in the objects when you want to
                          //assign a new value to the object in other classes 
 private:
  char* dateFormat;
  char* monthFormat;
  char* yearFormat;
};

class Date {
 public:
  Date(Day d,Month m,Year y);

  explicit Date(const char* date);

  Date();

  Date(const Date&);

  ~Date();

  Date& operator=(const Date&);

  //Unary Assignment operators
  Date& operator++();
  Date& operator++(int);
  Date& operator--();
  Date& operator--(int);

  //Binary Arithmatic Operators
  unsigned int operator-(const Date&);
  Date operator+(int);

  //Cast Operators
  operator WeekNumber() const;
  operator Month() const;
  operator WeekDay() const;

  bool leapYear() const;

  //Binary Relational Operators
  bool operator==(const Date&);
  bool operator!=(const Date&);
  bool operator<(const Date&);
  bool operator<=(const Date&);
  bool operator>(const Date&);
  bool operator>=(const Date&);

  //Format Function
  static void setFormat(DateFormat&);
  static DateFormat& getFormat();

 private:
  static DateFormat format;
  Day day;
  Month mon;
  Year year;

 public:
  //Basic I/O using Friend functions
  friend ostream& operator <<(ostream&,const Date&);
  friend istream& operator >>(istream&,Date&);

};

char* mstr(Month m);

char* wstr(WeekDay w);

Month cToMon(char* m);

class invalid_argument : public exception
{
 public:
  char * error;
  
  //constructor
  invalid_argument();

  //constructor with error string
  invalid_argument(char*);

  //destructor
  ~invalid_argument() throw();

  //Output Stream Operator
  friend ostream& operator<<(ostream&,invalid_argument&);
};

class domain_error :public exception
{
 public:
  char *error;

  //constructor
  domain_error();

  //constructor with error string
  domain_error(char*);

  //destructor
  ~domain_error() throw();

  //Output Stream Operator
  friend ostream& operator<<(ostream&,domain_error&);
};

class out_of_range :public exception
{
 public:
  char *error;

  //constructor
  out_of_range();

  //constructor with error string
  out_of_range(char*);

  //destructor
  ~out_of_range() throw();

  //Output Stream Operator
  friend ostream& operator<<(ostream&, out_of_range&);
};

#endif
