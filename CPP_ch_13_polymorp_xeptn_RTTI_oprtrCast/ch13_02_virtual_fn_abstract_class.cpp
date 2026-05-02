
/*  ------------------------    Virtual Functions (VF)    ------------------------

    A virtual function is a "base class member function" and redefined (overridden) by derived classes.
    
    Declaration:
        Declared using the "virtual" keyword in the base class. 
        The keyword is optional in derived classes.

    polymorphic class:
        A class that contains a virtual function (VF) is referred to as a "polymorphic class".
        i.e. enabling the "one interface, multiple methods" principle:
            Base class defines the interface of the VF; 
            Different derived classes provide their specific implementations to the VF.

    

    ----------------    Run-Time Polymorphism    ----------------

    A VF can be called just like any other member function. 

    But interesting thing happens when a VF is called through a "pointer"
        it creates the run-time polymorphism. 


    When a "base pointer" points to a derived object that contains a VF 
        and that VF is called through that pointer: 
        
        It is the "type" of that "pointed object" that determines which version of 
            the VF will be executed at the time when the call occurs.
        
        And, this determination is made at run time. 
        This process is the way that run-time polymorphism is achieved.


    Runtime Resolution (Dynamic Dispatch):
        The exact function version to execute is determined at "runtime", not at "compile time". 
        This "late binding" mechanism checks the object's true type the moment the call is made, 
            allowing the "correct overridden version" to run.

        This runtime selection process is how polymorphism is achieved. 
        It enables a single, consistent interface (the base pointer) to
            trigger different behaviors depending on the actual object it points to.
        Meaning "different derived objects will each execute their own specific function version, 
            even when accessed through the same base pointer."

    Note: Polymorphism is the goal. Dynamic dispatch is the tool. Runtime resolution is the timing.


    Therefore, if "multiple classes" are derived from a base class that contains a VF, 
    (each derived class has its own version of the VF)
        Then a base pointer can point to different objects at different times.
        And different versions of the VF are executed depending on which object it points to
*/




/* Example 1: Following program uses a VF. 

                Here the "type of the object" being pointed to determines which version of an 
                overridden VF will be executed when accessed via a base class pointer.
                And this decision is made at run time.  

                This program creates three classes : base, derived1 and derived2
                    The "base" class defines the virtual function func(). 
                    "base" is then inherited by both "derived1" and "derived2". 
                    Each of these classes overrides func() with its individual implementation. 


                Inside main(), the "base pointer p" is declared along with objects of type: 
                    "base", "derived1", and "derived2". 

                First, p is assigned the address of "ob" (base type object). 
                    When func() is called by using p, the "base version" of func() is used. 

                Next, p is assigned the address of "d_ob1" (derived1 type object). 
                    This time derived1 version (the overridden version) of func() is executed when func() is called using p. 
                    (the type of the object pointed to determines which VF will be called)

                Finally, p is assigned the address of "d_ob2" (derived2 type object) 
                    In this time, when func() is called by using p, 
                    the overridden version of func() defined inside derived2 is executed.

*/

#include <iostream>

class base{
    public:
        int i;
        base(int x){ i = x; }
        // VF
        virtual void func(){ 
            std::cout<< " Using base version of func(): ";
            std::cout << i << '\n'; 
        }
};

class derived1 : public base {
    public:
        derived1(int x) : base(x){} // passing argument to base constructor and uses same definition. Using base's constructor
        // override VF
        void func(){
            std::cout<< " Using derived1's version of func(): ";
            std::cout << i*i << '\n'; 
        }
};

class derived2 : public base {
    public:
        derived2(int x) : base(x){} // passing argument to base constructor and uses same definition. Using base's constructor
        // override VF
        void func(){
            std::cout << " Using derived2's version of func(): ";
            std::cout << i + i << '\n';
        }
};


int main(){ 
    base *p;

    base ob(10);
    derived1 d_ob1(10);
    derived2 d_ob2(10);

    p = &ob;
    p -> func();  // use base's func()

    p = &d_ob1;
    p -> func();  // use derived1's func()

    p = &d_ob2;
    p -> func();  // use derived2 's func()

    return 0; 
} 

/* 
    It displays the following output:

        Using base version of func(): 10
        Using derived1's version of func(): 100
        Using derived2's version of func(): 20
*/




