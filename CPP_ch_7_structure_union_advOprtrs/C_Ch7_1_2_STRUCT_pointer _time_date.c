
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


    Remember use of "." and "->":
        When accessing a member using a structure variable, use the dot operator.
        When accessing a member using a pointer, use the arrow operator. 




    --------------------    Application of structure-pointer  : Date and Time functions     --------------------

    Several of C's TIME and DATE functions use a pointer to the "current time and date of the system"
        The time and date functions require the header <TIME.H> for their prototypes. This header file also defines 'four types' and 'two macros'. 

    time_t:
        The type "time_t" is able to represent the system time and date as a long integer. This is called the "CALENDAR TIME". 
        'time_t' represents the time and date of the system in an encoded implementation specific internal format. 
        
        time():
            To obtain the CALENDAR TIME of the system, you must use the time() function, whose prototype is:
    
                    time_t time(time_t *systime) ;

            time() returns the encoded CALENDAR TIME of the system or -1 if no system time is available. 
                It also places this encoded form of the time into the variable pointed to by systime. 
                However, if systime is null, the argument is ignored.



    tm:
    The following structure type 'tm' holds date and time broken down into its elements. 
        This tm structure is defined inside <TIME.H>
        The tm structure is defined as shown here:

            struct tm {	
                int tm_sec; 		// seconds, 0-61 
                int tm_min; 		// minutes. 0-59 
                int tm_hour; 		// hours, 0-23 
                int tm_mday; 		// day of the month, 1-31
                int tm_mon; 		// months since Jan, 0-11 
                int tm-year; 		// years from 1900 
                int tm_wday; 		// days since Sunday, 0-6 
                int tm_yday; 		// days since Jan 1, 0-365 
                int tm_isdst;		// Daylight Saving Time indicator 
            } ;

        The value of tm_isdst will be positive if Daylight Saving Time is in effect, 0 if it is not in effect, and negative if there is no information available. 
        When the date and time are represented in this way, they are referred to as "BROKEN-DOWN TIME".



    localtime():
        Since the CALENDAR TIME is represented using an implementation specified internal format, 
            you must use another of C's time and date functions to convert it into a form that is easier to use.  
            Called localtime(). Its prototype is

                struct tm *localtime(time_t *systime);

        localtime() returns a pointer to the "BROKEN-DOWN-FORM" of systime. 
            The structure that holds the broken-down time is internally allocated by the compiler and will be overwritten by each subsequent call.




    clock_t : 
        The type clock_t is defined the same as time_t. The header file also defines size_t.


    macros : 
        The macros defined are NULL and CLOCKS_PER_SEC.


    gmtime() : 
        Another of C's time and date functions is called gmtime() . Its prototype is

            struct tm *gmtime(time_t *time);

        The gmtime() function works exactly like localtime(), except that it returns the 
            Coordinated Universal Time (which is, essentially, GREENWICH MEAN TIME) of the system.

*/




/* Example 1: Following program demonstrates time() and localtime() by displaying the current time of the system: */

#include <stdio.h>
#include <time.h>
int main(void) {
    struct tm *systime;
    time_t t;
 
    t = time(NULL);
    systime = localtime(&t);
    
    printf("Time is %.2d:%.2d:%.2d\n", systime->tm_hour, systime->tm_min, systime->tm_sec);
    printf("Date: %.2d/%.2d/%.2d", systime->tm_mon+1, systime->tm_mday, systime->tm_year);

    return 0;
}

// Here is sample output produced by this program: 	Time is 10:32:49
// Date: 03/15/97
// use following if year is 123 or 100+
// printf("Date: %.2d/%.2d/%d", systime->tm_mon+1, systime->tm_mday, systime->tm_year-100);




/* Example 2: The following program illustrates how to use a pointer to a structure */
#include <stdio.h>
#include <string.h>

struct s_type {
    int i;
    char str[80];
};

struct s_type s, *p;

int main(void){
    p = &s;

    // assigning values using pointer p
    s.i = 10;   /* this is functionally the same */
    p->i = 10;  /* as this */
    strcpy(p->str, "I like structures.");

    printf("%d %d %s", s.i, p->i, p->str);

    return 0;
}




/* Example 3: Following program fragment incorrect.
                Since p is a 'pointer' to a 'structure', you must use the ARROW OPERATOR "->", 
                not the dot operator ".", to access a member.
*/

struct s_type {
    int a; 
    int b;
} s, *p;

int main(void){
    p = &s;
    p.a = 100   // WRONG
    p->a = 100  // CORRECT
    .
    .
    .
}
p = &s;

