#include <stdio.h>
#include "input.h"

int main()
{
	int choice = 0;

	char rangeFromChar = ' ';
	char rangeToChar = ' ';
    int rangeFromInt = 0;
    int rangeToInt = 0;
    double rangeFromFloat = 0;
    double rangeToFloat = 0;

	char* string = 0;
	char chr = ' ';
    int intNumber = 0;
    double floatNumber = 0;

    while (true)
    {
        puts("1. input()\n"
        "2. input_char()\n"
        "3. input_int()\n"
        "4. input_float()\n"
        "5. input_char_range()\n"
        "6. input_int_range()\n"
        "7. input_float_range()\n"
        "8. Exit\n");

        choice = input_int_range("Enter a choice (1 - 8): ", 1, 8);

    	switch (choice)
     	{
     		case 1:
     			string = input("Enter a string: ");
                printf("You entered: %s\n\n", string);
                free(string); 
     			break;

     		case 2:
     			chr = input_char("Enter a char: ");
     			printf("You entered: %c\n\n", chr);
     			break;

     		case 3:
     			intNumber = input_int("Enter an integer: ");
     			printf("You entered: %d\n\n", intNumber);
     			break;

     		case 4:
     			floatNumber = input_float("Enter a float: ");
     			printf("You entered: %f\n\n", floatNumber);
     			break;

            case 5:
            	rangeFromChar = input_char("Range from: ");
            	rangeToChar = input_char("Range to: ");
            	printf("Range: %c - %c\n", rangeFromChar, rangeToChar);

            	// Limition: I can't print rangeFromChar and rangeToChar.
            	chr = input_char_range("Enter a char within that range: ", rangeFromChar, rangeToChar);
            	printf("You entered: %c\n\n", chr);
            	break;

     		case 6:
     			rangeFromInt = input_int("Range from: ");
     			rangeToInt = input_int("Range to: ");
                printf("Range: %d - %d\n", rangeFromInt, rangeToInt);

                // Limition: I can't print rangeFromInt and rangeToInt.
     			intNumber = input_int_range("Enter an integer within that range: ", rangeFromInt, rangeToInt);
     			printf("You entered: %d\n\n", intNumber);
     			break;

     		case 7:
                rangeFromFloat = input_float("Range from: ");
                rangeToFloat = input_float("Range to: ");
                printf("Range: %f - %f\n", rangeFromFloat, rangeToFloat);

                // Limition: I can't print rangeFromFloat and rangeToFloat.
                floatNumber = input_float_range("Enter a float within that range: ", rangeFromFloat, rangeToFloat);
                printf("You entered: %f\n\n", floatNumber);
     			break;

     		case 8:
     			puts("Goodbye");
     			string = input("Enter anything to exit... ");
     			free(string);
     			return 0;

     		// No need for default.
    	}
    }

	return 0;
}
