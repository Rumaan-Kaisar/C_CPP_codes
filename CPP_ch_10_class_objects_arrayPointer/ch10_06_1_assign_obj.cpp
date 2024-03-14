
/*  ------------    Assigning Objects    ------------
    One object can be 'assigned to another object':
        both objects need to be the same type (similar to structure). 
 
    When one object is assigned to another, a "BITWISE COPY" of all the data members is made.

    Important fact:
        C++ is different in this case from Java, JavaScript & Python

        In C++, when you assign one object to another, a 'MEMBERWISE COPY' is made by default. 
            i.e. each data member of the SOURCE OBJECT is copied to the corresponding data member of the destination object. 
                For 'built-in' types, this copy operation is essentially a "bitwise copy". 
                For 'user-defined' types, the copy operation may involve calling the 'copy constructor' or "assignment operator", 
                    depending on how they are implemented.


        In Java / JavaScript / Python, on the other hand, when you assign one object reference to another, 
            you are "copying the REFERENCE", not the object itself. 
            Both the 'original' and the 'copied reference' point to the "same object" in MEMORY. 
            i.e. modifications made to the properties of one object will affect the other object 
                if they are referring to the same underlying data.

            To create a copy of an object with its 'own separate memory space' in Java/JavaScript/Python, 
                you typically need to perform a deep copy manually.

        Java:
            To create a deep copy of an object in Java, implement the 'Cloneable' interface and overriding the clone() method,
                This involves creating a new instance of the object and copying the state of all its fields to the new instance.  
            Alternatively use serialization/deserialization techniques.

        JavaScript:
            iterate through its properties and creating 'new copies of nested objects' recursively. 
            Alternatively, use built-in methods such as: 
                spread syntax ({...obj}) or Object.assign() to create shallow copies, 
            or you can use external libraries like lodash for deep copying.

        Python:
            Use the copy() method or the 'copy module' for shallow copies, 
            Or the deepcopy() function from the 'copy module' for deep copies. 
            These functions create new objects with their own memory space, recursively copying all nested objects.


    
    ----------------    rev[14-mar-24]    ----------------








Example 1: the contents of object called obj_1 is assigned to another object called obj_2, the contents of all of obj_1's data are copied into the equivalent members of obj_2. 
 
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

// assign obj_1 to obj_2 

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

// assign obj_1 to obj_2 

obj_2 = obj_1; 	// compile-time error will occur: not same type
obj_1.show();	 obj_2.show();
return 0;}
In this case, even though myclass and yourclass are physically the same, because they have different type names, they are treated as differing types by the compiler.
	All data members of one object are assigned to another when an assignment is performed. This includes compound data such as arrays. 

 */
