
/*  ------------    friend functions    ------------
    friend functions:
        friend functions have access to the 'private members' of a class 
            without that function actually being a member of that class. 

        A friend is not a member of a class but still has access to its private elements.


    friend functions are useful for 
        [1]	Operator overloading 
        [2]	Creation of certain types of "I/O functions"
        [3]	Need one function to have access to the private members of two or more different classes.


    friend keyword:
        A friend function is defined as a "regular, nonmember function". 
        However, inside the class declaration for which it will be a friend, 
            its PROTOTYPE is also included, prefaced by the keyword "friend".


    FRIEND is not INHERITED
        Remember: A friend function is not inherited. 
        i.e. when a base class includes a friend function, that friend-function is not a friend of a derived (child) class.

    A friend function can be friends with "MORE than one CLASS"
        A friend function occurs in two different types of classes when 
            the classes have some quantity in common that needs to be compared. 

    A function can be a "MEMBER-function" of one class and a "FRIEND-function" of another.
*/




/* Example 1: Following demonstrates the friend function 
                Because isfactor() is a friend of myclass, isfactor() has access to its private members. 
                This is why, within isfactor(), it is possible to directly refer to 'ob.n' and 'ob.d'.
*/
#include <iostream>
class myclass{ 
        int n, d;
    public:
        myclass(int i, int j){
            n = i; 
            d = j;
        }

    // declare a friend of myclass
    friend int isfactor(myclass ob);
};


/* Here is friend function definition. 
    It returns true if d is a factor of n. 
    Notice that the keyword friend is not used in the definition of isfactor() 
    Keyward 'friend' only used in "class definition"
*/
int isfactor(myclass ob) { 
    if( !(ob.n % ob.d) ) return 1;
    else return 0;
} 

int main(){
    myclass ob1(10, 2), ob2(13, 3);

    if(isfactor(ob1)) std::cout << "2 is a factor of 10 \n";
    else std::cout << "2 is not a factor of 10 \n";

    if(isfactor(ob2)) std::cout << "3 is a factor of 13 \n";
    else std::cout << "3 is not a factor of 13 \n";

    return 0;
}




/*  ------------    Restrictions    ------------

    Note that a friend function is not a member of the class for which it is a friend. 
        Thus, it is not possible to call a friend function by using an object name and 
            a class member access operator (a dot "." or an arrow "->" ). 
        Friends are called just like "regular functions". For example, given the preceding example, this statement is wrong: 
                ob1.isfactor(); // wrong ; isfactor() is not a member function



    Although a friend function can access private elements of the class
        it can only access them through an object of that class. 

        i.e. unlike a member function of myclass, which can refer to n or d directly,
            a friend can access these variables "only in conjunction with an object" 
            that is declared within or passed to the friend function.

        like "isfactor(ob1)" or "isfactor(ob2)"



    Inside the friend function, it is meaningless to "refer to a private member without reference to a specific object". 

                    int isfactor(myclass ob) { 
                        if( !(ob.n % ob.d) ) return 1;
                        else return 0;
                    }

        A friend function is not linked to any object. 
        It simply is granted access to the private elements of a class. 



    Because friends are not members of a class, 
        they will typically be passed one or more objects of the class for which they are friends.

        For example: isfactor() without being friend it would not be able to access ob.d or ob.n 
            since n and d are private members of myclass.

*/

 


/*  ----------------    Forward declaration    ----------------
    Forward declaration:
        It's a way to tell the compiler about a 'class name' without actually declaring it. 
        Use following format before the class name is first used

                class class_name;

        Forward declaration also called "forward reference"

        For example, in the following program, the forward declaration is:
                class truck ; 
            Because sp_greater() takes parameters of both the "car" and the "truck" classes, 
            it is logically impossible to declare both before including sp_greater() in either.
*/




/* Example 2 : A friend function occurs in two different types of classes when the classes have some quantity in common that needs to be compared. 
                following program creates a class called "car" and a class called "truck", 
                each containing, as a private variable, the "speed" of the vehicle it represents.

                In this case we need forward declaration (also called forward reference). 
                    Because sp_greater() takes parameters of both the "car" and the "truck" classes, 
                    it is logically impossible to declare both before including sp_greater() in either.  
                    
                Now "truck" can be used in the friend declaration of sp_greater() without generating a compile-time error.
*/
#include <iostream>

