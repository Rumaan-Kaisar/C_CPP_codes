
/*  ------------------------    chapter    ------------------------


/*  ------------------------    chapter    ------------------------

13.4 Polymorphism: Early binding & Late binding
Polymorphism: Polymorphism is the process by which a common interface is applied to two or more similar (but technically different) situations, thus implementing the "one interface, multiple methods" philosophy. In polymorphism a single, well-defined interface is used to access a number of different but related actions, and artificial complexity is removed.
	There are two terms that are often linked to OOP in general and to C++ specifically. They are early binding and late binding. 
	Early binding: Early binding essentially refers to those events that can be known at compile time. Specifically, it refers to those function calls that can be resolved during compilation. Early bound entities include:
[1]	"Normal" functions, 	[2]	Overloaded functions,	[3]	Non-virtual member 	[4]	Friend functions.
	When these types of functions are compiled, all address information necessary to call them is known at compile time. 
	Calls to functions bound at compile time are the fastest types of function calls. Main disadvantage is lack of flexibility.
	Late binding: Late binding refers to events that must occur at run time. A late bound function call is one in which the address of the function to be called is not known until the program runs. 
	In C++, a virtual function is a late bound object.  When a VF is accessed via a base class pointer, the program must determine at run time what type of object is being pointed to and then select which version of the overridden function to execute. 
	Advantage: Flexibility at run time.  Disadvantage: is that there Slower than early binding.

	Example 1: Here is a program that illustrates "one interface, multiple methods." It defines an abstract list class for integer values. 
	The interface to the list is defined by the PVFs store() and retrieve(). To store a value, call store(). To retrieve a value, call retrieve(). 
	The base list does not define any default methods for these actions. Instead, each derived defines exactly what type of list will be maintained.
	In the program, two types of lists are implemented: a queue and a stack. Although the two lists operate completely differently, each is accessed using the same interface. 


#include<iostream >
#include<cstdlib >
using namespace std;

class list{ 	public: 	list *head ; 		/* pointer to start of list */ 
				list *tail ; 		/* pointer to end of list */ 
				list *next ; 		/* pointer to next item */ 

				int num ; 			/* value to be stored */ 

				list(){ head = tail = next = NULL ; }
			virtual void store(int i) = 0; 		/* PVF */
			virtual int retrieve() = 0; 		/* PVF */
	};

/* Create a queue - type list.*/

class queue : public list {
			public : void store(int i);
				   int retrieve();
				};

void queue :: store(int i){ list *item;
	item = new queue ;
	if(!item ){ 	cout << " Allocation error .\n";
			exit(1); }
	item -> num = i;

/* put on end of list */
	if(tail) tail -> next = item ;
	tail = item ;
	item -> next = NULL ;
	if(!head) head = tail ;  }

int queue :: retrieve(){	int i;
				list *p;
	if(!head){ 	cout << " List empty.\n ";
			return 0; }

/* remove from start of list */
	i = head -> num;
	p = head ;
	head = head -> next ;
	delete p;
	return i; }	
/* Create a stack - type list.*/

class stack : public list {
			public : void store(int i);
				   int retrieve();
				};

void stack :: store(int i){ list *item ;
	item = new stack ;
	if(!item){ 	cout << " Allocation error.\n";
			exit(1); }
	item -> num = i;

/* put on front of list for stack - like operation */
	if(head) item -> next = head ;
	head = item ;
	if(!tail) tail = head ; }

int stack :: retrieve(){ 	int i;
				list *p;
	if(!head){	cout << " List empty .\n";
			return 0; }

/* remove from start of list */
	i = head -> num;
	p = head ;
	head = head -> next ;
	delete p;
	return i; }

int main() {	list *p;
/* demonstrate queue */
		queue q_ob ;
		p = &q_ob;  	/* point to queue */ 
			p-> store(1);
			p-> store(2);
			p-> store(3);
		cout << " Queue : ";
			cout << p-> retrieve();
			cout << p-> retrieve();
			cout << p-> retrieve();
			cout << '\n';	/* demonstrate stack */
		stack s_ob;
		p = &s_ob; 	/* point to stack */ 
			p-> store(1);
			p-> store(2);
			p-> store(3);
		cout << " Stack : ";
			cout << p-> retrieve();
			cout << p-> retrieve();
			cout << p-> retrieve();
			cout << '\n';
		return 0;}

	Example 2:  To see why run-time polymorphism is so powerful, try using this main() instead of previous example:
	This main() illustrates how random events that occur at run time can be easily handled by using VFs and run-time polymorphism. 
	The program executes a for loop running from 0 to 9. Each iteration through the loop, you are asked to choose into which type of list- stack or the queue-you want to put a value. According to your answer, the base pointer p is set to point to the correct object and the current value of i is stored.
	Once the loop is finished, another loop begins that prompts you to indicate you to indicate from which list to remove a value. Once again, it is your response that determines which list is selected.

int main(){ 	list *p;
		queue q_ob ;
		stack s_ob ;
		char ch;
		int i;

	for(i=0; i <10; i++) {
		cout << " Stack or Queue ? (S/Q): ";
		cin >> ch;
		ch = tolower(ch);
		if(ch == 'q') p = &q_ob ;
		else p = &s_ob ;
		p -> store(i);	}	cout << " Enter T to terminate \n";

for(;;){  cout << " Remove from Stack or Queue ? (S/Q): ";
	    cin >> ch;
	    ch = tolower(ch);
		if(ch == 't') break ;
		if(ch == 'q') p = &q_ob ;
		else p = &s_ob ;
	    cout << p-> retrieve() << '\n';   }
	    cout << '\n';
return 0;}



Difference between Stack and Queue Data Structures :

Stack: A stack is a linear data structure in which elements can be inserted and deleted only from one side of the list, called the top. 
	A stack follows the LIFO (Last In First Out) principle, i.e., the element inserted at the last is the first element to come out. 
	The insertion of an element into stack is called push operation, and deletion of an element from the stack is called pop operation. 
	In stack we always keep track of the last element present in the list with a pointer called top.	Queue: A queue is a linear data structure in which elements can be inserted only from one side of the list called rear, and the elements can be deleted only from the other side called the front.

	The queue follows the FIFO (First In First Out) principle, i.e. the element inserted at first in the list, is the first element to be removed from the list. 
	The insertion of an element in a queue is called an enqueue operation and the deletion of an element is called a dequeue operation. 
	In queue we always maintain two pointers, one pointing to the element which was inserted at the first and still present in the list with the front pointer and the second pointer pointing to the element inserted at the last with the rear pointer.

*/  


*/  
