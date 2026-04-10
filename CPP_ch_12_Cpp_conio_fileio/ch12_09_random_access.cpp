
/*  ------------------------    Random Access    ------------------------

    Random Access:
        Normally, files are read or written "sequentially" (from start to end).
        But sometimes we want to "jump directly to a specific position" in the file.
        This is called RANDOM ACCESS.
    
        C++ provides two functions for this:
            seekg()     move input (read) position
            seekp()     move output (write) position

                istream& seekg(offset, origin);
                ostream& seekp(offset, origin);



    ----------------    seekg() and seekp()    ----------------

    Use the seekg() and seekp()  to perform RANDOM ACCESS (i.e. nonsequential access),
    these are members of the I & O stream classes, respectively.
    
    Important Note:
        Files used with seekg() and seekp() should usually be opened in BINARY "std::ios::binary"
        Because binary mode avoids character translation and ensures exact byte positions.

    Common forms:
                istream &seekg(off_type offset, seekdir origin);
                ostream &seekp(off_type offset, seekdir origin);

        off_type:
            is an "integer type" defined by "ios" that is capable of 
            containing the largest valid value that "offset" can have. 

        seekdir:
            is an enumeration defined by ios that has these values:
                ios::beg (Means-Seek from beginning of file)	
                ios::cur (Means-Seek from current location)	
                ios::end (Means-Seek from end of file)

        offset:
            how many bytes to move

        origin:
            where to start counting from


    File position pointers:
        C++ I/O system manages two pointers associated with a file. 
        The appropriate pointer is automatically applied for each I/O operation. 

        get pointer:
            where the next read will happen

        put pointer:
            where the next write will happen

        These two acts as separate position markers in a file.
        
        seekg() and seekp() can be used in nonsequential fashion.

        
    Functions:
        seekg() moves the "input/get (read)" pointer "offset" number of bytes from the specified "origin".
        seekp() moves the "output/put (write)" pointer "offset" number of bytes from the specified "origin".

    usage:
        jump to any byte
        modify a specific part of a file
        read data from the middle
        skip unwanted parts

        No need to read everything before it.



    --------  current position  --------

    To determine the current position of each file pointer use:

            pos_type tellg();
            pos_type tellp();

        tellg()     current read position
        tellp()     current write position

        They return the current byte location in the file (return pos_type).

        "pos_type" is an integer type defined by "ios" that is capable of 
            holding the "largest value" that defines a file position.



    --------  Overloaded versions of seekg() and seekp()  --------

    Following overloaded versions of seekg() and seekp() used to
    jump directly to a position returned by tellg() or tellp().
    
    Their prototypes are:
        istream &seekg( pos_type position );
        ostream &seekp( pos_type position );

    You can move directly to a known position using those.


    Example:
        A program can open a file for 
        
            # reading and writing
            # Jump to a specific byte
            # Replace one character there

                CLI: changer_prog file_name 10 X

            This changes the character at byte 10 to X.


    NOTE on CLI:
        Some programs take input like:

            "program filename position character"

        These values are received using:

            int main(int argc, char *argv[])

        *argv[] and argc are called the command line arguments. (Recall: C_Ch5_3_2_main_param.c)
*/




/* Example 1: The following program demonstrates the use of the seekp() function..

                It allows us to modify a specific character in a file.

 
                How to use: 
                    Specify a file name on the command line, followed by the number of the byte 
                    in the file you want to change, followed by the new character.
                
                    Provide command-line arguments in this order:

                    CLI:    changer_prog file_name 10 X

                    file_name:
                        the file to modify.
                        
                    Byte number:
                        position in the file (number of the byte in the file you want to change).

                    New character:
                        the character to write at that position.

                    Notice that the file is opened for read/write operations.


                seekp() is used to move the "put" pointer (output position) to the specified byte location.
                After seeking, the new character is written at that position.

                The name of the file and the location to begin reading from are specified on the CLI.
                    in.seekg( atoi(argv[2]), ios::beg );


                CLI:    ch12_07_file_io_basics_10 test_file 4 @
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if(argc !=4) { 
        std::cout << " Usage : CHANGE <filename> <byte> <char>\n"; 
        return 1;
    }

    std::fstream out( argv[1], std::ios::in | std::ios::out | std::ios::binary );   // file I/O in Binary node

    if(!out){
        std::cout << " Cannot open file.\n"; 
        return 1;
    }

    out.seekp( atoi(argv[2]), std::ios::beg );
    out.put(*argv[3]);

    out.close();

    return 0;
}




/* Example 2:  In the above program we've used seekp() to move the "put" pointer.
                Now following program uses seekg() to position the get pointer 
                    into the middle of a file named "in" 
                    and then displays the contents of that file from that point. 

                Specify the filename and starting point on the command line.

                CLI:    ch12_07_file_io_basics_11 accounts 4
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main( int argc, char *argv[]) {
    char ch;

    if(argc!=3){
        std::cout << " Usage : LOCATE <filename> <loc>\n";
        return 1;
    }

    std::ifstream in( argv[1], std::ios::in | std::ios::binary );

    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }
    
    in.seekg( atoi( argv[2]), std::ios::beg );

    while(!in.eof()) {
        in.get(ch);
        std::cout << ch;
    }

    in.close();

    return 0;
}




/* Example 3: Following program displays a text file backwards. 
                CLI:    ch12_07_file_io_basics_12 accounts
*/

