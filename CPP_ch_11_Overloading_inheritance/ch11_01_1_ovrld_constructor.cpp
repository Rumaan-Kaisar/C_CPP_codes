
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


    Initializing dynamically allocated array: 
        Overloading a class's constructor function allows us to initialize dynamically allocated array. 
        We know that a dynamic array cannot be initialized. 

        Thus, if the class contains a constructor that takes an initializer, 
            you must include an overloaded version that takes no-initializer.
*/




/* Example 1: In the following program, o1 is given an initial value, but o2 is not. 
                Either removing PARAMETERLESS-constructor  or PARAMETERIZED-constructor will cause compile-time error.
                Because there is no match for an initialized object or non-initialized object.
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









/*  



	Overloading constructor functions is to allow us to select the most convenient method of initializing an object. For example following overloads the date() constructor two ways. One as a character string. Another passed as three integers.

#include<cstdio> // included for sscanf() 
class date{int day, month, year ;
  public : date( char *str );
           date( int m, int d, int y){
day = d; month = m; year = y;}
     void show(){
   cout <<month<<'/'<<day<<'/'<<year<<'\n';}
};	date :: date( char *str ){
sscanf(str, "%d%*c%d%*c%d", &month, &day, &year);}
int main(){
   date sdate("12/31/99");		// using string 
   date idate (12, 31, 99) ; 	// using integers 
	sdate.show();
	idate.show();
return 0;}


	Initializing dynamically allocated array: Overloading a class's constructor function allows us to initialize dynamically allocated array. We know that a dynamic array cannot be initialized. Thus, if the class contains a constructor that takes an initializer, you must include an overloaded version that takes no-initializer.

 For example, here is a program that allocates an object array dynamically:



class myclass{ int x;
	public :
myclass() {x=0;}     // no initializer 
myclass(int n) {x=n;}  // initializer 
int getx() {return x;}
};	int main(){	myclass *p;
	myclass ob(10) ; 	    // initialize single variable 
	p = new myclass[10];    // can 't use initializers here 
if(!p){cout << "Allocation error \n"; return 1;}
int i;
for(i=0; i <10; i++) p[i]=ob;  // initialize all elements to ob 
for (i=0; i<10; i++){
	    cout <<"p["<<i<<"]: "<<p[i].getx()<<'\n';}
return 0;}
Without overloaded myclass() that has no-initializer, "new" would've generated a compile-time error.

Note
[1]	The C library function sscanf() of "stdio.h" reads formatted input from a string.
Declaration: 	int sscanf(const char *str, const char *format, ...)
Parameters :  	str - This is the C string that the function processes as its source to retrieve the data.
format - This is the C string that contains one or more of the items: Whitespace character, Non-whitespace character and Format specifiers.

[2]	It is possible to overload a constructor as many times as you want but, 
	Doing so excessively has a destructing effect on the class. 
	It is best to overload a constructor to accommodate only those situations that are likely to occur frequently. 



*/  


