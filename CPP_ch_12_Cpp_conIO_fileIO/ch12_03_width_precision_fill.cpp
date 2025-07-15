
/*  ------------------------    chapter    ------------------------


12.3 width(), precision(), AND fill()
To set these format parameters: the field width, the precision, and the fill character, there are three member functions defined by ios. These are 	width(), 	precision()       and 	fill(),     respectively.
	width(): To specify a minimum field width we use the width() function. Its prototype is:
streamsize width( streamsize w);
	Here w becomes the field width, and the previous field width is returned. 
	The streamsize type is defined by <iostream> as some form of integer. 
	It might be necessary to set the minimum field width before each output statement.
	When a value uses less than the specified width, the field is padded with the current fill character (the space, by default) so that the field width is reached.
	If the size of the output value exceeds the minimum field width, the field will be overrun. No values are truncated.
	precision(): By default, six digits of precision are used. You can set this number by using the precision() function. Its prototype:
streamsize precision( streamsize p);
	Here the precision is set to p and the old value is returned.
	fill(): by default, when a field needs to be filled, it is filled with spaces. To specify the fill character use fill() function. Prototype:
char fill( char ch);
	After a call to fill(), ch becomes the new fill character, and the old one is returned.
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



*/  
