
/*  ------------------------    chapter    ------------------------


12.9 Checking I/O Status
The current status of an I/O stream is described in an object of type iostate, it is an enumeration defined by ios that includes members:

[1]	goodbit (Means-No errors occurred)	[2]	eofbit (Means-End-of-file has been encountered)	[3]	failbit (Means-A nonfatal I/O error has occurred)	[4]	badbit (Means-A fatal I/O error has occurred)
	There are two ways in which you can obtain I/O status information. 
	First, you can call the rdstate() function, which is a member of ios. It has this prototype: 	iostate rdstate();
	It returns the current status of the error flags. 
	rdstate() returns goodbit when no error has occurred. Otherwise, an error flag is returned.
	Second way to determine whether an error has occurred is by using one or more of these ios member functions:

[1]	bool eof();
The eof() was discussed earlier.	[2]	bool bad();
The bad() returns true if badbit is set.	[3]	bool fail();
The fail() returns true if failbit is set.	[4]	bool good(); 
The good() returns true if there are no errors. 
	Otherwise they return false.
	clear(): To clear an error before your program continues use the ios member function clear() whose prototype is:

void clear(iostate flags = ios::goodbit);
	If flags is goodbit (as it is by default), all error flags are cleared. Otherwise, set flags to the settings you desire.


	Example 1: Following uses rdstate() to detect a file error for a file named "in":

void checkstatus(ifstream &in) { 	ios :: iostate i;
i = in.rdstate();
if(i & ios::eofbit ) 	cout << "EOF encountered \n";
else if(i & ios::failbit ) cout << "Non - Fatal I/O error \n";
else if(i & ios::badbit ) 	cout << "Fatal I/O error \n"; }


	Example 2: Following uses good() to detect a file error for a file named "in":
if(!in.good() && !in.eof()) { cout << "I/O Error ... terminating \n"; return 1; }



---- QWEN  ----

Here is the **pointwise organized** version of **Section 12.9: Checking I/O Status**:

---

### 🔹 12.9 – Checking I/O Status

#### ✅ I/O Status (`iostate`)
- The status of a stream is stored in an `iostate` object (an enumeration defined in `ios`).
- Key status flags:
  1. **`goodbit`** → No errors.
  2. **`eofbit`** → End-of-file reached.
  3. **`failbit`** → Non-fatal I/O error (e.g., invalid input format).
  4. **`badbit`** → Fatal I/O error (e.g., hardware failure).

> These flags are set automatically when operations fail.

---

#### ✅ Ways to Check I/O Status

##### 1. **`rdstate()`**
- Prototype: `iostate rdstate();`
- Returns the current value of the error state flags.
- If no error: returns `goodbit`.
- Can be used with bitwise operators to check specific flags.

##### 2. **Status Check Functions**
These return `true` if the condition is set, `false` otherwise:
- `bool eof()` → true if end-of-file (`eofbit`) is set.
- `bool bad()` → true if fatal error (`badbit`) occurred.
- `bool fail()` → true if non-fatal error (`failbit`) or `badbit` is set.
- `bool good()` → true only if **no errors** (i.e., `goodbit` is set).

> ⚠️ `fail()` returns true for both `failbit` and `badbit`.

---

#### ✅ Clearing Error States: `clear()`
- Prototype: `void clear(iostate flags = ios::goodbit);`
- Resets the error flags.
- Default: clears all flags (`goodbit`).
- Optional: pass a specific flag to set the new state.

> Use after handling an error to resume normal stream operations.

---

#### ✅ Example 1: Using `rdstate()` to Detect Errors
```cpp
void checkstatus(ifstream &in) {
    ios::iostate i = in.rdstate();
    if (i & ios::eofbit)      cout << "EOF encountered\n";
    else if (i & ios::failbit) cout << "Non-fatal I/O error\n";
    else if (i & ios::badbit)  cout << "Fatal I/O error\n";
}
```
- Uses bitwise AND (`&`) to check which flag(s) are set.

---

#### ✅ Example 2: Using `good()` for Error Handling
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

*/  

/* Example 1: The following program illustrates rdstate(). It displays the contents of a text file. If an
error occurs, the function reports it by using checkstatus(). 

This program will always report at least one "error." After the while loop ends,
the final call to checkstatus() reports, as expected, that an EOF has been encountered.

*/

# include <iostream >
# include <fstream >
using namespace std ;
void checkstatus ( ifstream &in);
int main ( int argc , char * argv [])
{
if( argc !=2)
{
cout << " Usage : DISPLAY <filename >\n";
return 1;
}
ifstream in( argv [1]) ;
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
char c;
while (in. get (c))
{
cout << c;
checkstatus (in);
}
checkstatus (in); // check final status
in. close ();
return 0;
}
void checkstatus ( ifstream &in)
{
ios :: iostate i;
i = in. rdstate ();
if(i & ios :: eofbit )
cout << " EOF encountered \n";

else if(i & ios :: failbit )
cout << "Non - Fatal I/O error \n";
else if(i & ios :: badbit )
cout << " Fatal I/O error \n";
}





/* Example 2: This program displays a text file. It uses good() to detect a file error: */
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

