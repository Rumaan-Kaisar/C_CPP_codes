/* 
    An array is a list of like-type variables
    
    To declare a one-dimensional array, use the general form
        type var_name[size];
    where 'type' is a valid C data type, 
    'var_name' is the name of the array, and 
    'size' specifies the number of elements in the array.
    arrays start at zero, so an index of 1 references the second element. 
    specify the index of the element you want inside square brackets. For example, myarray[1] refers to the second element of myarray
    
    TO assign an array element a value, myarray[0] = 100;  gives the first element in myarray the value 100.
    User input: call to scanf() reads an integer into count[9].
        scanf("%d", &count[9]);
    Array overrun: C does not perform any bounds checking on array indexes. This means that it is possible to overrun the end of an array. 
    Copying array: you must do so by copying each element separately
        Char a1[10], a2[10];
        . . .
        . . .
        a1=a2; 	//This is wrong
*/



/* Example 1: use the value of an array element anywhere you would use a simple variable or constant. 
                For example, the following program loads the 'sqrs' array with the squares of the numbers 1 through 10 and then displays them. */
#include <stdio.h>
int main(void){
    int sqrs[10]; 
    int i;

    for(i = 1; i<11; i++) sqrs[i-1] = i*i;

    for(i = 0; i < 10; i++) printf("%d ", sqrs[i]);

    return 0;
}


/* Example 2: This program reads the noonday temperature for each day of a month 
                and then reports the month's average temperature, as well as its hottest and coolest days. */
#include <stdio.h>
int main(void){
    int temp[31], avg, i, min, max, total_temp; 
    int days;

    printf("How many days in the month? "); 
    scanf("%d", &days);
    for(i = 0; i < days; i++ ) {
        printf("Enter noonday temperature for day %d: ", i+1); 
        scanf("%d", &temp[i]);
    }

    // find average 
    total_temp = 0;
    for(i=0; i < days; i++) total_temp = total_temp + temp[i];
    avg = total_temp/days;
    printf("\nAverage temperature: %d", avg);

    // find min and max
    min = 200; // initialize min and max
    max = 0;
    for(i=0; i < days; i++){
        if(min > temp[i]) min = temp[i];
        if(max < temp[i]) max = temp[i];
    }

    printf("\nMinimum temperature: %d ", min);
    printf ("\nMaximum temperature: %d ", max);

    return 0;
}



/* Example 3: copy each element separately. 
                For example, this program loads a1 with the numbers 1 through 10 and then copies them into a2. */
#include <stdio.h>
int main(void){
    int a1[10], a2[10];
    int i;
    for(i=1; i < 11 ; i++) a1[i-1] = i;
    for(i=0; i<10; i++) a2[i] = a1[i];
    for(i=0; i<10; i++) printf("%d" , a2[i]);
    
    return 0;
}

// https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/
/* Method 1 : Using gets
Syntax : char *gets(char *str)
#include <stdio.h>
int main()
{
   char str[20];
   gets(str);
   printf("%s", str);
   return 0;
} */


/* Example 4: cypher program: the user first enters the message, which is stored in a character array. 
                When the user presses ENTER, the entire message is then encoded by adding I to each letter */
#include <stdio.h>
// #include <conio.h>
int main(void){
    char mess[8];
    int i;

    printf("Enter message (less than 80 characters)\n");
    for(i=0; i < 8; i++){
        mess[i] = getchar();
        if(mess[i]=='\r') break;
    }

    printf("\n") ;
    for(i=0; mess[i] !='\r'; i++) printf("%c", mess[i]+1);
    return 0;
}

// using string
#include <stdio.h>
#include <conio.h>
int main(void){
    char mess[8];
    int i;

    printf("Enter message (less than 80 characters)\n");
    gets(mess);

    printf("\n") ;
    for(i=0; mess[i] !='\r'; i++) printf("%c", mess[i]+1);
    return 0;
}

// Using string and no conio.h
/* Method 2 : To overcome the above limitation, we can use fgets as :
Syntax : char *fgets(char *str, int size, FILE *stream)
Example : fgets(str, 20, stdin); as here, 20 is MAX_LIMIT according to declaration.
#include <stdio.h>
#define MAX_LIMIT 20
int main()
{
   char str[MAX_LIMIT];
   fgets(str, MAX_LIMIT, stdin);
   printf("%s", str);
 
   return 0;
} */

#include <stdio.h>
#define MAX_LIMIT 20
int main(void){
    char mess[MAX_LIMIT];
    int i;

    printf("Enter message (less than 80 characters)\n");
    fgets(mess, MAX_LIMIT, stdin);

    printf("\n") ;
    // for(i=0; mess[i] !='\r'; i++) printf("%c", mess[i]+1);
    for(i=0; i < MAX_LIMIT; i++) {
        if(!mess[i]) break; // breaks if an empty element appers
        printf("%c", mess[i]+1);
    }
    return 0;
}


