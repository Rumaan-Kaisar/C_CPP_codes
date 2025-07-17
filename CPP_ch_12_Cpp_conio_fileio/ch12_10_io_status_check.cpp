
/*  ------------------------    chapter    ------------------------


12.9 Checking I/O Status
The current status of an I/O stream is described in an object of type iostate, it is an enumeration defined by ios that includes members:

[1]	goodbit (Means-No errors occurred)	[2]	eofbit (Means-End-of-file has been encountered)	[3]	failbit (Means-A nonfatal I/O error has occurred)	[4]	badbit (Means-A fatal I/O error has occurred)
	There are two ways in which you can obtain I/O status information. 
	First, you can call the rdstate() function, which is a member of ios. It has this prototype: 	iostate rdstate();
	It returns the current status of the error flags. 
	rdstate() returns goodbit when no error has occurred. Otherwise, an error flag is returned.
	Second way to determine whether an error has occurred is by using one or more of these ios member functions:

[1]	bool eof();
The eof() was discussed earlier.	[2]	bool bad();
The bad() returns true if badbit is set.	[3]	bool fail();
The fail() returns true if failbit is set.	[4]	bool good(); 
The good() returns true if there are no errors. 
	Otherwise they return false.
	clear(): To clear an error before your program continues use the ios member function clear() whose prototype is:

void clear(iostate flags = ios::goodbit);
	If flags is goodbit (as it is by default), all error flags are cleared. Otherwise, set flags to the settings you desire.
	Example 1: Following uses rdstate() to detect a file error for a file named "in":

void checkstatus(ifstream &in) { 	ios :: iostate i;
i = in.rdstate();
if(i & ios::eofbit ) 	cout << "EOF encountered \n";
else if(i & ios::failbit ) cout << "Non - Fatal I/O error \n";
else if(i & ios::badbit ) 	cout << "Fatal I/O error \n"; }
	Example 2: Following uses good() to detect a file error for a file named "in":
if(!in.good() && !in.eof()) { cout << "I/O Error ... terminating \n"; return 1; }


*/  
