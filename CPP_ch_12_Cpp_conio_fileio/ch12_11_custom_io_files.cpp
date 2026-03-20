
/*  ------------------------    Customized I/O And Files    ------------------------
Customized I/O And Files
Overloaded inserters and extractors, as well as I/O manipulators, can be used with any stream as long as they are written in a general manner. Because all C++ streams are the same, for example, the same overloaded inserter function can be used to output to the screen or to a file with no changes whatsoever.
   If you "hard-code" a specific stream into an I/O function, its use is, of course, limited to only that stream. This is why you were urged to generalize your I/O functions whenever possible. (Recall 12.5 : Make inserter/extractor as general as possible)
   Example 1: In the following program, the coord class overloads the << and >> operators. Notice that you can use the operator functions to write both to the screen and to a file.

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
            return stream ;}    int main() {coord o1(1, 2) , o2(3, 4);
    ofstream out(" test ");
    if (!out ) { cout << " Cannot open output file .\n";
        return 1; }
    out << o1 << o2;
    out . close ();
    ifstream in(" test ");
    if (!in) {   cout << " Cannot open input file .\n";
        return 1; }
    coord o3(0, 0) , o4(0, 0);
    in >> o3 >> o4;
    cout << o3 << o4;
    in.close ();
return 0; }



----  Qwen  ----

# Customized I/O And Files

**1. General Principle of Stream Operations**
*   **Versatility:** Overloaded inserters (`<<`), extractors (`>>`), and I/O manipulators can be used with **any** stream.
*   **Condition:** This works provided they are written in a general manner.
*   **Reasoning:** All C++ streams share the same underlying structure.
*   **Benefit:** The same overloaded inserter function can output to the screen (`cout`) or to a file (`ofstream`) without requiring any changes.

**2. Best Practices and Warnings**
*   **Avoid Hard-Coding:** Do not "hard-code" a specific stream (e.g., `cout`) into an I/O function.
*   **Consequence:** Hard-coding limits the function's use to only that specific stream.
*   **Recommendation:** Always generalize I/O functions whenever possible (e.g., use `ostream&` or `istream&` as parameters).
    *   *(Reference: Recall section 12.5 – Make inserter/extractor as general as possible)*

**3. Illustrative Example**
*   **Scenario:** A `coord` class overloads the `<<` and `>>` operators.
*   **Demonstration:** The program uses these operator functions to write data to both the screen and a file.

**4. Source Code**
```cpp
#include <iostream>
#include <fstream>
using namespace std;

class coord {
    int x, y;
public:
    coord(int i, int j) { x = i; y = j; }
    
    // Friend functions for overloading operators
    friend ostream &operator <<(ostream &stream, coord ob);
    friend istream &operator >>(istream &stream, coord &ob);
};

// Overload << operator
ostream &operator <<(ostream &stream, coord ob) {
    stream << ob.x << ' ' << ob.y << '\n';
    return stream;
}

// Overload >> operator
istream &operator >>(istream &stream, coord &ob) {
    stream >> ob.x >> ob.y;
    return stream;
}

int main() {
    coord o1(1, 2), o2(3, 4);
    
    // Writing to File
    ofstream out("test");
    if (!out) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    out << o1 << o2; // Uses overloaded <<
    out.close();
    
    // Reading from File
    ifstream in("test");
    if (!in) {
        cout << "Cannot open input file.\n";
        return 1;
    }
    
    coord o3(0, 0), o4(0, 0);
    in >> o3 >> o4; // Uses overloaded >>
    
    // Output to Screen
    cout << o3 << o4; // Uses overloaded <<
    
    in.close();
    return 0;
}
```

**5. Key Observations from the Code**
*   **Class Definition:** The `coord` class defines friend functions to handle I/O operations.
*   **File Output:** The `ofstream` object `out` uses the overloaded `<<` operator to save objects `o1` and `o2`.
*   **File Input:** The `ifstream` object `in` uses the overloaded `>>` operator to load data into objects `o3` and `o4`.
*   **Screen Output:** The standard `cout` stream uses the same overloaded `<<` operator to display `o3` and `o4`, proving the function's generality.


Customized I/O And Files
1. General Principle of Stream Operations
Versatility: Overloaded inserters (<<), extractors (>>), and I/O manipulators can be used with any stream.
Condition: This works provided they are written in a general manner.
Reasoning: All C++ streams share the same underlying structure.
Benefit: The same overloaded inserter function can output to the screen (cout) or to a file (ofstream) without requiring any changes.
2. Best Practices and Warnings
Avoid Hard-Coding: Do not "hard-code" a specific stream (e.g., cout) into an I/O function.
Consequence: Hard-coding limits the function's use to only that specific stream.
Recommendation: Always generalize I/O functions whenever possible (e.g., use ostream& or istream& as parameters).
(Reference: Recall section 12.5 – Make inserter/extractor as general as possible)
3. Illustrative Example
Scenario: A coord class overloads the << and >> operators.
Demonstration: The program uses these operator functions to write data to both the screen and a file.
4. Source Code

#include <iostream>
#include <fstream>
using namespace std;

class coord {
    int x, y;
public:
    coord(int i, int j) { x = i; y = j; }
    
    // Friend functions for overloading operators
    friend ostream &operator <<(ostream &stream, coord ob);
    friend istream &operator >>(istream &stream, coord &ob);
};

// Overload << operator
ostream &operator <<(ostream &stream, coord ob) {
    stream << ob.x << ' ' << ob.y << '\n';
    return stream;
}

// Overload >> operator
istream &operator >>(istream &stream, coord &ob) {
    stream >> ob.x >> ob.y;
    return stream;
}

int main() {
    coord o1(1, 2), o2(3, 4);
    
    // Writing to File
    ofstream out("test");
    if (!out) {
        cout << "Cannot open output file.\n";
        return 1;
    }
    out << o1 << o2; // Uses overloaded <<
    out.close();
    
    // Reading from File
    ifstream in("test");
    if (!in) {
        cout << "Cannot open input file.\n";
        return 1;
    }
    
    coord o3(0, 0), o4(0, 0);
    in >> o3 >> o4; // Uses overloaded >>
    
    // Output to Screen
    cout << o3 << o4; // Uses overloaded <<
    
    in.close();
    return 0;
}


5. Key Observations from the Code
Class Definition: The coord class defines friend functions to handle I/O operations.
File Output: The ofstream object out uses the overloaded << operator to save objects o1 and o2.
File Input: The ifstream object in uses the overloaded >> operator to load data into objects o3 and o4.
Screen Output: The standard cout stream uses the same overloaded << operator to display o3 and o4, proving the function's generality.

*/  