#include <iostream>
#include <fstream>

int main( int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << " Usage : REVERSE <filename>\n";
        return 1;
    }

    std::ifstream in( argv[1], std::ios::in | std::ios::binary );

    if (!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    char ch;
    long i;

    // go to end of file ( less eof char )
    in.seekg(0, std::ios::end );

    i = (long)in.tellg();   // see how many bytes in file
    i -= 2;     // backup before eof

    for( ; i>=0; i--) {
        in.seekg(i, std::ios::beg);
        in.get(ch);
        std::cout << ch;
    }

    in.close();

    return 0;
}




/* Example 4: Following program swaps "each character pair" in a text file. 
                For example, if the file contains "1234", then after execution, the file will contain "2143".
                (For simplicity, you may assume that the file contains an even number of characters.)
                
                CLI:    ch12_07_file_io_basics_13 test
*/

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if(argc!=2) {
        std::cout << " Usage : SWAP <filename>\n";
        return 1;
    }

    // opne file for input / output
    std::fstream io_test( argv[1] , std::ios::in | std::ios::out | std::ios::binary );

    if(!io_test) {
        std::cout << " Cannot open file .\n";
        return 1;
    }

    char ch1, ch2;
    long i;

    // for(i=0; !io_test.eof(); i += 2) {
    //     io_test.seekg(i, std::ios::beg);
    //     io_test.get(ch1);
        
    //     if(io_test.eof()) continue;
    //     io_test.get(ch2);

    //     if(!io_test.eof()) continue;
    //     io_test.seekp(i, std::ios::beg);

    //     io_test.put(ch2);
    //     io_test.put(ch1);
    // }

    while(true) {

        io_test.seekg(i, std::ios::beg);

        if(!io_test.get(ch1))
            break;

        if(!io_test.get(ch2))
            break;

        io_test.seekp(i, std::ios::beg);

        io_test.put(ch2);
        io_test.put(ch1);

        i += 2;
    }

    io_test.close();

    return 0;
}




/* Example 5: Write a statement that sets the "put pointer" to the 234th byte 
                in a file linked to a stream called "out". 

            ans:
                The statement:
                                out.seekp(234, ios::beg);
*/




/* Example 6: What function positions the "get pointer"? 
              What function positions the "put pointer"?

            ans:
                To set the "get pointer", use seekg(). 
                To set the "put pointer", use seekp().
*/




