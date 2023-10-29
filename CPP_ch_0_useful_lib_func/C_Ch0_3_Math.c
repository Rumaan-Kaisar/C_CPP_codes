Mathematics functions
ANSI C defines several mathematics functions that take double arguments and return double values. Function categories:
	Trigonometric 		Hyperbolic 		Exponential and logarithmic 		Miscellaneous 

All the math functions require that the header math.h be included in any program that uses them.  This header defines a macro called huge_val for overflowing double causing range error. A domain error occurs if the input value is not in the domain. All angles are specified in radians.

Header Function	Description       #include <math.h>    must be  included before use	Example
#include <math.h>
double sin(double arg);	sin() returns the sine of arg. The  arg must be in radians.	printf("%f ", sin(x))
double cos(double arg);	cos() returns the cosine of arg. The  arg must be in radians.	printf("%f ", cos(x));
double tan(double arg);	tan() returns the tangent of arg. The  arg must be in radians.	printf("%f ", tan(x));
double asin(double arg);	asin() returns the arc sine of arg.  The range -1 through 1; otherwise a domain error occur.	printf("%f ", asin(x));
double acos(double arg);	acos() returns the arc cosine of arg.  The range -1 through 1; otherwise a domain error occur.	printf("%f ", acos(x));
double atan(double arg);	atan() returns the arc tangent of arg.  	printf("%f ", atan(x));
double atan2(double y, double x);	atan2() returns the arc tangent of y/x.  Signs of args are used to determine quadrant.	printf("%f ", atan2(y, x));
double sinh(double arg);	sinh() returns the hyperbolic sine of arg. 	printf("%f ", sinh(x));
Double cosh(double arg);	cosh() returns the hyperbolic cosine of arg. 	printf("%f ", cosh(x));
double tanh(double arg);	tanh() returns the hyperbolic tangent of arg. 	printf("%f ", tanh(x));
double ceil (double num);	ceil() returns smallest integer (represented as a double) that is not less than num.	printf("%f", ceil(9.9)); out: 10.0
double floor(double num);	floor() returns the largest integer (represented as a double) not greater than num.	printf("%f", floor(9.9)); out: 9.0
double pow(double base, double exp);	pow() returns base^exp. A domain error may occur if base=0 and exp≤0.  A domain error will occur if base<0 and exp is not an integer. An overflow produces a range error.	printf("%f ", pow(x, y));
double sqrt(double num);	sqrt() returns √num . If num<0 a domain error will occur.	printf("%f ", sqrt(4.0));
double exp(double arg);	exp() returns the natural logarithm e raised to the arg power e^arg.	printf("%f ", exp(1.0));
double log (double num);	log() returns the ln⁡(num). A domain error  for num<0 and a range error for num=0	printf("%f ", log(8.0));
double log 10(double num);	log10() returns the log_10⁡(num). domain error  for num<0 and range error for num=0	printf("%f ", log10(8.0));
double fabs(double num);	fabs() function the absolute value of num.	printf("%f ", fabs(-1.0));

