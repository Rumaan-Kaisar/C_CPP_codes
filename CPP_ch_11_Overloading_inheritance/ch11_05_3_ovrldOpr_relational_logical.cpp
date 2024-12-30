
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









