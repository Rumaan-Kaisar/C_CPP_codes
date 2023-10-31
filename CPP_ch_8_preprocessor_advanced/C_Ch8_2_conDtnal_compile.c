
/* 
    -----------------    conditional compile    -----------------

    selective/conditional compilation:
        The 'C preprocessor' includes several DIRECTIVES that allow 
            'parts of the source code of a program' to be selectively compiled.

        This is called CONDITIONAL COMPILATLON. These directives are
 
                #if
                #else
                #elif
                #endif
                #ifdef
                #ifndef



    #if : 	
                #if constant-expression
                    statement-sequence
                #endif

        If 'constant-expression' is true the statements between #if and #endif are compiled. 
        If the constant-expression is false, the compiler skips the statement or statements.

        No variables may be used:
            note that the preprocessing stage is the 'first stage of compilation',
            So the constant-expression means exactly that. No variables may be used.



    #else : 
                #if constant-expression
                    statement-sequence
                #else
                    statement-sequence
                #endif

        Notice that there is only one #endif. The #else  automatically terminates the #if  block of statements. 
        If the constant-expression is false, the statements associated with the #else are compiled.



    #elif: 
        You can create an if-else-if ladder using the #elif directive

                #if constant-expression-1
                    statement-sequence
                #elif constant-expression-2
                    statement-sequence
                #elif constant-expression-3
                    statement-sequence
                #endif

        If first expression is true, the lines of code associated with that expression are compiled, 
            and the rest of the code is, skipped.



    #ifdef:
        It is used to check if a 'macro' has defined.

                #ifdef macro-name
                    statement-sequence
                #endif

        If the macro-name is currently defined, 
            then the statement-sequence associated with the #ifdef directive will be COMPILED. 
            Otherwise, it is skipped. 

        #else may also be used with #ifdef to provide an alternative.



    defined:
        Second way to determine if a macro name is defined: 
            use the #if in conjunction with the defined 'compile-time operator'. 

            The defined operator has this general form:

                #if  defined macro-name

            If macro-name is defined, then the outcome is true. Otherwise, it is false. 
            

        For example, the following two preprocessor directives are equivalent:

                #ifdef WIN32
                #if defined WIN32	// defined is a compile-time operator

            In this case you can also apply the '!' operator to defined to reverse the condition.



    #ifndef: 
        The complement of #ifdef is #ifndef. It has the same general form as #ifdef. 
        The only difference is that the 
            statement sequence associated with an #ifndef directive is compiled only if the macro-name is not defined.
            (alternative to !defined ).


    NOTE:
        In conditional compilation you should debug for each case
            compiler just NEGLECT the other test-cases during compilation
                any EROOR will remain uncaught for neglected test cases

*/



/* Example 1: Sometimes you will want a program's behavior to depend on a value ciefined within the program. 
                Although examples that are both short and meaningful are hard to find, 
                    the following program gives the flavor of it.

                This program can be compiled to display either the ASCII character set by itself, 
                    or the full extended set, depending on the value of CHAR_SET. 

                As you know, the ASCII character set defines characters for the values 0 through 127.  
                However, most computers reserve the values 128 through 255 for foreign-language characters 
                    and mathematical and other special symbols.
                (You might want to try this program with CHAR_SET set to 256. You will see some very interesting characters.) 
*/


#include <stdio.h>

// define CHAR_SET as either 256 or 128 
#define CHAR_SET 256

int main(void) {
    int i;

#if CHAR_SET == 256
    printf ("Displaying ASCII character set plus extensions. \n");
#else
    printf("Displaying only ASCII character set.\n");
#endif

    for(i=0; i<CHAR_SET; i++) printf("%c", i);

    return 0;
}
// Notice the indentation




/* Example 2: A good use of #ifdef is for imbedding debugging information into your programs.
                For example, here is a program that copies the contents ofone file into another:
*/

// Copy a file.
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

