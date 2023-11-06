
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-         Keyword Summary        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

There are 32 keywords in C. All keywords are in lowercase. 

        auto	 	 	 	 	 	 	 
        break	 	 	 	 	 	 	 
        case	 	 	 		 	 	 
        char 	 	 	 		 	 	
        const
        continue
        default
        do
        double
        else

                enum
                extern
                float
                for
                goto
                if
                int
                long
                regiser
                return

                        short
                        signed
                        sizeof
                        static
                        struct
                        switch
                        typedef
                        union
                        unsigned
                        void

                                volatile
                                while


// Keyword	
// Keyword Summery and general form
// Example


/* 
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-        Control-flow        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    if, else:

        The general form of the 'if-else' statement is

            if(condition){ 
                statement block 1 
            }
            else { 
                statement block 2 
            }

        If single statements are used, the braces are not needed. 
        The else is optional. 
        The 'condition' may be any expression. 
        If that expression evaluates to any value other than 0, then statement block 1 will be executed; 
            otherwise, if it exists, statement block 2 will be executed.	

        Example: 
            ch = getche();
            if (ch=='q'){	printf("Prog. Terminated");
                exit(0); }
            else proceed() ;



    for	:
        The for loop allows 'automatic initialization' and incrementation of a counter variable. The general form is:

            for(initialization; condition; increment) { 
                statement block 
            }

        The braces are not necessary for only one statement. 
        Although the for allows a number of variations, 
            generally the initialization is used to set a counter variable to its starting value. 
        The condition is generally a 'relational statement' that checks the counter variable against a termination value, 
            and the increment increments (or decrements) the counter value. 
        The loop repeats until the condition becomes false.	

        Example:
            The following code will print hello 10 times.

            for( t=O; t<10; t++) printf("Hello \n");



    do :
        The do loop is one of three loop constructs in available in C. The general form:

            do{ statement block } while(condition);

        The braces are not necessary for only one statement. 
        The do loop repeats as long as the condition is true. 
        
        The do loop is the only loop in C that will "always have at least ONE ITERATION" 
            because the condition is tested at the bottom of the loop.	
            
        Example: 
            do {ch=getche();} while(ch!='q');



    while :
        The while loop has the general form:

            while(condition){ 
                statement block 
            }

        The braces are not necessary for only one statement. 
        The loop will repeat as long as the condition is true. 
        The while tests its condition "AT THE TOP" of the loop. 
        Therefore, if the condition is false to begin with, the loop will not execute at all. 
        The condition may be any expression.

        reads characters until end-of-file (EOF)	

        Example:
            t = 0;
            while (!feof(fp)) {
                s[t] = getc(fp);
                t++;
            }



    switch, case, default :
        The switch statement is C's multi-path branch statement. 
        It is used to route execution in one of several ways. 
        The general form :                 
        
            switch(value) {	
                case constant_1: statement sequence; break;
                case constant_2: statement sequence; break;
                case constant_3: statement sequence: break;
                        . . . 
                        . . .
                default : statement sequence; break;
            }
        
        Each statement-sequence may be one or many statements long. 
        "default" portion is optional. 
        The expression controlling the switch and all case constants must be of 'int' or 'char' types.

        The switch works by checking the value of int-expression against the constants. 
            As soon as a match is found, that set of statements is executed. 

        break: If the break statement is omitted, execution will continue into the next case. 
        cases are similar to labels. 
        Execution will continue until a break statement is found or the switch ends.	

        Example:
            ch = getche();
            switch(ch) {
                case 'e': enter(); break;
                case 'l': list(); break;
                case 's': sort(); break;
                case 'q': exit(O); break;
                default: printf("Unknon cmd\n");
                printf("Try Again \n");
            }



    continue :
        continue is used to BYPASS PORTIONS of code in a loop and forces the conditional expression to be evaluated. 
        
        Example: 
            The call to process() will not occur until ch contains the character s and char entry won't stop until s is entered.
        
            while(ch=getche()) {
                if(ch != 's') continue; 
                process(ch); 
            }



    break :
        break is used to exit from a do, for, or while loop, BYPASSING the normal loop condition. 
        It is also used to EXIT from a switch statement 
            (in a switch, break effectively keeps program execution from "falling through" to the next case).	
        
        Example:
            while(x<1OO){	
                x = get_new_x();
                // key hit on keyboard
                if (kbhit()) break; 
                process(x);
            }



    goto :
        The goto causes program execution to JUMP to the LABEL specified in goto.  The general form:

            goto label;
                . . . . .
            label:

        All labels must end in a colon and must not conflict with keywords or function names. 
        A goto can branch only within the CURRENT function, and 'not from one function to another'.	
        
        Example: The following example will prim the message "right" but not the "wrong":

            goto lab_1;
            printf("wrong");
            lab_1: printf("right");
        

*/

	










