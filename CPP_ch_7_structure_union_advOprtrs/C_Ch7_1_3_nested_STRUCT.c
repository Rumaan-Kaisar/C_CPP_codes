7.2.11 NESTED STRUCTURES
we have only been working with structures whose members consist solely of C's basic types. However, members can also be other structures. These are referred to as nested structures. Here is an example that uses nested structures to hold information on the performance of two assembly lines, each with ten workers:

struct worker{char name[80];
int avg_units_per_hour;
int avg_errs_per_hour; };

struct asm_line{	int product_code;
double material_cost;
struct worker wkers[NUM_ON_ LINE];
} line1, line2;

	To assign the value 12 to the avg_units_per_hour of the second wkers structure of line1 , use this statement:

line1.wkers[1].avg_units_per_hour = 12;

As you see, the structures are accessed from the outer to the inner. This is also the general case. Whenever you have nested structures, you begin with the "outermost " and end with the "innermost ".
