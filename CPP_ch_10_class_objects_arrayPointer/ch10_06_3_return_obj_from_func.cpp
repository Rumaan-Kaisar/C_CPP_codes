
/*  ----------------------    RETURN objects from function    ---------------------- 
    RETURNING objects from functions: 
        Declare the function as returning a class type. 
        Then return an object of that type using the normal return statement.

                return_class_type function_name( any_type obj_1, any_type obj_2, . . . . );    
*/



/* Example 1: Here is an example of a function that returns an object: 
                In this example, input() creates a "local object" called "str" and then reads a string from the keyboard. 
                This string is copied into "str.s" and then str is returned by the function. 
                This object is then assigned to "ob" inside main() when it is returned by the call to input(). 
*/
#include <iostream>
#include <cstring>

class samp {
        char s[80];
    public:
        void show(){ std::cout << s << "\n"; }
        void set(char *str){ strcpy(s, str ); }  
};

// Function input() return an object of type samp
samp input(){ 
    char g[80];     // it is a local variable. However s[80] used in book. Which have no connection with the private variable s[80] in the class samp
    samp str;       // declaring local object str

    std::cout << " Enter a string : ";  
    std::cin >> g;
    str.set(g);     // copying g to str.s
    return str;     // returning object
}


int main(){	
    samp ob;
    ob = input();   // assign returned object to ob
    ob.show();

    return 0;
}




/*  --------    temporary object and destructor    --------
    When an object is "returned by a function", a TEMPORARY OBJECT 
        is automatically created which holds the return value (the object). 
        After the value has been returned, this object is DESTROYED. 
        
    The destruction of this "temporary object" might cause unexpected SIDE EFFECTS in some situations 
        (This problem can be resolved in two ways : 
                using reference
                using copy-constructor.)


    Be careful about "returning objects from functions" if those objects contain "DESTRUCTOR" 
        because the "returned object goes out of scope" 
        as soon as the value is returned to the calling routine.

        For example, if the object returned by the function has a 
            DESTRUCTOR that frees "dynamically allocated memory", that memory will be freed 
            even though the object that is assigned the return value is still using it. 
*/

/* Example 1: memory will be freed even though the object that is 
                assigned the return value is still using it
*/

// ----    rev[08-apr-24]    ----
#include <cstdlib> 					/* we'll use allocation function malloc() and free() */

class samp {char *s;
        public :
            samp() {s="\0";} 						/* "\0" means null */
            ~samp() {if(s) free(s); cout<< "freeing s \n";}  	/* freeing memory */
            void show() { cout << s << "\n"; }
            void set( char *str );  };

            /* load a string */
void samp :: set( char *str ){	s=(char *)malloc(strlen(str)+1); 	/* allocating memory */
if(!s){cout<< "Allocation error \n"; exit(1);}
strcpy(s, str); }

In this case different error arise in different compiler. Here destructor called multiple times (In old complier three times actually). 
1.	First, it is called when the local object str goes out of scope when input() returns. 
2.	The second time ~samp() is called is when the temporary object returned by input() is destroyed. Remember, when an object is returned from a function, an invisible (to you) temporary object is automatically generated which holds the return value. In this case, this object is simply a copy of str, which is the return value of the function. Therefore, destructor is executed. 
3.	Finally, the destructor for object ob, inside main(), is called when the program terminates.

The trouble is that in this situation, the first time the destructor executes, the memory allocated to hold the string input by input() is freed. Thus, not only do the other two calls to samp's destructor try to free an already released piece of dynamic memory, but they destroy the dynamic allocation system in the process, as evidenced by the run-time message "Null pointer assignment." (Depending upon your compiler, you may or may not see this message). 
	The key point to be understood from this example is that when an object is returned from a function, the temporary object used to effect the return will have its destructor function called. Thus, you should avoid returning objects in which this situation is harmful. (However, it is possible to use a copy constructor to manage this situation.)


