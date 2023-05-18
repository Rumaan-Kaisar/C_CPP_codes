IN this chapter you will learn about.C's console I/O functions and also File I/O functions.
These are the functions that read or write information to and from the console/file. 

You have already been using some of these functions.
  Here we will look at them in detail. 
 
---------------     Raw Mstry & skill     -------------


-------------     mastery     -------------
Before proceeding you should be able to answer these questions and
perform these exercises:
1. What is the difference between getchar( ), getche( ), and
getch( )?
2. What is the difference between·the %e and the %E printf( )
format specifiers?
What is a scanset?
4. Write a program, using scanf( ), that inputs your first name,
birth date (using the format mmldd/yy), and telephone
number. Redisplay the information on the screen to verify that
it was input correctly.
5. What is one advantage to using puts( ) over printf( ) when
you only need to output a string? What is one disadvantage to
puts( )?
6. Write a program that defines a macro called COUNT as the
value 100. Have the program then use this macro to control a
for loop that displays the numbers a through 99.
7. What is EOF, and where is it defined?


This section checks how well you have integrated the material in
this chapter with that from earlier chapters.
1. Write a program that allows you to enter the batting averages for
the players on a little league team. (Assume there are exactly 9
players.) Have the user enter the first name and batting average
of each player. Use a two-dimensional character arrav to hold
the names and a one-dimensional double array to hold the
batting averages. Once all the names are entered, have the
program report the name and average of the players with the
highest and lowest averages. Also, have the program display the
team average.
2. Write a program that is a simple electronic library card catalog.
Have the program display this menu:
Card Catalog:
1. Enter
2. Search by Author
3. Search by Title
4. Quit
Choose your selection:


If you choose Enter, have the program repeatedly input the name,
author, and publisher of a book. Have this process continue until the
user enters a blank line for the name of the book.
For searches, prompt the user for the specified author or title and
then, if a match is found, display the rest of the information. After you
finish this program, keep your file, because in the next chapter you
wi11learn how to save the catalog to a disk file.





------------- ch 9 intro note -------------
L THO UGH C does not define any keywords that perform
file 110, the C standard library contains a very rich set of
110 functions. As you will see in this chapter, C's approach
to 110 is efficient, powerful, and flexible.
Most C compilers supply two complete sets of file 110 functions. One is called
the ANSI file system (sometimes called the buffered file system). This file
system is defined by the ANSI Cstandard. The second file system is based on
the original UNIX operating environment and is called the UNIX-like file
system (sometimes called the unbuffered file system). This file system is not
defined by the ANSI C standard. The ANSI standard only defines one file
system because the two file systems are redundant. Further, not all
environments may be able to adapt to the UNIX-like system. For these
reasons, this book only discusses the ANSI file system. For a discussion of the
UNIX-like file system, see my book C: The Complete Reference (Berkeley,
CA, Osborne/McGraw-HilI)



---------------------    review skill    ------------------------
Before proceeding you should be able to perform these exercises
and ans',,'er these questions:
I . What is the difference between getchar( ) and gctche( F
2. Gwe one ·reason why you probably won't use 8canf( )'s %8
option to read strings from the keyboard.
3. Write a program that prints a four-column table of the prime
numbers between 2 and 1000. Make sure that the columns
are aligned.
4. Write a program that inputs a double, a character, and a string
not longer than 20 characters. Redisplay the values to confirm
that they were input correctly.
5. Write a program that reads and discards leading digits and then
reads a string. (Hint: Use a scanset to read past any leading digits.)


--------------  mastery - 9 ---------------
Before continuing, you should be able to answer these questions
and complete these exercises:
1. Write a program that displays the contents of a text file (specified
on the command line), one line at a time. After each line is
displayed, ask the user ifhe or she wants to sec another line.
Write a program that copies a text file. Have the user specify
both file na~es on the command line. Have the copy program
convert all lowercase letters into uppercase ones.
3. What do fprintf( ) and fscanf( ) do?
4. Write a program that uses fwrite( ) to write 100 randomly
generated integers to a file called RAND.
5. Write a program that uses fread( ) to display the integers stored
in the file called RAND, created in Exercise 4.
6. Using the file called RAND, write a program that uses fseek( )
to allow the user to access and display the value·of any integer
in the file.
7. How do the "console' I/O functions relate to the file system?


This section checks how well you have integrated the material in
this chapter with that from earlier chapters.
1. Enhance the card-catalog program you wrote in Chapter 8 so
that it stores its information in a disk file called CATALOG.
When the program begins, have it read the catalog into memory.
Also, add an option to save the information to disk.
2. Write a program that copies a file. Have the user specify both
the source and destination files on the command line. Have the
program remove tab characters, substituting the appropriate
number of spaces.
3. On your own, create a small database to keep track of anything
you desire-your CD collectiorl;" for el<ample:


N this chapter you wil11earn about two of C's most important
user·defined types: the structure and the union.




Before proceeding you should be able to answer these questions and
perform these exercises:
1. Write a program that copies a file. Have the user specifY both
the source and destination file names on the command line.
Include full error checking.
2. Write a program using fprintf( ) to create a file that contains
this information:
this is a string 1230.23 IFFF A
Use a string, a double, a hexadecimal integer, and character
format specifiers and values.
3. Write a program that contains a 20·element integer array.
Initialize the array so that it contains the numbers 1 through 20.
Using 0Tlly one fwrite( ) statement, save this array to a file
called TEMP.
4. Write a program that reads the TEMP file created in Exercise 3
into an integer array using only one fread( ) statement. Display
the contents of the array.
5. What are stdin, stdout, and stderr?
6. How do functions like printf( ) and scanf( ) relate to the C
file system?
