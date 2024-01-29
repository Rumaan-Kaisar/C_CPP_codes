
10.12 References
Reference a feature that is related to the pointer. A reference is an implicit pointer that for all intents and purposes acts like another name for a variable. There are three ways that a reference can be used.
 
[1]	First, a reference can be passed to a function. 
[2]	Second, a reference can be returned by a function. 
[3]	Finally, an independent reference can be created. 
 
	Reference as parameter : The most important use of a reference is as a parameter to a function. Let's first start with a program that uses a pointer (not a reference) as a parameter:

void f(int *n); 			/* use a pointer parameter */ 

int main() { 	int i = 0;
f(&i);
cout << " Here is i's new value : " << i << "\n";
return 0;}

void f(int *n){ *n = 100; } 	/* put 100 into the argument pointed to by n */ 

Here f() loads the value 100 into the integer pointed to by n. In this program, f() is called with the address of i in main(). Thus, after f() returns, i contains the value 100.
This program demonstrates how a pointer is used as a parameter to manually create a call-by-reference parameter-passing mechanism. In a C program, this is the only way to achieve a call-by-reference.

	However, in C++ reference parameter completely automate this process. To see how, let's rework the previous program. Here is a version that uses a reference parameter:

void f(int &n); 			/* declare a reference parameter */ 

int main() { 	int i = 0;
f(i);
cout << " Here is i's new value : " << i << "\n";
return 0;}

/* using now the reference parameter. Notice that no * is needed in the following statement */ 

void f(int &n){ n = 100; } 	/* put 100 into the argument pointed to by n */ 

	First, to declare a reference variable or parameter, you precede the variable's name with the &. This is how n is declared as a parameter to f(). 
	Now that n is a reference, it is no longer necessary-or even legal-to apply (not allowed) the * operator. Instead, each time n is used within f(), it is automatically treated as a pointer to the argument used to call f(). Within the function, the compiler automatically uses the variable pointed to by the reference parameter. This means that the statement n = 100; actually puts the value 100 into the variable used to call f(), which in this case, is i. 
	Further, when f() is called, there is no need ( in fact not allowed ) to precede the argument with the &. Instead, because f() is declared as taking a reference parameter, the address to the argument is automatically passed to f().When you use a reference parameter, the compiler automatically passes the address of the variable used as the argument. Thus, a reference parameter fully automates the call-by-reference parameter-passing mechanism.
	You cannot change what a reference is pointing to. For example, if the statement   " n++ ; "   were put inside f() in the preceding program, "n" would still be pointing to i in main(). Instead of incrementing n, this statement increments the value of the variable being referenced  (in this case, i).

Example:  The classic example of passing arguments by reference is a function that exchanges the values of the two arguments with which it is called. Here is an example called swap_args() that uses references to swap its two integer arguments:
written using references	written using pointers instead of references (recall 5.3)
	void swap_args(int &x, int &y)
	{	int t;
	t = x;  x = y;  y = t; 	}	void swap_args(int *x, int *y)
	{	int t;
	t = *x;  *x = *y;  *y = t; 	}
