
/*  ------------------------    operator overloading : unary    ------------------------

Overloading a unary operator


11.11 Overloading A UNARY Operator
Overloading a unary operator is similar to overloading a binary operator except that there is only one operand to deal with. 
	When you overload a unary operator using a member function, the function has no parameters. 
	Since there is only one operand, it is this operand that generates the call to the operator function. 



	Example 1:  The following program overloads the increment operator (++) relative to the coord class

class coord { 
	public: 	
// all elements similar to Example 1 
coord operator++(); 	    
}; 	crood coord::operator++(){
			x++;
			y++;
	   return *this ;}	int main(){coord o1(10, 10);  int x, y;
	    ++o1; // increment an object 
	    o1.get_xy(x, y); 
	    cout<<"(++o1) X:"<<x<<", Y:"<<y;
	    return 0;}

	++ is designed to increase its operand by 1, the overloaded ++ modifies the object it operates upon. 
	The function returns the object that it increments allowing ++ to be used as part of a larger statement, such as: o2 = ++o1;
	There is no rule that says we must overload a unary operator so that it reflects its normal meaning. 
	In early version of C++ there was no way to determine whether an overloaded ++ or --  preceded or followed its operand. That is these two statements would have been identical:  o1++;  and   ++o1;
	In modern C++ to distinguish between these two statements we declare following by which the compiler can distinguish.
coord coord :: operator++( int notused );
	If the ++ operator precedes its operand, the operator++() function is called. 
	If the ++ follows its operand, the operator++( int notused ) function is used. In this case, notused will always be passed the value 0. 
	So, if the difference between prefix and postfix increment or decrement is important to your class objects, you will need to implement both operator functions.
coord coord :: operator++();
coord coord :: operator++( int notused );



	Example 2 (Use – as "unary" and "binary" both in a program):  The solution is: you simply overload it twice, once as a binary operator and once as a unary operator. This program shows how:

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

	This difference in the number of parameters is what makes it possible for the minus to be overloaded for both operations. 
	When the minus is overloaded as a binary operator, it takes one parameter. When the minus sign is used as a binary operator, the operator-(coord ob2) function is called. 
	When it is overloaded as a unary operator, it takes no parameter. When it is used as a unary minus, the operator-() function is called.



*/  
