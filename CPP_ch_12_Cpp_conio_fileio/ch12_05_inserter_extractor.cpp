
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



    ---- '<<' and '>>' as Class Members ----

    Inserter and extractor cannot be a member of a class:
        If << or >> were class member functions, the left operand would have to be a class object.
        But in I/O, When you create an inserter/extractor, the left operand is a stream (cout, cin).
            and the right operand is the object that you want to output/input.
        So inserters/extractors cannot be a member function of a class.

    Recall: 
        If an overloaded operator function is a member of a class, 
        the left operand (which implicitly passed through 'this' and also generates the call to the operator) must be an object of that class. 

        But in "cout << obj", the left operand is "cout" (a stream), not obj.
        Hence, these operators must be non-member functions.



    ---- '<<' and '>>' as friend ----

    Inserter and extractor as friend of a class:  
        Inserters/extractors are often made friends of the class.
        An overloaded inserter will be a friend of the class for which it was created.
        This gives them access to private members (like x, y in coord).

        Example:
                class coord {
                        int x, y;
                    public:
                        coord(int i=0, int j=0): x(i), y(j) {}
                        friend ostream &operator<<(ostream &, coord);
                        friend istream &operator>>(istream &, coord &);
                };



    ---- Making Inserters/Extractors General ----

    Make inserter/extractor as general as possible:
        Always use the passed 'stream' parameter (e.g., stream << ...), not hard-coded 'cout' or 'cin' 
            (so that the code works for any stream.)

        In this case, the I/O statement inside the inserter/extractor outputs/inputs the values of x and y to "stream", 
            which is whatever stream is passed to the function 
            ( "stream" is general for cin, cout and both "<<" & ">>" can be used with it). 

        In the following chapter we'll see, when written correctly 
            the same inserter that outputs to the 'screen' can be used to output to 'any stream'. 

        This ensures the same function works with:
            cout, cerr as output
            File streams (ofstream, ifstream)
            String streams (stringstream)

        Avoid this mistake:
                cout << ob.x << ob.y;    // Bad: tied only to console

        Do this instead:
                stream << ob.x << ob.y;  // Good: works with any output stream


    However the following is not for general streaming:
        In this case, the output statement is "hard-coded" to display information on the standard output device linked to "cout". 
        This prevents the inserter from being used by 'other streams'. 

        Bad practice: 
                
                // hard-coding with 'cout' ties the inserter only to 'console output'.

                ostream &operator<<(ostream &stream, coord ob){
                    cout << ob.x << ", " << ob.y << '\n'; 	// using "cout" instead of  "stream"
                    return stream;
                }

        Good practice: 

                // use the passed stream (cout, file, etc.) 

                ostream &operator<<(ostream &stream, coord ob) {
                    stream << ob.x << ", " << ob.y;
                    return stream;
                }



    ----  Non-Friend Inserters/Extractors  ----

    If inserter/extractor are not friends to any class, they cannot use the "private members" of any class. 
    However all public members are accessible.

*/  



// ---- rev[03-Oct-2025]  ----

/* Example 1: This program contains an inserter and an extractor for the coord class. */


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





class coord {int x, y;
public:
coord() { x = 0; y = 0; }
coord(int i, int j) { x = i; y = j; }
friend ostream & operator <<( ostream &stream , coord ob);      // inserter 
friend istream & operator >>( istream &stream , coord &ob);     // extractor
};


ostream &operator<<(ostream &stream, coord ob){
stream << ob.x << ", " << ob.y << '\n';
return stream ; }
istream &operator>>(istream &stream, coord &ob){
cout << " Enter coordinates : ";
stream >> ob.x >> ob.y;
return stream ; }

int main() { coord a(1, 1) , b(10 , 23);
cout << a << b;
cin >> a;
cout << a;
return 0; }




🔹 Example: coord Class with Inserter & Extractor
cpp



