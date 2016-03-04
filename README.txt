LibDate

Date library for C++

This library provides with various functions to work on Dates ranging in the years 1-1-1950 to 31-12-2049, and also on different formats for printing and scanning dates. Functions available through this library are mentioned below

Data Types
* Day
* WeekDay
* WeekNumber
* Month
* Year
* DateFormat
* Date

Functions

* DateFormat

    * Members  
        private `char* dateFormat`   
        private `char* monthFormat`   
        private `char* yearFormat`
	* Constructors  
        `DateFormat(const char* dateFormat,
                    const char* monthFormat,
                    const char* yearFormat);`   
        "Constructor for DateFormat for initialization of members to preferred values.  
		Eg: DateFormat dFormat("dd","mm","yyyy");"  

        `DateFormat(const char* format);`  
        "Constructor for DateFormat where members get initialized to the format provided in format parameter.  
		Eg: DateFormat dFormat("dd-mm-yyyy");"  

		`DateFormat();`  
		"Constructor with default format "dd-mmm-yy""  
		
	* Members Accessibility Functions  
		`char* getdateFormat();`  
		"Members are private and hence cannot be accessible from outside the class scope, so this function provides with dateFormat copy"  

		`char* getmonthFormat();`
		"This functions gives a copy of monthFormat String"  
		
		`char* getyearFormat();`  
		"This functions gives a copy of yearFormat String"  
		
	* Swapping Operation
		`void swap(DateFormat& dFormat);`  
		"Swaps pointers of members in current object and dFormat"   


* Date

	* Members
		private `Day day`  
		private `Month mon`  
		private `Year year`  
		private static `DateFormat format`  
	* Constructors  
		`Date();`  
		"Default Constructor initializes current date to that day"  

		`Date(const Date& date);`  
		"Copy Constructor creates a copy of date object"  

		`Date(Day day,Month month,Year year);`  
		"Initializes current object members respectively"  

		`Date(const char* date);`  
		"Parses the date string in the format as in format member"  

	* Assignment operators
		`Date& operator=(const Date& date);`  
		"Copies date member values into Current Object"  

		`Date& operator++();`
		"Gives the date of next Day and assigns it to current object"  

		'Date& operator++(int);`  
		"Gives the date of Same week Day in next week and assigns to current object"  

		`Date& operator--();`
		"Gives the date of previous day and assigns it to current date"  

		`Date& operator--(int);`  
		"Gives the date of same week day in previous week and assigns it to current date"  

	* Binary Arithmatic Operators
		`unsigned int operator-(const Date& date);`  
		"Gives absolute no of days in between date and current date"  

		`Date operator+(int noOfDays);`  
		"Changes current object by noOfDays"  

	* Cast Operators
		`operator WeekNumber() const;`  
		"Gives the WeekNumber of the current Object"  
		
		`operator Month() const;`
		"Gives the Month of the current Object"  
		
		`operator WeekDay() const;`  
		"Gives the WeekDay of current Object"  

	* Relational Operators
		`bool operator==(const Date& date);`  
		"Returns true if dates are equal else false"  

		`bool operator!=(const Date& date);`  
		"Returns true if date are not equal else false"  

		`bool operator<(const Date& date);`  
		"Returns true if current date is older to date else false"  

		`bool operator<=(const Date& date);`  
		"Returns true if current date is older or equal to date else false"  

		`bool operator>(const Date& date);`  
		"Returns true if current date is newer to date else false"  

		`bool operator>=(const Date& date);`  
		"Returns true if current date is newer or equal to date else false"  

	* Format Function
		`static void setFormat(DateFormat& dFormat);`  
		"Changes format of the format member of this class to dFormat"  

		`static DateFormat& getFormat();`  
		"Gets format of the format member of this class"  

	* Basic I/O operations
		`friend ostream& operator <<(ostream&,const Date&);`  
		"To output the Date in format given by format class"  

		`friend istream& operator >>(istream&,Date&);`  
		"To scan the Date in format given by format class"  

	* Checking Functions
		`bool leapYear() const;`  
		"returns true if current Object is leap year else false"  

* Miscellaneous Functions
	`char* mstr(Month m);`  
	"Returns String for the corresponding Month"  

	`char* wstr(WeekDay w);`  
	"Returns String for the corresponding WeekDay"  

	`Month cToMon(char* m);`  
	"Returns Month for the corresponding m string"  

Exceptions
* invalid_argument
	"When the date value is more than 31 and month value is more than 12"  

* domain_error
	"Thrown when the date as a triplet is invalid
	Eg: 30-02-2016 is an invalid date and hence throws domain_error"  

* out_of_range
	"Thrown when the year of date goes beyond 2049 or goes less than 1950"
