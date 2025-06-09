

// --------    rev[09-Jun-25]    --------


// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-







// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
MASTERY SKILLS CHECK: Chapter 7
1. # include <iostream >
using namespace std ;
class building
{
protected :
int floors ;
int rooms ;
double footage ;
};
class house : public building
{
int bedrooms ;
int bathrooms ;
public :
house ( int f, int r, double ft , int br , int bth)
{
floors = f;
rooms = r;
footage = ft;
bedrooms = br;
bathrooms = bth;
}
void show ()
{
cout << " floors : " << floors << ’\n’;
505TEACH YOURSELF
C++
cout << " rooms : " << rooms << ’\n’;
cout << " square footage : " << footage << ’\n’;
cout << " bedrooms : " << bedrooms << ’\n’;
cout << " bathrooms : " << bathrooms << ’\n’;
}
};
class office : public building
{
int phones ;
int extinguishers ;
public :
office ( int f, int r, double ft , int p, int ext )
{
floors = f;
rooms = r;
footage = ft;
phones = p;
extinguishers = ext;
}
void show ()
{
cout << " floors : " << floors << ’\n’;
cout << " floors : " << floors << ’\n’;
cout << " rooms : " << rooms << ’\n’;
cout << " square footage : " << footage << ’\n’;
cout << " Telephones : " << phones << ’\n’;
cout << " fore extinguishers : ";
cout << extinguishers << ’\n’;
}
};
int main ()
{
house h_ob (2, 12, 5000 , 6, 4);
office o_ob (4, 25, 12000 , 30, 8);
cout << " House :\n";
h_ob . show ();
cout << "\ nOffice :\n";
o_ob . show ();
return 0;
}
2. When a base class is inherited as public, the public members of the base become public
members of the derived class, and the base’s private members remain private to the base.
If the base is inherited as private, all members of the base become private members of the
derived class.
3. Members declared as protected are private to the base class but can be inherited (and
506ANSWERS
CUMULATIVE SKILLS CHECK: Chapter 7
accessed) by any derived class. When used as an inheritance access specifier, protected
causes all public and protected members of the base class to become protected members
of the derived class.
4. Constructors are called in order of derivation. Destructors are called in reverse order.
5. # include <iostream >
using namespace std ;
class planet
{
protected :
double distance ; // miles from the sun
int revolve ; // in days
public :
planet ( double d, int r) { distance = d; revolve = r; }
};
class earth : public planet
{
double circumference ;
public :
earth ( double d, int r) : planet (d, r)
{
circumference = 2* distance *3.1416;
}
void show ()
{
cout << " Distance from sun : " << distance << ’\n’;
cout << " Days in orbit : " << revolve << ’\n’;
cout << " Circumference of orbit : ";
cout << circumference << ’\n’;
}
};
int main ()
{
earth ob (93000000 , 365) ;
ob. show ();
return 0;
}
6. To fix the program, have motorized and road use inherit vehicle as a virtual base class.
Also, refer to Question 1 in the Cumulative Skills Check in this chapter.



// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
CUMULATIVE SKILLS CHECK: Chapter 7
1. Some compilers will not allow you to use a switch in an in-line function. If this is the
case with your compiler, the functions were automatically made into "regular" functions.
507TEACH YOURSELF
C++
2. The assignment operators is the only operator that is not inherited. The reason for this
is easy to understand. Since a derived class will contain members not found in the base
class, the overloaded = relative to the base has no knowledge of the members added by
the derived class and, as such, cannot properly copy those new members.



// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-
REVIEW SKILLS CHECK: Chapter 8
1. # include <iostream >
using namespace std ;
class airship
{
protected :
int passengers ;
double cargo ;
};
class airplane : public airship
{
char engine ; // p for propeller , j for jet
double range ;
public :
airplane ( int p, double c, char e, double r)
{
passengers = p;
cargo = c;
engine = e;
range = r;
}
void show ();
};
class balloon : public airship
{
char gas ; // h for hydrogen , e for helium
double altitude ;
public :
balloon ( int p, double c, char g, double a)
{
passengers = p;
cargo = c;
gas = g;
altitude = a;
}
void show ();
};
void airplane :: show ()
{
cout << " Passengers : " << passengers << ’\n’;
cout << " Cargo capacity : " << cargo << ’\n’;
508ANSWERS
REVIEW SKILLS CHECK: Chapter 8
cout << " Engine : ";
if( engine == ’p’)
cout << " Propeller \n";
else
cout << " Jet \n";
cout << " Range : " << range << ’\n’;
}
void balloon :: show ()
{
cout << " Passengers : " << passengers << ’\n’;
cout << " Cargo capacity : " << cargo << ’\n’;
cout << " Gas : ";
if( gas == ’h’)
cout << " Hydrogen \n";
else
cout << " Helium \n";
cout << " Altitude : " << altitude << ’\n’;
}
int main ()
{
balloon b(2, 500.0 , ’h’, 12000.0) ;
airplane b727 (100 , 40000.0 , ’j’, 40000.0) ;
b. show ();
cout << ’\n’;
b727 . show ();
return 0;
}
2. The protected access specifier causes a class member to be private to its class but still
accessible by any derived class.
3. The program displays the following output, which indicates when the constructors and
destructors are called.
Constructing A
Constructing B
Constructing C
Destructing C
Destructing B
Destructing A
4. Constructors are called in the order ABC, destructors in the order CBA.
5. # include <iostream >
using namespace std ;
509TEACH YOURSELF
C++
class base
{
int i, j;
public :
base ( int x, int y) { i = x; j = y; }
void showij () { cout << i << ’ ’ << j << ’\n’; }
};
class derived : public base
{
int k;
public :
derived ( int a, int b, int c) : base (b, c)
{
k = a;
}
void show () { cout << k << ’ ’; showij (); }
};
int main ()
{
derived ob (1, 2, 3);
ob. show ();
return 0;
}
6. The missing words are "general" and "specific".


