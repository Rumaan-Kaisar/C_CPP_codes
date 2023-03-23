
/* 
    -------   STRINGS as 1D array   -------
    The most common use of the one-dimensional array in C is the string.

    C has no built-in string data type. Instead, a string is defined as a null-terminated character array.
        In C, a null is zero.
        i.e. our array will be one byte larger than the largest string it will be required to hold, to make room for the null.
        A string constant is null-terminated by the compiler automatically. 

    Null string: 
        A null string is a string that contains only the null character

    gets(): 
        To read a string from the keyboard uses the STDIO.H header file.
        Call it using the name of a character array without any index.
        Reads characters until press ENTER (carriage return). The ENTER key is not stored, but is replaced by a null, which terminates the string.
        gets() has no bounds checking, so "array overrun/program-crash" is normal.

        Output string directly using printf():
                                                gets (str); 
                                                printf(str); 
            With format specifier: Display str using the %s format code. For example, to output a newline after str : 	  
                printf("%s\n", str); 	


    
    4-string functions:
        strcpy(), 
        strcat(), 
        strcmp(),  
        strlen(),
        These functions require the header file <STRING.H>. 

    strcpy():
        General form: 		strcpy(to, from);
        It copies the contents of "from" to "to".
            char str[80];
            strcpy (str, "hello" ); 
            printf("%s", str);

        No bounds checking.


    strcat():
        General form is :  		strcat(to, from);
        For Concatenation. It adds the contents of "from" to the contents of "to". 
        This fragment displays "hello there".
            char str[80];
            strcpy (str, "hello" ) ; 
            strcat (str, "there" ) ; 
            printf("%s", str);

        No bounds checking.


    strcmp():
        General form:       strcmp(s1, s2); 
        Compares two strings.

        returns 'zero' if the strings are the same.
        'less than zero' if s1 is less than s2 and 
        'greater than zero' if s1 is greater than s2.

        The strings are compared lexicographically; that is, in dictionary order.
            One string is less than other if it appear before the other in a dictionary.
            The comparison is not based upon the length of the string.
            comparison is case-sensitive, lowercase characters being greater than uppercase. 

        This fragment prints 0, because the strings are the same:
            printf("%d", strcmp("one", "one"));


    strlen(): 
        General form is:  strlen(str);
        Returns the length, in characters, of a string. 
        Does not count the null terminator.

        strlen("test"), will return 4.


    atoi():
        converts string of numbers to actal int.
        Returns the integer equivalent of the number represented by its string argument. 
        For example, atoi("100") returns the value 100.
        scanf() is incompatible with gets().
        atoi()  uses the header file <STDLIB.H>.


    Null string:
        A zero-length string can be created using a strcpy():
                strcpy(str, "");
        It contains only one element: the null terminator.


    STRING.H & STDLIB.H:
        atoi()  uses the header file <STDLIB.H>.
        strcpy(), strcat(), strcmp(), strlen(), require the header file <STRING.H>. 
   
   
    Following fragment is wrong:
        char name[10] = "Thomas Jefferson";
        The array, "name", is not big enough to hold the string being assigned to it 

*/





/* Example 1: For example, this program reads a string entered at the keyboard. It then displays the contents of that string one character at a time.
                Notice how the program uses the fact that a null (means str[i] is zero/null or false ) is false
                to control the loop that outputs the string (i.e. until the string reach to its end).*/
#include <stdio.h>
#include <string.h>

int main(void){
    char str[80];
    int i;

    printf("Enter a string (less than 80 chars): ");
    gets(str); 	//Reads the string from the keyboard and store at "str" array

    for(i=0; str[i]; i++) printf("%c", str[i]); //when string ends str[i] will be false
    printf("\n");

    // There is, of course, a much easier way to display a string using printf()
    printf(str); // Without any specifire

    // With format specifier
    printf("%s\n", str);

    return 0;
}

    


/* Example 2: This program requests input of two strings, then demonstrates the four string functions with them */

#include <stdio.h>
#include <string.h>

