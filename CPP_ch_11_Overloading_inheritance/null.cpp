

// --------    rev[17-Mar-25]    --------


// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-






/* Example 4: Given the following partially completed program, fill in the "needed operator functions":

note:

is array::array(){
    for(int i=0; i<10; i ++) nums[i] = 0;
}

is same as

array::array(){ int i;

    for(i=0; i<10; i ++) nums[i] = 0;
}

#include <iostream>

class array{
        int nums[10];
    public:
        array();
        void set(int n[10]);
        void show();
        
        // overload +, -, ==
        array operator+(array ob2);
        array operator-(array ob2);
        array operator==(array ob2);
};


array::array(){
    for(int i=0; i<10; i ++) nums[i] = 0;
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


// Fill in operator functions.



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

