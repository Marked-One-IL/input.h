#ifndef INPUT
#define INPUT

#include <stdlib.h>
#include <stdbool.h>

/* 
Note: I only use .h file and don't separate it with .c file.
   It's because it's you will no input extra parameters when compiling.
   And I don't care if it doesn't follow standard conventions, it's simpiler that way.
*/

// Main functions.
char* input(const char strPrn[]);
long long int input_int(const char strPrn[]);
double input_float(const char strPrn[]);
long long int input_int_range(const char strPrn[], long long int rangeFrom, long long int rangeTo);
double input_float_range(const char strPrn[], double rangeFrom, double rangeTo);


// Sub functions, mainly to help the main functions.
long long int string_to_int(const char str[], bool* is_error);
double string_to_float(const char str[], bool* is_error);
bool only_spaces_string(const char str[]);
double power(int base, int pow); // While can be found in the math.h, you have to include -lm when you compile on Linux.

/*
Input: String to print.
Output: Allocated string.

Action: Recreate the input() function from Python in C.
        it return an allocated buffer who can accept any input size (That the Computer and the Terminal can handle).

Time Complexity: O(len(input)).
Note: Unlike fgets() there is no '\n' at the end, and no buffer overflow.
*/
char* input(const char strPrn[])
{
    char* buffer = NULL;
    char* temp = NULL;
    char chr = ' ';
    int size = 0;
    int chunk_size = 15;

    fputs(strPrn, stdout);

    // Allocate guessed needed memory.
    buffer = (char*)malloc(sizeof(char) * chunk_size);
    if (buffer == NULL)
    {
        return NULL;
    }

    // getc(stdin) tell the Termianl to ask for input string,
    // and then read the returned string from the Termianl until reached '\n'.
    while ((chr = getc(stdin)) != '\n')
    {
        size += 1;

        // If more memory is needed, increase the chunk size and reallocate the buffer.
        if (size >= chunk_size)
        {
            chunk_size *= 2;

            temp = (char*)realloc(buffer, sizeof(char) * chunk_size);
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }

            buffer = temp;
        }

        // Apply the new char on the buffer.
        buffer[size - 1] = chr;
    }
    
    // Reallocate the buffer for the '\0', and also will shrink the buffer if needed.
    temp = (char*)realloc(buffer, sizeof(char) * (size + 1));
    if (temp == NULL)
    {
        free(buffer);
        return NULL;
    }

    buffer = temp;
    buffer[size] = '\0';

    return buffer;
}


/*
Input: String.
Output: Boolean is the string only contain spaces.
Time Complexity: O(len(string)).
Note: This function is useless outside of the main functions. 
*/
bool only_spaces_string(const char str[])
{
    int i = 0;

    if (str == NULL)
    {
        return false;
    }

    for (i; str[i] != '\0'; i += 1)
    {
        if (str[i] != ' ')
        {
            return false;
        }
    }

    return true;
}

/*
Input: Base number, Power number.
Output: Base^Power.
Time Complexity: O(power).
Note: This function is very limited (And it's enough), also it this function is useless outside of the main functions.
      Like stated before it was just to save a command a Linux when compiling.
*/
double power(int base, int pow)
{
    double results = 1;
    int i = 0;

    for (i; i < pow; i += 1)
    {
        results *= base;
    }
    
    return results;
}

/*
Input: String to extract, Pointer to a boolean log.
Output: Extracted number (Interger).
Action: Extract a string of char numbers to the actual value number, and return it,
        also put in the bool log if the results of the extraction.

Time Complexity: O(len(string))
Note: The function is also very strict with valid input.
      For example if 1234s was given while functions like atoi would let that pass.
      This function wouldn't.
*/
long long int string_to_int(const char str[], bool* is_error)
{
    long long int sum = 0;
    int i = 0;
    int is_negative = 1;
    bool trash = false;

    // If "is_error" is NULL, don't apply log.
    if (is_error == NULL) is_error = &trash;

    if (str == NULL || str[i] == '\0' || str[i] == ' ') {
        *is_error = true;
        return 0;
    }

    // If the number is negative
    if (str[0] == '-') {
        is_negative = -1;
        i += 1;

        // If it's the end. failure.
        if (str[1] == '\0') {
            *is_error = true;
            return 0;
        }
    }

    // Extract the Integer
    for (i; str[i] != '\0'; i += 1)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum *= 10;
            sum += str[i] - 48;
        }

        // If encountered an invalid char, failure. 
        else
        {
            // If the rest of string is just spaces, success.
            if (only_spaces_string(str + i))
            {
                *is_error = false;
                return sum * is_negative;
            }

            // Else, failure.
            *is_error = true;
            return 0;
        }
    }

    *is_error = false;
    return sum * is_negative;
}

