#include "main.h"
/**
 * get_precision - Extracts the precision from a format string
 * @format: A string containing the format specifier
 * @index: A pointer to the current index in the format string
 * @list: A va_list of arguments to be printed
 *
 * Return: The precision for printing
 */
int get_precision(const char *format, int *index, va_list list)
{
	int current_index = *index + 1;
	int precision = -1;

	/* Check if the current character is a period (.) */
	if (format[current_index] != '.')
		return precision;

	precision = 0;

	/* Loop through the characters after the period */
	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		/* If the current character is a digit, update the precision accordingly */
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		/* If the current character is an asterisk (*), retrieve the precision from the va_list */
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(list, int);
			break;
		}
		/* If the current character is neither a digit nor an asterisk, break out of the loop */
		else
			break;
	}

	/* Update the index to the end of the precision */
	*index = current_index - 1;

	/* Return the calculated precision */
	return precision;
}
