


// ----  rev[25-Aug-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-






Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.


/* Example 1:   What are generic function and generic class? 
                Specify their general forms.

            ans:
                A generic function defines a "general set of operations" which then applied to different data-types.
                It is implemented with the keyword "template".

                    Its general form is:

                            template <class Ttype> ret_type func_name(para_list) {
                                // ...
                            }


                On the other hand a generic class defines all operations that relate to that class, 
                but the actual data is specified as a parameter when an object of that class is created. 

                    Its general form is:

                            template <class Ttype> class class_name {
                                // ...
                            };
*/













5. Briefly explain how try, catch, and throw work together to provide C++ exception
handling.


6. Can throw be used if execution has not passed through a try block?

7. What purpose do terminate() and unexpected() serve?

8. What form of catch will handle all types of exceptions?












MASTERY SKILLS CHECK:










/* 7. If new throws an exception when an allocation error occurs, you can be sure that the
error will be handled one way or another-even if only by abnormal program termination.
In contrast, an allocation failure that is reported by new, a return of a null pointer
can be overlooked if you forget to check for this possibility. The trouble is that when
your program attempts to use the null pointer, it might work for a while, then behave
erratically, and finally crash in unpredictable (and unduplicatable ) ways. This is very
difficult type of bug to diagnose. 


Here’s a simpler version:

> If `new` throws an exception when memory allocation fails, you can be sure the error will be handled somehow—even if the program simply terminates.
>
> On the other hand, if `new` reports an allocation failure by returning a **null pointer**, you might forget to check it. If your program then uses that null pointer, it may behave strangely, work for a while, and eventually crash in unpredictable ways.
>
> **Such bugs are very difficult to find and diagnose.**

### In very simple terms:

* **`new` throws an exception:** The error is hard to ignore because the program must deal with the exception.
* **`new` returns `nullptr`:** You might forget to check it, causing strange behavior or crashes later.
* Therefore, **exceptions make memory-allocation errors easier to detect and handle.**


*/



/* 5. try, catch, and throw work together like this: Put all statements that you wish to
monitor for exceptions within a try block, if an exception occurs, throw that exception
using throw and handle it with a corresponding catch statement. */


6. No.


/* 7. terminate() is called when an exception is thrown for which there is no corresponding
catch statement. unexpected() is called when an attempt is made to throw an exception
out of a function that is not specified in the function’s throw clause. */


8. catch(...).
