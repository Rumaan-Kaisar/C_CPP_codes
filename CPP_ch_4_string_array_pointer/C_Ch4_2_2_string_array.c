

/* 
----------|    ARRAYS OF STRINGS    |----------
Arrays of strings, often called string tables.
A string table is created like any other "two-dimensional array". For example, here is a small string table. 
        char names[10][40];
    This statement specifies a table that can contain 10 strings, each up to 40 characters long (including the null terminator).
    To access a string within this table, specify only the left-most index.
    
    For example, to read a string from the keyboard into the third string in names :
        gets(names[2]);
    
    To output the first string, use this printf() statement:	
        printf (names[0] ) ;



----------|    Three-dimensional table of strings    |----------
 		char animals[3][5][80];
The declaration creates a three-dimensional table with "three lists of strings". 
Each list is five strings long, and 
each string can hold 80 characters.

To access a specific string in this situation, you must specify the two left-most indexes. 
    For example, to access the "second string" in the "third list", specify
        animals[2][1].  
*/




/* Example 1: This program lets you enter ten strings, then lets you display
                them, one at a time, in any order you choose. To stop the program, enter a negative number. */
#include <stdio.h>

int main(void){
    char text[10][80];
    int i;
    
    for(i=0; i<10; i++){
        printf("%d: ", i+1);
        gets(text[i]);
    }
    
    do{
       printf("Enter number of string (1-10) :");
       scanf("%d",&i);
       i--; //adjust value to match array index
       if(i>=0 && i<10) printf("%s\n", text[i]);
    }while(i>=0);

    return 0;
}




/* Example 2: You can initialize a string table as you would any other type of array. 
                For example, the following program uses an initialized
                string table to translate between German and English. Notice
                that curly braces are needed to surround the list. The only time
                they are not needed is when a single string is being initialized . */
//English to German translator

#include <stdio.h>
#include <string.h>

/* Unsized array of list, each list contain 1 english (index 0) and 1 german (index 0) word,
an word can be 40 char long */
char words[][2][40]={
    "dog","Hund",
    "no","nein",
    "year", "Jahr",
    "child", "Kind",
    "I", "Ich",
    "drive", "fahren",
    "house", "Haus",
    "to", "zu",
    "",""
};

int main(void){
    char english[80];
    int i;
    
    printf("Enter English word: ");
    gets(english);
    
    //look up the word
    i=0;
    //search while null string  not yet encountered
    while(strcmp(words[i][0],"")){
        if(!strcmp(english, words[i][0])){
            printf("German translation: %s", words[i][1]);
            break;
        }
        i++;
    }
    
    if(!strcmp(words[i][0],"")) printf("NOt in dictonary\n");
    
    return 0;
}




/* Example 3: You can access the individual characters that comprise a string
                within a string table by using the rightmost index. For example,
                the following program prints the strings in the table one
                character at a time. */
#include <stdio.h>

