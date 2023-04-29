#include "main.h"

/**
 * get_size - Extracts the size modifier from a format string
 * @format: A string containing the format specifier
 * @index: A pointer to the current index in the format string
 *
 * Return: The size modifier as an integer
 */
int get_size(const char *format, int *index)
{
	int current_index = *index + 1;
	int size = 0;

	/* Check if the current character is 'l' */
	if (format[current_index] == 'l')
		size = S_LONG;
	/* Check if the current character is 'h' */
	else if (format[current_index] == 'h')
		size = S_SHORT;

/* If the size modifier was not found, update the index to the current position */
	if (size == 0)
		*index = current_index - 1;
	/* If the size modifier was found, update the index to the next position */
	else
		*index = current_index;

	/* Return the size modifier as an integer */
	return (size);
}
