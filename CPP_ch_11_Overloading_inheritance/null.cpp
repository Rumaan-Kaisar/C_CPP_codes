

// --------    rev[10-Mar-25]    --------


// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


/* Example 3: Rewrite your answer to Question 2 so that it uses reference parameters instead of value
parameters to the operator functions. (Hint: You will need to use friend functions for the
increment and decrement operators.) */
3. # include <iostream >
using namespace std ;
class three_d
{
int x, y, z;
public :
490ANSWERS
MASTERY SKILLS CHECK: Chapter 6
three_d ( int i, int j, int k)
{
x = i; y = j; z = k;
}
three_d () { x =0; y =0; z=0; }
void get ( int &i, int &j, int &k)
{
i = x; j = y; k = z;
}
three_d operator +( three_d &ob2 );
three_d operator -( three_d &ob2 );
friend three_d operator ++( three_d &ob);
friend three_d operator --( three_d &ob);
};
three_d three_d :: operator +( three_d &ob2 )
{
three_d temp ;
temp .x = x + ob2 .x;
temp .y = y + ob2 .y;
temp .z = z + ob2 .z;
return temp ;
}
three_d three_d :: operator -( three_d &ob2 )
{
three_d temp ;
temp .x = x - ob2 .x;
temp .y = y - ob2 .y;
temp .z = z - ob2 .z;
return temp ;
}
three_d operator ++( three_d &ob)
{
ob.x ++;
ob.y ++;
ob.z ++;
return ob;
}
three_d operator --( three_d &ob)
{
ob.x --;
ob.y --;
ob.z --;
return ob;
491TEACH YOURSELF
C++
}
int main ()
{
three_d o1 (10 , 10, 10) , o2 (2, 3, 4) , o3;
int x, y, z;
o3 = o1 + o2;
o3. get (x, y, z);
cout << "X: " << x << ", Y: " << y;
cout << ", Z: " << z << "\n";
o3 = o1 - o2;
o3. get (x, y, z);
cout << "X: " << x << ", Y: " << y;
cout << ", Z: " << z << "\n";
++ o1;
o1. get (x, y, z);
cout << "X: " << x << ", Y: " << y;
cout << ", Z: " << z << "\n";
--o1;
o1. get (x, y, z);
cout << "X: " << x << ", Y: " << y;
cout << ", Z: " << z << "\n";
return 0;
}




/* Example 4: How do friend operator functions differ from member operator functions? */
4. A binary member operator function is passed the left operand implicitly via this pointer.
A binary friend operator function is passed both operands explicitly. Unary member
operator functions have no explicit parameters. A friend unary operator function has one
parameter.



/* Example 5: Explain why you might need to overload the assignment operator. */
5. You will need to overload the = operator when the default bitwise copy is insufficient.
For example, you might have a situation in which you want only parts of the data in one
object to be assigned to another object.



/* Example 6: Can operator=() be a friend function? */
6. No.



/* Example 7: Overload the + for the three d class in Question 2 so that it accepts the following types
of operations:
ob + int ;
int + ob; */

7. # include <iostream >
using namespace std ;
class three_d
{
int x, y, z;
public :
three_d ( int i, int j, int k)
{
x = i; y = j; z = k;
}
492ANSWERS
MASTERY SKILLS CHECK: Chapter 6
three_d () { x =0; y =0; z=0; }
void get ( int &i, int &j, int &k)
{
i = x; j = y; k = z;
}
friend three_d operator +( three_d ob , int i);
friend three_d operator +( int i, three_d ob);
};
three_d operator +( three_d ob , int i)
{
three_d temp ;
temp .x = ob.x + i;
temp .y = ob.y + i;
temp .z = ob.z + i;
return temp ;
}
three_d operator +( int i, three_d ob)
{
three_d temp ;
temp .x = ob.x + i;
temp .y = ob.y + i;
temp .z = ob.z + i;
return temp ;
}
int main ()
{
three_d o1 (10 , 10, 10) ;
int x, y, z;
o1 = o1 + 10;
o1. get (x, y, z);
cout << "X: " << x << ", Y: " << y;
cout << ", Z: " << z << "\n";
o1 = -20 + o1;
o1. get (x, y, z);
cout << "X: " << x << ", Y: " << y;
cout << ", Z: " << z << "\n";
return 0;
}