/* 
// Size of an array: https://www.w3schools.com/cpp/cpp_arrays_size.asp
Empty character constant in C++: https://stackoverflow.com/questions/31193454/empty-character-constant-in-c
This line:
m_pchString[m_nLength-1] = '';
What you probably mean is:
m_pchString[m_nLength-1] = '\0';
Or even:
m_pchString[m_nLength-1] = 0;
Strings are zero terminated, which is written as a plain 0 or the null character '\0'. For double quote strings "" the zero termintation character is implicitly added to the end, but since you explicitly set a single character you must specify which. */



/* Example 5: The general concept behind the bubble sort, is the repeated comparisons and, if necessary, exchanges of adjacent elements. 
                This is a little like bubbles in a tank of water with each bubble, in turn, seeking its own level. */

/*Sorting Numbers*/
#include<stdio.h>
int main(void){
    int s[100], count, i, j, x;

    printf("How many numbers ? : "); 
    scanf("%d", &count);

    printf("\n Enter the numbers one by one. : "); 
    for(i=0; i<count; i++) scanf("%d", &s[i]);

    /*Now sort them using bubble sort*/
    for(i=1; i < count; ++i)
    	for(j=(count-1); j>=i; --j){
    	    /*Compare adjacent element*/
    	    if(s[j-1]>s[j]){ 
                x=s[j];  
                s[j]=s[j-1];  
                s[j-1]=x; /*Exchange elements*/ }
			/*Ascending : s[j-1]>s[j], Descending : s[j-1]<s[j]*/
   		 }
    for(i=0; i<count; i++) printf(" %d", s[i]);
    return 0;
}

// float version
#include<stdio.h>
int main(void){
    float item[100], tmp;
    int count, i, j;

    printf("How many numbers ? : "); 
    scanf("%d", &count);

    printf("\n Enter the numbers one by one. : "); 
    for(i=0; i < count; i++) scanf("%f", &item[i]);

    /*Now sort them using bubble sort*/
    for(i=1; i < count; ++i)
    	for(j=(count-1); j>=i; --j){
    	    /*Compare adjacent element*/
    	    if(item[j-1] > item[j]){ 
                tmp = item[j];  
                item[j] = item[j-1];  
                item[j-1] = tmp; /*Exchange elements*/ }
			/*Ascending : s[j-1]>s[j], Descending : s[j-1]<s[j]*/
   		 }
    for(i=0; i<count; i++) printf(" %f", item[i]);
    return 0;
}


/* Example 6: ERROR: The array count is being overrun. It is only 10 elements long,
                but the program requires one that is 100 elementi long. */

#include <stdio.h>
int main(void){
    int i, count[10];

    for(i=0; i<10; i++){
        printf("Enter a number: ");
        scanf("%d", &count[i]);
    }

    for(i=0; count[i]; i++) printf("%d ", count[i]);

    return 0;
}



/* Example 7: Write a program that reads ten numbers entered by the user and
                reports if any of them match or duplication. */
#include <stdio.h>
int main (void){
    int i[10], j, k, match;

    printf("Enter 10 numbers:\n");
    for(j=0; j<10; j++) scanf("%d", &i[j]);

    // see if any match
    for(j=0; j<10; j++){
        match = i[j];
        for(k=j+1; k<10; k++){  //compare all elements after i[j], with i[j]
            if(match==i[k]) printf("%d is duplicated \n", match);
        }
    }

    return 0;
}




/* Example 8: Given the array
            int count[10];
		will this statement generate an error message?
		for(i=0; i<20; i++) count[i] =i; 
		
	The statement will not generate an error message because C
	provides "no bounds checking" on array operations, but it is
	wrong because it causes "count" to be "overrun".
*/




/* Example 9:  In statistics, the mode of a group of numbers is the one that
		occurs the most often. For example, given the list 1, 2, 3, 6, 4, 7,
		5,4,6, 9, 4, the mode is 4, because It occurs three times. Write a
		program that allows the user to enter a list of 20 numbers and
		then finds and displays the mode. */
#include <stdio.h>

int main(void){
    int stats[20], i, j;
    int mode, count, oldcount, oldmode;

    printf("Enter 20 numbers: \n");
    for(i=0; i<20; i++) scanf("%d", &stats[i]);

    oldcount = 0;

    //find the mode
    for(i=0; i<20; i++) {
        mode = stats[i];
        count = 1;

        //count the occurrences of this value */
        for(j=i+1; j<20; j++){
            if(mode==stats[j]) count++;
        }

        // if count is greater than old count, use new mode
        if (count > oldcount) {
            oldmode = mode;
            oldcount = count;
        }
    }

    printf("The mode is %d\n", oldmode);
    return 0;
}




/* Example 10 : Show how to initialize an integer array called "items" with the values 1 through 10. */
int items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


