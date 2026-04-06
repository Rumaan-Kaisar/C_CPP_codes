
/*  ------------------------    Checking I/O Status    ------------------------

    iostate:
        The status of a stream is stored in an "iostate" object 
        It is an enumeration defined in "ios".

            goodbit     No errors occurred
            eofbit      End-of-file has been encountered
            failbit     A nonfatal I/O error has occurred
            badbit      A fatal I/O error has occurred


    Ways to Check I/O Status:
        There are two ways in which you can obtain I/O status information. 

            Using "rdstate()"
            Using "Status Check Functions"

        rdstate():
            It is a member of ios. It has this prototype: 	

                iostate rdstate();

            It returns the current status of the error state flags. 
            If no error: returns "goodbit" otherwise, an "error flag" is returned.


        Status Check Functions:
            These are ios member functions.
            These return "true" if the condition is set, "false" otherwise:

                bool eof()          true if end-of-file "eofbit" is set.
                bool bad()          true if fatal error "badbit" occurred.
                bool fail()         true if non-fatal error "failbit" or "badbit" is set.
                bool good()         true only if "no errors" (i.e., "goodbit" is set).

            Note: "fail()" returns true for both "failbit" and "badbit".



    ----------------    clear(): Clearing Error States    ----------------

    Use the clear() to clear an error before your program continues 
    It is a "ios" member function clear() whose prototype is:

                void clear(iostate flags = ios::goodbit);

        It resets the error flags.
        If "flags" is goodbit (as it is by default), all error flags are cleared. 
        Otherwise, pass a specific flag to set the new state. (optional)

    Note: Use after handling an error to resume normal stream operations.



    Always check "stream status" after "critical I/O operations" to handle errors gracefully.

    Function            Purpose
    ----------------------------------------------------------------
    rdstate()           Get full status (use with `iostate`)
    eof()               Check for end-of-file
    bad()               Check for fatal error
    fail()              Check for non-fatal or fatal error
    good()              True only if no errors
    clear()             Reset error flags
*/




/* Example 1: Following uses rdstate() to detect a file error for a  input file stream named "in". 
                This program displays a text file's contents and uses checkstatus() to report errors. 

                Note that it will always report an 'EOF encountered' message after the loop finishes, 
                which is expected behavior when the file ends (the final call to checkstatus() happens).

                CLI:    ch12_07_file_io_basics_14 test
*/

#include <iostream>
#include <fstream>

void checkstatus (std::ifstream &in);

int main(int argc, char *argv[]) {
    if(argc !=2) {
        std::cout << " Usage : DISPLAY <filename>\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    
    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    char c;
    while(in.get(c)) {
        std::cout << c;
        checkstatus(in);
    }

    checkstatus(in);    // check final status
    in.close();
    return 0;
}


// Using rdstate() to Detect Errors
void checkstatus(std::ifstream &in) {
    std::ios::iostate i;
    
    i = in.rdstate();
    if(i & std::ios::eofbit)    std::cout << "EOF encountered\n";
    else if(i & std::ios::failbit)  std::cout << "Non-fatal I/O error\n";
    else if(i & std::ios::badbit)   std::cout << "Fatal I/O error\n";
}




/* Example 2: Following program displays a text file,
                it uses good() to detect a file error for a input file stream named "in".

                Checks if stream is not in good state and not just at EOF.
                Helps distinguish between normal end-of-file and actual errors.

                CLI:    ch12_07_file_io_basics_15 test
*/

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    char ch;
    
    if(argc != 2) {
        std::cout << " Usage : PR <filename>\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    while(!in.eof()) {
        in.get(ch);

        // Using good() for Error Handling
        if(!in.good() && !in.eof()) {
            std::cout << "I/O Error ... terminating \n";
            return 1;
        }
        std::cout << ch;
    }

    in.close();

    return 0;
}




/* Example 3: Add error checking to "Example 3" and "Example 4" from 
                the preceding section "ch12_09_random_access.cpp".
*/

// Following program displays a text file backwards. 
// CLI:    ch12_07_file_io_basics_16 accounts

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
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
    if(!in.good()) return 1;    // Error Handling

    i = (long)in.tellg();   // see how many bytes in file
    if(!in.good()) return 1;    // Error Handling

    i -= 2;     // backup before eof

    for( ; i>=0; i--) {
        in.seekg(i, std::ios::beg);
        if(!in.good()) return 1;    // Error Handling

        in.get(ch);
        if(!in.good()) return 1;    // Error Handling

        std::cout << ch;
    }

    in.close();
    if(!in.good()) return 1;    // Error Handling

    return 0;
}



// Following program swaps "each character pair" in a text file. 
// CLI:    ch12_07_file_io_basics_17 test

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


    while(true) {

        io_test.seekg(i, std::ios::beg);
        if(!io_test.good()) return 1;   // Error check

        if(!io_test.get(ch1))
            break;

        if(!io_test.get(ch2))
            break;

        if(!io_test.good()) return 1;   // Error check


        io_test.seekp(i, std::ios::beg);
        if(!io_test.good()) return 1;   // Error check

        io_test.put(ch2);
        if(!io_test.good()) return 1;   // Error check

        io_test.put(ch1);
        if(!io_test.good()) return 1;   // Error check

        i += 2;
    }

    io_test.close();
    if(!io_test.good()) return 1;   // Error check

    return 0;
}




/* Example 4: What functions report status information about the C++ I/O system? 

                ans:
                    The functions are rdstate(), good(), eof(), fail(), and bad().
*/




/* Example 5: Following program copies a text file and reverse case of letters. */

#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[]) {
    char ch;

    if(argc!=3) {
        std::cout << " Usage : COPYREV <source> <target>\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in){
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    std::ofstream out(argv[2]);

    if(!out) {
        std::cout << " Cannot open output file .\n";
        return 1;
    }

    while(!in.eof()) {
        ch = in.get();

        if(!in.eof()) {
            if(islower(ch)) ch = toupper(ch);
            else ch = tolower(ch);
            out.put(ch);
        }
    }

    in.close();
    out.close();

    return 0;
}

