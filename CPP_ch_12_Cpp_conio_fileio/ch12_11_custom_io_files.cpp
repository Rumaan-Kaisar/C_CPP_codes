
/*  ------------------------    chapter    ------------------------
12.11 Customized I/O And Files
Overloaded inserters and extractors, as well as I/O manipulators, can be used with any stream as long as they are written in a general manner. Because all C++ streams are the same, for example, the same overloaded inserter function can be used to output to the screen or to a file with no changes whatsoever.
	If you "hard-code" a specific stream into an I/O function, its use is, of course, limited to only that stream. This is why you were urged to generalize your I/O functions whenever possible. (Recall 12.5 : Make inserter/extractor as general as possible)
	Example 1: In the following program, the coord class overloads the << and >> operators. Notice that you can use the operator functions to write both to the screen and to a file.

#include <iostream >
#include <fstream >
using namespace std;
class coord { int x, y;
public :
coord (int i, int j) { x = i; y = j; }
friend ostream &operator <<( ostream &stream , coord ob);
friend istream &operator >>( istream &stream , coord &ob);
};

ostream &operator <<( ostream &stream , coord ob){
			stream << ob.x << ' ' << ob.y << '\n';
			return stream ;}
istream & operator >>( istream &stream , coord &ob){
			stream >> ob.x >> ob.y;
			return stream ;}	int main() {coord o1(1, 2) , o2(3, 4);
	ofstream out(" test ");
	if (!out ) { cout << " Cannot open output file .\n";
		return 1; }
	out << o1 << o2;
	out . close ();
	ifstream in(" test ");
	if (!in) {	 cout << " Cannot open input file .\n";
		return 1; }
	coord o3(0, 0) , o4(0, 0);
	in >> o3 >> o4;
	cout << o3 << o4;
	in.close ();
return 0; }






*/  
