
/*  ------------------------    Overloading CONSTRUCTOR    ------------------------
    Overloading CONSTRUCTOR:
        It's possible overload a class's CONSTRUCTOR
        But "not possible" to overload a DESTRUCTOR


    Reasons to overload constructor: 
        1. to gain flexibility, 
        2. to support arrays
        3. to create "copy constructors"

        the first two of these are discussed in this section.
 



    --------    why overload constructor    -------

    compile-time error for no matching constructor:
        Attempting to create an object "without a matching constructor" 
            (either with parameters or without) results in a COMPILE-TIME ERROR.
            That's why overloaded constructor functions are so common in C++


    Providing an object with or without initialization: 
        The most frequent use of overloaded constructor functions is to offer the option of either initializing an object or not. 
        By providing both a "PARAMETERIZED" and a "PARAMETERLESS" constructor, 
            your program allows the creation of objects that "can be initialized" or "left uninitialized "as needed. 


    Enabling both "single objects" and "object arrays":
        Overloaded constructors enable both individual objects and object arrays in a program. 
        While initializing a single variable is common, initializing an array is less so. 
        Therefore, we include constructors for both scenarios. For example, both of these declarations are valid in "Example 1": 
                myclass ob(10);
                myclass ob[5];


    It offers a choice for the most convenient object initialization:
        Overloading constructor functions allows us to choose the most convenient method for initializing an object. 
        For example, we can overload a constructor in two ways: 
            one that accepts a character string and 
            another that accepts three integers.


    Provide dynamically allocated array: 
        You need to overload a class's constructor when creating a dynamic array of that class. 
        Since dynamic arrays can't be initialized, 
            if the class has a constructor with an initializer, 
            you must also provide one without an initializer.


    It is possible to overload a constructor as many times as you want but, 
        Doing so excessively has a destructing effect on the class. 
        It's best to overload a constructor only for common scenarios

*/




/* Example 1: In the following program, o1 is given an initial value, but o2 is not. 
                Either removing PARAMETERLESS-constructor  or PARAMETERIZED-constructor will cause compile-time error.
                Because there is no match for an initialized object or non-initialized object.

                Note: 
                    Constructor overloading also allow both individual objects and arrays of objects to occur within a program. 
                    We know that it is fairly common to "initialize a single variable", but it is not as common to initialize an array.

                    For example, both of these declarations are valid: 
                                    myclass ob(10);
                                    myclass ob[5];
*/

#include <iostream>

class myclass{
        int x;
    public: 
        // overload constructor two ways 
        myclass() {x=0;}// no initializer
        myclass(int n) {x=n;} // initializer
        int getx() { return x; }   
};	


int main(){
    myclass o1(10);  // declare with initial value
    myclass o2;     // declare without initializer

    std::cout << "o1: " << o1.getx() << '\n';
    std::cout << "o2: " << o2.getx() << '\n';

    return 0;
}




// --------    initialized and non-initialized arrays    --------

/*  Example 2: We can use both parameterized and parameterless constructors to create initialized and non-initialized arrays. 
                For example, the following program with previous example's class (i.e. Example 1), 
                declares two arrays of type myclass; one is initialized and the other is not. 

                once you have defined both parameterized and parameterless constructors you
                    can use them to create initialized and non-initialized arrays.

                Here, all elements of o1 are set to 0 by the constructor function. 
                The elements of o2 are initialized as shown in the program.
*/

#include <iostream>

class myclass{
        int x;
    public: 
        // overload constructor two ways 
        myclass() {x=0;}// no initializer
        myclass(int n) {x=n;} // initializer
        int getx() { return x; }   
};	


int main(){
    myclass o1[10];  // non-initialized array
    myclass o2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // initialized array
    int i; 
    
    // Output both array
    for(i=0; i <10; i++){
        std::cout <<"o1["<<i <<"]: "<< o1[i].getx()<<'\n';
        std::cout <<"o2["<<i <<"]: "<< o2[i].getx()<<'\n';
    }

    return 0;
}




/* Example 3: Constructor overloading offers a choice for the most convenient object initialization.
                Following overloads the date() constructor two ways: 
                            One as a character string. 
                            Another passed as three integers. 

                    You're free to use the version that best fits the situation. 
                    For example, 
                        use the "string version" for user input and 
                        the "three-integer version" for internal calculations.


                ------------  sscanf()  ------------

                The C library function sscanf() from the "stdio.h" header reads formatted input from a string.

                Declaration:
                                int sscanf(const char *str, const char *format, ...);

                Parameters:
                            str:    This is the C string from which the function retrieves the data.
                            format: This is the C string that contains one or more items, such as:
                                        Whitespace characters
                                        Non-whitespace characters
                                        Format specifiers (e.g., %d, %s, etc.) to specify the types of data to be extracted.

*/

#include <iostream>
#include <cstdio> // contains sscanf() 

class date{
        int day, month, year;
    public:
        // following constructor reads character string
        date(char *str );
        // following constructor reads 3 integers
        date(int m, int d, int y){
            day = d; 
            month = m; 
            year = y;
        }
        void show(){std::cout <<month<<'/'<<day<<'/'<<year<<'\n';}
};

date :: date(char *str){
    sscanf(str, "%d%*c%d%*c%d", &month, &day, &year);
}


int main(){
    date sdate("12/31/99");     // construct date object using string 
    date idate(12, 31, 99);     // construct date object using integers 

    sdate.show();
    idate.show();

    return 0;
}




