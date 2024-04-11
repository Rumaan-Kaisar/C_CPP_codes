
/*  ----------------------    RETURN objects from function    ---------------------- 
    RETURNING objects from functions: 
        Declare the function as returning a class type. 
        Then return an object of that type using the normal return statement.

                return_class_type function_name( any_type obj_1, any_type obj_2, . . . . );    


    ----------------    Restrictions    ----------------
    Restriction of returning objects:
        Incorrect freeing of dynamically allocated memory by Destructor of the object

        If an object opens a "disk file" when it is created and "closes that file when it is destroyed", 
            if that object is returned from a function, 
            the file will be closed when the temporary object is destroyed.
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




/* Example 2: You must be careful about returning objects from functions if 
                those objects contain destructor functions because the returned object goes out of scope 
                as soon as the value is returned to the calling routine.
 
                memory will be freed even though the object that is 
                    assigned the return value is still using it
*/

#include <iostream>
#include <cstring>
#include <cstdlib>  // we'll use allocation function malloc() and free()

class samp {
        char *s;
    public :
        samp(){s="\0";}    // "\0" means null
        ~samp(){
            if(s) free(s);  // freeing memory
            std::cout<< "Freeing s \n";
        }     
        void show(){ std::cout << s << "\n"; }
        void set(char *str);  
};

// load a string 
void samp::set(char *str){
    s = (char *)malloc(strlen(str)+1); 	// allocating memory 
    if(!s){
        std::cout<< "Allocation error \n"; 
        exit(1);
    }
    strcpy(s, str);     // storing the passed string
}


// following function returns an object of type samp
samp input(){
    char s[80];
    samp str;

    std::cout << " Enter a string : ";
    std::cin >> s;
    str.set(s);
    return str;
}


int main(){
    samp ob;

    // assign returned object to ob
    ob = input();   // This causes an error !!!!
    ob.show();
    
    return 0;
}

/*  ERROR: In this case different error arise in different compiler. 
        Here destructor called multiple times (In old complier three times actually). 

        1.	First, it is called when the local object str goes out of scope when input() returns. 

        2.	The second time ~samp() is called is when the temporary object returned by input() is destroyed. 
                Remember, when an object is returned from a function, an invisible (to you) 'temporary object' 
                is automatically generated which holds the return value. 
                In this case, this object is simply a "copy of str", which is the return value of the function. 
                Therefore, destructor is executed. 

        3.	Finally, the destructor for object ob, inside main(), is called when the program terminates.


    The trouble is that in this situation:
        the first time the destructor executes, the memory allocated to hold the string input by input() is freed. 
        Thus, not only do the other two calls to samp's destructor try to free an already released piece of dynamic memory, 
        but they destroy the dynamic allocation system in the process, 
        as evidenced by the run-time message "Null pointer assignment." (Depending upon your compiler, you may or may not see this message). 

    The key point is:
        when an object is returned from a function, the temporary object used to effect the return will have its destructor function called. 
        Thus, you should avoid returning objects in which this situation is harmful. 
        
        
    Use copy constructor:
        However, it is possible to use a copy constructor to manage this situation.

*/




/*  Example 3: To illustrate "exactly when" an object is CONSTRUCTED and DESTRUCTED when "returned from a function", 
                create a class called who(). 
                Have who's constructor take one character argument that will be used to "identify an object". 

                Have the constructor display a message similar to this when constructing an object:
                            "Constructing who #x"
                    where 'x' is the "identifying character" associated with each object. 

                When an object is destroyed, have a message similar to this displayed:
                            "Destroying who #x"
                    where, again, 'x' is the "identifying character". 
                    
                Finally, create a function called make_who() that returns a who object. 

                Give each object a unique name. Note the output displayed by the program.
*/

#include <iostream>

class who{
        char name;
    public:
        who(char c){
            name = c;
            std::cout << " Constructing who #";
            std::cout << name << '\n';
        } 
        ~who(){ std::cout << " Destructing who #" << name << "\n"; }
};

// following functiion returns object of type 'who'
who make_who(){
    who temp('B');
    return temp;
}

int main(){
    who ob('A');
    make_who();
    return 0;
}



