# Chapter 2 Notes 2.1 - 2.8

### 2.1 Variable Names

Variables have a variety of restrictions on how they can be named.
-   The character must be a letter.
-   "_" counts as a letter. However library routines often start with _ so using it as the start is not recommended
-   Names are case sensative so 'A' & 'a' are different.
-   reserved words such as: 'if', 'else', 'float', 'int', etc.. cannot be used

### 2.2 Data Types and Sizes

char a = 'C';                   // single character    %c
    char b[] = "Bro";            // array of characters %s  

    float c = 3.141592;                          // 4 bytes (32 bits of precision) 6 - 7 digits %f
    double d = 3.141592653589793; // 8 bytes (64 bits of precision) 15 - 16 digits %lf

    bool e = true;                         // 1 byte (true or false) %d
    
    char f = 120;                          // 1 byte (-128 to +127) %d or %c
    unsigned char g = 255;       // 1 byte (0 to +255) %d or %c

    short h = 32767;                   // 2 bytes (−32,768 to +32,767) %d
    unsigned short i = 65535;  // 2 bytes (0 to +65,535) %d

    int j = 2147483647;                     // 4 bytes (-2,147,483,648 to +2,147,483,647) %d
    unsigned int k = 4294967295;  // 4 bytes (0 to +4,294,967,295) %u

    long long int l = 9223372036854775807; // 8 bytes (-9 quintillion to +9 quintillion) %lld
    unsigned long long int m = 18446744073709551615U; // 8 bytes (0 to +18 quintillion) %llu

    printf("%c\n", a);  // char
    printf("%s\n", b);  // character array
    printf("%f\n", c);  // float
    printf("%lf\n", d); // double
    printf("%d\n", e);  // bool
    printf("%d\n", f);  // char as numeric value
    printf("%d\n", g);  // unsigned char as numeric value
    printf("%d\n", h);  // short
    printf("%d\n", i);  // unsigned short
    printf("%d\n", j);  // int
    printf("%u\n", k);  // unsigned int
    printf("%lld\n", l);  // long long int
    printf("%llu\n", m);  // unsigned long long int
    
    
### 2.3 Constants

Constants are values that cannot be changed, to make a constant simply precede a variable with 'const' 

It is convention to make constants capitialized. Ex: const int PI = 3;

### Using #Define
values can be defined using octal by setting have an integer with a leading 0 and hexidecimal by have using 0x. 
Ex: 



Additionally the type can be set by trailing the value with the type, l for long double, 
which is typically more precise then a double but is at least as precise. 
A U can also be added to octal and hexidecimal numbers to make it unsigned
Ex: 0XFUL is a unsigned long with a decimal value of 15. 

### Character Constants

A character constant is an integer represented as a character in single quotes, where the integer value is based on the integer value of the character in ASCII. 

### Escape sequences
Certain "special" characters can be represented through escape sequences. Some examples of these would be the newline character "\n", which looks like two characters but is actually one character. 

An arbitrary byte size bit pattern can be specified by 
'\ooo' where ooo is 1 - 3 octal digits. Or '\xhh' where hh is 1 - 2 hexidecimal digits. 
Escape sequences have values so instead of using the letter, the escape sequence can be defined using octal or hexidecimal.

Ex: 
    #define VTAB '\xb'       ASCII vertical tab /
    #define BELL '\x7'       ASCII bell character /

The full list of escape sequences are:
\a alert (bell) character 
\ \ backslash
\b backspace 
\? question mark
\f formfeed 
\' single quote
\n newline 
\ " double quote
\r carriage return 
\t horizontal tab 
\v vertical tab

The null constant is '\0'

### Enumeration

You can enumerate booleans:
enum boolean { NO, YES }; No is equal to the 0/false and the yes is equal to the 1/true value.

Two examples of enumeration are:
```
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
```
```
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB = 2, MAR = 3, etc. */
```


### 2.4 Declaration 
Variables have to be declared after initialization

### 2.5 Arithmetic operations
The arithmetic operators are * (multiplication), / (division), + (addition), - (subtraction), and % (modulo)

### 2.6 Logical Operations
< (less than), <= (less than or equal too), >= (greater than or equal too), > (greater than), == (equal too), != (not equal too), && (logical AND operator), and || (logical OR) 

If there are multiple on one line like in an if statement then they are evaluated from left to right. Additionally the precedence of && is higher than that of ||, and both are lower than relational and equality operators. 

### 2.7 Type Conversion

In general the only "automatic" conversion are those from data types that are "narrower" to "wider" without losing information. Such as a int to a long or a float to a double. 

If there are operands that end up taking in two datatypes the "wider" or datatype is considered for the output. Floats however are not automatically converted to doubles as floats are typically used in databases to save space. 

Additionally types can be forcibly converted. For example in the sqrt function imported from the math standard library <math.h> The sqrt() function expects two doubles so if an integer (n) is used it will output an incorrect answer. 
This can be solved by using sqrt( (double) n)

### 2.8 Increment and Decrement Operators 
To increment you can just do variable (n) and then '++' Ex: n++; or n--. ++ adds 1 and -- subtracts 1. 