/* Example 4: Since a dynamic array cannot be initialized. 
                Thus, if the class contains a constructor that takes an initializer, 
                    you must include an overloaded version that takes no-initializer.

                Following program allocates an object array dynamically.

                Without overloaded myclass() that has no-initializer, 
                    "new" would've generated a compile-time error.
*/  
#include <iostream>

class myclass{ 
        int x;
    public:
        // overload constructor two ways
        myclass() {x=0;}    // no initializer 
        myclass(int n) {x=n;}   // initializer 
        int getx() {return x;}
};	

int main(){	
    myclass *p;
    myclass ob(10);    // initialize single variable 

    p = new myclass[10];    // can't use initializers here 
    if(!p){
        std::cout << "Allocation error \n"; 
        return 1;
    }
    
    int i;
    for(i=0; i <10; i++) p[i]=ob;   // initialize all elements to ob 
    for (i=0; i<10; i++) std::cout <<"p["<<i<<"]: "<<p[i].getx()<<'\n';

    return 0;
}




/* Example 5: Given this partially defined class

                    class strtype{
                            char *p;
                            int len;
                        public :
                            char *getstring { return p; }
                            int getlength() { return len; }
                    };

                add two constructor functions. 


                First constructor take no parameters.
                    Allocate 255 bytes of memory (using new), 
                    Initialize that memory as a null string, and
                    Give 'len' a value of 255.


                Other constructor take two parameters: 
                        i.  the string to use for initialization and the other is the 
                        ii. number of bytes to allocate.
                    Allocate the specified amount of memory and copy the string to that memory.


                Perform all necessary boundary checks and apply those to a short program.
*/



1. # include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
int len ;
public :
strtype ();
strtype ( char *s, int l);
char * getstring () { return p; }
int getlength () { return len; }
};
strtype :: strtype ()
{
p = new char [255];
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
} *
p = '\0'; // null string
len = 255;
}
strtype :: strtype ( char *s, int l)
{
if( strlen (s) >= l)
{
cout << " Allocating too little memory !\n";
exit (1) ;
} p
= new char [l];
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, s);
len = l;
}
465TEACH YOURSELF
C++
int main ()
{
strtype s1;
strtype s2(" This is a test ", 100) ;
cout << "s1: " << s1. getstring () << " - Length : ";
cout << s1. getlength () << ’\n’;
cout << "s2: " << s2. getstring () << " - Length : ";
cout << s2. getlength () << ’\n’;
return 0;
}






/* Example 6: In "Example 7" of "ch10_01_2_constructor_destructor.cpp", we created a stopwatch emulation. 

                Now we expand our solution so that the stopwatch class provides both:
                    i.  a parameterless constructor (as it does already) and 
                    ii. an overloaded version that accepts the "system time" in the form returned by the standard function clock().


                Create a class called 'stopwatch' that emulates a stopwatch that keeps track of elapsed time. 
                
                Use a CONSTRUCTOR to initially set the elapsed time to 0. 
                
                Provide two member functions called start() and stop() that turn on and off the timer, respectively. 
                Include a member function called show() that displays the elapsed time. 
                
                Also, have the DESTRUCTOR function automatically display elapsed time when a stopwatch object is destroyed. 
                (To simplify, report the time in seconds.) 
*/

// Stopwatch emulator
#include <iostream>
#include <ctime>


class stopwatch {
        double begin, end;

    public:
        stopwatch();
        ~stopwatch();
        void start();
        void stop();
        void show();
};




stopwatch :: stopwatch(){
    begin = end = 0.0;
}


stopwatch ::~ stopwatch(){
    std::cout << " Stopwatch object being destroyed ... ";
    show();
}


void stopwatch::start(){
    begin = (double)clock() / CLOCKS_PER_SEC;
}


void stopwatch::stop(){
    end = (double)clock() / CLOCKS_PER_SEC;
}


void stopwatch::show(){
    std::cout << " Elapsed time : " << end - begin;
    std::cout << "\n";
}


int main(){
    stopwatch watch ;
    long i;

    watch.start();
    for(i =0; i<320000; i++); // time a for loop
    watch.stop();
    watch.show();

    return 0;
}

/* 
    // another for loop to test
        for(i =0; i<3200000000; i++){
            if(!(i%60000)) {
                watch.stop();
                watch.show();
            }
        }
*/





2. // Stopwatch emulator
# include <iostream >
# include <ctime >
using namespace std ;
class stopwatch
{
double begin , end ;
public :
stopwatch ();
stopwatch ( clock_t t);
~ stopwatch ();
void start ();
void stop ();
void show ();
};
stopwatch :: stopwatch ()
{
begin = end = 0.0;
}
stopwatch :: stopwatch ( clock_t t)
{
begin = ( double ) t / CLOCKS_PER_SEC ;
end = 0.0;
}
stopwatch ::~ stopwatch ()
{
cout << " Stopwatch object being destroyed ... ";
show ();
}
void stopwatch :: start ()
{
begin = ( double ) clock () / CLOCKS_PER_SEC ;
}
void stopwatch :: stop ()
{
end = ( double ) clock () / CLOCKS_PER_SEC ;
}
void stopwatch :: show ()
{
cout << " Elapsed time : " << end - begin ;
cout << "\n";
}
int main ()
{
stopwatch watch ;
long i;
watch . start ();
for (i =0; i <320000; i++); // time a for loop
watch . stop ();
watch . show ();
// create object using initial value
stopwatch s2( clock ());
for (i =0; i <250000; i++); // time a for loop
s2. stop ();
s2. show ();
return 0;
}

