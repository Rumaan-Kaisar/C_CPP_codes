

10.7 Object Pointers
It is possible to access a member of an object via pointer to that object. When a pointer is used, the arrow operator (->) rather than the dot operator is employed. (This is exactly the same way the arrow operator is used when given a pointer to a structure.)
However using the dot operator to access members of an object is the correct method.
	You declare an object pointer just like you declare a pointer to any other variable. Specify its class name, and then precede the variable name with an asterisk. 
	To obtain the address of an object, precede the object with & operator, just as you do when taking the address of any other type of variable.
	Just like pointers to other types, an object pointer, when incremented, will point to the next object of its type.
	It is important to understand that creation of an object pointer does not create an object-it creates just a pointer to one. 
For example 
int myclass :: get() { return a; }
int main() {	myclass ob (120) ; 	/*  create object  */
myclass *p; 		/*  create pointer to object  */ 
p = &ob; 		/*  put address of ob into p  */
cout << " Value using object : " << ob.get();
cout << "\n";
cout << " Value using pointer : " << p->get();
return 0; }
	Notice how the declaration          myclass *p; 	creates a pointer to an object of myclass. 
	The address of ob is put into p by using this statement:       p = &ob;
	Finally, the program shows how the members of an object can be accessed through a Pointer as using :      p->get()  .

	Pointer arithmetic using an object pointer is the same as it is for any other data type: it is performed relative to the type of the object. For example, when an object pointer is incremented, it points to the next object. When an object pointer is decremented, it points to the previous object.
 
class samp { int a, b;
/* inline function as constructor */
   public : samp(int n, int m) { a=n; b=m; } 
     int get_a() { return a; }
     int get_b() { return b; }   };
int main() {
samp ob[4] = {samp(1, 2), samp(3, 4),
samp(5, 6), samp(7, 8) };
int i;
samp *p;
p = ob;  /* get starting address of array */ 
for (i=0; i <4; i++){
cout << p->get_a () << ' ';
cout << p->get_b () << "\n";
p++;  /* advance to next object */ }
. . . . . }
 
	Each time p is incremented, it points to the next object in the array.


