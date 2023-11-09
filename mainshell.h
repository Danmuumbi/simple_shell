#include "shell.h"

/**
 * Check if the shell is operating in interactive mode.
 *
 * @param info - a pointer to the shell information structure
 *
 * @return 1 if the shell is in interactive mode, 0 otherwise
 */
int check_interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Determine whether a character is a delimiter within a given delimiter string.
 *
 * @param c - the character to examine
 * @param delim - the delimiter string to check against
 * 
 * @return 1 if the character is a delimiter, 0 if it is not
 */
int is_character_delimiter(char c, char *delim)
{
	while (*delim) {
		if (*delim++ == c) {
			return 1;
		}
	}
	return 0;
}

/**
 * Check if a character is alphabetic.
 *
 * @param c - the character to evaluate
 *
 * @return 1 if 'c' is an alphabetic character, 0 otherwise
 */
int is_alphabetic_character(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
		return 1;
	} else {
		return 0;
	}
}

/**
 * Convert a string to an integer.
 *
 * @param s - the string to be converted
 *
 * @return 0 if there are no numbers in the string, the converted number otherwise
 */
int convert_string_to_integer(char *s)
{
	int i, sign = 1, flag = 0, result;
	unsigned int output = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++) {
		if (s[i] == '-') {
			sign *= -1;
		}

		if (s[i] >= '0' && s[i] <= '9') {
			flag = 1;
			output *= 10;
			output += (s[i] - '0');
		} else if (flag == 1) {
			flag = 2;
		}
	}

	if (sign == -1) {
		result = -output;
	} else {
		result = output;
	}

	return result;
}
