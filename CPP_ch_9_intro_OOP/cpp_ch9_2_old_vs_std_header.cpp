
/* ----------------------     HEADER : Old vs Standard     ----------------------

    Two versions of C++:
        The differences between old-style and modern code involve "two new features":
                new-style headers and 
                namespace statement. 
        
        old-style coding (C++ skeleton):

                                            // A traditional - style C++ program.

                                            #include <iostream.h>

                                            int main(){
                                                // program code
                                                return 0;
                                            }

            Pay special attention to the '#include statement'. 
                This statement includes the file "iostream.h", which provides support for C++'s I/O system. (It is to C++ what stdio.h is to C.) 
                
                Following is the second version of the skeleton, which uses the modern style:



        Modern-style coding (C++ skeleton):

                                            // A modern - style C++ program that uses the new - style headers and a namespace

                                            #include <iostream>
                                            using namespace std;

                                            int main(){
                                                // program code
                                                return 0;
                                            }

            Notice the first two lines in this program immediately after the first comment; this is where the changes occur.
                First, in the #include statement, there is no ".h" after the name 'iostream'. 
                Second, the next line, specifying a 'namespaces'.


        Note: using "std" in namespace is a Bad-idea
            To avoid namespace collision we'll use '::' to access functions of 'std'




    ------------    new-style header    ------------
    in C we used           #include <stdio.h> 	, to include the "HEADER FILE" stdio.h for the I/O functions.
        Here stdio.h is the name of the 'file' used by the I/O functions
        The key point is that the #include statement includes a file.

    The new-style headers do not specify filenames. 
        Instead, they simply specify 'standard identifiers' that might be 'mapped to files' by the compiler, but they need not be. 
        The new-style C++ headers are abstractions that simply guarantee that 
            the appropriate prototypes and definitions required by the C++ library have been declared.
        
        Since the "new-style header" is not a filename, it does not have a ".h" extension. 
        
            Eg:
                For example, here are some of the new-style headers supported by Standard C++:

                    <iostream>	 
                    <fstream> 	
                    <vector> 	
                    <string>

    The "new-style headers" are included using the #include statement. 


    C++ still supports the 'standard C-style header files' such as <stdio.h> and <ctype.h>. 
        However, Standard C++ also defines new-style headers that can be used in place of these header files. 

        The C++ versions of the standard C headers 'simply add a c prefix' to the filename and drop the .h. 
            For example, the new style C++ header for   
                <math.h>   is   <cmath>,   and    
                <string.h>   is   <cstring>. 




    ------------    namespace    ------------
    When you include a 'new-style header' in your program the 'contents of that header' are contained in the "std namespace".

    A namespace is simply a declarative region. 
        The purpose of a 'namespace' is to localize the names of identifiers to avoid 'name collisions'. 
        Traditionally, the names of 'library functions' and other such items were simply placed into the global namespace (as they are in C). 
        However, the contents of 'new-style headers' are placed in the 'std namespace'.

    To bring the 'std namespace' into visibility (i.e., to put "std" into the 'global namespace') 
        just use  " using namespace std; ". 
        After this statement has been compiled, there is no difference between working with an 'old-style header' and a "new-style one".

    The traditional way:    #include <iostream.h>  
        this causes the file "iostream.h" to be included in your program. 
            In general, an old-style header will use the same name as its corresponding new-style header with a .h appended.

        To transforms a modern program into a traditional-style one just replace

                    #include <iostream>
                    using namespace std;
            with
                    #include <iostream.h>

            Since the old style header reads all of its contents into the global namespace, there is no need for a 'namespace statement'.




    ------------    Scope resolution operator '::'    ------------

    Scope resolution operator:
        modern c++ programmares use Scope resolution operator '::' to use "std"
        They dont use 'using namespace std;'

            Eg: 
                std::cout 
                std::cin

*/