class truck ; // a forward declaration

class car { 
        int passengers;
        int speed;
    public:
        car(int p, int s){ passengers = p; speed = s; }
        friend int sp_greater(car c, truck t); 
        // this friend function uses 'car' and 'truck' type. That's why forward declaration needed.
};

class truck { 
        int weight;
        int speed;
    public:
        truck(int w, int s) { weight = w; speed = s; }
        friend int sp_greater(car c, truck t);
};

/*
    Return positive if car speed faster than truck.
    Return 0 if speeds are the same.
    Return negative if truck speed faster than car.
*/
int sp_greater(car c, truck t){ 
    return (c.speed - t.speed); 
}


int main(){ 
    int t;
    car c1(6, 55) , c2(2, 120);
    truck t1(10000 ,55), t2(20000 ,72);

    std::cout << " Comparing c1 and t1 :\n";
    t = sp_greater(c1 , t1);
    if(t<0) std::cout << " Truck is faster .\n";
    else if(t==0) std::cout << "Speed is the same .\n";
    else std::cout << "Car is faster .\n";

    std::cout << " Comparing c2 and t2 :\n";
    t = sp_greater(c2 , t2);
    if(t<0) std::cout << " Truck is faster .\n";
    else if(t==0) std::cout << "Speed is the same .\n";
    else std::cout << "Car is faster .\n";

    return 0;
}





/*  ----------------    scope resolution operator '::' with friend    ----------------
    Use of scope resolution operator with friend:
        To make a friend from other class
        We have to use the scope resolution operator '::' to declare 
            a "friend function" to a class which is actually a "member-function" of another class.  
        
    For example, following is the preceding example rewritten so that 
        sp_greater is a "member of car" and a "friend of truck":

    TO fully specify a class member is that:
        "class name" followed by '::' followed by the member name 

                class_name :: member_name
*/




/* Example 3: (Scope resolution operator '::' with friend)
                Following is the preceding example rewritten so that 
                sp_greater is a "member of car" and a "friend of truck": */

#include <iostream>

class truck ; // a forward declaration

class car { 
        int passengers;
        int speed;
    public:
        car(int p, int s){ passengers = p; speed = s; }
        int sp_greater(truck t); 
        // this member function of 'car' is also a friend-function of 'truck' type. 
        // That's why forward declaration needed.
};

class truck { 
        int weight;
        int speed;
    public:
        truck(int w, int s) { weight = w; speed = s; }
        // notice the new use of scope resolution operator '::' to make a friend of other clsass's member
        friend int car :: sp_greater( truck t);
        // friend int sp_greater(truck t); Need to apply '::'
};

/*
    Return positive if car speed faster than truck.
    Return 0 if speeds are the same.
    Return negative if truck speed faster than car.
*/
int car :: sp_greater(truck t){ 
    return (speed - t.speed); // notice the direct access of car's "speed"
    // Since sp_greater() is member of car , only a truck object must be passed to it.
}


int main(){ 
    int t;
    car c1(6, 55) , c2(2, 120);
    truck t1(10000 ,55), t2(20000 ,72);

    std::cout << " Comparing c1 and t1 :\n";
    // t = sp_greater(c1 , t1);
    t = c1.sp_greater(t1);  // evoke as member function of car
    if(t<0) std::cout << " Truck is faster .\n";
    else if(t==0) std::cout << "Speed is the same .\n";
    else std::cout << "Car is faster .\n";

    std::cout << " Comparing c2 and t2 :\n";
    // t = sp_greater(c2 , t2);
    t = c2.sp_greater(t2);  // evoke as member function of car
    if(t<0) std::cout << " Truck is faster .\n";
    else if(t==0) std::cout << "Speed is the same .\n";
    else std::cout << "Car is faster .\n";

    return 0;
}


