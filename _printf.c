#include "main.h"

void print_buffer(char my_buffer[], int *buffer_index);

/**
 * my_printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int my_printf(const char *format, ...)
{
	int i, num_printed = 0, printed_chars = 0;
	int my_flags, my_width, my_precision, my_size, buffer_index = 0;
	va_list args;
	char my_buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			my_buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
				print_buffer(my_buffer, &buffer_index);
			printed_chars++;
		}
		else
		{
			print_buffer(my_buffer, &buffer_index);
			my_flags = get_my_flags(format, &i);
			my_width = get_my_width(format, &i, args);
			my_precision = get_my_precision(format, &i, args);
			my_size = get_my_size(format, &i);
			++i;
			num_printed = handle_my_print(format, &i, args, my_buffer,
				my_flags, my_width, my_precision, my_size);
			if (num_printed == -1)
				return (-1);
			printed_chars += num_printed;
		}
	}

	print_buffer(my_buffer, &buffer_index);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - prints the contents of the buffer if it exists
 * @my_buffer: array of characters
 * @buffer_index: index at which to add the next character, represents the length
 */
void print_buffer(char my_buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &my_buffer[0], *buffer_index);

	*buffer_index = 0;
}