int	int is the type specifier used to declare integer variables. Eg: to declare count as an integer 	int count;
char 		char is a data type used to declare character variables. In C, a character is one byte long.	char ch;
float	float is a data type specifier used to declare floating-point variables. To declare f to be of type float:	f loat f;
double	double is a data type specifier used to declare double-precision floating-point variables. To declare d to be of type double 	double d;
	Data type Modifier        :      Keyword Summery and general form	Example
short	short is a data type modifier used •to declare small integers. Eg: to declare sh to be a short integer 	short int sh;
long	long is a data type modifier used to declare long integer and long double variables. Eg: to declare count as a long int	long int count;
signed	The signed type modifier is most commonly used to specify a signed char data type.	signed char ch;
unsigned 
	The unsigned type modifier tells the compiler to create a variable that holds only unsigned (i.e., positive) values. Eg: to declare big to be an unsigned integer you would write	unsigned int big;
const 
	The const modifier tells the compiler that the contents of a variable cannot be changed. It is also used to prevent a function from modifying the object pointed to by one of its arguments.	Access Modifiers
	const  int  i=10;
volatile
	The volatile modifier tells the compiler that a variable may have its contents altered in ways not explicitly defined by the program. Variables that are changed by the hardware, such as real-time clocks, interrupts, or other inputs are examples.		volatile  unsigned  u;
typedef
	The typedef statement allows you to create a new name for an existing data type. The general form 
typedef type-specifier new-name;	statement	' balance ' in place of ' float ' :
typedef float balance;
	Structure        :      Keyword Summery and general form	Example
struct
	The struct statement is used to create aggregate data types, called structures, that are made up of one or more members. The general form:
	struct struct-name {type member';
			type member2 ;
			. . . . 
			type memberN ; } variable-list;
The individual members are referenced using the dot or arrow operators.	struct catalog {
char name [40] ; 	/* author name */
char title[40] ; 	/* title */
char pub[40] ; 	/* publisher */
unsigned date;	/* copyrit date */
unsigned char ed; 	/* edition */
}card;
union
	The union keyword creates an aggregate type in which two or more variables share the same memory location. The form of the declaration and the way a member is accessed are the same as for struct. The general form is
	union union-name {type member1 ;
			type member2 ;
			. . .
			type member N ;  } variable-list;	union item {int m; 
float x; 
char c;} code;

enum
	The enum type specifier is used to create enumeration types. An enumeration is simply a list of named integer constants. For example, the code declares an enumeration called color that consists of three constants: red, green, and yellow.
	enum color {red, green, yellow};
enum color c;
int main(void){ c = red;
if (c==red) printf("is red\n");
return 0; }
	Memory mangmnt        :      Keyword Summery and general form	Example
auto	auto is used to create temporary variables that are created upon entry into a block and destroyed upon exit. The use of auto is optional since local variables are auto by default.
In the example, the variable t is created only if the user strikes an a. Outside the if block, t is completely unknown; and any reference to it would generate a compile-time syntax error.	if(getche()=='a'){  auto int t;
	for(t=O; t<'a'; t++)printf("%d", t);
	break;}
static
	The static keyword is a data type modifier that causes the compiler to create permanent storage for the local variable that it precedes. This enables the specified variable to maintain its value between function calls. static can also be used on global variables to limit their scope to the file in which they are declared.	to declare last_time as a static integer:

	static int last_time;

extern
	The extern data type modifier tells the compiler that a variable is defined elsewhere in the program. This is often used in conjunction
with separately compiled files that share the same global data and are linked together. In essence, it notifies the compiler of a variable without redefining it.	As an example, if first were declared in another file as an integer, the following declaration would be used in subsequent files:
	extern int first;
register
	The register modifier requests that a variable be stored in the way that allows the fastest possible access. In the case of characters or integers, this usually means a register of the cpu. 	declare i to be a register integer:
register int i;
	Miscellanious        :      Keyword Summery and general form	Example
void
	The void type specifier is primarily used to declare void functions (functions that do not return values). It is also used to create void pointers (pointers to void) that are generic pointers capable of pointing to any type of object and to specify an empty parameter list.	void func_1( );
sizeof
	The sizeof keyword is a compile-time operator that returns the length of the variable or type it precedes. If it precedes a type, the type must be enclosed in parentheses. The sizeof statement's principal use is in helping to generate portable code when that code depends on the size of the C built-in data types.	operator	 printf("%d", sizeof(short int));
will print 2 for most C implementations.
return
	The return statement forces a return from a function and can be used to transfer a value back to the calling routine. Keep in mind that as soon as a return is encountered, the function will return, skipping any other code in the function.	statement	int mul(int a, int b){
	         return a*b;}


