
/*  ------------------------    operator overloading : unary    ------------------------
    Overloading A UNARY Operator
        Overloading is similar to binary operator except theres only one operand

        Overloading a "unary" operator as a member function requires "no parameters"
        The single operand triggers the call to the operator function
*/




/* Example 1: The following program overloads the increment operator (++) relative to the coord class 
                The overloaded ++ operator increases the object by 1.
                It modifies the object it operates on and returns the incremented object.
                This allows usage in larger statements like o2 = ++o1;.

                While it's not mandatory to overload a unary operator to match its usual behavior, 
                    it is generally recommended.
*/

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // overloading ++
        coord operator++();
};


// Overload ++ for coord, notice the use of "this", and '*'
coord coord::operator++(){
    x++;
    y++;
    return *this;
}

int main(){
    coord o1(10,10);
    int x, y;

    ++o1; // increment an object
    o1.get_xy(x, y);
    std::cout << " (++ o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}









/*  

	In early version of C++ there was no way to determine whether an overloaded ++ or --  preceded or followed its operand. That is these two statements would have been identical:  o1++;  and   ++o1;
	In modern C++ to distinguish between these two statements we declare following by which the compiler can distinguish.
coord coord :: operator++( int notused );
	If the ++ operator precedes its operand, the operator++() function is called. 
	If the ++ follows its operand, the operator++( int notused ) function is used. In this case, notused will always be passed the value 0. 
	So, if the difference between prefix and postfix increment or decrement is important to your class objects, you will need to implement both operator functions.
coord coord :: operator++();
coord coord :: operator++( int notused );


In early version of C++, when an increment or decrement operator was overloaded, there
was no way to determine whether an overloaded ++ or { preceded or followed its operand.
That is, assuming the preceding program, these two statements would have been identical:
o1 ++;
++ o1;
However, the modern specification for C++ has defined a way by which the compiler can
distinguish between these two statements. To accomplish this, create two versions of the
operator++() function. The first is defined as shown in the preceding example. The
second is declared like this:
coord coord :: operator ++( int notused );
If the ++ operator precedes its operand, the operator++() function is called. However,
if the ++ follows its operand, the operator++(int notused) function is used. In this
case, notused will always be passed the value 0. Therefor, if the difference between prefix
and postfix increment or decrement is important to your class objects, you will need to
implement both operator functions.

*/

/* 	Example 2 (Use – as "unary" and "binary" both in a program):  The solution is: you simply overload it twice, once as a binary operator and once as a unary operator. This program shows how: */

class coord { 
	public: 	
// all elements similar to Example 1 
coord operator-(coord ob2);  //binary
coord operator-(); };       //unary	coord coord :: operator-(){
		x = -x;
		y = -y;
	return *this ;}	coord coord :: operator-( coord ob2){
		coord temp ;
		temp.x = x - ob2.x;
		temp.y = y - ob2.y;
		return temp ; }
int main() { coord o1(10, 10), o2(5, 7);	  int x, y;
	o1=o1-o2;  	o1.get_xy(x, y);  cout<< "(o1 -o2) X:"<< x <<", Y:"<< y << "\n"; // subtraction 
	o1=-o1;  	o1.get_xy(x, y);  cout<< "(-o1) X:" << x << ", Y: " << y << "\n"; // negation 
	return 0; }



/*  
	This difference in the number of parameters is what makes it possible for the minus to be overloaded for both operations. 
	When the minus is overloaded as a binary operator, it takes one parameter. When the minus sign is used as a binary operator, the operator-(coord ob2) function is called. 
	When it is overloaded as a unary operator, it takes no parameter. When it is used as a unary minus, the operator-() function is called.



*/  
