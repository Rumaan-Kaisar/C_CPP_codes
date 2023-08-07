
// -------------------    NESTED STRUCTURES    -------------------

// A sctructure's members can also be other structures. These are referred to as nested structures. 


/* Example 1: Here is an example that uses nested structures to hold information on 
the performance of two assembly lines, each with ten workers: */

struct worker{
    char name[80];
    int avg_units_per_hour;
    int avg_errs_per_hour; 
};

struct asm_line{	
    int product_code;
    double material_cost;
    struct worker wkers[NUM_ON_ LINE];
};

struct asm_line line1, line2;


// ------------------    accessing nested structure members    ------------------
// Whenever you have nested structures, you begin with the "outermost " and end with the "innermost ".

// To assign the value 12 to the 'avg_units_per_hour' of the "second wkers structure of line1" , use this statement:

line1.wkers[1].avg_units_per_hour = 12;

// As you see, the structures are accessed from the outer to the inner. This is also the general case. 




/* Example 2: A nested structure can be used to improve the card catalog program. 
                Here, the mechanical information about each book is stored in its own structure, 
                which, in turn, is part of the catalog structure. 

                It stores its information in a disk file called "CATALOG".

                Notice how the program now stores the 'length of the book' in "pages".
				
				Notice how using a 'structure' makes it easier to organize the information about each book.
				Also notice how the 'entire structure array' is written and read from disk in a 'single operation'.

                When the program begins, have it read the catalog into memory.
                Also, add an option to save the information to disk.

                Card Catalog:
                            1. Enter Books
                            2. Search by author
                            3. Search by Title
                            4. Save catalog
                            5. Quit


                If you choose Enter, have the program repeatedly input the name, author, and publisher of a book.
                    Have this process continue until the user enters a blank line for the name of the book.

                For searches, prompt the user for the specified author or title and
                then, if a match is found, display the rest of the information.

                The program should be capable of storing 100 book info.
*/

/* =-=-=-=-=-=-=-=-=-=-=            An electronic card catalog             =-=-=-=-=-=-=-=-=-=-= */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int menu(void);
void enter(void);
void load(void);
void save(void);

void display(int i);
void author_search(void);
void title_search(void);


// Following structuer "book_type" will be Nested inside "catalog"
struct book_type {
	unsigned date; 		// copyright date
	unsigned char ed; 	// edition
    unsigned pages;     // length of book
};

struct catalog{
	char name[80]; 		    // author name
	char title[80];		    // title
	char pub[80];  		    // publisher
    struct book_type book;  // mechanical info wi
};

struct catalog cat[MAX];    // creating array of "catalog structure"


int top = 0;    // last location used


