
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-         String/Character Functions        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-



In C, a string is a null-terminated array of characters.

<string.h> :
    Declarations for the string functions are in <string.h> and 

<ctype.h> :
    Declarations for character functions are in  ctype.h . 

overflow:
    C has no bounds-checking on array operations, programmer prevent an array overflow.



// ------------------    <ctype.h>    ------------------

#include <ctype.h> // must be  included before use following function

int isalnum(int ch);	// The isalnum() function returns nonzero if its argument is letter/digit. Otherwise 0 is returned. 	
/* Example:
char ch;
if(isalnum(ch)) printf("alphanumeric"); */

int isalpha(int ch);	// isalpha() returns nonzero if ch is a letter of the alphabet; otherwise 0 is returned.	
/* Example:
char ch;
if (isalpha(ch)) printf("letter") */

int iscntrl(int ch);	// iscntrl() function returns nonzero if ch is between 0 and 0x1F or is equal to 0x7F (DEL); otherwise 0 is returned.	
/* Example:
char ch;
if(iscntrl(ch) ) printf(" In control "); */

int isdigit(int ch);	// isdigit() function returns nonzero if ch is a digit 0 through 9; otherwise 0 is returned.	
/* Example:
char ch;
if(isdigit(ch)) printf("is a digit"); */

int isgraph(int ch);	// isgraph() returns nonzero if ch is any printable, character other than a space (0x21 through 0x7E); otherwise 0 is returned.	
/* Example:
char ch;
if(isgraph(ch)) printf ("printing char"); */

int islower(int ch);	// islower() returns nonzero if ch is a lowercase letter (a through z); otherwise 0 is returned.	
/* Example:
char ch;
if(islower(ch)) printf("lowercase"); */

int isupper(int ch);	// isupper() returns nonzero if ch is a uppercase letter (a through z); otherwise 0 is returned.	
/* Example:
char ch;
if(isupper(ch)) printf("uppercase"); */

int isprint(int ch);	// isprint() returns nonzero if ch is a printable character (0x20 through 0x7E), including a space, otherwise 0 is returned.	
/* Example:
char ch;
if(isprint(ch)) printf("printable"); */

int ispunct(int ch);	// ispunct() returns nonzero if ch is a punctuation (neither alphanumeric nor a space); otherwise 0 is returned.	
/* Example:
char ch;
if(ispunct(ch)) printf("punctuation "); */

int isspace(int ch);	// isspace() returns nonzero if ch is either a space, tab, vertical tab, form feed, carnage return, or newline character; otherwise 0 is returned.	
/* Example:
char ch;
if(isspace(ch)) printf("White-Space "); */

int isxdigit(int ch);	// isxdigit() returns nonzero if ch is a hexadecimal digit (A-F or a-f or 0-9); otherwise 0 is returned. 	
/* Example:
char ch;
if(isxdigit(ch)) printf("hexadecimal"); */

int tolower(int ch);	// tolower() returns the lowercase equivalent of ch if ch is a letter; otherwise ch, is returned unchanged.	
/* Example:
putchar(tolower('Q')); */

int toupper(int ch);	// toupper() returns the uppercase equivalent of ch if ch is a letter; otherwise ch, is returned unchanged.	
/* Example:
putchar(toupper('t')); */






// ------------------    <string.h>    ------------------

#include <string.h>    // must be  included before use below funcs.	


char *strcat(char *strl, const char *str2);	
/* 
    strcat() concatenates a copy of str2 to str1 (ensure that str1 is large enough to hold both its original contents those of str2) 
        and terminates str1 with a null. The null terminator originally ending str1 is overwritten by the first character of str2. 
        str2 is untouched by the operation. The strcat() function returns str1.	
        
    Example: 
            gets(s1); 
            gets(s2);
            strcat(s2. s1); 
*/

char *strcpy(char *str1, const char *str2);	
/* strcpy() is used to copy the contents of str2 into str1: str2 must be a pointer to a null-terminated string. strcpy()returns a pointer to str1. If str1 and str2 overlap, the behavior of strcpy() is undefined.	char str[80]; 
strcpy(str, "hello"); */

char *strchr(const char *str, int ch);	
/* strchr() returns a pointer to the first occurrence of the low-order byte of ch in the string pointed to by str. If no match is found, a null pointer is returned.	char *p;
p = strchr("test", ' ' )
printf(p); */

int strcmp(const char *str1, cost char *str2);	strcmp() function lexicographically compares two null-terminated strings and returns an integer based on the outcome, as:	Result	Meaning	
/* if(strcmp(s, "pass " )) {
printf (" Invalid PW");
return 0;}
		less than 0 	str1 < str2 	
		0	str1 = str2 	
		greater than 0	str1 > str2	 */

size_t strlen(const char *str);	
/* strlen() rerums the length of the null-terminated string pointed to by str. The null is not counted. The size_type is defined in string.h .	strcpy(s, "hello"); 
printf("%d", strlen(s)); */

char *strtok(char *str1, const char *str2);
/* Example:  The | summer | soldier
	strtok() returns a pointer to the next token in the string pointed to by str1. The characters making up the string pointed to by str2 are the delimiters that separate each token. A null pointer is returned when there are no more tokens.	char *p;
p = strtok("The summer soldier", ",")
printf(p); 
do{ p = strtok('\0' , ",") 
if(p) printf("|%s", p); } while(p) */

char *strstr(const char *str1, const char *str2);
/* Example:  " is a test "	strstr() returns a pointer to the first occurrence of the string pointed to by str2 in the string pointed to by str1 (except str2's null terminator). It returns a null pointer for no match. 	char *p;
p = strstr("this is a test", "is");
printf(p); */





