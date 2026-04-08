


// ----  rev[27-Nov-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// ----  rev[31-Mar-2026] ----



// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-



/* Example 1: Following is a reworked version of the inventory class 
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

/* void inventory::retrieve( std::fstream &stream ) {
    stream.read(item, SIZE);
    stream.read((char*) &onhand, sizeof(int));
    stream.read((char*) &cost, sizeof(double));
} */


// read (returns false when EOF reached)
bool inventory::retrieve(std::fstream &stream) {
    if (!stream.read(item, SIZE))
        return false;

    item[SIZE - 1] = '\0';

    stream.read(reinterpret_cast<char*>(&onhand), sizeof(onhand));
    stream.read(reinterpret_cast<char*>(&cost), sizeof(cost));

    return true;
}


int main() {
    std::fstream inv("inv", std::ios::out | std::ios::binary );
    int i;

    inventory temp("", 0, 0.0);
    inventory pliers(" pliers ", 12, 4.95);
    inventory hammers(" hammers ", 5, 9.45);
    // inventory wrenches(" wrenches ", 22, 13.90);
    // inventory batteries(" 18650 batteries ", 60, 1.00);

    if(!inv) {
        std::cout << " Cannot open file for output.\n";
        return 1;
    }

    // write to file
    pliers.store(inv);
    hammers.store(inv);
    wrenches.store(inv);

    inv.close();

    // open for input
    inv.open ("inv", std::ios::in | std::ios::binary);

    if(!inv){
        std::cout << " Cannot open file for input .\n";
        return 1;
    }

/*     do {
        std::cout << " Record # (-1 to quit ): ";
        std::cin >> i;

        if(i == -1) break;

        inv.seekg(i*(SIZE + sizeof(int) + sizeof(double)), std::ios::beg);
        temp.retrieve(inv);
        std::cout << temp;
    } while(inv.good()); */

    std::cout << "\nAll records:\n\n";

    while (temp.retrieve(inv)) {
        std::cout << temp;
    }

    inv.close();

    return 0;
}



// GPT : fix

#include <iostream>
#include <fstream>
#include <cstring>

#define SIZE 40

class inventory {
    char item[SIZE];
    int onhand;
    double cost;

public:
    inventory(const char *i = "", int o = 0, double c = 0.0) {
        std::strncpy(item, i, SIZE - 1);
        item[SIZE - 1] = '\0';
        onhand = o;
        cost = c;
    }

    void store(std::fstream &stream);
    bool retrieve(std::fstream &stream);

    friend std::ostream &operator<<(std::ostream &stream, const inventory &ob);
};

// output
std::ostream &operator<<(std::ostream &stream, const inventory &ob) {
    stream << ob.item << ": " << ob.onhand
           << " on hand at $" << ob.cost << '\n';
    return stream;
}

// write
void inventory::store(std::fstream &stream) {
    stream.write(item, SIZE);
    stream.write(reinterpret_cast<char*>(&onhand), sizeof(onhand));
    stream.write(reinterpret_cast<char*>(&cost), sizeof(cost));
}

// read (returns false when EOF reached)
bool inventory::retrieve(std::fstream &stream) {
    if (!stream.read(item, SIZE))
        return false;

    item[SIZE - 1] = '\0';

    stream.read(reinterpret_cast<char*>(&onhand), sizeof(onhand));
    stream.read(reinterpret_cast<char*>(&cost), sizeof(cost));

    return true;
}

int main() {
    std::fstream inv("inv", std::ios::out | std::ios::binary);

    inventory pliers("pliers", 12, 4.95);
    inventory hammers("hammers", 5, 9.45);
    inventory wrenches("wrenches", 22, 13.90);

    // write
    pliers.store(inv);
    hammers.store(inv);
    wrenches.store(inv);

    inv.close();

    // read all
    inv.open("inv", std::ios::in | std::ios::binary);

    if (!inv) {
        std::cout << "Cannot open file.\n";
        return 1;
    }

    inventory temp;

    std::cout << "\nAll records:\n\n";

    while (temp.retrieve(inv)) {
        std::cout << temp;
    }

    inv.close();
    return 0;
}
// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-














// Fixed, but no user inputs

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
    // inventory batteries(" 18650 batteries ", 60, 1.00);

    if(!inv) {
        std::cout << " Cannot open file for output.\n";
        return 1;
    }

    // write to file
    pliers.store(inv);
    hammers.store(inv);
    wrenches.store(inv);

    inv.close();

    // open for input
    inv.open ("inv", std::ios::in | std::ios::binary);

    if(!inv){
        std::cout << " Cannot open file for input .\n";
        return 1;
    }

    // printing all the records
    std::cout << "\nAll records:\n\n";

    while (inv.good()) {
        temp.retrieve(inv);
        std::cout << temp;
    }

    inv.close();

    return 0;
}

