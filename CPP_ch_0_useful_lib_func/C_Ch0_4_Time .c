
/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-         Time And Date Functions        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    The time and date functions require the header <time.h> for their prototypes. 
        This header file also defines four TYPES and two MACROS. 
        
        The 'type time_t' is able to represent the 'system time and date' as a long integer. 
            This is called the calendar time.  
        
        The 'structure type tm' holds date and time broken down into its elements. 
            The 'tm structure' is defined as shown here:

        The type clock_t is defined the same as time_t. 
        The header file also defines size_t.
        The 'macros' defined are NULL and CLOCKS_PER_SEC.
*/


struct tm { 	
    int tm_sec; 	// seconds, 0-61 
	int tm_min; 	// minutes, 0-59 
	int tm_hour; 	// hours, 0-23 
	int tm_mday; 	// day of the month, 1-31
	int tm_mon; 	// months since Jan, 0-11 
	int tm_year; 	// years from 1900 
	int tm_wday; 	// days since Sunday, 0-6 
	int tm_yday; 	// days since Jan 1, 0-365 
	int tm_isdst; 	// Daylight Saving indicator 
};

/* 
    The value of 'tm_isdst' will be 
        +ve if Daylight Saving is in effect, 
        0 if it is not in effect, and 
        -ve if there is no information available. 
        
        When the date and time are represented in this way, they are referred to as 'broken-down time'.
*/






Header Function	Description       #include <time.h>    must be  included before use	Example
#include <time.h>
char *asctime(const struct tm *ptr);	asctime() returns a pointer to a string that contains the time and date stored in the structure pointed to by ptr after it has been converted into the following form:
day month date hours:minutes:seconds year\n\0  
(Eg: Wed Jun 19 12:05:34 1999)
struct pointer passed to asctime() is generally obtained from either localtime() or gmtime(). The buffer used by asctime() to hold the formatted output string is a statically allocated character array and is overwritten each time the function is called. To save the contents of the string, copy it elsewhere.	struct tm *ptr; 
time_t It;
It = time(NULL); 
ptr = localtime(&lt); 
printf(asctime(ptr));

clock_t clock(void);	clock() returns the number of system clock cycles that have occurred since the program began execution. To compute the number of seconds, divide this value by the CLOCKS_PER_SEC macro.	#include <stdio.h> 
#include <time.h>
int main(void){int i;
for(i=0; i<10000; i++) printf("%u", clock() ); 
return 0 ;}
char *ctime(const time_t *time);	ctime() returns a pointer to a string of the form 
day month date hours:minutes:seconds year\n\0
given a pointer to the calendar time. The calendar time is generally obtained through a call to time(). ctime() is equivalent to: asctime(localtime(time))
The buffer used by crime() to hold the formatted output string is a statically allocated character array and is overwritten each time the function is called. To save the contents of the string, you need to copy it elsewhere.	
time_t It;
It = time(NULL);
printf( ctime(&lt) );

double difftime(time_t time2, 
time_t time1);	difftime() returns the difference, in seconds, between timel and time2. i.e, time2 – time1. The given program times the number of seconds that it takes for the empty for loop to go from 0 to 500000.	int main(void) { time_t start, end;     long unsigned int t;
        start = time(NULL); 
        for(t=0; t<500000L; t++); end = time(NULL);
        printf("Loop required %f seconds.\n”, difftime(end, start)); 
        return 0; }
time_t time(time_t *systime);	time() returns the system's current calendar time. If the system has no time-keeping mechanism, then -1 is returned.
time() can be called either with a null pointer or with a pointer to a variable of type time_t. The argument will be assigned the calendar time due to using type time_t.	struct tm *ptr; time_t lt;
lt = time(NULL); 
ptr = localtime(&lt);
printf(asctime(ptr))
struct tm *localtime(const time_t *time);	localtime() returns a pointer to the broken-down form of tm structure. The time is represented in local time which is obtained through a call to the time(). This structure statically allocated and is overwritten each call time the function is called. So copy it elsewhere.	struct tm *local;   time_t t;
t = time(NULL); 
local = localtime(&t);
printf("Local'time: %s", asctime(local));
strut tm *gmtime(const time_t *time);	gmtime() returns a pointer to the broken-down form of tm structure. The time is represented in Coordinated Universal Time (i.e., Greenwich Mean Time). The time value is generally obtained through a call to time(). This structure statically allocated and is overwritten each call time the function is called. So copy it elsewhere.	struct tm *gmt;   time_t t;
t = time(NULL); 
gmt = gmtime(&t);
printf("GMT time: %s", asctime(gmt));

