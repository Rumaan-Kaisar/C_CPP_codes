9.2 Old Header And Standard Header Declaration Of C++
The differences between old-style and modern code involve two new features: new-style headers and the namespace statement. The first version, shown here, reflects the old-style coding.

/*	A traditional - style C++ program .	*/
#include <iostream.h>
int main(){
/* program code */
return 0;}

Pay special attention to the #include statement. This statement includes the file iostream.h, which provides support for C++'s I/O system. (It is to C++ what stdio.h is to C.) Following is the second version of the skeleton, which uses the modern style:

/*   A modern - style C++ program that uses the new - style headers and a namespace .	*/
# include <iostream>
using namespace std;
int main(){
/* program code */
return 0;}

Notice the two lines in this program immediately after the first comment; this is where the changes occur. First, in the #include statement, there is no .h after the name iostream. And second, the next line, specifying a namespaces.

The new header : When you use a library function in a program, you must include its header file. This is done using the #include statement. For example, in C we used           #include <stdio.h> 	, to include the header file stdio.h for the I/O functions. Here stdio.h is the name of the file used by the I/O functions, and the       #include <stdio.h>      statement cause that file to be included in your program. The key point is that the #include statement includes a file.

The new-style headers do not specify filenames. Instead, they simply specify standard identifiers that might be mapped to files by the compiler, but they need not be. The new-style C++ headers are abstractions that simply guarantee that the appropriate prototypes and definitions required by the C++ library have been declared. Since the new-style header is not a filename, it does not have a ".h" extension. For example, here are some of the new-style headers supported by Standard C++:

<iostream>,	 <fstream>, 	<vector>, 	<string>

The new-style headers are included using the #include statement. 
	C++ still supports the standard C-style header files such as stdio.h and ctype.h. However, Standard C++ also defines new-style headers that can be used in place of these header files. 
	The C++ versions of the standard C headers simply add a c prefix to the filename and drop the .h. For example, the new style C++ header for   math.h   is   <cmath>,   and for   string.h   is   <cstring>. 

The namespace : When you include a new-style header in your program the contents of that header are contained in the " std namespace ". A namespace is simply a declarative region. The purpose of a namespace is to localize the names of identifiers to avoid name collisions. Traditionally, the names of library functions and other such items were simply placed into the global namespace (as they are in C). However, the contents of new-style headers are placed in the std namespace. 
	To bring the std namespace into visibility (i.e., to put std into the global namespace) just use  " using namespace std; ". After this statement has been compiled, there is no difference between working with an old-style header and a new-style one.

Note
[1]	The traditional way to include the I/O header is	  #include <iostream.h>  this causes the file iostream.h to be included in your program. In general, an old-style header will use the same name as its corresponding new-style header with a .h appended.
[2]	To transforms a modern program into a traditional-style one just replace

#include <iostream>
using namespace std;

with

#include <iostream.h>

Since the old style header reads all of its contents into the global namespace, there is no need for a namespace statement.