/*
Input: String to extract, Pointer to a boolean log.
Output: Extracted number (Float).
Action: Extract a string of char numbers to the actual value number, and return it,
        also put in the bool log if the results of the extraction.

Time Complexity: O(2len(string))
Note: The function is also very strict with valid input.
      For example if 1234.1234s was given while functions like atof would let that pass.
      This function wouldn't.
*/
double string_to_float(const char str[], bool* is_error)
{
    double sum = 0;
    int i = 0;
    int j = 0;
    int is_negative = 1;
    bool trash = false;

    // If "is_error" is NULL, don't apply log.
    if (is_error == NULL) is_error = &trash;

    if (str == NULL || str[i] == '\0' || str[i] == ' ') {
        *is_error = true;
        return 0;
    }

    // If the number is negative
    if (str[0] == '-') {
        is_negative = -1;
        i += 1;

        // If it's the end. failure.
        if (str[1] == '\0') {
            *is_error = true;
            return 0;
        }
    }

    // Extract the Integer part.
    for (i; str[i] != '.'; i += 1)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum *= 10;
            sum += str[i] - 48;
        }

        else
        {
            // If it's the end or the rest of string is just spaces, success.
            if (str[i] == '\0' || only_spaces_string(str + i))
            {
                *is_error = false;
                return sum * is_negative;
            }

            // Else, failure.
            *is_error = true;
            return 0;
        }
    }

    // Extract the Decimal part.
    for (i += 1; str[i] != '\0'; i += 1)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            j += 1;
            sum += (str[i] - 48) / power(10, j);
        }

        else
        {
            // If the rest of string is just spaces, success.
            if (only_spaces_string(str + i))
            {
                *is_error = false;
                return sum * is_negative;
            }

            // Else, failure.
            *is_error = true;
            return 0;
        }
    }

    *is_error = false;
    return sum * is_negative;
}


/*
Input: String to print.
Output: Int input.
Action: Ask the user for a integer number, until it succeed.
Note: No buffer overflow.
*/
long long int input_int(const char strPrn[])
{
    char* inp = NULL;
    long long int value = 0;
    bool is_error = false;

    do
    {
        inp = input(strPrn);
        if (inp == NULL)
        {
            return 0;
        }

        value = string_to_int(inp, &is_error);
        free(inp);

    } while (is_error);

    return value;
}

/*
Input: String to print.
Output: Float input.
Action: Ask the user for a float number, until it succeed.
Note: No buffer overflow.
*/
double input_float(const char strPrn[])
{
    char* inp = NULL;
    double value = 0;
    bool is_error = false;

    do
    {
        inp = input(strPrn);
        if (inp == NULL)
        {
            return 0;
        }

        value = string_to_float(inp, &is_error);
        free(inp);

    } while (is_error);

    return value;
}

/*
Input: String to print, Range from valid number, Range to valid number.
Output: The inputed interger.
Action: Ask from user to enter an input until it match the range.
Note: No buffer overflow.
*/
long long int input_int_range(const char strPrn[], long long int rangeFrom, long long int rangeTo)
{
    long long int inp = 0;

    // If the range is invalid, return 0.
    if (rangeFrom >= rangeTo) return 0;

    // Ask for input until it match the range.
    do
    {
        inp = input_int(strPrn);
    } while (inp < rangeFrom || inp > rangeTo);

    return inp;
}

/*
Input: String to print, Range from valid number, Range to valid number.
Output: The inputed floatnumber.
Action: Ask from user to enter an input until it match the range.
Note: No buffer overflow.
*/
double input_float_range(const char strPrn[], double rangeFrom, double rangeTo)
{
    double inp = 0;

    // If the range is invalid, return 0.
    if (rangeFrom >= rangeTo) return 0;

    // Ask for input until it match the range.
    do
    {
        inp = input_float(strPrn);
    } while (inp < rangeFrom || inp > rangeTo);

    return inp;
}

#endif