/* Example 8: Overload the ==, !=, and jj operators relative to the three d class from Question 2. */
8. # include <iostream >
using namespace std ;
class three_d
493TEACH YOURSELF
C++
{
int x, y, z;
public :
three_d ( int i, int j, int k)
{
x = i; y = j; z = k;
}
three_d () { x =0; y =0; z=0; }
void get ( int &i, int &j, int &k)
{
i = x; j = y; k = z;
}
int operator ==( three_d ob2);
int operator !=( three_d ob2);
int operator ||( three_d ob2);
};
int three_d :: operator ==( three_d ob2)
{
return x== ob2 .x && y== ob2.y && z== ob2 .z;
}
int three_d :: operator !=( three_d ob2)
{
return x!= ob2 .x && y!= ob2.y && z!= ob2 .z;
}
int three_d :: operator ||( three_d ob2)
{
return x|| ob2 .x && y|| ob2.y && z|| ob2 .z;
}
int main ()
{
three_d o1 (10 , 10, 10) , o2 (2, 3, 4) , o3 (0, 0, 0);
if(o1 == o1)
cout << "o1 == o1\n";
if(o1 != o2)
cout << "o1 != o2\n";
if(o3 || o1)
cout << "o1 or o3 is true \n";
return 0;
}




/* Example 9: Explain the main reason for overloading the [ ] operator. */
9. The [ ] is usually overloaded to allow an array encapsulated within a class to be indexed
with the normal array indexing syntax.




// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

/* Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.


Example 1: Create a strtype class that allows the following types of operators:
➤ string concatenation using the + operator
➤ string assignment using the = operator
➤ string comparisons using <, >, and ==
Feel free to use fixed-length strings. This is a challenging assignment, but with some
thought (and experimentation), you should be able to accomplish it. */
1. /*
For clarity , no error checking has been used . However
you should add some if using this code for a real
application .
*/
# include <iostream >
# include <cstring >
using namespace std ;
class strtype
{
char s [80];
public :
strtype () { *s = ’\0 ’; }
strtype ( char *p) { strcpy (s, p); }
char * get () { return s; }
strtype operator +( strtype s2);
strtype operator =( strtype s2);
int operator <( strtype s2);
int operator >( strtype s2);
int operator ==( strtype s2);
};
strtype strtype :: operator +( strtype s2)
{
strtype temp ;
strcpy ( temp .s, s);
strcat ( temp .s, s2.s);
return temp ;
}
strtype strtype :: operator =( strtype s2)
{
strcpy (s, s2.s);
return * this ;
}
int strtype :: operator <( strtype s2)
{
return strcmp (s, s2.s) < 0;
}
int strtype :: operator >( strtype s2)
{
return strcmp (s, s2.s) > 0;
}
495TEACH YOURSELF
C++
int strtype :: operator ==( strtype s2)
{
return strcmp (s, s2.s) == 0;
}
int main ()
{
strtype o1(" Hello "), o2(" There "), o3;
o3 = o1 + o2;
cout << o3. get () << ’\n’;
o3 = o1;
if(o1 == o3)
cout << "o1 equals o3\n";
if(o1 >o2)
cout << "o1 > o2\n";
if(o1 <o2)
cout << "o1 < o2\n";\
return 0;
}




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-
Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.




/* Example 1: When an operator is overloaded, does it lose any of its original functionality? */
1. No. Overloading an operator simply expands the data types upon which it can operate,
but no preexisting operations are affected.



/* Example 2: Must an operator be overloaded relative to a user-defined type, such as a class? */
2. Yes. You cannot overload an operator relative to one of C++’s built-in types.



/* Example 3: Can the precedence of an overloaded operator be changed? Can the number of operands be altered? */
3. No, the precedence cannot be changed. No, the number of operands cannot be altered.



/* Example 4: Given the following partially completed program, fill in the needed operator functions:
# include <iostream >
using namespace std ;
class array
{
int nums [10];
public :
array ();
void set ( int n [10]) ;
void show ();
array operator +( array ob2);
array operator -( array ob2);
array operator ==( array ob2);
};
array :: array ()
{
int i;
for (i =0; i <10; i ++)
nums [i] = 0;
}
void array :: set ( int *n)
{
int i;
for (i =0; i <10; i ++)
nums [i] = n[i];
}
void array :: show ()
174INHERITANCE
{
int i;
for (i =0; i <10; i ++)
cout << nums [i] << ’ ’;
cout << "\n";
}
// Fill in operator functions .
int main ()
{
array o1 , o2 , o3;
int i [10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10 };
o1. set (i);
o2. set (i);
o3 = o1 + o2;
o3. show ();
o3 = o1 - o3;
o3. show ();
if(o1 == o2)
cout << "o1 equals o2\n";
else
cout << "o1 does not equal o2\n";
if(o1 == o3)
cout << "o1 equals o3\n";
else
cout << "o1 does not equal o3\n";
return 0;
}
Have the overloaded + add each element of each operand. Have the overloaded - subtract
each element of the right operand from the left. Have the overloaded == return true if
each element of each operand is the same and return false otherwise.
 */

