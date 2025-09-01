
/*  ------------------------    width, precision, fill    ------------------------

    To set these format parameters: 
        the field width, 
        the precision, and 
        the fill character, 
        
        thse are three member functions defined by "std::ios":

        width():
            specify a minimum field width (padding spaces or fill chars).

        precision():
            number of digits for floating-point output.

        fill():
            padding character when width is not filled.

    Together, these are part of the C++ stream formatting system, "defined" inside the
    std::ios_base / std::ios hierarchy



    width(): 
        Purpose: Sets the minimum field width for the next output/input operation.
        
        Prototype:
                streamsize width(streamsize w);

        What it does:
            "w" becomes the new minimum "field width".
            Returns the previous width.
            "streamsize" is a type defined in <iostream> as a some kind of integer type.
        
        Important points:
            Must be set before each output/input — it is reset after each operation.
            If output is shorter than width, it's padded with the fill character (space by default).
            If the size of the output value exceeds the minimum field width, the field will be overrun.
                No truncation, the entire value is printed 
        


    precision():
        Purpose: Sets the number of digits after the decimal point for floating-point numbers.

        Prototype:
                streamsize precision(streamsize p);

        What it does:
            Sets precision to p (e.g., 4 means 4 digits after decimal).
            Returns the previous precision.
            Default: 6 digits.

        Note:
            Precision setting persists until changed again.



    fill()
        Purpose: Sets the "character" used to "pad fields" when width is larger than value.

        Prototype:
                char fill(char ch);

        What it does:
            "ch" becomes the new "fill character".
            Returns the previous fill character.
            Default: space ' '.


    NOTE: 
        These differ from manipulators (like std::setw, std::setprecision, std::setfill), 
        They do the same job but are used differently.




// ----  rev[29-Aug-2025]  ----


	Example 1: Following illustrates the basics of width, precision and fill.
int main(){ cout.width(10) ; 	// set minimum filed width
	cout<< "hello"<<'\n'; 	// right - justify by default

	cout.fill ('%'); 		// set fill character
	cout.width(10) ; 		// set width
	cout<< "hello" << '\n'; 	// right - justify default

	cout.setf(ios :: left ); 	// left - justify
	cout.width (10) ; 		// set width
	cout<< "hello" <<'\n'; 	// output left justified	
cout.width(10) ; 		// set width
cout.precision (10) ; 	// set 10 digits of precision
cout<< 123.234567 << '\n';

cout.width(10) ; 		// set width
cout.precision(6) ; 		// set 6 digits of precision
cout<< 123.234567 << '\n';

return 0; }
	Notice that the field width is set before each output statement.
	Example 2: The following segment uses the C++ I/O format functions to create an aligned table of numbers:
int main(){ double x;
   cout.precision(4) ;
   cout<< "x  sqrt(x)  x^2  \n\n";	for(x=2.0; x<=20.0; x++) {	cout.width(7); cout<<x<<" ";
				cout.width(7); cout<<sqrt(x)<<" ";
				cout.width(7); cout<<x*x<< \n';}
return 0; }





----  Qwen  ----

Here is the simplified pointwise summary of the given content on width(), precision(), and fill():

🔹 width(), precision(), and fill() – Stream Formatting Functions
These are member functions of ios (used with streams like cout, cin) to control how data is formatted during input/output.

✅ 1. width()




🔹 Example 1: Basic Use
cpp


1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
cout.width(10);           // Min width = 10
cout << "hello";          // Output: "     hello" (right-aligned, space-padded)

cout.fill('%');           // Change fill char
cout.width(10);
cout << "hello";          // Output: "%%%%%hello"

cout.setf(ios::left);     // Left-justify
cout.width(10);
cout << "hello";          // Output: "hello%%%%%"

cout.width(10);
cout.precision(10);
cout << 123.234567;       // Shows 10 digits precision

cout.precision(6);        // Reset precision
cout.width(10);
cout << 123.234567;       // Shows 6 digits after decimal
⚠️ Key Note: width() must be set before each output, as it applies only to the next insertion. 

🔹 Example 2: Creating a Neat Table
cpp


1
2
3
4
5
6
7
8
9
⌄
cout.precision(4);  // Set floating-point precision to 4 digits

cout << "x    sqrt(x)    x^2\n\n";

for(double x = 2.0; x <= 20.0; x++) {
    cout.width(7); cout << x << " ";
    cout.width(7); cout << sqrt(x) << " ";
    cout.width(7); cout << x*x << "\n";
}
Produces neatly aligned columns.
Each number takes up at least 7 characters, padded with spaces.
🔹 Summary Table
width(w)
Sets min field width
❌ No
✅ Yes
precision(p)
Sets decimal precision
✅ Yes
❌ No
fill(ch)
Sets padding character
✅ Yes
❌ No

✅ Key Takeaway
Use these functions to:

Align output (e.g., tables, reports)
Control decimal places
Customize padding and appearance
Always set width() just before the value you want to format! 


*/  