/*  
    --------  Constructor & Destructor Rules  --------

    Constructors "cannot" be virtual.
    Destructors can (and often should) be virtual to ensure 
        proper cleanup in polymorphic hierarchies.


    ----------------   overriding vs overloading    ----------------

    "Redefinition of a VF" inside a derived class and "function overloading" are different process 
    (although they look similar). 

    overriding: Redefining a virtual function is called OVERRIDING, not overloading.

    parameter and return type Rules:
        Overloading: Functions must differ in parameter type, number, or both.
        Overriding: The redefined VF must exactly match the base function's parameter types, count, and return type.

    Parameter Changes Break Virtual Behavior:
        Changing either the number or type of parameters of redefined VF
            destroys its virtual (polymorphic) nature and makes it an "overloaded function"

    Class Membership: 
        Virtual functions must be class members. 
        Overloaded functions can be standalone or class members.

    Constructors vs. Destructors:
        Destructors can be virtual; constructors cannot.


    Because of the difference between overloaded functions and redefined VF, 
        the term "overriding" is used to describe VF redefinition.



    --------   Inheritance & Hierarchy Behavior  --------

    Virtual functions are hierarchical in "order of inheritance". 
    Virtual nature is preserved through multiple inheritance levels.

    when a derived class does not override a VF, 
        the function defined within its base class (the nearest base) is used. 

    Example: 
            Base  ->  Derived1  ->  Derived2

        If only Derived1 overrides, Derived2 inherits that version.
        If neither overrides, Base version runs.
*/




/* Example 2: "VF are HIERARCHICAL" in order of inheritance. 

                when a derived class does not override a virtual function, 
                    the function defined within its base class is used.

                Following is the reworked version of Example 1 with modified "derived2"
*/

#include <iostream>

class base{
    public:
        int i;
        base(int x){ i = x; }
        // VF
        virtual void func(){ 
            std::cout<< " Using base version of func(): ";
            std::cout << i << '\n'; 
        }
};

class derived1 : public base {
    public:
        derived1(int x) : base(x){} // passing argument to base constructor and uses same definition. Using base's constructor
        // override VF
        void func(){
            std::cout<< " Using derived1's version of func(): ";
            std::cout << i*i << '\n'; 
        }
};


// VF is not overriden here, base version used autometically
class derived2 : public base { 
    public :
        derived2(int x) : base(x){} // passing argument to base constructor
        // derived2 does not override the VF func()
};


int main(){ 
    base *p;

    base ob(10);
    derived1 d_ob1(10);
    derived2 d_ob2(10);

    p = &ob;
    p -> func();  // use base's func()

    p = &d_ob1;
    p -> func();  // use derived1's func()

    p = &d_ob2;
    p -> func();  // Notice it use now base's func()

    return 0; 
} 


/* Above program displays the following output:

        Using base version of func(): 10
        Using derived1’s version of func(): 100
        Using base version of func(): 10


    Here, derived2 does not override func(). 
        When p points to d_ob2 and func() is called, 
        the "base version" runs because it’s next in the hierarchy.

    In general, when a derived class does not override a VF, 
        the base class's version is used.   
*/




/* Example 3: A VF can respond to "random events" that occur at run time. 

                Consider Example 1, following modified main() selects between d_ob1 and d_ob2 
                    based upon the value returned by the standard random number generator rand(). 

                Remember that the version of func() executed is resolved at run time. 
                    (Which is impossible at compile time.)


                int main(){ 
                    base *p;
                    derived1 d_ob1 (10);
                    derived2 d_ob2 (10);
                    int i,j;

                    for(i=0; i<10; i++){
                        j = rand();

                        if( (j%2) ) p = &d_ob1 ;    // if odd use d_ob1
                        else p = &d_ob2 ;           // if even use d_ob2

                        p -> func();    // call appropriate function
                    }       

                    return 0;
                }
*/

#include <iostream>
#include <cstdlib>

class base{
    public:
        int i;
        base(int x){ i = x; }
        // VF
        virtual void func(){ 
            std::cout<< " Using base version of func(): ";
            std::cout << i << '\n'; 
        }
};

class derived1 : public base {
    public:
        derived1(int x) : base(x){} // passing argument to base constructor and using it
        // override VF
        void func(){
            std::cout<< " Using derived1's version of func(): ";
            std::cout << i*i << '\n'; 
        }
};

class derived2 : public base {
    public:
        derived2(int x) : base(x){} // passing argument to base constructor and using it
        // override VF
        void func(){
            std::cout << " Using derived2's version of func(): ";
            std::cout << i + i << '\n';
        }
};


int main(){ 
    base *p;
    derived1 d_ob1 (10);
    derived2 d_ob2 (10);
    int i,j;

    for(i=0; i<10; i++){
        j = rand();

        if( (j%2) ) p = &d_ob1 ;    // if odd use d_ob1
        else p = &d_ob2 ;           // if even use d_ob2

        p -> func();    // call appropriate function
    }       

    return 0;
}


