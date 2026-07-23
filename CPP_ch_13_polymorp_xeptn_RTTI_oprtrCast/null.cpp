


// ----  rev[09-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-










3. Create a generic class, called input, that does the following when its constructor is called:
➤ prompts the user for input,
➤ inputs the data entered by the user, and
➤ reprompts if the data is not within a predetermined range.
Objects of type input should be declared like this:
input ob(" prompt message ", min_value , max_value )
Here prompt message is the message that prompt for input. The minimum and maximum
acceptable values are specified by min-value and max-value, respectively. (Note: the type
of data entered by the user will be the same as the type of min-valueand max-value.)



3. # include <iostream >
using namespace std ;
template <class X> class input
{
X data ;
public :
input ( char *s, X min , X max);
// ...
};
template <class X>
input <X >:: input ( char *s, X min , X max )
{
do
{
cout << s << ": ";
cin >> data ;
}

while ( data < min || data > max);
}
int main ()
{
input <int > i(" enter int ", 0, 10) ;
input <char > c(" enter char ", ’A’, ’Z’);
return 0;
}



