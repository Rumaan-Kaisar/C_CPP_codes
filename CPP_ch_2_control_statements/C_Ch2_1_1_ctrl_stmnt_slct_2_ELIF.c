/* 
------------------ Simple if-else ------------------ 
    if(expression) statementOrBlock;
    else statementOrBlock;      // Notice no condition with else
*/



/* 
------------------  if-else-if ladder & filtering  ------------------
if-else-if ladder is another form of nested if: 

FORM 1 :

        if(expression) statement;
        else
        if(expression) statement;
        else
            if(expression) statement;
            .
            .
            .
            else statement;



FORM 2 :

        if(expression) statement;
        else {  if(expression) statement;
                else {  if(expression) statement;
                        else {  if(expression) statement;
                                else {  if(expression) statement;
                                        else statement;
                                }
                        }
                }
        }

Both "FORM 1" and  "FORM 2" act in the same way. 
The expressions are calculated from the top - downward. 
As soon as a true condition is found. the statement associated with it is executed, 
and the rest of the ladder is bypassed.


General form of If-Else-If ladder:

        if(expression) statement;
        else if(expression) statementOrBlock;
        else if(expression) statementOrBlock;
        .
        .
        .
        else statementOrBlock;
 */



/* 
------------------  Nested IFs   ------------------
if(count > max)    // outer if 
    if (error) printf ("Error, try again. ");     // Inner-nested if
*/



------------------ Types of nested IF-ELSEs ----------------

Type 1:   General Nested if

    if(condition 1){
        if(condition 2)
        else
    }
    else { 
        if(condition 1)
        else
    }



Type 2 (Filter type):   General Nested if 

    if(cond. 1){
    if(cond. 2){ 
        if(cond. 3){
            if(cond. 4) /*4th*/
            else    }/*3rd*/
            else   }/*2nd*/
        else    }/*1st*/
    else

It is a filter type of nested if. If cond. 4 is true then all four conditions are true . 
If cond. 4 is false then associated else will be executed.



Type 3 - If-else-if ladder: Described already

    if(cond. 1) statement;
    else if(cond. 2) statement;
    else if(cond. 3) statement;
    .
    .
    .
    else statement;

Control statement can be passed through a series of  conditional statement using if-else-if ladder (Type-3) or
can be choose to flow through different series of  conditional statement (Type-1) or 
the control can be filtered (Type-2).