int main(void){
    char str1[80], str2[80];
    int i;
    
    printf("Enter the first string:");
    gets(str1);
    printf("Enter the second string:");
    gets(str2);
    
    //see how long the string are
    printf("%s is %d chars long\n", str1, strlen(str1));
    printf("%s is %d chars long\n", str2, strlen(str2));
    
    //compare the strings
    i = strcmp(str1,str2);
    if(!i) printf("The strings are equal.\n");
    else if( i < 0 ) printf("%s is less than %s\n", str1, str2);
    else  printf("%s is less than %s\n", str2, str1);
    
    //concatenate str2 to end of str1 if there is enough room
    if(strlen(str1) + strlen(str2) < 80){
        strcat(str1, str2);
        printf("%s\n",str1);
    }
    
    //copy str2 to 1
    strcpy(str1,str2);
    printf("%s %s\n", str1, str2);

    return 0;
}


// #include<stdio.h>
// void printstr(char *p);
// int main() {
//     char str[20] ="Hello";
//     printstr(str);

//     return 0;
// }

// void printstr(char *p){
//     p[0] = 'A';
//     printf("%c",p[0]);
// }



/* Example 3: The following program allows the user to add, subtract,
                multiply, or divide, but does not use a menu. Instead, it uses a command-based interface. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char command[80], temp[80];
    int i, j;
    
    for( ; ; ){
        printf("Operation? ");
        gets(command);
        
        //see if user wants to stop
        if(!strcmp(command,"quit")) break;
        
        printf("Enter the first number:");
        gets(temp);
        i = atoi(temp);
        
        printf("Enter the second number:");
        gets(temp);
        j = atoi(temp);
        
        //now perform the opetation
        if(!strcmp(command, "add")) printf("%d\n",i+j);
        else if(!strcmp(command, "subtract")) printf("%d\n", i-j);
        else if(!strcmp(command, "divide")) printf("%d\n", i/j);
        else if(!strcmp(command, "multiply")) printf("%d\n", i*j);
        else printf("Unknown command\n");
    }
    
    return 0;
}



/* Example 4: Write a program that inputs a string, then displays it backward on the screen. */
#include<stdio.h>
#include<string.h>

int main(void) {
    char str[80];
    int i;

    printf("Enter a string: ");
    gets(str);

    // int i= strlen(str);
    for(i = strlen(str)-1; i >= 0; i--) printf("%c", str[i]);

    return 0;
}



/* Example 5: Following program gives err because of string overrun. */
#include <string.h>
#include <stdio.h>
int main(void){
    char str[5];

    strcpy(str, "this is a test");   //bigger than the available room
    printf (str);

    return 0:
}



/* Example 6: Following repeatedly inputs strings. Each time a string is input, concatenate it with a second string called 'bigstr'.
                Add newlines to the end of each string. If the user types 'quit', stop inputting and display bigstr (which will contain a record of
                all strings input). Also stop if bigstr will be overrun by the next concatenation */

#include<stdio.h>
#include<string.h>

int main(void) {
    char bigstr[1000]="", str[50];

    for( ; ; ) {
        printf("Enter a string: ");
        gets(str);

        if(!strcmp(str, "quit")) break;

        strcat(bigstr, "\n");

        // prevent an array overrun
        if(strlen(bigstr) + strlen(str) >= 1000) break;
        strcat(bigstr, str);
    }

    printf(bigstr);

    return 0;
}




/* Example 7:  Write a program that repeatedly reads strings from the keyboard
                until the user enters quit. */

#include <stdio.h>
#include <string.h>
int main(void){
    char str[80];

    do {
        printf("Enter a string: ");
        gets(str);
    } while(strcmp("quit", str));

    return 0;
}




/* Example 8:  Write a program that acts like an electronic dictionary. If the
                user enters a word in the dictionary, the program displays its
                meaning. Use a three-dimensional character array to hold the
                words and their meanings */

// Computerized dictionary program.
#include <stdio.h>
#include<string.h>

char dict[][2][40]={
    "house", "where you live",
    "car", "a vehicle, what you drive",
    "chair", "where you sit",
    "ball", "round object for playing",
    "food", "what you eat",
    "computer" , "a thinking machine",
    "program",  "sequence of instructions"
    };

int main(void){
    char word[80];
    int i;

    printf("Enter word: ");
    gets(word);

    //look up the word
    i = 0;
    // search,while null string not yet encountered, strcmp(dict[i][0], "") is +ve
    while(strcmp(dict[i][0], "")){
        // if match occurs, then strcmp(dict[i][0], word) will be "0"
        if(!strcmp(word, dict[i][0])){
            printf("\n meaning is %s",dict[i][1]);
            break;
        }
        i++;
    }

    if(!strcmp(dict[i][0],""))
        printf("\n word doesnt exist in dictionary");

    return 0;
}


