
/*  ------------------------    In-Line Functions    ------------------------
    IN-LINE FUNCTIONS: 
        In C++, IN-LINE FUNCTIONS are not actually called but, rather, are expanded in line, at the point of each call. 
        This is much the same way that a C-like parameterized macro works 
        (recall 8.1, C_Ch8_1_adv_define_include.c function-like macro). 

        The advantage is, no overhead associated with the 'function call and return mechanism
            makes an in-line functions executed much faster than normal functions. 
        
        The disadvantages of in-line functions is that if they are too large and called too often, your program grows larger. 
            In general only 'short functions' are declared as in-line functions.


    Declaration:
        simply precede the function's "definition" with the "inline" specifier. For Example :

                inline int even(int x) { return !(x%2); }

        The function even(), which returns true if its argument is even, is declared as being-in-line. 
        It means that,   
                                            if(even(x)) cout << "Even";    
            is functionally equivalent to:   
                                            if(!(x%2)) cout << " Even ";


    Restrictions:
        An in-line function must be defined before it is first called.  
            That's why even() must defined before main().

            inline int even(int x) { return !(x%2); }
            int main(){
                . . . . . . . . . 
            }

        Some compilers will not in-line a function if it contains 
            a 'static' variable, 
            a loop statement, 
            a switch or a goto, or 
            if the function is RECURSIVE.


    Remember, the inline specifier is a "REQUEST", not a "command", to the compiler. 
    If any in-line restriction is 'violated', the compiler is free to generate a 'normal function' 
        (i.e. the function is compiled as a normal function and the inline request is ignored.). 

*/




// ----  rev[16-2-24]  ----
/*  

C++ provides inline functions to reduce the function call overhead. An inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the inline function gets inserted or substituted at the point of the inline function call. This substitution is performed by the C++ compiler at compile time. An inline function may increase efficiency if it is small.

Syntax:

    inline return-type function-name(parameters) {
        // function code
    }  



    Normal function:
        in this case fn() stays outside main()

        start: main() -> flow ctrl transfer -> fn() -> stop
                or -> stop


    In-line function:
        in this case fn() goes inside main(), there is no 'flow ctrl transfer' outside main()

        start: main() ->  fn() -> stop
*/


// ChatGPT
An inline function in C++ is a function that is expanded in place at the point of call, rather than being called like a regular function. When a function is declared as inline, the compiler replaces each call to that function with the corresponding function body. This process is called inline expansion.

To declare a function as inline in C++, you use the inline keyword before the function declaration, like so:

inline int add(int a, int b) {
    return a + b;
}

Benefits of using inline functions:

Performance Improvement: By eliminating the overhead of function calls (such as pushing arguments onto the stack, jumping to the function, and returning), inline functions can lead to performance improvements, especially for small, frequently-called functions.

Reduced Function Call Overhead: Since the function body is inserted directly at the call site, there's no need to save and restore the program state, leading to reduced overhead associated with function calls.

Optimization Opportunities: The compiler has more visibility into the function body, which may enable additional optimizations, such as constant propagation, dead code elimination, and loop unrolling.

Avoidance of Linker Errors: In C++, functions defined in header files that are included in multiple source files can lead to linker errors due to multiple definitions. Declaring such functions as inline can help avoid such errors by allowing multiple definitions of the same function across translation units, as long as they are identical.

However, it's important to note that the inline keyword is just a suggestion to the compiler, and the compiler may choose to ignore it. Whether a function is actually inlined or not depends on various factors, including the size of the function, optimization settings, and the compiler's heuristics.

Additionally, inline functions may increase code size, especially if the function body is large or if the function is called from multiple places. Therefore, it's typically best to use inline functions for small, frequently-called functions, and let the compiler decide whether to inline larger functions.




While inline functions can offer performance benefits in certain situations, there are also potential disadvantages to consider:

Code Bloat: Inlining a function involves copying its code to every call site. If the function is large or called from many places, this can lead to increased code size, which may negatively impact memory usage and cache performance.

Compiler Heuristics: The decision of whether to inline a function is ultimately up to the compiler, even if you use the inline keyword. Some compilers may choose not to inline a function even if it's marked as inline, depending on optimization settings, function size, and other factors.

Debugging Complexity: Inlined functions can complicate debugging, as the function call stack may not accurately reflect the program's execution flow. This can make it more difficult to trace the program's behavior during debugging sessions.

Increased Compilation Time: Inlining functions can lead to longer compilation times, especially for large projects with many inline function calls. This is because the compiler needs to process and generate code for each inline function at every call site.

Binary Size Increase: Inlined functions can increase the size of the binary executable, which may be undesirable in resource-constrained environments or for applications where minimizing file size is a priority.

Potential for Duplicated Code: Inlining functions can lead to code duplication if the same function is inlined in multiple places. This can increase maintenance overhead and make it harder to ensure consistency across the codebase.

Limited Optimization Opportunities: Inlining functions may limit certain optimization opportunities, such as function-level optimizations and interprocedural optimizations, which rely on separate function bodies.

Overall, while inline functions can offer performance benefits in specific scenarios, it's essential to use them judiciously and consider their potential impact on code size, compilation times, and debugging complexity.Inlining should primarily be applied to small, frequently-called functions where the benefits outweigh the potential drawbacks.



