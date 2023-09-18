
// -----------    rev    -----------
/* Example 6: One very easy way to encode a file is to reverse the state of each bit using the '~' operator.
                Write a program that encodes a file using this method.
                (To decode the file, simply run the program a second time.)
                Have the user specify the name of the file on the command line. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *in, *out;
    unsigned char ch;

    if(argc!=3) {
        printf("Usage: code <in> <out>\n");
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
        if(!feof(in)) fputc(~ch, out);
    }

    // closing the files
    fclose(in);
    fclose(out);

    return 0;
}
