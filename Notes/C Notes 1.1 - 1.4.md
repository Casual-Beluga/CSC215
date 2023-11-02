# The C programming language Chapters 1.1 - 1.4 

### 1.1

To print "Hello World" the code is: 
```
#include <stdio.h>
    
main(){

printf("hello, world\n");
}
```

### 1.2

The following program converts fahreneheit to celsius:

```
#include <stdio.h>

//print Fahrenheit to Celsius table from 0 - 300

#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main()
{   
    //declare variables
    //use float for more precisision over integers
    float fahr, celsius; 
    float lower, upper, step;
    
    //initialize variables
    lower = 0; /* lower limit of temperature scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;
    
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr-32);
        printf("%f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

```
### 1.3
Converting fahrenheit to celsius using a FOR statement:
```
#include <stdio.h>
// print Fahrenheit-Celsius table 
main()
{
    int fahr;
    for (fahr = 0; fahr <= 300; fahr = fahr + 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

```

Exercise 1 - 5 print the list in reverse order:
```
#include <stdio.h>
// print Fahrenheit-Celsius table 
main()
{
    int fahr;
    for (fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
```
Additional Data types
-
    char: character - a single byte
    short: a short integer
    long: a long integer
    double: double-precision floating point
    
### Format Specifiers

    // format specifier % = defines and formats a type fo data to be dispalyed

    %c = character
    %s = string (array of characters)
    %f = float
    %lf = double
    %d = integer

    %.1 = decimal precision
    %1 = minimum field width
    %- = left align

### Symbolic Constants
"#define" can be used to give a value to a piece of text, it however is not a variable
Ex:
    #define LOWER 0
    #define UPPER 300
    #define STEP 20
So instead of writing the numeric value in the conversion program LOWER, UPPER, and STEP, can be written instead. 
    



    
