
/*  ------------------------    chapter    ------------------------

	Insertion and inserter: In C++, the output operation is called an insertion and the << is called the insertion operator. (The reason for this term: an output operator inserts information into a stream).
	Overloading the << for output, creates an inserter function, or inserter for short.  All inserted functions have this general form:

ostream &operator<<(ostream &stream, class_name obj) {  /* body of inserter */ 
    return stream;	}
	The inserted function "ostream &operator<<" returns a reference to stream, which is of type ostream. This is required if the overloaded << is going to be used in a series of I/O expressions, such as cout<< ob1 << ob2 << ob3 ;
	The first parameter is a reference to an object of type ostream. This means that stream must be an output stream. (ostream is derived form the ios class.) 
	The second parameter receives the object that will be output. (This can also be a reference parameter). 


/*  ------------------------    chapter    ------------------------

	Extraction and extractor:  In C++, the >> is referred to as the extraction operator. The reason for this term is that the act of inputting information from a stream removes (that is, extracts) data from it.
	A function that overloads >> is called an extractor.  The general form of an extractor function is:

istream &operator>>(istream &stream, class_name &ob) { /* body of extractor */ 
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
		friend ostream & operator <<( ostream &stream , coord ob); 		/* inserter */
		friend istream & operator >>( istream &stream , coord &ob); 		/* extractor */
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
cout << ob.x << ", " << ob.y << '\n'; 	/* using "cout" instead of  "stream" */
return stream ;}
	Non-Friend inserter/extractor: If inserter/extractor are not friends to any class, they cannot use the private members of any class. However all public members are accessible.




*/  


*/  
