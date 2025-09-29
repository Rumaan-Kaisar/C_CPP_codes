
/*  ------------------------    inserter and extractor    ------------------------

    ----------------    inserter    ----------------

    Insertion Operator '<<' (Output):
        Output in C++ is called insertion, using the '<<' operator.
        Eg: It "inserts" data into an output stream (like cout).


        OVERLOADING '<<' creates an INSERTER function (or inserter for short).

            General form:

                    ostream &operator<<(ostream &stream, class_name obj) {
                        // body of inserter
                        return stream;
                    }

                Returns a reference to 'stream', which is of type 'ostream'. so we can chain: 
                    cout << ob1 << ob2 << ob3;.

                First parameter: 
                    'ostream&' reference to an object of type ostream (output stream).
                    So 'stream' must be an output stream (e.g., cout, file streams).
                    ('ostream' is derived form the ios class.) 

                Second parameter: 
                    receives the object that will be output or printed
                    (This can also be a reference parameter, i.e. can be passed by value or const reference for efficiency).

            Inserter Cannot be a member function because 
                the left operand (cout) is not of the class type.



    ----------------    extractor    ----------------

    Extraction operator '>>' (Input):
        Input in C++ is called "extraction", and the >> is referred to as the extraction operator. 
        Eg: It "extracts" data from an input stream (like cin).

        The reason for this term is that the act of "inputting information from a stream" 
            removes (i.e. extracts) data from it.


        OVERLOADING '>>' creates an EXTRACTOR function.

            General form:

                    istream &operator>>(istream &stream, class_name &ob) {
                        // body of extractor
                        return stream;
                    }

                Return a reference to 'stream' , which is of type 'istream' an input stream. So chaining works: 
                    cin >> ob1 >> ob2;.

                First parameter: 
                    reference to an 'istream' (input stream).
                    So "istream&" must be an input stream (e.g., cin).

                Second parameter: 
                    reference to the object that receives input.


            Like inserter, an extractor cannot be a member function because
                left operand is a stream, not a class object.



---- rev[29-sep-2025] ----

Inserter and extractor cannot be a member of a class:
If an overloaded operator function is a member of a class, the left operand (which implicitly passed through this and also generates the call to the operator) must be an object of that class. 

	When you create an inserter/extractor, the left operand is a stream and the right operand is the object that you want to output/input.  Therefore, an inserter/extractor cannot be a member function.
	Inserter and extractor as friend of a class:  Inserters/extractors can be friends of the class. In fact, in most programming situations you will encounter, an overloaded inserter will be a friend of the class for which it was created.

----  GPT ----

Why Not Class Members?:

    If << or >> were class member functions, the left operand would have to be a class object.

    But in I/O, the left operand is a stream (cout, cin).

    So inserters/extractors cannot be class members.



---- Qwen ----


🔹 Why Inserters/Extractors Can’t Be Member Functions
For member operator overloading, the left operand must be an object of the class.
But in cout << obj, the left operand is cout (a stream), not obj.
Hence, these operators must be non-member functions.


--------------


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


Using Friend Functions:

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



General vs. Non-General Inserters:

    Good practice: use the passed stream (cout, file, etc.) so the code works for any stream.

    ostream &operator<<(ostream &stream, coord ob) {
        stream << ob.x << ", " << ob.y;
        return stream;
    }


    Bad practice: hard-coding with cout ties the inserter only to console output.



Non-Friend Inserters/Extractors:

    If not declared as friends, they cannot access private members.

    They can only use public members of the class.







----  Qwen  ----

Here is the simplified pointwise version of the content from (8.5 + 8.6) on Insertion/Extraction Operators and Inserters/Extractors:






🔹 Use of friend Keyword
Inserters/extractors are often made friends of the class.
This gives them access to private members (like x, y in coord).
Without friend, they can only access public members.





✅ Most common practice: Declare inserter/extractor as friend functions. 

🔹 Example: coord Class with Inserter & Extractor
cpp

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
