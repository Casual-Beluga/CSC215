/*
    Description: Convert the text in the file passed as input to base64.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

char base64Alphabet[64] = {
    // list of characters who's position corresponds to its value **generated using github copilot**
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', /*  0 -  7 */ 
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', /*  8 - 15 */
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', /* 16 - 23 */
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', /* 24 - 31 */
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', /* 32 - 39 */
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', /* 40 - 47 */
    'w', 'x', 'y', 'z', '0', '1', '2', '3', /* 48 - 55 */
    '4', '5', '6', '7', '8', '9', '+', '/'  /* 56 - 63 */
};

char getbits(char x, int p, int n); //initializes the function

int main(int argc, char *argv[])
{
    FILE *file;
    char *buffer;
    long file_size;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the binary file in binary read mode
    file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Find the size of the file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the buffer to hold the file contents
    int bytesOver = file_size % 3;
    buffer = (char *)malloc(file_size + (3 - bytesOver));
    if (buffer == NULL)
    {
        perror("Memory allocation error");
        fclose(file);
        return 1;
    }

    // Read the file contents into the buffer
    if (fread(buffer, 1, file_size, file) != file_size)
    {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);

    // ***** convert to base64 & print *****
    int iters = ceil(file_size / 3.0); //finds the number of groups of 24, as 8*3 is 24
    for (long i = 0; i < iters; ++i) //iterates through the groups of 24 bits.
    {
        bool isLast = i == iters - 1; //checks if the program has arrived at the last set of 24 bits.

        int bufIndex = i * 3; //set bufIndex to the location of the first byte in the set of 24 bits.
        char currentChar = (char)buffer[bufIndex]; //sets the current character to location of the current 'first byte' in the buffer
        char first = getbits(buffer[bufIndex], 8, 6); //gets the first 6 bits from the left
        char second = (getbits(buffer[bufIndex], 2, 2) << 4) | getbits(buffer[bufIndex + 1], 8, 4); // adjoins the first 4 bits of the next byte to the two remaining bits of the last byte
        char third = (getbits(buffer[bufIndex + 1], 4, 4) << 2) | getbits(buffer[bufIndex + 2], 8, 2); //creates the next grouping of 6 bits by adjoining bits.
        char fourth = getbits(buffer[bufIndex + 2], 6, 6); //24 is the LCD of 6 and 8 so the last 6 bits can just be used.

        printf("%c", base64Alphabet[first]); //prints the corrosponding character to the first group of 6 bits
        printf("%c", base64Alphabet[second]); //then the 2nd
        if (isLast && bytesOver == 1) // if it is 1 byte over then your need two padding characters
        { // quantize
            printf("==");
            break; // end the loop, we've processed everything
        }
        else
        {
            printf("%c", base64Alphabet[third]); //prints the 3rd group of 6 bits
        }
        if (isLast && bytesOver == 2)// checks to see if it is two bytes over
        { // quantize
            printf("=");
        }
        else
        {
            printf("%c", base64Alphabet[fourth]); //if the final set of 24 bits has three bytes then no padding is needed.
        }
    }


    printf("\n");

    // Free the allocated memory
    free(buffer);

    return 0;
}

char getbits(char x, int p, int n)
{
    return (x >> (p - n)) & ~(~0 << n); // 
    /*
    gets n number of bits starting p bits from the leftmost side of a byte.
    this is useful because we are working with sets of 6 
    and there will be a variable amounts of bits that will need to be gathered
    */
}
