

// --------    rev[25-Feb-25]    --------


// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
Mastery Skills Check
At this point you should be able to perform the following exercises and answer the questions.
1. Overload the >> and << shift operator relative to the coord class so that the following
types of operations are allowed:
ob << integer
ob >> integer
Make sure your operations shift the x and y values by the amount specified.
2. Given the class
class three_d
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
};
170INTRODUCING OPERATOR OVERLOADING
SKILLS CHECK
overload the +, -, ++, and { operators for this class. (For the increment and decrement
operators, overload only the prefix form.)
3. Rewrite your answer to Question 2 so that it uses reference parameters instead of value
parameters to the operator functions. (Hint: You will need to use friend functions for the
increment and decrement operators.)
4. How do friend operator functions differ from member operator functions?
5. Explain why you might need to overload the assignment operator.
6. Can operator=() be a friend function?
7. Overload the + for the three d class in Question 2 so that it accepts the following types
of operations:
ob + int ;
int + ob;
8. Overload the ==, !=, and jj operators relative to the three d class from Question 2.
9. Explain the main reason for overloading the [ ] operator.





// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.
1. Create a strtype class that allows the following types of operators:
➤ string concatenation using the + operator
➤ string assignment using the = operator
➤ string comparisons using <, >, and ==
Feel free to use fixed-length strings. This is a challenging assignment, but with some
thought (and experimentation), you should be able to accomplish it.




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-
Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. When an operator is overloaded, does it lose any of its original functionality?
2. Must an operator be overloaded relative to a user-defined type, such as a class?
3. Can the precedence of an overloaded operator be changed? Can the number of operands
be altered?
4. Given the following partially completed program, fill in the needed operator functions:
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
5. Convert the solution from Exercise 4 so it overloads the operators by using friend functions.
6. Using the class and support functions from Exercise 4, overload the ++ operator by
using a member function and overload the { operator by using a friend. (Overload only
the prefix forms of ++ and {.)
7. Can the assignment operator be overloaded by using a friend function.



// ------------    Cumulative/Masery/Review skill check    ------------



