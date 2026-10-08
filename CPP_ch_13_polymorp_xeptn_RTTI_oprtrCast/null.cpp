


// ----  rev[25-Aug-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-






Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.




/* 


Here’s a simpler version:

If "new" throws an exception when memory allocation fails, 
    you can be sure the error will be handled somehow—even if the program simply terminates.

On the other hand, if "new" reports an allocation failure by returning a "null pointer", you might forget to check it. 
    If your program then uses that "null pointer", it may behave strangely, 
    it may work for a while, and eventually crash in unpredictable ways.

    Such bugs are very difficult to find and diagnose.



### In very simple terms:

* **`new` throws an exception:** The error is hard to ignore because the program must deal with the exception.
* **`new` returns `nullptr`:** You might forget to check it, causing strange behavior or crashes later.
* Therefore, **exceptions make memory-allocation errors easier to detect and handle.**


*/



/* 5.  */

