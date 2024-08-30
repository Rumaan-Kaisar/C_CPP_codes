
/*  ------------------------    operator overloading : RELATIONAL and LOGICAL    ------------------------


Overloading the relational and logical operators

11.10 Overloading the RELATIONAL and LOGICAL operators
Overloading the relational and logical operators so that they behave in their traditional manner, they will return an integer that indicates either true or false.
	It allows the operators to be integrated into larger relational and logical expressions that involve other types of data.
Example 1. In the following program, the == and && operators are overloaded: comparing two objects- same/true/false/different.
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



*/  