/*  Notice the new use of the scope resolution operator "::" 
        as it occurs in the "friend declaration" within the truck class declaration. 
        In this case, it is used to tell the COMPILER that the function sp_greater() is a "member of the car class".

    However a slight change appear inside main() which need to compute t ( because sp_greater is a member of car )
            t = c1.sp_greater(t1); // evoke as member function of car
                and
            t = c2.sp_greater(t2); // evoke as member function of car


    When referring to a member of a class, it is never wrong to fully specify its name. 
        However, it is redundant, and seldom used. Eg:
                t = c1.sp_greater(t1);
        Can be written using the scope resolution operator and the "class name car" like this:      
                t = c1.car :: sp_greater(t1);
*/




/* Example 4: Imagine a situation in which two classes, called 'pr1' and 'pr2', shown here, "share one printer".
                Further, imagine that 
                    other parts of your program need to know when the printer "is in use by an object" of either of these two classes. 

                Create a function called inuse() that returns true when the printer is being used by either and false otherwise. 

                Make this function a friend of both pr1 and pr2.


                class pr1 {
                        int printing;
                        // ...
                    public:
                        pr1(){ printing = 0; }
                        void set_print(int status){ printing = status ; }
                        // ...
                };

                class pr2 {
                        int printing;
                        // ...
                    public:
                        void set_print(int status){ printing = status ; }
                        // ...
                };
*/

#include <iostream>

class pr2 ; // forward declaration

class pr1 {
        int printing;
        // ...
    public:
        pr1(){ printing = 0; }
        void set_print(int status){ printing = status ; }
        // ...
        friend int inuse( pr1 o1, pr2 o2); // friend function
};


class pr2 {
        int printing;
        // ...
    public:
        pr2(){ printing = 0; }
        void set_print(int status){ printing = status ; }
        // ...
        friend int inuse( pr1 o1, pr2 o2); // friend function
};


// Return 'true' if printer is in use .
int inuse( pr1 o1, pr2 o2) {
    if(o1.printing || o2.printing) return 1;
    else return 0;
}


int main(){
    pr1 p1;
    pr2 p2;

    if(!inuse(p1 , p2)) std::cout << " Printer idle \n";

    std::cout << " Setting p1 to printing ...\ n";
    p1.set_print(1);

    if(inuse(p1 , p2)) std::cout << " Now printer in use .\n";
    
    std::cout << " Turn off p1 ...\ n";
    p1.set_print(0);

    if(!inuse(p1, p2)) std::cout << " Printer idle \n";
    
    std::cout << " Turn on p2 ...\ n";
    p2.set_print(1);

    if( inuse (p1 , p2)) std::cout << " Now printer in use .\n";

    return 0;
}




/* Example 5: What is a friend function 

                ANS:
                    A friend is a non-member function that is granted access 
                        to the "private members" of the class for which it is a friend.
*/




/* Example 6: Using the strtype class shown in [ch10_06_1_assign_obj.cpp: Example 4], 
                add a friend function that takes as an argument "a pointer to an object" of type 'strtype' and 
                returns a pointer to the string pointed to by that object. 

                (That is, have the function return p.) 
                Call this function get_string().

                You must exercise some CARE when assigning one object to another. 
                For example, here is the "strtype class" developed in parameterized constructor.
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

// class definition
class strtype{
        char *p;
        int len;
    public:
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        void show();
        friend char * get_string(strtype *ob);      // returns a pointer of type 'strtype'
};

// constructor: Initialize a string object with parameter.
strtype::strtype(char * ptr){
    len = strlen(ptr);      // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    if(!p){     // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 
    strcpy(p, ptr);     // copy string to p
}

// destructor: Free memory when destroying string object .
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}

void strtype::show(){
    std::cout << p << " - length : " << len;
    std::cout << "\n";
}

// friend function definition
char *get_string(strtype *ob){
    // notice the use of arrow operator '->'
    return ob -> p;     // returning pointer to the object p
}


int main(){
    // initialize with string, as parameters
    strtype s1(" This is a test .");
    char *s;

    s1.show();
    // get pointer to string
    s = get_string(&s1);
    std::cout << " Here is string contained in s1: ";
    std::cout << s << "\n";

    return 0;
}

