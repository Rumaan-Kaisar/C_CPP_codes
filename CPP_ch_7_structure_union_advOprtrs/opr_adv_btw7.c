
/* Example 7: A better method of coding a file uses the 'XOR' operation combined wah a user-defined key.
                Write a program that encodes a file using this method. Have the user specify the file
                to code as well as a single character key on the command line.
                (To decode the file, run the program a second time using the same key.) */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in, *out;
    unsigned char ch;

    if(argc!=4){
        printf("Usage: code <in> <out> <key>\n");
        exit(1);
    }

    // read
    if((in = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open input file.\n");
        exit(1);
    }

    // write
    if((out = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open output file.\n");
        exit(1);
    }

    // putting the encoded characters into 'out' file
    while(!feof(in)) {
        ch = fgetc(in);
        ch = *argv[3] ^ ch; // applying 'XOR'
        if(!feof(in)) fputc(ch, out);
    }

    // closing the files
    fclose(in) ;
    fclose (out);

    return 0;
}

// save-compile the code as : 'opr_adv_btw7.c'
// CLI:      opr_adv_btw7 XOR_encd XOR_encoded 7
// CLI:      opr_adv_btw7 XOR_encoded XOR_decoded