/* 
// For-loop version
    
int main(void){
    char word[80];
    int i;

    printf("Enter word: ");
    gets(word);

    //look up the word
    for(i=0; strcmp(dict[i][0],""); i++){
        if(!strcmp(dict[i][0], word)){
            printf("\n meaning is %s",dict[i][1]);
            break;
        }
    }
    if(!strcmp(dict[i][0],""))
        printf("\n word doesnt exist in dictionary");
        
    return 0;
}

*/




/* Example 9: Write a program that inputs strings from the user. If the string is
                less than 80 characters long, pad it with periods. Print out the
                string to verify that you have correctly lengthened the string. */
#include <stdio.h>
#include <string.h>
int main(void){
    char str[80];
    int i;

    printf("Enter a string: ");
    gets(str);

    //pad the string if necessary 
    for(i=strlen(str); i<79; i++) strcat(str, ".");

    printf(str) ;
    return 0;
}




/* Example 10: Write a program that inputs a string and then encodes it by
                taking the characters from each end, starting with the left side
                and alternating, stopping when the middle of the string has been
                reached. For example, the string "Hi there" would be "Heir eth". */
// A simple coding program. 
#include <stdio.h>
#include <string.h>

int main (void){
    char str[80];
    int i, j;

    printf("Enter message: ");
    gets(str);

    //code it
    i = 0;   j = strlen(str) - 1;

    while(i<=j){
        if(i<j) printf("%c%c", str[i], str[j]);
        else printf ("%c", str[i]);

        i++;   j--;
    }

    return 0;
}




/* Example 11: Write a program that counts the number of spaces, commas, and
                periods in a string. Use a switch to categorize the characters." */

#include <stdio.h>
#include <string.h>

int main(void){
    char str[80];
    int spaces, periods, commas;
    int i;

    printf("Enter a string: ");
    gets(str);

    spaces = 0;
    commas = 0;
    periods = 0;

    for(i=0; i < strlen(str); i++){
        switch(str[i]){
            case '.': periods++; break;
            case ',': commas++; break;
            case ' ': spaces++;
        }
    }

    printf("spaces: %d\n", spaces);
    printf("commas: %d\n", commas),
    printf("periods: %d\n", periods);

    return 0;
}




/* Example 12:  What is wrong with this fragment?
                char str[80];
                str = getchar(); 

The getchar() function returns a character, not a string.
Hence, it cannot be used as shown. You must use gets() to
read a string from the keyboard
*/




// ----------|    HangMan    |----------
/* Example 13: Write a program that plays a computerized version of Hangman.
                In the game of Hangman, you are shown the length of a magic
                word (using hyphens) and you try to guess what the word is by
                entering letters. Each time you enter a letter, the magic word is
                checked to see if it contains that letter. If it does, that letter is
                shown. Keep a count on the number ofletters entered to
                complete the word. For the sake of simplicity, a player wins
                when the magic word is entirely filled by characters using 15 or
                fewer guesses. For this exercise make the magic word
                "concatenation." */

#include <stdio.h>
#include <string.h>

int main(void){
    char word[] = "concatenation";
    char temp[] = "-------------";
    char ch;
    int i, count;

    count = 0;  //count number of guesses
    do{
        printf("%s\n", temp);
        printf("Enter your guess: ");
        ch = getchar();
        printf("%n");

        // see if letter matches any in word
        for(i=0; i<strlen(word); i++){
            if(ch==word[i]) temp[i] = ch;
        }
        count++;

    } while (strcmp(temp, word));

    printf("%s\n", temp);
    printf ("You guessed the word and used %d guesses", count);

    return 0;
}





/* Example 14: Write a program that simulates a log-on to a remote system. The
                system can be accessed only if the user knows the password,
                which in this case is "Tristan". Give the user three tries to enter
                the correct password. If the user succeeds, simply print Log-on
                Successful and exit. If the user fails after three attempts to
                enter the correct password, display Access Denied and exit. */
#include <stdio.h>
#include <string.h>

int main(void){
    char pw[80];
    int i;

    for(i=0; i<3; i++) {
        printf("Password: ");
        gets(pw) ;
        if(!strcmp("Tristan", pw)) break;
    }

    // Notice: i slill holds the incremented value
    if(i==3) printf("Access Denied");
    else printf("Log-on Successful");

    return 0;
}
