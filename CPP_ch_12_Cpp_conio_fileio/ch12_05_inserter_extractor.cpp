
/*  ------------------------    inserter and extractor    ------------------------

    ---- rev[25-sep-2025] ----

(8.5 + 8.6)
	Insertion and inserter: In C++, the output operation is called an insertion and the << is called the insertion operator. (The reason for this term: an output operator inserts information into a stream).
	Overloading the << for output, creates an inserter function, or inserter for short.  All inserted functions have this general form:

ostream &operator<<(ostream &stream, class_name obj) {  // body of inserter 
    return stream;	}
	The inserted function "ostream &operator<<" returns a reference to stream, which is of type ostream. This is required if the overloaded << is going to be used in a series of I/O expressions, such as cout<< ob1 << ob2 << ob3 ;
	The first parameter is a reference to an object of type ostream. This means that stream must be an output stream. (ostream is derived form the ios class.) 
	The second parameter receives the object that will be output. (This can also be a reference parameter). 


/*  ------------------------    chapter    ------------------------

	Extraction and extractor:  In C++, the >> is referred to as the extraction operator. The reason for this term is that the act of inputting information from a stream removes (that is, extracts) data from it.
	A function that overloads >> is called an extractor.  The general form of an extractor function is:

istream &operator>>(istream &stream, class_name &ob) { // body of extractor
    return stream; 	}
	Extractors return a reference to stream " istream &operator>>", which is of type istream an input stream. 
	The first parameter must be a reference to an input stream. 
	The second parameter is a reference to the object that is receiving input.
	Inserter and extractor cannot be a member of a class:  If an overloaded operator function is a member of a class, the left operand (which implicitly passed through this and also generates the call to the operator) must be an object of that class. 
	When you create an inserter/extractor, the left operand is a stream and the right operand is the object that you want to output/input.  Therefore, an inserter/extractor cannot be a member function.
	Inserter and extractor as friend of a class:  Inserters/extractors can be friends of the class. In fact, in most programming situations you will encounter, an overloaded inserter will be a friend of the class for which it was created.
	Example 1: This program contains an inserter and an extractor for the coord class.
class coord {	int x, y;
	public:
		coord() { x = 0; y = 0; }
		coord(int i, int j) { x = i; y = j; }
		friend ostream & operator <<( ostream &stream , coord ob); 		// inserter 
		friend istream & operator >>( istream &stream , coord &ob); 		// extractor
		};
ostream &operator<<(ostream &stream, coord ob){
		stream << ob.x << ", " << ob.y << '\n';
		return stream ; }
istream &operator>>(istream &stream, coord &ob){
		cout << " Enter coordinates : ";
		stream >> ob.x >> ob.y;
		return stream ; }	int main() { coord a(1, 1) , b(10 , 23);
		cout << a << b;
		cin >> a;
		cout << a;
		return 0; }
	Make inserter/extractor as general as possible: In this case, the I/O statement inside the inserter/extractor outputs/inputs the values of x and y to "stream", which is whatever stream is passed to the function ( "stream" is general for cin, cout and both "<<" & ">>" can be used with it). As you will see in the following chapter, when written correctly the same inserter that outputs to the screen can be used to output to any stream. 
	However the following is not for general streaming. In this case, the output statement is hard-coded to display information on the standard output device linked to cout. This prevents the inserter from being used by other streams. 

ostream &operator<<(ostream &stream, coord ob){
cout << ob.x << ", " << ob.y << '\n'; 	// using "cout" instead of  "stream"
return stream ;}
	Non-Friend inserter/extractor: If inserter/extractor are not friends to any class, they cannot use the private members of any class. However all public members are accessible.




*/  




