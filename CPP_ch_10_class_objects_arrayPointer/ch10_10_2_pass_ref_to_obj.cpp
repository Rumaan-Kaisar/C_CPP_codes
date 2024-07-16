
/*  ----------------    pass the object by reference    ----------------

    We know when an object is passed to a function by 
        use of the default "call-by-value parameter-passing" mechanism, a copy of that object is made.

    Although the parameter's constructor function is not called, 
        its destructor function is called when the function returns

        this can cause serious problems in some instances-
            For example: when the destructor frees dynamic memory.

        There is two way to solve this: 
            1. pass an object by reference
            2. use of copy constructors (discussed in Next chapter: Function overloading)



    Resolving problem of execution of "copy's destructor function" during function return
            Recall "ch10_06_2_pass_obj_to_func.cpp" and "ch10_06_3_return_obj_from_func.cpp"

        When you pass the object by REFERENCE, "no copy is made",
            so its destructor isn't called during function returns. 
        
        Remember: 
            that changes made to the object inside the function "affect the object" used as the argument.


        Note: --------    Passing by Pointer vs. Reference    --------
            It is crucial to understand that a reference is not a pointer. 
            
            Therefore, when an object is passed by reference, 
                the member access operator remains the dot (.), not the arrow (->).

            Both pointers and references allow changes made inside a function 
                to affect the original object used as the argument.

            When using a POINTER, you must DEREFERENCE it to access or modify the object.
            When using a REFERENCE, you can access or modify the object DIRECTLY.

*/




/* Example 1: Using REFERENCES resolvs problem of execution of "copy's destructor function" during function return */

// (version 1) call-by-value parameter-passing mechanism
#include <iostream>

// class with constructor and destructor
class myclass {	
        int who ;
    public: 
        myclass(int n) { 
            who = n;
            std::cout << " Constructing " << who << "\n";
        }
        ~myclass(){ std::cout << " Destructing " << who << "\n"; }
        int id() { return who; }	
};

// t is passed by value
void f(myclass t){
    std::cout << " Received" << t.id() << "\n"; 
}


int main(){	
    myclass x(1) ;
    
    f(x);
    
    return 0;
}


/*  Notice: destructor called twice

 Constructing 1
 Received1
 Destructing 1
 Destructing 1
*/




// (version 2) call-by-reference parameter-passing mechanism
#include <iostream>

// class with constructor and destructor
class myclass {	
        int who ;
    public: 
        myclass(int n) { 
            who = n;
            std::cout << " Constructing " << who << "\n";
        }
        ~myclass(){ std::cout << " Destructing " << who << "\n"; }
        int id() { return who; }	
};

// Now t is passed by reference
void f(myclass &t){  
    std::cout << "Received" << t.id() << "\n"; // still "." used
}


int main(){	
    myclass x(1) ;

    f(x);
	
    return 0;
}

/*  Notice: destructor called once

 Constructing 1
 Received1
 Destructing 1
*/




/* Example 2: What is wrong with the following program? 
                Show how it can be fixed by using a reference parameter.
                Recall: ch10_09_3_more_new_delete.cpp
*/
// This program has an error .
#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
    public:
        strtype(char *s);
        // following frees dynamic memory using delete, 
        // by calling DESTRUCTOR function for "each element" in the array
        ~strtype(){ delete [] p; }
        char *get(){ return p; }
};

strtype :: strtype(char *s){
    int leN;
    leN = strlen(s) +1;
    p = new char [leN];
    if(!p){
        std::cout << " Allocation error \n";
        exit(1);
    }
    strcpy(p, s);
}

void show(strtype x){
    char *s;
    s = x.get();
    std::cout << s << "\n";
}


int main(){
    strtype a(" Hello "), b(" There ");

    show(a);
    show(b);

    return 0;
}



/* ans: ERROR for double free memory 

        In the above program, the object is passed to show() "by value". Thus, a copy is made.

        When show() returns, the copy is destroyed and its destructor is called. 
            This causes "p" to be released, 
            But the memory pointed to it is still needed by the arguments to show().

        Here is a corrected version that uses a reference parameter to 
            prevent a copy from being made when the function is called:
*/

// This program is now fixed .

#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
    public:
        strtype(char *s);
        // following frees dynamic memory using delete, 
        // by calling DESTRUCTOR function for "each element" in the array
        ~strtype(){ delete [] p; }
        char *get(){ return p; }
};

strtype :: strtype(char *s){
    int leN;
    leN = strlen(s) +1;
    p = new char [leN];
    if(!p){
        std::cout << " Allocation error \n";
        exit(1);
    }
    strcpy(p, s);
}

// Fix by using a reference parameter.
void show(strtype &x){
    char *s;
    s = x.get();
    std::cout << s << "\n";
}


int main(){
    strtype a(" Hello "), b(" There ");

    show(a);
    show(b);

    return 0;
}




