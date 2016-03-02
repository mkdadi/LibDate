/*
*@file : Testdate.cpp
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

using namespace std;

int main(int argc,char* argv[])
{
  Date date;
  cout<<date<<endl;
  cin>>date;
  date++;
  cout<<date<<endl;
  date--;
  cout<<date<<endl;
  DateFormat d("dd","mm","yyyy");
  --date;
  cout<<date<<endl;
  date++;
  cout<<date<<endl;
  ++date;
  cout<<date<<endl;
  date=date+5;
  cout<<date<<endl;
  date=date+(-5);
  cout<<date<<endl;
  Date::setFormat(d);
  cout<<date<<endl;
  return 0;
}