int main(int argc, char *argv[]) {

    FILE *from, *to;
    char ch;

    //see if correct number of command line arguments
    if(argc!=3){
        printf("Usage: copy <source> <destination>\n");
        exit(1);
    }

    // open source file
    if((from = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination file
    if((to = fopen(argv[2], "wb"))==NULL) {
        printf("Cannot open destination file. \n");
        exit(1);
    }

    // copy the file
    while(!feof(from)) {
        ch = fgetc(from);
        if(ferror(from)){
            printf("Error reading source file.\n");
            exit(1);
        }

        if(!feof(from)) {
            fputc(ch, to);
#ifdef DEBUG
            putchar(ch);
#endif
        }

        if(ferror(to)) {
            printf("Error writing destination file. \n");
            exit(1);
        }
    }

    fclose(from);
    fclose(to);

    return 0;
}

// ppcr_1_dbg <source> <destination>
// ppcr_1_dbg neg_decoded neg_decoded_copied


/* 
    If DEBUG is defined, the program displays each byte as it is transferred. 
        This can be helpful during the development phase.

    Once the program is finished, the statement defining DEBUG is removed, and the output is not displayed. 

    However, if the program ever misbehaves in the future, DEBUG can be defined again, 
        and output will again be shown on the screen. 
        
    While this might seem like a lot of work for such a simple program, 
        in actual practice programs may have many debugging statements,
        and this procedure can greatly facilitate the development and testing cycle.

    Note:
        As shown in this program, to simply define a macro name, you do not have to associate any character sequence with it
*/






/* Example 3: Continuing with the debugging theme, it is possible to use 
                the #if to allow several levels of debugging code to be easily managed.

                For example, here is one of the encryption programs from previous chapter 
                    that supports three debugging levels:
                    coding a file uses the 'XOR' operation combined wah a user-defined key. 
                    Have the user specify the file to code as well as a single character key on the command line.
                (To decode the file, run the program a second time using the same key.)
*/


// Macro Substitution : #define is used
    // Recall C_Ch6_1_1_mcro_sbt_define.c
    // by changing value 0, 1, 2, 3 in " #define DEBUG 2 " we can set the DEBUG LEVELS


/* 
    DEBUG levels:
        0. no debug
        1. display byte read flom source file
        2. display byte written to destination file
        3. display bytes read and bytes written 
*/

#include <stdio.h>
#include <stdlib.h>

#define DEBUG 2

int main(int argc, char *argv[]) {
    FILE *in, *out;
    unsigned char ch;

    // check correct number of command line arguments
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
        // 0. no debug
        // 1. display byte read from source file
        // 2. display byte written to destination file
        // 3. display bytes read and bytes written 
// display bytes read from source file
#if (DEBUG == 1) || (DEBUG == 3)
        putchar(ch);
#endif
        ch = *argv[3] ^ ch; // applying 'XOR'
// display bytes will be witten to output file
#if (DEBUG >= 2)
        putchar(ch);    // display changes
#endif
        if(!feof(in)) fputc(ch, out);   // write to the file 
    }

    // closing the files
    fclose(in) ;
    fclose (out);

    return 0;
}

// save-compile the code as : 'opr_adv_btw7.c'
// CLI:      ppcr_cndtnCMP XOR_encd ppcr_XOR_encoded 5
// CLI:      ppcr_cndtnCMP ppcr_XOR_encoded ppcr_XOR_decoded 5





/* Example 4: The following fragment illustrates the #elif. It displays 'NUM is 2' on the screen. */
#define NUM 2
.
.
.
#if NUM == 1
    printf("NUM is 1");
#elif NUM == 2
    printf ("NUM is 2");
#elif NUM == 3
    printf("NUM is 3");
#elif NUM == 4
    printf("NUM is 4");
#endif




/* Example 5: Here, the defined operator is used to determine if TESTPROJECT is defined. */
#include <stdio.h>

#define TESTPROJECT 29

#if defined TESTPROJECT
int main(void) {
    printf("This is a test.\n");

    return 0;
}
#endif




/* Example 6: Write a program that defines three macros called 
                        INT, 
                        FLOAT, and 
                        PWR_TYPE. 

                Define INT as 0, 
                FLOAT as 1, and
                PWR_TYPE as either INT or FLOAT. 

                Have the program request two numbers from the user and 
                    display the result of the first number raised to the second number.

                Using #if and depending upon the value of PWR_TYPE, 
                    have both numbers be integers, or allow the first number to be a double.

*/
// cause error for FLOAT test case
#include <stdio.h>

#define INT 0
#define FLOAT 1
#define PWR_TYPE INT

int main(void) {
    int e;
#if PWR_TYPE == FLOAT
    double base. result;    // makes ERROR
#elif PWR_TYPE == INT
    int base, result;
#endif

#if PWR_TYPE == FLOAT
    printf("Enter floating point base: ");
    scanf("%lf", &base);
#elif PWR_TYPE==INT
    printf("Enter integer base: ");
    scanf("%d", &base);
#endif

    printf("Enter integer exponent (greater than 0): ");
    scanf ("%d", &e);

    // calculate exponent
    result = 1;
    for(; e; e--) result = result * base;

#if PWR_TYPE == FLOAT
    printf("Result: %f", result);
#elif PWR_TYPE == INT
    printf("Result: %d", result);
#endif

    return 0;
}


// ------------    Corrected FLOAT-case    ------------

#include <stdio.h>

#define INT 0
#define FLOAT 1
#define PWR_TYPE FLOAT

int main(void) {
    int e;
#if PWR_TYPE == FLOAT
    double base, result;    // corrected
#elif PWR_TYPE == INT
    int base, result;
#endif

#if PWR_TYPE == FLOAT
    printf("Enter floating point base: ");
    scanf("%lf", &base);
#elif PWR_TYPE==INT
    printf("Enter integer base: ");
    scanf("%d", &base);
#endif

    printf("Enter integer exponent (greater than 0): ");
    scanf ("%d", &e);

    // calculate exponent
    result = 1;
    for(; e; e--) result = result * base;

#if PWR_TYPE == FLOAT
    printf("Result: %f", result);
#elif PWR_TYPE == INT
    printf("Result: %d", result);
#endif

    return 0;
}




/* Example 7: Is this fragment correct' If not, show one way to fix it. 

                        #define MIKE
                        #ifdef !MIKE
                        .
                        .
                        .
                        #endif


                No. You cannot use an expression like "!MIKE" with #ifdef. 
                Here are two possible solutions:

                        #ifndef MIKE
                        .
                        .
                        #endif

                        // or
                        #if !defined MIKE
                        .
                        .
                        #endif                        
*/




/* Example 8: Using an #ifdef, show how to conditionally compile this
                fragment of code based upon whether DEBUG is defined or not. 

                        if(!(j%2)) {
                            printf("j = %d\n", j);
                            j = 0;
                        }
*/
#if DEBUG
if(!(j%2)) {
    printf("j = %d\n", j);
    j = 0;
}
#endif




/* Example 9: Using the fragment from previous Exercise, show how you can
                conditionallv compile the code when DEBUG is defined as 1.
                (Hint: Use #if).
*/

#define DEBUG 1

#if DEBUG == 1
if(!(j%2)) {
    printf("j = %d\n", j);
    j = 0;
}
#endif


