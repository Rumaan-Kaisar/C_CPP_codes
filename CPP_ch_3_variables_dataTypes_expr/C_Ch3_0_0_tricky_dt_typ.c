
/* 
traditionally getchar() and getche() functions are declared as returning integers, not character values.
However, the character read from the kevboard is contained in the low-order byte.
the return value of getctar() or getche() can be assigned to a char is 
because C automatically removes the high-order byte.
 */

/* 
The loop never terminate because in C integers are 16 bits long.

    int i;
    for(i=0; i<33000; i++);

And i is a signed integer, its maximum value is 32,767. Therefore, it will never exceed 33,000,

 */