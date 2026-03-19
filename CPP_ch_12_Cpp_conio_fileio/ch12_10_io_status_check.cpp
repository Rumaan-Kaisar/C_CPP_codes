
/*  ------------------------    Checking I/O Status    ------------------------

    iostate:
        The status of a stream is stored in an "iostate" object 
        It is an enumeration defined in "ios".

            goodbit     No errors occurred
            eofbit      End-of-file has been encountered
            failbit     A nonfatal I/O error has occurred
            badbit      A fatal I/O error has occurred


    Ways to Check I/O Status:
        There are two ways in which you can obtain I/O status information. 

            Using "rdstate()"
            Using "Status Check Functions"

        rdstate():
            It is a member of ios. It has this prototype: 	

                iostate rdstate();

            It returns the current status of the error state flags. 
            If no error: returns "goodbit" otherwise, an "error flag" is returned.


        Status Check Functions:
            These are ios member functions.
            These return "true" if the condition is set, "false" otherwise:

                bool eof()          true if end-of-file "eofbit" is set.
                bool bad()          true if fatal error "badbit" occurred.
                bool fail()         true if non-fatal error "failbit" or "badbit" is set.
                bool good()         true only if "no errors" (i.e., "goodbit" is set).

            Note: "fail()" returns true for both "failbit" and "badbit".



    ----------------    clear(): Clearing Error States    ----------------

    Use the clear() to clear an error before your program continues 
    It is a "ios" member function clear() whose prototype is:

                void clear(iostate flags = ios::goodbit);

        It resets the error flags.
        If "flags" is goodbit (as it is by default), all error flags are cleared. 
        Otherwise, pass a specific flag to set the new state. (optional)

    Note: Use after handling an error to resume normal stream operations.

*/


// ---- rev[18-Mar-2026] ----


/* Example 1: Following uses rdstate() to detect a file error for a  input file stream named "in". 
                This program displays a text file's contents and uses checkstatus() to report errors. 

                Note that it will always report an 'EOF encountered' message after the loop finishes, 
                which is expected behavior when the file ends (the final call to checkstatus() happens).
*/

#include <iostream>
#include <fstream>

void checkstatus (std::ifstream &in);

int main(int argc, char *argv[]) {
    if(argc !=2) {
        std::cout << " Usage : DISPLAY <filename >\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    
    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    char c;
    while(in.get(c)) {
        std::cout << c;
        checkstatus(in);
    }

    checkstatus(in);    // check final status
    in.close();
    return 0;
}


// Using rdstate() to Detect Errors
void checkstatus(std::ifstream &in) {
    std::ios::iostate i;
    
    i = in.rdstate();
    if(i & std::ios::eofbit)    std::cout << "EOF encountered\n";
    else if(i & std::ios::failbit)  std::cout << "Non-fatal I/O error\n";
    else if(i & std::ios::badbit)   std::cout << "Fatal I/O error\n";
}





/* Example 2: Following program displays a text file,
                it uses good() to detect a file error for a input file stream named "in".
*/

// Using good() for Error Handling
if(!in.good() && !in.eof()) { cout << "I/O Error ... terminating \n"; return 1; } 


---- QWEN  ----

Here is the **pointwise organized** version of **Section 12.9: Checking I/O Status**:

---
 
```cpp

```
- Uses bitwise AND (`&`) to check which flag(s) are set.

---

#### ✅ Example 2: 
```cpp
if (!in.good() && !in.eof()) {
    cout << "I/O Error... terminating\n";
    return 1;
}
```
- Checks if stream is not in good state and not just at EOF.
- Helps distinguish between normal end-of-file and actual errors.

---

### ✅ Summary Table

| Function | Purpose |
|--------|--------|
| `rdstate()` | Get full status (use with `iostate`) |
| `eof()` | Check for end-of-file |
| `bad()` | Check for fatal error |
| `fail()` | Check for non-fatal or fatal error |
| `good()` | True only if no errors |
| `clear()` | Reset error flags |

> Always check stream status after critical I/O operations to handle errors gracefully.







/* Example 2: This . It uses good() to detect a file error: */
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
char ch;
if( argc !=2)
{
cout << " Usage : PR <filename >\n";
return 1;
}
ifstream in( argv [1]) ;
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
while (! in. eof ())
{
in. get (ch);
// check for error
if (! in. good () && !in.eof ())
{
cout << "I/O Error ... terminating \n";
return 1;
}
cout << ch;
}
in. close ();
return 0;
}



/* Example 1: Add error checking to your answers to the exercise from the preceding section */