/*  NOTE:
        Why does it produce the same output even though it uses rand()?

        The “randomness” just isn’t actually changing between runs.

        The issue is with rand() from <cstdlib>: 
            rand() produces the same output across runs because it isn't seeded, 
            if you don’t seed it, it starts from the "same initial seed" every time the program runs.
            
            So it produces the same sequence of numbers each time.

            Use srand(time(0)) (or modern <random>) to get different results on each run.
*/




/* Example 4: Following is a practical example of how a VF can be used.
                This program creates a generic base class called "area"
                    it holds two dimensions of a figure to represent general shapes (like triangle, rectangle)

                It declares a virtual function getarea(), which is meant to calculate area.

                The base class only defines the interface (i.e., that getarea() exists), not how it works.
                Derived classes override it to provide the actual implementation.
*/

#include <iostream>

class area {
        double dim1 , dim2 ; // dimensions of figure
    public:
        void setarea(double d1, double d2) {
            dim1 = d1;
            dim2 = d2;
        }
        void getdim(double &d1, double &d2) {
            d1 = dim1;
            d2 = dim2;
        }
        // virtual function that define interface
        virtual double getarea() {
            std::cout << " You must override this function \n";
            return 0.0;
        }
};


class rectangle : public area {
    public:
        double getarea() {
            double d1, d2;
            getdim(d1 , d2);
            return d1*d2;
        }
};


class triangle : public area {
    public:
        double getarea() {
            double d1, d2;
            getdim(d1 , d2);
            return 0.5*d1*d2;
        }
};


int main() {
    area *p;
    rectangle r;
    triangle t;

    r.setarea(3.3, 4.5);
    t.setarea(4.0, 5.0);

    p = &r;
    std::cout << "Rectangle has area : " << p-> getarea () << '\n';

    p = &t;
    std::cout << "Triangle has area : " << p-> getarea () << '\n';

    return 0;
}


/*  The getarea() method in the base area class is just a placeholder. 
        Since it isn't tied to a specific shape, it does nothing.
        So it must be overridden by subclasses to actually calculate an area. 

    The next section (abstract fn and PVF) shows how to enforce this requirement.
*/




/* Example 5: Following program creates a base class called num.
                This class hold an integer value and 
                contain a virtual function called shownum().

                Create two derived classes called "outhex" and "outoct" that inherit "num". 

                Have these derived classs override shownum() 
                    to display the number in hexadecimal and octal formats.
*/

#include <iostream>

class num {
    public:
        int i;
        num(int x) { i = x; }
        virtual void shownum() { std::cout << i << '\n'; }
};


class outhex : public num {
    public:
        outhex(int n):num(n){}
        void shownum() { std::cout << std::hex << i << '\n'; }
};


class outoct : public num {
    public:
        outoct(int n) : num(n){}
        void shownum() { std::cout << std::oct << i << '\n'; }
};


int main() {
    outoct o(10);
    outhex h(20);

    o.shownum();
    h.shownum();

    return 0;
}




/* Example 6: Following program creates a base class called "dist" 
                This class stores the distance between two points in a double variable.

                It has a virtual function called trav_time() that
                    outputs the time it takes to travel that distance,

                Assuming that:
                    the "distance" is in miles and
                    the "speed" is 60 miles per hour.


                In a derived class called "metric"                
                    override trav_time() so that it display travel time 
                    assuming: 
                        distance is in kilometers and 
                        speed is 100 km/h.
*/

#include <iostream>

class dist {
    public:
        double d;
        dist(double f) { d = f; }
        // VF
        virtual void trav_time() {
            std::cout << " Travel time at 60 mph : ";
            std::cout << d / 60 << '\n';
        }
};


class metric : public dist {
    public:
        metric(double f) : dist(f) {}   // passing argument to base constructor
        // override VF
        void trav_time() {
            std::cout << " Travel time at 100 kph : ";
            std::cout << d / 100 << '\n';
        }
};


int main() {
    dist *p, mph(88.0);
    metric kph(88);

    p = &mph;
    p-> trav_time();

    p = &kph;
    p-> trav_time();

    return 0;
}








/*  ------------------------    Abstract Class & Pure Virtual function (PVF)    ------------------------

    ---- More Abstraction ----
    
    Abstraction is the process of removing specific details 
        to focus on essential, general characteristics, reducing complexity.


----  rev[02-May-2026]  ----

Sometimes when a VF is declared in the base class there is no meaningful operation for it to perform.

  Because often a base simply supplies a core set of member functions and variables to which the derived class supplies the remainder.  
  
  In this case we use pure virtual functions (PVF).



*/













