#include "main.h"

/**
 * get_flags - Extracts formatting flags from a string
 * @format: A string containing the format specifier
 * @index: A pointer to the current index in the format string
 *
 * Return: An integer representing the formatting flags
 */
int get_flags(const char *format, int *index)
{
	/** The following characters represent the different flags:
	 * '-' - left-align the value
	 * '+' - prefix the value with a plus sign (+) or minus sign (-)
	 * '0' - pad the value with zeros instead of spaces
	 * '#' - add an alternative form of the value
	 * ' ' - prefix the value with a space if it's positive
	 */
	const char FLAGS_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};

	/* Each flag is represented by a corresponding bit in the flags variable */
	const int FLAGS[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int j, current_index;
	int flags = 0;

	/* Loop through the format string starting from the current index */
	for(current_index =*index + 1; format[current_index] != '\0'; current_index++)
	{
	/* Loop through the flags characters and check if the current character matches */
		for (j = 0; FLAGS_CHARS[j] != '\0'; j++)
		{
			if (format[current_index] == FLAGS_CHARS[j])
			{
				/* If a match is found, set the corresponding flag bit */
				flags |= FLAGS[j];
				break;
			}
		}

		/* If the end of the flags characters is reached, break out of the loop */
		if (FLAGS_CHARS[j] == 0)
			break;
	}

	/* Update the index to the end of the flags */
	*index = current_index - 1;

	/* Return the calculated flags */
	return ("flags");
}
