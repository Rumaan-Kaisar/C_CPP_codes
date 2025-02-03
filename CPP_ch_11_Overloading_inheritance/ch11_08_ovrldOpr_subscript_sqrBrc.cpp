
/*  ------------------------    overloading "subscript" : []-operator   ------------------------

    Overloading The '[]' SUBSCRIPT Operator:
        The general form of a member "operator[]()" function is:
        
                return_type class_name::operator[](int index) {
                    // Function implementation
                }

    // rev[03-Feb-2025]


	Technically, the parameter does not have to be of type int, but operator[ ]() functions are typically used to provide array subscripting and as such an integer value is generally used.
	In C++, the [] is considered a binary operator for the purposes of overloading. 
	The [] can be overloaded only by a member function. 
	To understand how the [] operator works, assume that an object called O is indexed as: O[9]; This index will translate into the following call to the operator[]() function:
O.operator[](9)
	The value of the expression within the subscripting operator is passed to the operator[]() function in its explicit parameter. 
	The "this" pointer will point to O, the object that generated the call.
	Example 1: In the following program, arraytype declares an array of five integers. 
[1]	Its constructor function initializes each member of the array. 
[2]	The overloaded operator[]() function returns the value of the element specified by its parameter.

const int SIZE = 5;
class arraytype { int a[ SIZE ];
		public :
	  arraytype() { int i;
	  for(i=0; i<SIZE; i++) a[i] = i; }
	  int operator[](int i) {return a[i]; } };	int main() { 	arraytype ob;
		int i;
		for(i=0; i< SIZE; i++)
		cout << ob[i] << " ";
	return 0; }
 [The initialization of the array a by the constructor in this and the following programs is for the sake of illustration only. It is not required.]
	Example 2 -Assigning values to & form using reference and []: It is possible to design the operator[]() function in such a way that the [] can be used on both the left and right sides of an assignment statement (i.e. a=b[i] and b[i]=a. Assigning values to & form array ). To do this, return a reference to the element being indexed. 

class arraytype
{. . . . 
public: 
/* as same as Example 1 of 11.14 */
int &operator[](int i){return a[i]; }    //reference
};	int main(){ arraytype ob;  int i;
      for(i=0; i<SIZE; i++) cout<<ob[i]<<" ";
cout << "\n";
/* add 10 to each element in the array */
for(i=0; i< SIZE ; i++){
		ob[i] = ob[i ]+10;}  // [] on left of =
      for(i=0; i<SIZE; i++) cout<<ob[i]<<" ";
return 0;}
	Because the operator[]() function now returns a reference to the array element indexed by i, it can be used on the left side of an assignment to modify an element of the array (just like normal arrays).
	Example 3 (Safe array): Recall that a safe array is an array that is encapsulated within a class that performs bounds checking. This approach prevents the array boundaries from being overrun. 
	To create a safe array with overloaded [] operator, simply add bounds checking to the operator[]() function. The operator[]() must also return a reference to the element being indexed.  Following program proves that it works by generating a boundary error:
{ public:. . . . 
/* as same as Example 1 of 11.14 */
int &operator[](int i) }; 			//reference
/* only declaration given inside class */	/* Bound checks inside the if statement */
int &arraytype :: operator[](int i){
if(i<0 || i>(SIZE-1)){
   cout<<i<< "is out of bounds.\n"; exit(1);}
return a[i]; }
	int main() { 	arraytype ob;  int i;
			for(i=0; i<SIZE; i++) cout<< ob[i] << " "; /* this is OK */ 
			ob[SIZE +100] = 99;  /* generates a run - time error because SIZE +100 is out of range */
		return 0;}
	In this program, when the statement ob[ SIZE +100] = 99; executes, the boundary error is intercepted by operator[]() and the program is terminated before any damage can be done.
	Remark 1: Because the overloading of the [] operator allows you to create safe arrays that look and act just like regular arrays.
	Remark 2: Be careful. A safe array adds overhead that might not be acceptable in all situations.  However, in applications in which you want to be sure that a boundary error does not take place, a safe array will be worth the effort.



*/  