int main(void){
    char text[][80]={
        "When", "in", "the",
        "course", "of", "human",
        "events", ""
    };
    
    int i, j;
    
    //now display them
    for(i=0; text[i][0]; i++){
        for(j=0; text[i][j]; j++){
            printf("%c",text[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}




/* Example 4: Write a program that creates a string table containing the
English words for the numbers 0 through 9. Using this table,
allow the user to enter a digit (as a character) and then have
your program display the word equivalent. (Hint: to obtain an
index into the table, subtract '0' from the character entered.) */

#include<stdio.h>
#include <conio.h>
int main(void){

    char numbers[10][10]={
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
    };

    char num;

    printf("Enter a number(0-9): ");
    num = getche();
    printf("Entered number %d\n", (int)num);
    // scanf(" %c", &num);

    num = num -'0'; // makes "num" between 0 and 9 during type promotion
    printf("Index number %d\n", (int)num);
    if(num>=0 && num<10) printf("%s", numbers[num]);

    return 0;
}












Mastery - Qumulative - Review
Split following

What is an array?
2. Given the array
int coul1t[lO) i
will this statement generate an error message?
for(i=O; i<20; i++J count[i] =~;
3. In statistics, the mode of a group of Lumbers is the one that
occurs the most often. For example, given the list 1, 2, 3, 6, 4, 7,
5,4,6, 9, 4, the mode is 4, because It occurs three times. Write a
program that allows the user to enter a list of 20 numbers and
then finds and displays the mode.
4. Show how to initialize an integer array called items with the
values 1 through 10.
5. Write a program that repeatedly reads strings from the keyboard
until the user enters quit.
6. Write a program that acts like an electronic dictionary. If the
user enters a word in the dictionary, the program displays its
meaning. Use a three-dimensional character array to hold the
words and their meanings

#include <stdio.h>
#include <conio.h>
int rnain(void)
(
,
char digits[10J [10J = (
) ;
Rzero", "one", "two", "three",
"four" "five", "six", "seven",
"eight", "nine"
char nurn;
prlntf("Enter number: .);
ntL'1l ::: getche () ;
printf("\n") ;
TI<L'"":l ::: num - '0';
if(nun>=Q && num<10) printf("%s", digits[num]);
return 0;

for(i=O; i<20; i++) {
mode = stats[i];
count = 1:
;
j* count the occurrences of this value */
for(j=i+l; j<20; j++)
)
if(mode==stats[j]) cou~t++;
/* if count is greater than old count, use new mode */
if (count>oldcount) {
ol~ode = mode:
oldcount = count;
)
printf (-The mode is %d\n", oldmode);
return 0;

4. int items[) = (1, 2, 3, 4, 5, 6, 7, B, 9, 10);
5. #include <stdio.h>
#include <string.h~
int main(voJ.d)
(
)
char str[aO];
do (
printf("Enter a string: M);
gets(str) ;
} while(strcmp("quit-, str»;
return 0;
6. ;* Computerized dictionary program. *j
#include <stdio.h>
#include <string.h>
int mal.n(void)
{
ehar diet[) [2) [40) = {

~house·, -a place of dwelling-,
"car" I ·a vehicle" •
•computer" , "a thinking machine~.
·program·, .~ sequence of instructions·,
• • • •
char word [80 J ;
int li
printf("Enter word: ");
gets (word) ;
'* look up the word */
i = OJ
/* search,while null string not yet encountered */
while(strcrnp(dict[iJ [0), "" )) (
)
H(!strcrnp(word. dict[i) [OJ)) {
printf ("meaning: %5·, dict [i] [1 J ) ;
break;
)
i++j
H(!strcrnp(dict[i}[OJ. "")
printf(-Not in dictionary\n");
return 0;

#include <stdio.h>

int main ()
{
    int i,a[20],j,k,max=0,maxi=0,mode;
    
    for(i=0;i<20;i++)
    {
        scanf("%d",&a[i]);
    }

    for (i = 0; i<20; i++)
    {
        k=a[i];
        
        for(j=i+1;j<20;j++)
        {
            if(k==a[j]) max++;
            if(max>maxi){
                maxi=max;
                mode=k;
            }
        }
    }
    printf("The mode is %d",mode);
    
    return 0;

}



#include <stdio.h>
#include<string.h>

char d[][2][40]={
    "house", "where you live",
    "car", "what you drive",
    "chair", "where you sit",
    "ball", "round object for playing",
    "food", "what you eat"};
    
int main()
{
    char word[80];
    int i;
    gets(word);
    for(i=0;strcmp(d[i][0],"");i++)
    {
        if(!strcmp(d[i][0],word))
        {
            printf("\n meaning is %s",d[i][1]);
            break;
        }
    }
    if(!strcmp(d[i][0],""))
        printf("\n word doesnt exist in dictionary");
        
    return 0;
}


#include <stdio.h>
#include <string.h>

int main ()
{
    char s[80];
    do
    {
        gets(s);
    } while(strcmp("quit",s));
    
    return 0;
}








This section checks how well you have integrated the material in
this chapter with that from earlier chapters.
I. Write a program that inputs strings from the user. If the string is
less than 80 characters long, pad it with periods. Print out the
string to verify that you have correctly lengthened the string.
2. Write a program that inputs a string and then encodes it by
taking the characters from each end, starting with the left side
and alternating, stopping when the middle of the string has been
reached. For example, the string "Hi there" would be "Heir eth".
3. Write a program that counts the number of spaces, commas, and
periods in a string. Usey switch to categorize the characters."
4. What is wrong with this fragment?
char str[BO);
str = getchar();
5. Write a program that plays a computerized version of Hangman.
In the game of Hangman, you are shown the length of a magic
word (using hyphens) and you try to guess what the word is by
entering letters. Each time you enter a letter, the magic word is
checked to see if it contains that letter. If it does, that letter is
shown. Keep a count on the number ofletters entered to
complete the word. For the sake of simplicity, a player wins
when the magic word is entirely filled by characters using 15 or
fewer guesses. For this exercise make the magic word
·concatenation."
\

#include <stdio.h>
#include <string.h>
int main(void)
(
char str[80];
int i;
printf{"Enter a string: ·)i
gets (str);
/* pad the string if necessary *1
for(i=strlen(str); i<79; i++)
strcat(str, ",");

printf(str} ;
return 0;
}
2. / * A simple coding program. */
linclude <stdio.h>
"include <string.h:>' ·
int main (void)
(
Ghar str[90];
. ~ . .
l.n .... 1, J;
printf("Enter message: .):
gets (str) ;
/ * code it '*/
1=0 : j = strlen(str) - 1:
whil"e(i<=j) {
ANSWERS
CUMIMTJ1IE SKlL1.S CHECK
if (i <j) printf("'c%c·, str[i], str[j]) .
else printf ("%c·, str[i}};
i++; j--:
)
return 0;
}
3. linclude <stdio.h>
*include <string.h>
int main(void)
(
char str[80];
int spaces, periods. commas;
int i:
printf("Enter a string: "):
gets (str) ;
spaces = 0;
commas = 0;
periods = 0;

for(i=Oi i<strlen(str); iTT)
switch(str[i]) (
)
case ',': periods++;
break:
case ',': commas++;
break:
case' '0 spaces++:
printf("spaces: %d\n", spaces);
printf("commas: %d\n", commas),
printf(·p~riods: 'dR, periods};
return 0;
4. The getchar( ) function returns a character, not a string.
Hence, it cannot be used as shown. You must use geta( ) to
read a string from the keyboard.
S. /. A simple game of Hangman */
•
'include <stdio.h>
#include <string.h>
int main (void)
(
char word{) = ·concatenation";
char temp{] = "-------------";
char Chi
int i, count;
count = 0: j* count number of guesses */
do (
printf("'s\n", temp);
printf(·F~ter your guess: .):
ch = getchar () ;
printf("'n"):
/* see if letter matches any in word *j
for(i=O; i<strlen(word); iTT)
if(ch==wordlij) temp[i) = ch;
count++;
) while (strcmp(temp, word)),

printf("'s\n", temp};
ANSWERS
REVIEWSKJUS CHECK
printf ("You guessed the word and used %d guesses". count);
return 0;
}

#include<stdio.h>
#include<string.h>

int main ()
{
    char c[80];
    int i;
    
    gets(c);
    
    i=strlen(c);
    printf("%s",c);
    
    for(i;i<80;i++)
    {
        printf(".");
    }
    
    return 0;
}


#include<stdio.h>
#include<string.h>

int main ()
{
    char str[80];
    gets(str);
    int i,space=0,comma=0,period=0;
    
    for(i=0;i<strlen(str);i++)
    {
        switch (str[i])
        {
            case ' ': space++;
            break;
            case '.': period++;
            break;
            case ',': comma++;
            break;
        }
    }
    printf("Number of commas is %d, number of spaces is %d, number of periods is %d", comma,space,period);
    return 0;
}


#include<stdio.h>
#include<string.h>

int main ()
{
    char c[50]="concentration", a[50]="-------------", x;
    int i,flag=0;
    
    do
    {
        printf("%s\n",a);
        printf("Enter alphabet:");
        x=getchar();

        for(i=0;i<strlen(c);i++)

            if(x==c[i])
                a[i]=x;
        flag++;
    } while(strcmp(a,c));
    
    printf("%s\n",c);
    printf("It took you %d tries to guess the word",flag);
    
    return 0;
}


#include<stdio.h>
#include<string.h>

int main ()
{
    int i,j;
    char str[80];
    gets(s);
    
    j=strlen(str);
    
    for(i=0;i<j/2;i++)
    {
        printf("%c%c",str[i],str[j-i-1]);
    }
    
    return 0;
}









Write a program that inputs 10 integers into an array. Then
have the program display the sum of the even numbers and the
sum of the odd numbers.
2. Write a program that simulates a log-on to a remote system. The
system can be accessed only if the user knows the password,
which in this case is 'Tristan: Give the user three tries to enter
the correct password. If the user succeeds, simply print Log-on
Successful and exit. If the user fails after three attempts to
enter the correct password, display Access Denied and exit.
3. What is wrong with this fragment>
char name[lO] = ftThomas Jefferson-;
4. What is a null string?
5. What does strcpy( ) do? What does strcmp( ) do?
6. Write a program that creates astring table consisting of names
and telephone numbers. Initialize the array with some nam~s of
people you know and their phone numbers. Next, have the
program request a name and print the associated telephone
number. In other words, create a computerized telephone book

1.• include <stdio.h>
int main(void)
{
}
int num[lO}. i, even, odd:
printf("Enter 10 integers: ");
for(i=O; 1<10; i++) seanf("td", &num[i]);
even = 0; odd = 0;
for(i=O; i< 10; i++) {
if{num[i]%2} odd = odd + num[i];
else even = even + num(i];
}
printf{·Sum of even numbers: %d\n", even);
printf("Sum of odd numbers: %dn, odd);
return 0;
2. #include <stdio.h>
_include <string.h>
int ma.in(void)
{
char pw[BO};
int i;
for(i=O; 1<3; i++) {
printf ("Password: .. );

gets (pw) ;
if(!strcrnp(~Tristan·. pw» break;
)
if(i==3) printf("Access Denied");
else printf("Log-on Successful");
return 0;
3. The array, name, is not big enough to hold the string being
assigned to it.
4. A null string is a string that contains only the null character.
S. The strcpy( ) function copies the contents of one string into
another. The strcmp( ) function compares two strings and
returns less than zero if the first string is less than the second,
zero if the strings match, or gteater than zero if the first string is
greater than the second.
6. /* A Simple computerized telephone book. */
#include <stdio.h>
#include <string.h>
char phone 1I 1211401 = (
"Fred", "555-1010",
"Barney", "555-1234" I
"Ralph", "555-2347".
"Tom". "555-8396",
" "
) ;
int main(void)
(
char name[BO);
int i;
printf("Name? ");
gets (name) ;
for(i=O; phonelillOIIOl; i++)
if ( ! strcmp (name, phone [i] [0] ) )
printf ("number: %5". phone(i] [lJ);

return 0;




#include <stdio.h>

int main ()
{
    int a[10],i,ev=0,od=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        if(a[i]%2==0)
        {
            ev=ev+a[i];
        }
        else od=od+a[i];
    }
    printf("sum of odd integers %d and sum of even integers %d",od,ev);
    
    return 0;
}




#include <stdio.h>

int main ()
{
    char pass[10]="Tristan", tr[10];
    int i;
    printf("Enter password: ");
    for(i=1;i<=3;i++)
    {
        scanf("%s",&tr);
        if( pass[0]==tr[0] && pass[1]==tr[1] && pass[2]==tr[2] && pass[3]==tr[3] && pass[4]==tr[4] && pass[5]==tr[5] && pass[6]==tr[6])
        {
            printf("Log-on successful");
            return 0;
        }
        else printf("try again\n");
    }
    printf("Access denied");
    return 0;
}




#include<stdio.h>
#include<string.h>

int main ()
{
    char namebook[][2][20]={  "Amy", "0191817161", "Paul", "01971615", "Farin", "01534694346"};
    char name[20];
    int i;
    gets(name);
    for(i=0;i<4;i++)
    {
        if(!strcmp(name,  namebook[i][0]))
        {
            printf("%s", namebook[i][1]);
            return 0;
        }
    }
    printf("Name not found");
    return 0;
}

