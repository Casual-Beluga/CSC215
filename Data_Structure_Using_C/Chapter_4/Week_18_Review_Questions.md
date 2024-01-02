# 1. What are strings? Discuss some of the operations that can be performed on strings.
String are arrays of characters that where the final element is a terminating character (\0).
The operations that can be performed on arrays can also be performed on strings. 
So you are able to print individual characters, you can swap out certain characters for others and there are variety of other ways to manipulate strings.


# 2. How are strings represented in main memory?

Strings are represented as sequential blocks of data. So for example if the 'H' of "Hello" was stored at the memory address 1000 then
the following characters would be stored from 1000 to 1101.

# 3. How are strings read from the standard input device?

Strings are typically read from the standard input device through use of the standard library more specifically the function scanf().
Strings can also be read from the standard input device using gets() and getchar(). Although gets() is being phased out to be replaced by fgets(). 

# 4. Explain how strings can be displayed on the screen?

One way that text can be displayed is by printing to the standard output which is the terminal. 
This can be done through printf() or putchar() or puts().

# 5. Explain the syntax of printf() and scanf()

The standard syntax of printf() is ("format_specifier", variable_name)
the standard syntax of scanf() is ("fortmat_specifier", &variable_name)
for scanf() if data type of the input is anything but a string then an ampersand (&) must be used before the name of the variable where the input is being allocated to.

# 13. Differentiate between scanf() and gets().
The main issue with scanf() is that it will terminate as soon as it gets to a blank space.
Also with scanf() you can specify the width of the field that you want to be read.

Gets() overcomes the issues with scanf() as it simply takes in the starting point
and then will continue looping through until it hits a null character.
