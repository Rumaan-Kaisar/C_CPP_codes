

/* Example 4: Following program reads a text file and then 
                counts how many times each letter appears in that file.
*/

#include <iostream>
#include <fstream>
#include <cctype>

int alpha[26];

int main(int argc, char *argv[]) {
    char ch;

    if(argc!=2) {
        std::cout << " Usage : COUNT <source>\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in) {
        std::cout << " Cannot open input file.\n";
        return 1;
    }

    // init alpha []
    int i;

    for(i=0; i<26; i++) alpha[i] = 0;

    while(!in.eof()) {
        ch = in.get();

        // if letter found , count it
        if(isalpha(ch)) {
            ch = toupper (ch); // normalize
            alpha [ch -'A']++; // 'A'-'A' == 0, 'B'-'A' == 1, etc.
        }
    }

    // display count
    for (i =0; i <26; i ++) std::cout << (char)('A'+i) << ": " << alpha[i] << '\n';
    
    in.close();

    return 0;
}