// ----  rev [01-May-2026]  ----




/* 






   A PVF has no definition relative to the base class. Only the function's prototype is included. To make a PVF, use this general form:
virtual type func_name(parameter_list =0;
   The key part of this declaration is the setting of the function equal to 0. This tells the compiler that no body exists for this function relative to the base class. 
   When a virtual function is made pure, it forces any derived class to override it. If a derived class does not, a compile-time error results. 
   Abstract class: When a class contains at least one PVF, it is referred to as an abstract class. It is an incomplete type, and no objects of that class can be created.  Thus, abstract classes exist only to be inherited. They are neither intended nor able to stand alone. 
   You can still create a pointer to an abstract class, since it is through the use of base class pointers that run-time polymorphism is achieved. 
   It is also permissible to have a reference to an abstract class.
   When a VF is inherited, so is its virtual nature. I.e. when a derived inherits a VF from a base and then that derived is used as a base for yet another derived, the VF can be overridden by the final derived class (as well as the first derived). For example, if base B contains a VF called f(), and D1 inherits B and D2 inherits D1, both D1 and D2 can override f() relative to their respective classes.
   Example 1: This program creates a base called area that holds two dimensions of a figure. It also declares a VF called getarea() that, when overridden by derived classes, returns the area of the type of figure defined by the derived. 

    class area{     double dim1 , dim2 ;    // dimensions of figure
        public :    void setarea(double d1, double d2){ dim1 = d1; dim2 = d2;}
        void getdim(double &d1 , double &d2) { d1 = dim1 ; d2 = dim2 ; }
            virtual double getarea(){   cout << "You must override this function \n";
                            return 0.0; }
        };
class rectangle : public area {
    public :
        double getarea(){double d1, d2;
                    getdim(d1, d2);
                    return d1*d2;  }
                };  class triangle : public area {
    public :
        double getarea() { double d1, d2;
                     getdim(d1, d2);
                  return 0.5*d1*d2;}
                };
int main(){     area *p;
        rectangle r;
        triangle t;
            r.setarea(3.3, 4.5) ;
            t.setarea(4.0, 5.0) ;
            p = &r; cout << " Rectangle has area : " << p-> getarea() << '\n';
            p = &t; cout << " Triangle has area : " << p-> getarea() << '\n';
        return 0; }
   In this case, the declaration of getarea() inside the base determines the nature of the interface. The actual implementation is left to the classes that inherit it. In this example, the area of a triangle and a rectangle are computed.
   Here the definition of getarea() inside area is just a placeholder and performs no real function. Because area is not linked to any specific type of figure, there is no meaningful definition that can be given to getarea() inside area.  
   getarea() must be overridden by a derived class in order to be useful. 

class area{ . . . . . . same as previous . . . . .
virtual double getarea() = 0;   // pure virtual function    };
   Example 2: Following program illustrates how a function's virtual nature is preserved when it is inherited:
class base {
public : virtual void func(){ 
cout << " Base version of func ( )\n"; }    };  class derived1 : public base {
public : void func(){ 
cout <<"derived1's version of func()\n"; }
 }; class derived2 : public derived1{   // derived2 inherits derived1
public : void func(){ 
cout << "derived2's version of func()\n"; } };
int main() {    base *p;
        base ob;
        derived1 d_ob1 ;
        derived2 d_ob2 ;
            p = &ob;    p -> func();        // use base's func()
            p = &d_ob1 ;    p -> func();        // use derived1's func()
            p = &d_ob2 ;    p -> func();        // use derived2's func()
        return 0; }
   The VF func() is first inherited by derived1, which overrides it relative to itself. Next, derived2 inherits derived1. In derived2, func() is again overridden.
   Since VFs are hierarchical, if derived2 did not override func(), when d_ob2 was accessed, derived1's func() would have been used.
   If neither derived1 nor derived2 had overridden func(), base's func( ) would have been used.









----  QWEN  ----

Here is a clean, simplified, and logically organized pointwise summary of your notes:



📘 13.2 Virtual Functions (VF)








⚠️ Changing a VF's signature destroys its virtual nature and turns it into an overloaded function.









📘 13.3 Pure Virtual Functions (PVF) & Abstract Classes


🔹 Pure Virtual Function (PVF)
Declared with = 0 in the base class: virtual return_type func() = 0;
Has no implementation in the base class (acts only as an interface placeholder).
Forces every derived class to override it; otherwise, compilation fails.
Used when the base class has no meaningful default behavior for that function.


🔹 Abstract Class
Any class containing at least one PVF is an abstract class.
❌ Cannot be instantiated (no objects can be created).
✅ Exists only to be inherited and used as a base.
✅ Pointers and references to abstract classes are allowed (essential for run-time polymorphism).


🔹 Key Behavior & Usage
PVFs define a contract: derived classes must provide the actual logic.
Example: class area { virtual double getarea() = 0; };
rectangle and triangle inherit area and must implement getarea().
Virtual hierarchy rules still apply: PVF overrides are inherited and can be further overridden down the chain.


💡 Quick Reference Checklist
✅ Use virtual in base class to enable overriding.
✅ Call through base pointer → run-time polymorphism.
✅ Missing override? → Base/nearest version runs.
✅ = 0 → Pure virtual → Abstract class → Must be overridden.
✅ Abstract classes: no objects, but pointers/references allowed.
✅ Overriding ≠ Overloading (signature must match exactly for VFs).
✅ Destructors: virtual ✅ | Constructors: virtual ❌
Let me know if you'd like this converted into flashcards, a diagram, or a condensed cheat sheet!








Here is a clean, simplified, and logically organized pointwise summary of your notes:

---
### 📘 **13.2 Virtual Functions (VF)**

#### 🔹 **Core Concepts**
- A **virtual function** is a base class member function intended to be redefined (overridden) in derived classes.
- Declared using the `virtual` keyword in the base class. The keyword is **optional** in derived classes.
- Enables the `"one interface, multiple methods"` principle → foundation of **polymorphism**.
- Base class defines the **interface**; derived classes provide **specific implementations**.

#### 🔹 **Run-Time Polymorphism**
- Achieved when a VF is called through a **base class pointer**.
- The **actual object type** pointed to determines which function version runs.
- Function resolution happens at **run-time**, not compile-time.
- Allows dynamic behavior: the same pointer can trigger different derived methods based on runtime conditions (e.g., user input, random selection).

#### 🔹 **Inheritance & Hierarchy Behavior**
- Virtual nature is **preserved** through multiple inheritance levels.
- If a derived class **does not override** a VF, the nearest base class version is automatically used.
- Example logic: `Base → Derived1 → Derived2`
  - If only `Derived1` overrides, `Derived2` inherits that version.
  - If neither overrides, `Base` version runs.

#### 🔹 **Virtual Functions vs. Function Overloading**
| Feature | Virtual Function (Overriding) | Function Overloading |
|--------|-------------------------------|----------------------|
| **Signature** | Must match exactly (same params & return type) | Must differ in parameter type/count |
| **Scope** | Must be a class member | Can be standalone or class member |
| **Resolution** | Run-time (dynamic binding) | Compile-time (static binding) |
| **Keyword** | `virtual` in base | None required |
| ⚠️ Changing a VF's signature destroys its virtual nature and turns it into an overloaded function. |

#### 🔹 **Constructor & Destructor Rules**
- ❌ **Constructors** cannot be virtual.
- ✅ **Destructors** can (and often should) be virtual to ensure proper cleanup in polymorphic hierarchies.

---
### 📘 **13.3 Pure Virtual Functions (PVF) & Abstract Classes**

#### 🔹 **Pure Virtual Function (PVF)**
- Declared with `= 0` in the base class: `virtual return_type func() = 0;`
- Has **no implementation** in the base class (acts only as an interface placeholder).
- **Forces** every derived class to override it; otherwise, compilation fails.
- Used when the base class has no meaningful default behavior for that function.

#### 🔹 **Abstract Class**
- Any class containing **at least one PVF** is an abstract class.
- ❌ **Cannot be instantiated** (no objects can be created).
- ✅ Exists **only to be inherited** and used as a base.
- ✅ Pointers and references to abstract classes **are allowed** (essential for run-time polymorphism).

#### 🔹 **Key Behavior & Usage**
- PVFs define a **contract**: derived classes must provide the actual logic.
- Example: `class area { virtual double getarea() = 0; };`
  - `rectangle` and `triangle` inherit `area` and must implement `getarea()`.
- Virtual hierarchy rules still apply: PVF overrides are inherited and can be further overridden down the chain.

---
### 💡 **Quick Reference Checklist**
- ✅ Use `virtual` in base class to enable overriding.
- ✅ Call through base pointer → run-time polymorphism.
- ✅ Missing override? → Base/nearest version runs.
- ✅ `= 0` → Pure virtual → Abstract class → Must be overridden.
- ✅ Abstract classes: no objects, but pointers/references allowed.
- ✅ Overriding ≠ Overloading (signature must match exactly for VFs).
- ✅ Destructors: virtual ✅ | Constructors: virtual ❌

Let me know if you'd like this converted into flashcards, a diagram, or a condensed cheat sheet!


 */