/* Example 7: Following is a reworked version of the inventory class 
                (Example 8 of "ch12_05_inserter_extractor.cpp").

                Write a program that fills in the functions store() and retrieve().                
                Next, create a small inventory file on disk containing a few entries. 
                
                Then, using random I/O, allow the user to display the information about any item 
                    by specifying its record number.


                Following is an inventory class is created that stores 
                    the name of an item, 
                    the number on hand and 
                    its cost. 
                The program includes both an "inserter" and an "extractor" for this class.


                #include <iostream>
                #include <fstream>
                #include <cstring>

                #define SIZE 40

                // inventory class
                class inventory {
                        char item[SIZE];    // name of item
                        int onhand;     // number on hand
                        double cost;    // cost of item

                    public:
                        inventory(char *i, int o, double c) {
                            strcpy(item, i);
                            onhand = o;
                            cost = c;
                        }

                        // fill these functions
                        void store( fstream & stream );
                        void retrieve( fstream & stream );

                        friend std::ostream &operator<<(std::ostream &stream, inventory ob);    // inserter
                        friend std::istream &operator>>(std::istream &stream, inventory &ob);   // extractor
                };


                // inserter
                std::ostream &operator<<( std::ostream &stream, inventory ob ) {
                    stream << ob.item << ": " << ob.onhand;
                    stream << " on hand at $" << ob.cost << '\n';
                    return stream;
                }

                // extractor
                std::istream &operator>>( std::istream &stream, inventory &ob ) {
                    std::cout << " Enter item name : ";
                    stream >> ob.item;

                    std::cout << " Enter number on hand : ";
                    stream >> ob.onhand;
                    
                    std::cout << " Enter cost : ";
                    stream >> ob.cost;
                    
                    return stream;
                }


                int main() {
                    inventory ob(" hammer ", 4, 12.55);

                    std::cout << ob;
                    std::cin >> ob;
                    std::cout << ob;

                    return 0;
                }
*/

#include <iostream>
#include <fstream>
#include <cstring>

#define SIZE 40

// inventory class
class inventory {
        char item[SIZE];    // name of item
        int onhand;     // number on hand
        double cost;    // cost of item

    public:
        inventory(char *i, int o, double c) {
            strcpy(item, i);
            onhand = o;
            cost = c;
        }

        // fill these functions
        void store( std::fstream &stream );
        void retrieve( std::fstream &stream );

        friend std::ostream &operator<<(std::ostream &stream, inventory ob);    // inserter
        friend std::istream &operator>>(std::istream &stream, inventory &ob);   // extractor
};


// inserter
std::ostream &operator<<( std::ostream &stream, inventory ob ) {
    stream << ob.item << ": " << ob.onhand;
    stream << " on hand at $" << ob.cost << '\n';
    return stream;
}

// extractor
std::istream &operator>>( std::istream &stream, inventory &ob ) {
    std::cout << " Enter item name : ";
    stream >> ob.item;

    std::cout << " Enter number on hand : ";
    stream >> ob.onhand;
    
    std::cout << " Enter cost : ";
    stream >> ob.cost;
    
    return stream;
}

void inventory::store( std::fstream &stream ) {
    stream.write(item, SIZE);
    stream.write((char*) &onhand, sizeof(int));
    stream.write((char*) &cost, sizeof(double));
}

void inventory::retrieve( std::fstream &stream ) {
    stream.read(item, SIZE);
    stream.read((char*) &onhand, sizeof(int));
    stream.read((char*) &cost, sizeof(double));
} 


int main() {
    std::fstream inv("inv", std::ios::out | std::ios::binary );
    int i;

    inventory temp("", 0, 0.0);
    inventory pliers(" pliers ", 12, 4.95);
    inventory hammers(" hammers ", 5, 9.45);
    inventory wrenches(" wrenches ", 22, 13.90);
    inventory batteries(" 18650 batteries ", 60, 1.00);

    if(!inv) {
        std::cout << " Cannot open file for output.\n";
        return 1;
    }

    // write to file
    pliers.store(inv);
    hammers.store(inv);
    wrenches.store(inv);
    batteries.store(inv);

    inv.close();

    // open for input
    inv.open ("inv", std::ios::in | std::ios::binary);

    if(!inv){
        std::cout << " Cannot open file for input .\n";
        return 1;
    }

    // printing all the records
    std::cout << "\nAll records:\n\n";

    while(true) {
        temp.retrieve(inv);
        if(!inv) break;  // Check AFTER read: Did the read succeed?
        std::cout << temp;
    }

    /*  Alternative loop:
            while(inv.good()) {
                temp.retrieve(inv);
                std::cout << temp;
            }
    
        Note:
            Do not use while(stream.good()) to control a read loop.

        Why the last element prints twice:
            -> while(inv.good()) checks the stream state before attempting to read
            -> After successfully reading the last record ("batteries"), the stream is still "good" because the EOF flag isn't set until a read attempts to go past the end
            -> The loop condition passes, so temp.retrieve(inv) executes again
            -> This read fails (EOF reached), but retrieve() doesn't clear temp
                it still holds the data from the previous successful read ("batteries")
            -> std::cout << temp; prints the stale data again
            -> Only after this failed read does the stream set eofbit/failbit, 
                so the next loop check exits
    */

    inv.close();

    return 0;
}


