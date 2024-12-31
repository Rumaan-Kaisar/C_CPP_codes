
/*  ------------------------    operator overloading : RELATIONAL and LOGICAL    ------------------------
    
    Relational (<, >, <=, >=, ==, !=) and logical operators (&&, ||, !) can be overloaded.

    Return Type:
        Operator functions should not return an "object" of the class they are defined for.
        Instead, return an integer (int) to indicate true (non-zero) or false (zero).
        This maintains traditional behavior and ensures compatibility with larger expressions.


    Modern C++ Option "bool":
        In modern C++ compilers, these operators can return a "bool" type.
        Although there's no functional advantage since bool automatically 
            converts to int (true → nonzero, false → 0) and vice versa.
*/




/* Example 1: The program overloads the == and && operators to compare two objects, 
                determining if they are the same (true) or different (false).
*/

// rev ---- 30-Dec-2024

class coord { public: /* similar to 11.9 Ex 1 */ 	int operator==(coord ob2); int  operator&&(coord ob2); };
int coord::operator==(coord ob2)
{
 return (x==ob2.x)&&(y==ob2.y);
}	int coord::operator&&(coord ob2)
{
return (x&&ob2.x)&&(y&&ob2.y);
}	int main(){coord o1(10, 10), o2(5, 3);
     if(o1 == o2) cout<<" same \n"; 
          else cout<<" differs \n";
     if(o1&&o2) cout<<" true \n"; 
          else cout << " false \n";
return 0;}
	Here both objects corresponding member elements are compared and then gives true or false value.
	Notice that in the declaration of both operator==() and operator&&() returns int. This is because true and false are corresponds to the values 1 and 0.



1. In the following program, the == and && operators are overloaded:
// Overload the == and && relative to coord class .
# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; };
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
int operator ==( coord ob2);
int operator &&( coord ob2);
};
// Overload the == operator for coord .
int coord :: operator ==( coord ob2)
{
return x== ob2 .x && y== ob2.y;
}
// Overload the && operator for coord .
int coord :: operator &&( coord ob2)
{
return (x && ob2 .x) && (y && ob2.y);
}
int main ()
{
coord o1 (10 , 10) , o2 (5, 3) , o3 (10 , 10) , o4 (0, 0);
if(o1 == o2)
cout << "o1 same as o2\n";
else
cout << "o1 and o2 differs \n";
if(o1 == o3)
cout << "o1 same as o3\n";
else
cout << "o1 and o3 differ \n";
if(o1 && o2)
cout << "o1 && o2 is true \n";
else
cout << "o1 && o2 is false \n";
if(o1 && o4)
cout << "o1 && o4 is true \n";
else
156INTRODUCING OPERATOR OVERLOADING
6.4. OVERLOADING A UNARY OPERATOR
cout << "o1 && o4 is false \n";
return 0;
}





1. Overload < and > operator relative to the coord class




