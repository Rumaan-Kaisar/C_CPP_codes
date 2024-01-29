	INDEPENDENT REFERENCES: Although not commonly used, the independent reference is another type of reference. An independent reference is a reference variable that in all effects is simply another name for another variable. 
	Because references cannot be assigned new values, an independent reference must be initialized when it is declared.
	Example :  	int main(){	int x;
int &ref = x; /* create an independent reference */ 

x = 10; 	/* these two statements */ 
ref = 10; 	/* are functionally equivalent */ 

ref = 100;

cout << x <<' '<< ref << "\n";	/* this prints 100 twice */ 
return 0; }
	In this program, the independent reference ref serves as a different name for x. From a practical point of view, x and ref are equivalent.
	An independent reference can refer to a constant. For example, const int &ref = 10; is valid.
	RESTRICTIONS on using Reference : There are a number of restrictions that apply to all types of references. 
 
[1]	You cannot reference another reference. 
[2]	You cannot obtain the address of a reference. 
[3]	You cannot create arrays of references.
[4]	You cannot reference a bit-field. 
[5]	References must be initialized unless they are members of a class, are return values, or are function parameters.
[6]	Remember, references are similar to pointers, but they are not pointers.
 

Note
[1]	Reference parameters offer several advantages over their (more or less) equivalent pointer alternatives. 
a.	No longer need to remember to pass the address of an argument. When a reference parameter is used, the address is automatically passed. 
b.	Reference parameters offer a cleaner, more elegant interface than the rather clumsy explicit pointer mechanism. 
c.	When an object is passed to a function as a reference, no copy is made. This is one way to eliminate the troubles associated with the copy of an argument damaging something needed elsewhere in the program (recall change : destructor problem while passing object to a function) when its destructor function is called.

