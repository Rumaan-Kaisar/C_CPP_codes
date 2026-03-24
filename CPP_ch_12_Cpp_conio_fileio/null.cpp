


// ----  rev[27-Nov-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


Mastery Skills Check
At this point you should be able to perform the following exercises and answer the questions.
1. Create an output manipulator that outputs three tabs and then sets the field width to 20.
Demonstrate that your manipulator works.
2. Create an input manipulator that reads and discards all non-alphabetical characters.
When the first alphabetical character is read, have the manipulator return it to the input
stream and return. Call this manipulator findalpha.
3. Write a program that copies a text file. In the process, reverse the case of all letters.
4. Write a program that reads a text file and then reports the number of times each letter
in the alphabet occurs in the file.
5. If you have not done so, add complete error checking to your solutions to Exercises 3 and
4 above.
6. What function positions the get pointer? What function positions the put pointer?


// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.
1. Following is a reworked version of the inventory class presented in the preceding chapter.
Write a program that fills in the functions store() and retrieve(). Next, create a small
inventory file on disk containing a few entries. Then, using random I/O, allow the user
to display the information about any item by specifying its record number.
# include <iostream >
# include <fstream >
# include <cstring >
using namespace std ;
# define SIZE 40
class inventory
{
char item [ SIZE ]; // name of item
int onhand ; // number on hand
double cost ; // cost of item
public :
inventory ( char *i, int o, double c)
{
strcpy (item , i);
onhand = o;
cost = c;
}
void store ( fstream & stream );
void retrieve ( fstream & stream );
friend ostream & operator <<( ostream &stream , inventory ob)
;
friend istream & operator >>( istream &stream , inventory &ob
);
};
ostream & operator <<( ostream &stream , inventory ob)
{
stream << ob. item << ": " << ob. onhand ;
stream << " on hand at $" << ob. cost << ’\n’;
return stream ;
}
istream & operator >>( istream &stream , inventory &ob)
{
cout << " Enter item name : ";
stream >> ob. item ;
cout << " Enter number on hand : ";
stream >> ob. onhand ;
cout << " Enter cost : ";
stream >> ob. cost ;
259TEACH YOURSELF
C++
return stream ;
}


2. As a special challenge, on your own, create a stack class for characters that stores them
in a disk file rather than in an array in memory.


// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-



// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. Create a manipulator that causes numbers to be displayed in scientific notation, using a
capital E.
2. Write a program that copies a text file. During the copy process, convert all tabs into the
correct number of spaces.
3. Write a program that searches a text file for a word specified on the command line. Have
the program display how many times the specified word is found. For simplicity, assume
that anything surrounded by whitespace is a word.
4. Show the statement that sets the put pointer to the 234th byte in a file linked to a stream
called out.
5. What functions report status information about the C++ I/O system?
6. Give one advantage of using the C++ I/O functions instead of the C-like I/O system.

// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-
