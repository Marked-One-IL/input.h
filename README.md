![Project Picture]()

A safer and easier solution for the C input functions.

C is known to be unsafe with input functions,
and sometimes even tedious just to implement them partly safe.

My small project remade the common input functions,
and make them safer and easier to use.

# Main Functions

- char* input(const char strPrn[])
  Return an allocated input with no limit (Like Python).
  
- char input_char(const char strPrn[])
  Return a char from input.
  If invalid input was entered, ask again for input.
 
- long long int input_int(const char strPrn[])
  Return a converted interger from input.
  If invalid input was entered, ask again for input.

- double input_float(const char strPrn[])
  Return a converted float from input.
  If invalid input was entered, ask again for input.

- char input_char_range(const char strPrn[], char rangeFrom, char rangeTo)
  Return a char from input within within a specified range.
  If invalid input was entered, ask again for input.

- long long int input_int_range(const char strPrn[], long long int rangeFrom, long long int rangeTo)
  Return a converted interger from input within a specified range.
  If invalid input was entered, ask again for input.

- double input_float_range(const char strPrn[], double rangeFrom, double rangeTo)
  Return a converted float from input within a specified range.
  If invalid input was entered, ask again for input.


# Note

Those functions can also be found in in project file,
and probably only practical in the main functions.
But you can still use them.
   
- long long int string_to_int(const char str[], bool* is_error)
  Convert a string to an int and return it.

- double string_to_float(const char str[], bool* is_error)
  Convert a string to a float and return it.

- bool only_spaces_string(const char str[])
  Check if the string only contains spaces and return the results.

- double power(int base, int pow)
  Return base^pow (Note: This functions is very limited. math.h is not used to avoid putting -lm when compiling on Linux).