/* 

----  GPT  ----

Here’s a simplified, pointwise version of your text:

Insertion (Output)

Output in C++ is called insertion, using the << operator.

Overloading << creates an inserter function.

General form:

ostream &operator<<(ostream &stream, class_name obj) {
    // body of inserter
    return stream;
}


Returns a reference to ostream so we can chain: cout << ob1 << ob2 << ob3;.

First parameter: reference to an ostream (output stream).

Second parameter: object to output (usually by reference).

Extraction (Input)

Input in C++ is called extraction, using the >> operator.

Overloading >> creates an extractor function.

General form:

istream &operator>>(istream &stream, class_name &ob) {
    // body of extractor
    return stream;
}


Returns a reference to istream so chaining works: cin >> ob1 >> ob2;.

First parameter: reference to an istream (input stream).

Second parameter: reference to the object that receives input.

Why Not Class Members?

If << or >> were class member functions, the left operand would have to be a class object.

But in I/O, the left operand is a stream (cout, cin).

So inserters/extractors cannot be class members.

Using Friend Functions

To access private members, inserters/extractors are usually declared as friends of the class.

Example:

class coord {
    int x, y;
public:
    coord(int i=0, int j=0): x(i), y(j) {}
    friend ostream &operator<<(ostream &, coord);
    friend istream &operator>>(istream &, coord &);
};


This allows direct access to private members x and y.

General vs. Non-General Inserters

Good practice: use the passed stream (cout, file, etc.) so the code works for any stream.

ostream &operator<<(ostream &stream, coord ob) {
    stream << ob.x << ", " << ob.y;
    return stream;
}


Bad practice: hard-coding with cout ties the inserter only to console output.

Non-Friend Inserters/Extractors

If not declared as friends, they cannot access private members.

They can only use public members of the class.

Would you like me to also re-explain with an example table (showing inserter vs extractor side by side for clarity), or keep it in this pointwise style?




----  Qwen  ----

Here is the simplified pointwise version of the content from (8.5 + 8.6) on Insertion/Extraction Operators and Inserters/Extractors:

🔹 Insertion Operator (<<) – Output
The << operator is called the insertion operator.
It "inserts" data into an output stream (like cout).
Overloading << creates a function known as an inserter.
✅ General Form of Inserter:
cpp


1
2
3
4
⌄
ostream& operator<<(ostream& stream, class_name obj) {
    // output obj data using 'stream'
    return stream;
}
Key Points:
Returns a reference to ostream → allows chaining:
cout << a << b << c;
First parameter: ostream& → must be an output stream (e.g., cout, file streams).
Second parameter: object to be printed (can be passed by value or const reference for efficiency).
Cannot be a member function because the left operand (cout) is not of the class type.
🔹 Extraction Operator (>>) – Input
The >> operator is called the extraction operator.
It "extracts" data from an input stream (like cin).
Overloading >> creates a function known as an extractor.
✅ General Form of Extractor:
cpp


1
2
3
4
⌄
istream& operator>>(istream& stream, class_name& obj) {
    // input data into obj using 'stream'
    return stream;
}
Key Points:
Returns a reference to istream → allows chaining:
cin >> a >> b;
First parameter: istream& → must be an input stream (e.g., cin).
Second parameter: reference to the object receiving input (must be modifiable).
Like inserter, cannot be a member function — left operand is a stream, not a class object.
🔹 Why Inserters/Extractors Can’t Be Member Functions
For member operator overloading, the left operand must be an object of the class.
But in cout << obj, the left operand is cout (a stream), not obj.
Hence, these operators must be non-member functions.
🔹 Use of friend Keyword
Inserters/extractors are often made friends of the class.
This gives them access to private members (like x, y in coord).
Without friend, they can only access public members.
✅ Most common practice: Declare inserter/extractor as friend functions. 

🔹 Example: coord Class with Inserter & Extractor
cpp


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
⌄
⌄
⌄
⌄
class coord {
    int x, y;
public:
    coord(int i = 0, int j = 0) : x(i), y(j) {}
    friend ostream& operator<<(ostream&, coord);
    friend istream& operator>>(istream&, coord&);
};

// Inserter
ostream& operator<<(ostream& stream, coord ob) {
    stream << ob.x << ", " << ob.y << '\n';
    return stream;
}

// Extractor
istream& operator>>(istream& stream, coord& ob) {
    cout << "Enter coordinates: ";
    stream >> ob.x >> ob.y;
    return stream;
}

int main() {
    coord a(1,1), b;
    cout << a;        // Output
    cin >> b;         // Input
    cout << b;
    return 0;
}
🔹 Make Inserters/Extractors General
Always use the passed stream parameter (e.g., stream << ...), not hard-coded cout or cin.
This ensures the same function works with:
cout, cerr → output
File streams (ofstream, ifstream)
String streams (stringstream)
🚫 Avoid this mistake:

cpp


1
cout << ob.x << ob.y;  // Bad: tied only to console
✅ Do this instead:

cpp


1
stream << ob.x << ob.y; // Good: works with any output stream
🔹 Non-Friend Inserters/Extractors
If not declared as friends, the function:
Cannot access private members of the class.
Can only use public methods or getters to read/write data.
Less common, but possible if class provides public access.
✅ Summary
Purpose
Output objects
Input objects
Return Type
ostream&
istream&
1st Param
ostream& stream
istream& stream
2nd Param
Object (by value/ref)
Object
by reference
Must be
friend
?
Recommended (for private access)
Recommended
Can be member?
❌ No
❌ No

💡 Inserters and extractors enable natural syntax for I/O and support any stream type when written correctly.

*/
