
// ----------------------     comments in C++     ----------------------

First, you can use the standard, C-like comment mechanism. 
    That is, begin a comment with /* and end it with */. 
    As with C, this type of comment cannot be nested in C++.

The second way that you can add a remark to your C++ program is to use the single-line comment. 
    A single-line comment begins with a // and stops at the end of the line. 

Typically, C++ programmers use 'C-like comments' for "multiline commentaries" and 
    reserve C++ style single line comments for "short remarks".




/* Example 1: Here is a program that contains both C and C++-style (single line) comments: */

/*
    Multi-line comment:
        This is a C- like comment.
        This program determines whether
        an integer is odd or even
*/

#include <iostream>
using namespace std;

int main(){
    int num;    // this is a C++ single-line comment

    // read the number
    cout << " Enter number to be tested : ";
    cin >> num ;

    // see if even or odd
    if((num %2) ==0) cout << " Number is even \n";
    else cout << " Number is odd \n";

    return 0;
}




/* Example 2: While multiline comments cannot be nested, it is possible to nest a single-line comment
                within a multiline comment. For example, this is perfectly valid: */

/*
    This is a multiline comment
    inside of which 
        // is nested a single-line comment .

        Here is the end of the multiline comment .
*/




/* Example 3: As an experiment, determine whether following comment (which nests a C-like comment within
                a C++-style, single-line comment) is valid: */

// This is a strange /* way to do a comment */
Ans: The comment, although strange, is valid. LOL
