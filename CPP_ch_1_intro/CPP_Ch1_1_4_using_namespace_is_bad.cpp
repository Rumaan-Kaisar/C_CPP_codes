// https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

/* 
    I have heard using namespace std; is bad practice, and that I should use "std::cout" and "std::cin" directly instead. Why is this? 
    Does it risk declaring variables that share the same name as something in the std namespace?

    1.
    Don't forget you can do: "using std::cout;" which means you don't have to type "std::cout", but "don't bring in the entire std namespace" at the same time.


    2.
    It is particularly bad to use 'using namespace std' at "file scope" in "header files". Using it in "source files" (*.cpp) at "file scope" after all includes is not quite as bad, as its effect is "limited to a single translation unit". Even "less problematic" is using it inside "functions" or "classes", because its effect is limited to the "function scope" or "class scope". 

    Problems 1: 
        Consider two libraries called Foo and Bar:

        using namespace foo;
        using namespace bar;

        Everything works fine, and you can call Blah() from "Foo" and Quux() from "Bar" without problems. But one day you upgrade to a new version of "Foo 2.0", which now offers also a function called "Quux()". Now you've got a "namespace conflict": Both Foo 2.0 and Bar import Quux() into your "global namespace". This is going to take some effort to fix, especially if the function parameters happen to match.

        If you had used foo::Blah() and bar::Quux(), then the introduction of foo::Quux() would have been a non-event.

    problems 2:
        Library Foo 2.0 could introduce a function, Quux(), that is an unambiguously better match for some of your calls to Quux() than the bar::Quux() your code called for years. Then your code still compiles, but it silently calls the wrong function and does god-knows-what. That's about as bad as things can get.

        Keep in mind that the "std namespace" has "tons of identifiers", many of which are very common ones (think list, sort, string, iterator, etc.) which are very likely to appear in other code, too.


    Benefit of using "std::" prefix:
        It actually made the "code more readable", the prefixes objectively add 'clarity' to the 'code'. Not only the compiler, but you, too, find it easier to see which identifier is referred to.

 */

#include<iostream>
// using namespace std;

int main(){
    std::cout<<"This is a short C program \n"<<std::endl;
    // following will be printed in one line unless "Escape character are used"
    std::cout<<"This is "<<std::endl;
    std::cout<<"Another "<<std::endl;
    std::cout<<"C++ program. "<<std::endl;

    return 0;
}