4. # include <iostream >
using namespace std ;
class array
{
int nums [10];
public :
array ();
void set ( int n [10]) ;
void show ();
array operator +( array ob2);
array operator -( array ob2);
int operator ==( array ob2);
};
array :: array ()
{
int i;
496ANSWERS
REVIEW SKILLS CHECK: Chapter 7
for (i =0; i <10; i ++)
nums [i] = 0;
}
void array :: set ( int *n)
{
int i;
for (i =0; i <10; i ++)
nums [i] = n[i];
}
void array :: show ()
{
int i;
for (i =0; i <10; i ++)
cout << nums [i] << ’ ’;
cout << "\n";
}
array array :: operator +( array ob2)
{
int i;
array temp ;
for (i =0; i <10; i ++)
temp . nums [i] = nums [i] + ob2 . nums [i];
return temp ;
}
array array :: operator -( array ob2)
{
int i;
array temp ;
for (i =0; i <10; i ++)
temp . nums [i] = nums [i] - ob2 . nums [i];
return temp ;
}
int array :: operator ==( array ob2)
{
int i;
for (i =0; i <10; i ++)
if( nums [i ]!= ob2 . nums [i])
return 0;
497TEACH YOURSELF
C++
return 1;
}
int main ()
{
array o1 , o2 , o3;
int i [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
o1. set (i);
o2. set (i);
o3 = o1 + o2;
o3. show ();
o3 = o1 - o3;
o3. show ();
if(o1 == o2)
cout << "o1 equals o2\n";
else
cout << "o1 does not equal o2\n";
if(o1 == o3)
cout << "o1 equals o3\n";
else
cout << "o1 does not equal o3\n";
return 0;
}




/* Example 5: Convert the solution from Exercise 4 so it overloads the operators by using friend functions. */

5. # include <iostream >
using namespace std ;
class array
{
int nums [10];
public :
array ();
void set ( int n [10]) ;
void show ();
friend array operator +( array ob1 , array ob2 );
friend array operator -( array ob1 , array ob2 );
friend int operator ==( array ob1 , array ob2 );
};
array :: array ()
{
int i;
for (i =0; i <10; i ++)
nums [i] = 0;
498ANSWERS
REVIEW SKILLS CHECK: Chapter 7
}
void array :: set ( int *n)
{
int i;
for (i =0; i <10; i ++)
nums [i] = n[i];
}
void array :: show ()
{
int i;
for (i =0; i <10; i ++)
cout << nums [i] << ’ ’;
cout << "\n";
}
array operator +( array ob1 , array ob2)
{
int i;
array temp ;
for (i =0; i <10; i ++)
temp . nums [i] = ob1 . nums [i] + ob2 . nums [i];
return temp ;
}
array operator -( array ob1 , array ob2)
{
int i;
array temp ;
for (i =0; i <10; i ++)
temp . nums [i] = ob1 . nums [i] - ob2 . nums [i];
return temp ;
}
int operator ==( array ob1 , array ob2)
{
int i;
for (i =0; i <10; i ++)
if( ob1 . nums [i ]!= ob2 . nums [i])
return 0;
return 1;
}
499TEACH YOURSELF
C++
int main ()
{
array o1 , o2 , o3;
int i [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
o1. set (i);
o2. set (i);
o3 = o1 + o2;
o3. show ();
o3 = o1 - o3;
o3. show ();
if(o1 == o2)
cout << "o1 equals o2\n";
else
cout << "o1 does not equal o2\n";
if(o1 == o3)
cout << "o1 equals o3\n";
else
cout << "o1 does not equal o3\n";
return 0;
}




/* Example 6: Using the class and support functions from Exercise 4, overload the ++ operator by
using a member function and overload the { operator by using a friend. (Overload only
the prefix forms of ++ and {.) */

6. # include <iostream >
using namespace std ;
class array
{
int nums [10];
public :
array ();
void set ( int n [10]) ;
void show ();
array operator ++() ;
friend array operator --( array &ob);
};
array :: array ()
{
int i;
for (i =0; i <10; i ++)
nums [i] = 0;
}
void array :: set ( int *n)
{
500ANSWERS
REVIEW SKILLS CHECK: Chapter 7
int i;
for (i =0; i <10; i ++)
nums [i] = n[i];
}
void array :: show ()
{
int i;
for (i =0; i <10; i ++)
cout << nums [i] << ’ ’;
cout << "\n";
}
// Overload unary op using member function .
array array :: operator ++()
{
int i;
for (i =0; i <10; i ++)
nums [i ]++;
return * this ;
}
// Use a friend ./
array operator --( array &ob)
{
int i;
for (i =0; i <10; i ++)
ob. nums [i]--;
return ob;
}
int main ()
{
array o1 , o2 , o3;
int i [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
o1. set (i);
o2. set (i);
o3 = ++ o1;
o3. show ();
o3 = --o1;
501TEACH YOURSELF
C++
o3. show ();
return 0;
}




/* Example 7: Can the assignment operator be overloaded by using a friend function. */
7. No. To overload the assignment operator you must use a member function.

