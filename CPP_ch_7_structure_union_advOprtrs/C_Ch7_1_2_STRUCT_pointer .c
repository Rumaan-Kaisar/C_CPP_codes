
// --------------------    pointer to a STRUCTURE    --------------------

struct s_type {
    int i; 
    char str[80];
} s, *p;

p = &s;



/* 
    It's the same way that we declare a pointer to any other type.
        "p", is a pointer to structures of type 's_type'.
        Then, 	p = &s; 	assigns to 'p' the address of 's'.


    --------------------    ARROW OPERATOR "->"    --------------------

    cannot use the dot to access INDIVIDUAL ELEMENT of 's' using 'p':
        To access an individual element of 's' using 'p' you cannot use the dot operator. 
        Instead, you must use the arrow operator "->" as shown in the following

            p->i = 1

        This statement assigns the value 1 to element i of s through p. 


    arrow operator : 
        The arrow operator is formed using a minus sign followed by a greater-than sign. There must be no spaces between the two.


    Why use pointer to structure : 
        C passes structures to functions in their entirety. 
            If the structure is very large, the program's execution speed becomes slow. 
            
        For this reason, we want to pass a 'pointer to a structure' instead of passing the structure itself.


    Remember:
        When accessing a member using a structure variable, use the dot operator.
        When accessing a member using a pointer, use the arrow operator. 

*/


    --------------------    Application of structure-pointer  : Date and Time functions     --------------------

 
One very useful application of structure pointers is found in C's time and date functions. Several of these functions use a pointer to the current time and date of the system.
	The time and date functions require the header TIME. H for their prototypes. This header file also defines four types and two macros. 
	The type time_t is able to represent the system time and date as a long integer. This is called the calendar time. time_t represents the time and date of the system in an encoded implementation specific internal format. To obtain the calendar time of the system, you must use the time() function, whose prototype is:
time_t time(time_t *systime) ;
The time() function returns the encoded calendar time of the system or -1 if no system time is available. It also places this encoded form of the time into the variable pointed to by systime. However, if systime is null, the argument is ignored.
	The structure type tm holds date and time broken down into its elements. The tm structure is defined as shown here:

struct tm {	int tm_sec; 		/* seconds, 0-61 */
int tm_min; 		/* minutes. 0-59 */
int tm_hour; 		/* hours, 0-23 */
int tm_mday; 		/* day of the month, 1-31*/
int tm_mon; 		/* months since Jan, 0-11 */
int tm-year; 		/* years from 1900 */
int tm_wday; 		/* days since Sunday, 0-6 */
int tm_yday; 		/* days since Jan 1, 0-365 */
int tm_isdst;		/* Daylight Saving Time indicator */
} ;
The value of tm_isdst will be positive if Daylight Saving Time is in effect, 0 if it is not in effect, and negative if there is no information available. When the date and time are represented in this way, they are referred to as broken-down time.

	Since the calendar time is represented using an implementation specified internal format, you must use another of C's time and date functions to convert it into a form that is easier to use.  Called localtime(). Its prototype is

struct tm *localtime(time_t *systime);

The localtime() function returns a pointer to the broken-down form of systime. The structure that holds the broken-down time is internally allocated by the compiler and will be overwritten by each subsequent call.

This program demonstrates time() and localtime() by displaying the current time of the system:

#include <stdio.h>
#include <time.h>
int main(void)
{struct tm *systime;
 time_t t;
 t = time(NULL);
 systime = localtime(&t);
 printf("Time is %.2d:%.2d:%.2d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
 printf("Date: %.2d/%.2d/%.2d", systime->tm_mon+1, systime->tm_mday, systime->tm_year);
 return 0;}

Here is sample output produced by this program: 	Time is 10:32:49
Date: 03115/97
	The type c1ock_t is defined the same as time_t. The header file also defines size_t.
	The macros defined are NULL and CLOCKS_PER_SEC.
	Another of C's time and date functions is called gmtime( ) . Its prototype is
struct tm *gmtime(time_t *time);
The gmtime() function works exactly like localtime() , except that it returns the Coordinated Universal Time (which is, essentially, Greenwich Mean Time) of the system.
