10.6 Assigning Objects
One object can be assigned to another provided that both objects are of the same type (similar to structure). By default, when one object is assigned to another, a bitwise copy of all the data members is made. 
	For example, the contents of object called obj_1 is assigned to another object called obj_2, the contents of all of obj_1's data are copied into the equivalent members of obj_2. 
 
#include <iostream >
using namespace std;

class myclass {
int a, b;
public :
void set(int i, int j) {a = i; b = j; }
void show() {cout << a << ' ' << b << "\n";}
};

int main(){	myclass obj_1 , obj_2;
obj_1.set(10 , 4);

/* assign obj_1 to obj_2 */ 

obj_2 = obj_1;
obj_1.show();
obj_2.show();
return 0;}
 
	Here, object obj_1 has its member variables a and b set to the values 10 and 4, respectively. Next, obj_1 is assigned to obj_2. This causes the current value of obj_1.a to be assigned to obj_2.a and  obj_1.b to be assigned to obj_2.b. 
	An assignment between two objects simply makes the data in those objects identical. The two objects are still completely separate, For example, after the assignment, calling obj_1.set() to set the value of obj_1.a has no effect on obj_2 or its a value.


	Only objects of the same type can be used in an assignment statement. If the objects are not of the same type, a compile-time error is reported. It is not sufficient that the types just be physically similar-their type names must be the same. 

 
class myclass {
int a, b;
public :
void set(int i, int j) {a = i; b = j; }
void show() {cout << a << ' ' << b << "\n";}
};
class yourclass {
int a, b;
public :
void set(int i, int j) {a = i; b = j; }
void show() {cout << a << ' ' << b << "\n";}
}; 

int main(){	myclass obj_1 ; 
yourclass obj_2;
obj_1.set(10 , 4);

/* assign obj_1 to obj_2 */ 

obj_2 = obj_1; 	/* compile-time error will occur: not same type */
obj_1.show();	 obj_2.show();
return 0;}
In this case, even though myclass and yourclass are physically the same, because they have different type names, they are treated as differing types by the compiler.
	All data members of one object are assigned to another when an assignment is performed. This includes compound data such as arrays. 

