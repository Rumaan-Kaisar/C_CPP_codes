// C's escape sequences:asm

These characters can not be entered from keyboard
    
    \b	    Backspace
    \f	    From feed
    \n	    Newline
    \r	    Carriage return (related to ENTER key)
    \t	    horizontal tab
    \"	    single quote
    \'	    double quote
    \0	    null
    \\	    backslash
    \v	    vertical tab
    \a	    alert
    \?	    Question  mark
    \N	    Octal constant (N is octal value)
    \xN	    hexdecimal constant (N is hexadecimal value) 

// Example 1: Newline and tab    
#include <stdio.h>
int main(void){
  printf("\n\tThis is a test.");
  printf("\n\tThis is a test.");
  return 0;
}
