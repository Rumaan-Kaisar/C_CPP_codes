
/*  ----------------    AUTOMATIC IN-LINING    ----------------

    If a member function's definition is 'short enough', 
        the DEFINITION can be included inside the "class declaration". 
        Then the function autometically become an "in-line function", if possible. 

    When a function is defined "within a class declaration", the 'inline' keyword is no longer necessary. 
        if any 'in-line restriction' is violated, the compiler is free to generate a normal function.
    
    For example, the  divisible()  is automatically in-lined as shown here:


            class samp {	
                    int i, j;
                public:
                    samp(int a, int b);
                    int divisible(){ return !(i%j); }   // divisible() is defined inside class-declaration and automatically 'in-lined'.
            };

            samp::samp(int a, int b) {
                i = a;
                j = b; 
            }


        Notice, the code associated with divisible() occurs inside the declaration for the class 'samp'. 
            Further notice that no other definition of divisible() is 'needed-or permitted'.

        Notice how divisible()  occurs all on one line. 
            This format is very common in C++ programs when a function is declared within a class declaration. 
            It allows the declaration to be more compact. 


*/


