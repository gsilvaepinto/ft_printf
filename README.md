<i>This project has been created as part of the 
42 curriculum by guilheda.</i>

## Description
<b>ft_printf</b> is a recreation of the standard C library function <b>printf()</b>. This project aims to deepen understanding of variadic functions, type formatting, and low-level output operations in C. The implementation handles multiple conversion specifiers and returns the total number of characters printed, mimicking the behavior of the original <b>printf()</b>.
The main goal is to build a custom formatted output function that can handle various data types while managing memory efficiently and adhering to the 42 Norm coding standards.

### The following conversions are implemented:

<b>%c</b> - Print a single character

<b>%s</b> - Print a string

<b>%d</b> / <b>%i</b> - Print a signed decimal integer

<b>%u</b> - Print an unsigned decimal integer

<b>%x</b> - Print an unsigned hexadecimal integer (lowercase)

<b>%X</b> - Print an unsigned hexadecimal integer (uppercase)

<b>%p</b> - Print a pointer address in hexadecimal

<b>%%</b> - Print a literal percent sign

## Instructions Compilation

To compile the library, run:

<b>make</b>

This will generate the libftprintf.a static library.

### Cleaning

Remove object files: 

- <b>make clean</b>

Remove object files and library:

- <b>make fclean</b>

Recompile everything: 

- <b>make re</b>

### Compile with your program:

gcc main.c libftprintf.a -o program
./program

## Algorithm and Data Structure

1. <b>Variadic Functions (va_list)</b>

The project uses C's <stdarg.h> library to handle variable numbers of arguments
va_start(), va_arg(), and va_end() macros traverse the argument list.

Type promotion rules are respected (e.g., char is promoted to int, so we use va_arg(args, int) for %c).

2. <b>Recursive Number Conversion</b>

Number printing functions use recursion to handle digits.

For ft_putnbr(): recursively divides by 10 until a single digit remains.

For ft_putnbr_base(): recursively divides by the base (16 for hex, 8 for octal, etc.).

3. <b>Modular Function Architecture</b>

Each conversion type has dedicated helper functions:

<b>ft_putstr()</b> - handles strings and characters

<b>ft_putnbr()</b> - handles signed integers

<b>ft_putlunbr_base()</b> - handles unsigned integers in any base (hex, decimal)

<b>ft_format()</b> - dispatcher that routes to the appropriate handler based on the specifier.


4. <b>Character Counting Strategy</b>

Every write operation returns the number of bytes written.

The main loop accumulates these counts.


### Special Cases Handled

INT_MIN (-2147483648): Cannot be negated directly due to two's complement limits, so it's hardcoded.

NULL strings: Prints "(null)" to match standard printf() behavior.

Pointer formatting: Casts addresses to unsigned long and prints in hexadecimal with "0x" prefix.

## Resources Documentation

<b>printf man page</b> - Standard printf reference

<b>stdarg.h documentation</b> - Variadic function handling

## AI Usage
AI assistance was used for the following tasks:

<b>Debugging support</b>: Identifying logic errors in variadic argument handling and type casting issues.

<b>Documentation:</b> Structuring this README and explaining technical concepts clearly.

No AI-generated code was used directly without understanding and manual verification. All core logic and implementation decisions were made independently with AI serving as a learning tool.