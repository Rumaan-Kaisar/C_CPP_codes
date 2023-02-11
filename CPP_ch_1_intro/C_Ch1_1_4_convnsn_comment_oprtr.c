// Variable convension in C/C++:
/* 
    Camel Case: firstName; lastName.
    Snake Case: first_name;  last_name
    Pascal Case: FirstName; LastName. 
*/


/* 
Class:
        class name should be a noun; PascalCase. EG: ReverseString, and Multiply2Numbers.
        No underscores (‘_’) are permitted in the class name.
        The private attribute name in class should be prepended with the character ‘m’. After prepending ‘m’, the same rules will be followed for the name as that for the class name.
        Character ‘m’ also precedes other name modifiers also. For example, ‘p’ for pointers.
        The name should be specific and hint at the functioning of the class without glancing at the body of the class. 

        This type of convention is called PascalCase.

            class PerimeterRectangle

            class FingerprintScanner


        class PerimeterRectangle
        {
            public:
            int perimeter;
            private:
            int mLength;
            int mWidth;
        }

function/method:
        Each method/ function name should begin with a verb. camelCase (with class names).
        We can also follow snake_case for methods.
        function name should make it clear what it does. For example, writeDataToFile() is more convenient name than WriteFile(). 
naming argumnets:
        The first character of function/ method argument names should be lowercase.  Each word should also begin with a capital letter.

        int perimeterRectangle(int lengthRectangle, int widthRectangle)


Using Suffix/prefix in function/class names:
        Suffixes are sometimes useful. For example,
            Count- the current count of the counter.
            Key- the key value.

        Prefixes are sometimes useful. For example,
            get-get value.
            set- set value.

        int getValue();


variable:
        snake_case
        begin with an alphabet.
        Digits may be used after the alphabet.
        No special symbols can be used in variable names except for the underscore(‘_’).
        No keywords can be used for variable names.
        Eg:
            int total_cost;
            int length;

        Pointer variables should be prepended with ‘p’ and place the asterisk ‘*’ close to the variable name instead of the pointer type.
        Eg:
            int *pName;
            int *pAge, address; // Here only pAge is a pointer variable

        Reference variables should be prepended with ‘r’. 
            This helps to differentiate between the method returning a modifiable object and the same method returning a non-modifiable object.

        Static variables should be prepended with ‘s’.
            static int sCount;



Constants:
        global constants should be all capital letters separated with ‘_’.
        Constants should be all capital letters with ‘_’ separators. For example, MAX_INT, TWO_PI, etc.
            const double TWO_PI = 6.28318531;

files:
    No special character is allowed in the file name except for underscore (‘_’) and dash (‘-‘).
    The file name should end with the .cc extension in the end or should end with the .cpp extension.
        Eg:
            helloworld.c        // Valid
            hello_world.cpp     // Valid
            hello-world.cpp     // Valid
            hel-lo_world.cpp    // Valid

    Do not use filenames that already exist in /user/include. or any predefined header file name.
        Eg:
            hello* world.cpp    // Not Valid
            iostream.cpp        // Not Valid
            hello123@world.cpp  // Not Valid
 */


#include <stdio.h>
int main(void){

    /* the - can be used as a unary operator to reverse the sign of its operand. */
        
    int i;
    i = 10;
    i = -i;
    printf("This is i: %d", i);
    /* You cannot place a comment inside the name of a function or
    variable name. For example, this is an incorrect statement: 
    
    pri/* wrong * / ntf("this won't work");

    */
    
    return 0;
    
}