# FT_PRINTF

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

- <b>make</b>

This will generate the libftprintf.a static library.

### Cleaning

Remove object files: 

- <b>make clean</b>

Remove object files and library:

- <b>make fclean</b>

Recompile everything: 

- <b>make re</b>

<hr>

### Compile with your program:

cc main.c libftprintf.a -o program

./program