int main(void){
    int choice;

    load();  // open to read in catalog

    do{
        choice = menu();
        switch(choice){
            case 1: enter(); // enter books
                break;
            case 2: author_search(); // search by author
                break;
            case 3: title_search(); // search by, title
                break;
            case 4: save();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice, select a choice
int menu(void){
    int i;
    char str[80];

    printf("Card Catalog:\n");
    printf("1. Enter Books\n");
    printf("2. Search by author\n");
    printf("3. Search by Title\n");
    printf("4. Save catalog\n");
    printf("5. Quit\n");

    do{
        printf("Choose your selection:\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


// Following codes are modified to access structure members
// Enter books into Database (modified code 1 )
void enter(void){
    int i;
	char temp[80];

	// notice how structre members are accessed
    for( i=top; i<MAX; i++){
        printf("Enter author name (ENTER to quit): ");
        gets(cat[i].name);
        if(!*cat[i].name) break;

        printf("Enter title: ");
        gets(cat[i].title);

        printf("Enter publisher: ");
        gets(cat[i].pub);

        // notice the acces of NESTED STURCTURE MEMBERS
		printf("Enter copyright date: ");
		gets(temp);
		cat[i].book.date = (unsigned) atoi(temp);

		printf("Enter edition: ");
		gets(temp);
		cat[i].book.ed = (unsigned char) atoi(temp);

        printf("Enter number of pages: ");
        gets(temp) ;
        cat[i].book.pages = (unsigned) atoi(temp);
    }

    top = i;
}



// Search by author
void author_search(void){
    char name[80];
    int i, found;

    printf("Name: ");
    gets(name);

    found= 0;

    for(i=0; i<top; i++){
        if(!strcmp(name, cat[i].name)){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Search by TITLE
void title_search(void){
    char title[80];
    int i, found;

    printf("Title: ");
    gets(title);

    found= 0;

    for(i=0; i<top; i++){
        if(!strcmp(title, cat[i].title)){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Display catalog entry. (modified code 2 )
void display(int i){
    printf("%s\n", cat[i].title);
    printf("By %s\n", cat[i].name);
    printf("Published by %s \n", cat[i].pub);
	printf("Copyright: %u, %u edition\n", cat[i].book.date, cat[i].book.ed);
    printf("Pages: %u\n", cat[i].book.pages);
}


// Load the catalog file
void load(void){
    FILE *fp;

    if((fp = fopen("catalog2","r"))==NULL){
        printf("Catalog file not on disk\n");
        // exit(1); we don't use it because we won't terminate the program
        return; // we use "return" to continue the "main" function
    }

    // read count: with ERR cheking
	if(fread(&top, sizeof top, 1, fp) != 1){
		printf("Error reading count.\n");
		exit(1);
	}

	// READ DATA: i.e array of catalog-structures,
		// "struct" keyward not necessary for "array of stucture"
	if(fread(cat, sizeof cat, 1, fp) != 1){
		printf("Error reading catalog DATA.\n");
		exit(1);
	}

    fclose(fp);
}


// save the catalog file
void save(void){
    FILE *fp;

    // open for writing
    if((fp = fopen("catalog2","w"))==NULL){
        printf("Cannot open catalog file\n");
        exit(1);
    }


    // write count: with ERR cheking
	if(fwrite(&top, sizeof top, 1, fp) != 1){
		printf("Error writing count.\n");
		exit(1);
	}

	// WRITE DATA: i.e array of catalog-structures,
		// "struct" keyward not necessary for "array of stucture"
	if(fwrite(cat, sizeof cat, 1, fp) != 1){
		printf("Error writing catalog DATA.\n");
		exit(1);
	}

    fclose(fp);
}



/* Update Note: (Manage Space: decrease 25 Times) In the preceding example, the entire catalog array is stored on disk, 
				even if the array is not full. 
				
				If you like, you can change the load() and save() routines as follows, 
				So that only structures actually holding data are stored on disk: */


// Load the catalog file (modified code 5 )
void load(void){
    FILE *fp;
	int i;

    if((fp = fopen("catalog2","rb"))==NULL){
        printf("Catalog file not on disk\n");
        return; // we use "return" to continue the "main" function
    }

    // read count: with ERR cheking
	if(fread(&top, sizeof top, 1, fp) != 1){
		printf("Error reading count.\n");
		exit(1);
	}

	// READ DATA: i.e array of catalog-structures,
		// NOTICE: "struct" keyward is necessary for each "structure"
		// also notice the use of "&" to point the structures
	for(i=0; i<top; i++) {
		// access each structure from the array
		if(fread(&cat[i], sizeof(struct catalog), 1, fp) != 1){
			printf("Error reading catalog DATA.\n");
			exit(1);
		}
	}

    fclose(fp);
}


// save the catalog file
void save(void){
    FILE *fp;
	int i;

    // open for writing
    if((fp = fopen("catalog2","wb"))==NULL){
        printf("Cannot open catalog file\n");
        exit(1);
    }

    // write count: with ERR cheking
	if(fwrite(&top, sizeof top, 1, fp) != 1){
		printf("Error writing count.\n");
		exit(1);
	}

	// WRITE DATA: i.e array of catalog-structures,
		// NOTICE: "struct" keyward is necessary for each "structure"
		// also notice the use of "&"
	for(i=0; i<top; i++) {
		// access each structure from the array
		if(fwrite(&cat[i], sizeof(struct catalog), 1, fp) != 1){
			printf("Error writing catalog DATA.\n");
			exit(1);
		}
	}

    fclose(fp);
}





/* Example 3: Improve the telephorle-directory program we wrote earlier in this chapter so that it includes each person's "mailing address".
                Store the address in its own structure, called 'address', which is nested inside the directory structure.


                we wrote a program that created a telephone directory that was stored on disk.
				    It uses an array of structures, each containing

							a person's name,
							area code, and
							telephone number.

					Store the area code as an integer.
					Store the name and telephone number as strings.
				Make the array MAX elements long, where MAX is any convenient value that you choose.


                Have the program present a menu that looks like this:

                        1. Enter the names and numbers
                        2. Find numbers
                        3. Save directory to disk
                        4. Load directory from disk
                        5. Quit

                The program should be capable of storing 100 names and numbers. (Use only first names if you like.)
                Use fprintf() to save the directory to disk and fscanf() to read it back into memory. */

// A simple computerized telephone book.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct address {
    char street[40];
    char city[40];
    char state[3];
    char zip[12];
};

struct phone_type{
	char name[40];
	int areacode;
	char number[9];
    struct address addr;
};

struct phone_type phone[MAX];   // creating array of "phone_type structure"

int loc = 0;

int menu(void);
void enter(void);
void load(void);
void save(void);
void find(void);

int main(void){
    int choice;

    do{
        choice = menu();
        switch(choice){
            case 1: enter();
                break;
            case 2: find();
                break;
            case 3: save();
                break;
            case 4: load();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice
int menu(void){
    int i;
    char str[80];

    printf("1. Enter names and numbers\n");
    printf("2. Find numbers\n");
    printf("3. Save directory to disk\n");
    printf("4. Load directory from disk\n");
    printf("5. Quit\n");

    do{
        printf("Enter your choice\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


void enter(void){
    char temp[80];

    for( ; loc<10; loc++){
        if(loc<10){
            printf("Enter name:\n");
            gets(phone[loc].name);
            if(!*phone[loc].name) break;

            printf("Enter area code:\n");
	        gets(temp);
	        phone[loc].areacode = atoi(temp);

	        printf("Enter number:\n");
            gets(phone[loc].number);

            // input address info
            printf("Enter street address: ");
            gets(phone[loc].addr.street);

            printf("Enter city: ");
            gets(phone[loc].addr.city);

            printf("Enter State: ");
            gets(phone[loc].addr.state);

            printf("Enter zip code: ");
            gets(phone[loc].addr.zip);
        }
    }
}


void find(void){
    char name[80];
    int i;

    printf("Enter name: ");
    gets(name);

	if(!*name) return;

    for(i=0; i<10; i++){
        if(!strcmp(name, phone[i].name)){
            printf("%s (%d) %s\n", phone[i].name, phone[i].areacode, phone[i].number);
            printf("%s\n%s %s %s\n", phone[i].addr.street, phone[i].addr.city, phone[i].addr.state, phone [i].addr.zip);
        }
    }
}


void load(void){
    FILE *fp;

    if((fp = fopen("phone","rb"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    loc = 0;
    // loading the array of structure
    // notice the use of '&' to read array
    while(!feof(fp)){
        fread(&phone[loc], sizeof phone[loc], 1, fp);
        // ----------    old code    -----------
        // fscanf(fp,"%s%d%s", phone[loc].name, &phone[loc].areacode, phone[loc].number);
        // printf("%s%d%s \n", phone[loc].name, &phone[loc].areacode, phone[loc].number);
        loc++;
    }
    fclose(fp);
}


void save(void){
    FILE *fp;
    int i;

    if((fp = fopen("phone","wb"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    for(i=0; i<loc; i++){
        fwrite(&phone[i], sizeof phone[i], 1, fp);  // write the array of structure
        // ----------    old code    -----------
        // notice the " " spaces after the specifiers, during write
        // fprintf(fp,"%s %d %s ", phone[i].name, phone[i].areacode, phone[i].number);
        // save in following format:
        // a 123 01901 b 234 01802 c 345 01703
    }

    fclose(fp);
}

