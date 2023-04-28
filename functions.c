/**
 * file: print_functions.c
 * author: [author name]
 * description: Contains functions to print various types of data
 */

#include "main.h"
/************************* PRINT CHARACTER *************************/

/**
 * print_character - Prints a character
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_character(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/******************** PRINT A STRING ********************/
/**
 * print_string - Prints a string
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
			{
				write(1, " ", 1);
			}
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
			{
				write(1, " ", 1);
			}
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/******************** PRINT PERCENT SIGN ********************/
/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_integer - Prints an integer
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_integer(va_list args, char buffer[], int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
int is_negative = 0;
long int num = va_arg(args, long int);
unsigned long int abs_num;

/* convert size specifier to number */
num = convert_size_number(num, size);

/* handle special case for zero */
if (num == 0)
{
buffer[i--] = '0';
}

buffer[BUFF_SIZE - 1] = '\0';

/* handle negative numbers */
if (num < 0)
{
abs_num = (unsigned long int)(-1 * num);
is_negative = 1;
}
else
{
abs_num = (unsigned long int)num;
}

/* convert integer to string and store in buffer */
while (abs_num > 0) 
{
buffer[i--] = (abs_num % 10) + '0';
abs_num /= 10;
}

/* adjust index */
i++;

/* write number to output stream */
return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Print unsigned int as binary
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_binary(va_list types, char buffer[],
    int flags, int width, int precision, int size)
{
    unsigned int n, i, count = 0;
    unsigned int a[32];

    n = va_arg(types, unsigned int);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    for (i = 0; i < 32; i++)
       	 a[i] = (n >> i) &1;

    for (i = 31; i > 0; i--)
    {
        if (a[i] == 1)
          	  break;
    }

    for (; i != (unsigned int)-1; i--)
    {
       	 char c = '0' + a[i];

      	  write(1, &c, 1);
        	count++;
    }

    return (count);
}
